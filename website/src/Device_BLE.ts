import { waitFor } from '@testing-library/react';
import { triggerNotification, waitForNotification } from './BLE_Handler';
import { Packet_t, Props_t, Command_t, Props, Command } from './PacketDefinitions';

const DEBUG: boolean = false;

// BLE UUIDs
const SERVICE_UUID = "9f9ece14-b513-4cdb-b0b8-9e5fa3b9fef2";
const CHARACTERISTIC_UUID = "f5db5ef9-c1d0-4d1b-8907-d3f2075872c5";

const DEVICE_BUFFER_SIZE: number = 256;

const UTF8Encoder = new TextEncoder();

declare global {
  interface Window {
    // characteristic: any;
    packet: any;
    props: any;
  }
};

var pDevice = null as BluetoothDevice | null;
var pServer: BluetoothRemoteGATTServer | null| undefined;
var pService = null as BluetoothRemoteGATTService | null;
var pCharacteristic = null as BluetoothRemoteGATTCharacteristic | null;
var pEventCharacteristic = null as BluetoothRemoteGATTCharacteristic | undefined | null;

var mtu = 128;       // useable MTU -> if actual MTU is 23, useable is 23 - 3 = 20

const connectToDevice = async (setMTU = 0) => {
    if (pDevice === null) {
      console.log("Requesting");
      pDevice = await navigator.bluetooth.requestDevice({filters: [{services: [SERVICE_UUID]}]});
      pServer = await pDevice.gatt?.connect();
      pService = await pServer?.getPrimaryService(SERVICE_UUID) || null;
      pCharacteristic = await pService?.getCharacteristic(CHARACTERISTIC_UUID) || null;
      // setDevice(await navigator.bluetooth.requestDevice({filters: [{services: [SERVICE_UUID]}]}));
      // setserver(await device.gatt.connect());
      window.characteristic = pCharacteristic;
      
      // pCharacteristic?.startNotifications().then((stuff) => {

      // });
      console.log(pCharacteristic?.properties);
      console.log("Installing notification listener");
      pCharacteristic!.addEventListener('characteristicvaluechanged', handleNotifications);
      
      
      if (setMTU !== 0) {
        changeMTU(setMTU);
      }
      
      console.log("Here I am");
    }
    else {
      console.log("Device is initialized. Nothing to do.");
    }
};

const disconnectToDevice = async() => {
    if (pDevice !== null) {
      pServer?.disconnect();
      pServer = null;
      pService = null;
      pCharacteristic = null;
    }
};

const handleNotifications = async (event: any) => {
  if (DEBUG) {

      console.log(typeof(event));
      console.log(event.target.value);
      console.log("Notification fired!");
  }
  triggerNotification();
};

const asyncWriteToDevice = async( packet: Uint8Array) => {
  var notification = waitForNotification();
  // pCharacteristic?.writeValueWithResponse(packet);
  await pCharacteristic?.writeValueWithResponse(packet);
  pCharacteristic?.readValue();
  await notification;
}

const getDefaultPacket = (): [Packet_t, Props_t, Command_t] => {
  return [new Packet_t(mtu), new Props_t(1), new Command_t(1)];
}

const setPacket = (packet: Packet_t, props: Props_t, command: Command_t) => {
  packet.set(new Uint8Array(props.buffer), 0);
  packet.set(command, 2);

  window.packet = packet;
  window.props = props;
  
  console.log("The build packet is: ");
  console.log(packet);
};

const changeMTU = async (setMTU: Number) => {

  var [sendPacket , props, command] = getDefaultPacket();
  
  
  
}

const ping = async () => {

  var [packet, props, command] = getDefaultPacket();
  command[0] = Command.PING[0];
  props[0] = Props.CLIENT_RESPONSE[0] | Props.REQUEST_FOR_SERVER_RESPONSE[0] | Props.REQUEST_FOR_NOTIFY[0];

  setPacket(packet, props, command);

  console.log("Pinging device");
  await asyncWriteToDevice(packet);
  console.log("Response from device: ");
  console.log(pCharacteristic?.value);
  
}

const uploadFile = async(file: File | Blob, filename: string = "noname.bin") => {

  var fileData: Uint8Array;
  var fileReader = new FileReader();
  var fileAccept: Function, fileReject: Function;
  var fileReadDone = new Promise((accept, reject) => {
    fileAccept = accept;
    fileReject = reject;
  });
  
  fileReader.onload =() => {
    fileAccept();
  };

  fileReader.onerror = (err) => {
    console.error(err);
    fileReject();
  };

  fileReader.onprogress = (data) => {
    if (data.lengthComputable) {
      let progress = data.loaded / data.total * 100;
      console.log(`Progress: ${progress}`);
    }
  };
  
  fileReader.readAsArrayBuffer(file);
  await fileReadDone;
  fileData = new Uint8Array(fileReader.result as ArrayBuffer);
  
  
  if (pServer?.connected) {

    console.log("Here I am");
    
    const MAX_TRANSMISSABLE_WRITE_BYTE_SIZE: number = mtu - 5;
    
    // setup packet
    var [packet, props, command] = getDefaultPacket();
    props[0] = Props.CLIENT_RESPONSE[0] | Props.REQUEST_FOR_NOTIFY[0] | Props.REQUEST_FOR_SERVER_RESPONSE[0];
    command[0] = Command.WRITE[0]

    // set packet information
    packet.set(new Uint8Array(props.buffer), 0);
    packet.set(command, 2);
    
    // put filename into buffer;
    {
      // write file into main buffer
      let [filePacket, fileProps, fileCommand] = getDefaultPacket();
      fileProps[0] = Props.CLIENT_RESPONSE[0] | Props.REQUEST_FOR_NOTIFY[0] | Props.REQUEST_FOR_SERVER_RESPONSE[0];
      fileCommand[0] = Command.WRITE[0];
      
      filePacket.set(new Uint8Array(fileProps.buffer), 0);
      filePacket.set(fileCommand, 2);
      filePacket.set(new Uint8Array(new Uint16Array([MAX_TRANSMISSABLE_WRITE_BYTE_SIZE << 11 | 0]).buffer), 3);
      filePacket.set(UTF8Encoder.encode(filename).slice(0, MAX_TRANSMISSABLE_WRITE_BYTE_SIZE), 5);
      
      console.log("Initial Packet: ");
      console.log(filePacket);

      await asyncWriteToDevice(filePacket);
      await wait(1000);
      
      // stage data from main buffer to small buffer
      fileCommand[0] = Command.STAGE_SMALL_BUFFER[0];
      await asyncWriteToDevice(filePacket);
      await wait(1000);

      // create file
      fileCommand[0] = Command.FILE_CREATE[0];
      await asyncWriteToDevice(filePacket);
      await wait(1000);
    }
    
    // setup packet for appending to file
    let [appendPacket, appendProps, appendCommand] = getDefaultPacket();
    appendProps[0] = Props.CLIENT_RESPONSE[0] | Props.REQUEST_FOR_NOTIFY[0] | Props.REQUEST_FOR_SERVER_RESPONSE[0]
    appendCommand[0] = Command.FILE_APPEND[0];
    
    // begin file transmission
    for (let i: number = 0; i < file.size;) {
      var writeAddress: number = i % (DEVICE_BUFFER_SIZE);
      var bytesToWrite: number = Math.min(MAX_TRANSMISSABLE_WRITE_BYTE_SIZE, file.size - i, DEVICE_BUFFER_SIZE - writeAddress);
      
      var fileInformation = new Uint16Array([bytesToWrite << 11 | writeAddress]);

      // package the packet
      packet.set(new Uint8Array(fileInformation.buffer), 3);
      packet.set(new Uint8Array(fileData.slice(i, i + bytesToWrite)), 5);
      
      // console.log("Transmission!");
      // console.log(`Address: ${writeAddress} - File Size: ${bytesToWrite}`);
      // console.log(packet);
      // console.log(fileData.slice(i, i + bytesToWrite));
      // console.log("Transmission end");

      // send over BLE

      i += bytesToWrite;

      // let notification = waitForNotification();
      // pCharacteristic?.writeValueWithResponse(packet);
      // await notification;
      await asyncWriteToDevice(packet);
      
      if (bytesToWrite < MAX_TRANSMISSABLE_WRITE_BYTE_SIZE || i >= file.size) {
        // append to BLE
        let bytesToAppend: Uint16Array = new Uint16Array([writeAddress + bytesToWrite]);
        appendPacket.set(new Uint8Array(bytesToAppend.buffer), 3)
        
        // let notification = waitForNotification();
        // pCharacteristic?.writeValueWithResponse(appendPacket);
        // await notification;
        await asyncWriteToDevice(appendPacket);
      }
    }
    
  }
  
  return false;

    
};

const wait = async (time: number) => {

  console.log(`${time} is the time`);
  
  var promise = new Promise((resolve: Function, reject: Function) => {
    
    setTimeout(() => {
      console.log("Here it is");
      resolve();
    }, time);
  });

  await promise;
  return;
};

export {
  connectToDevice,
  disconnectToDevice,
  uploadFile,
  ping
}
