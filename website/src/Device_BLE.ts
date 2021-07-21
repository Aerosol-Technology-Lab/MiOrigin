import { triggerNotification, waitForNotification } from './BLE_Handler';
import { Packet_t, Props_t, Command_t } from './PacketDefinitions';


// BLE UUIDs
const SERVICE_UUID = "9f9ece14-b513-4cdb-b0b8-9e5fa3b9fef2";
const CHARACTERISTIC_UUID = "f5db5ef9-c1d0-4d1b-8907-d3f2075872c5";



var pDevice = null as BluetoothDevice | null;
var pServer: BluetoothRemoteGATTServer | null = null;
var pService = null as BluetoothRemoteGATTService | null;
var pCharacteristic = null as BluetoothRemoteGATTCharacteristic | null;

var mtu = 20;       // useable MTU -> if actual MTU is 23, useable is 23 - 3 = 20

const connectToDevice = async (setMTU = 0) => {
    if (pDevice === null) {
      console.log("Requesting");
      pDevice = await navigator.bluetooth.requestDevice({filters: [{services: [SERVICE_UUID]}]});
      pService = await pServer?.getPrimaryService(SERVICE_UUID) || null;
      pCharacteristic = await pService?.getCharacteristic(CHARACTERISTIC_UUID) || null;
      // setDevice(await navigator.bluetooth.requestDevice({filters: [{services: [SERVICE_UUID]}]}));
      // setserver(await device.gatt.connect());

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

const getDefaultPacket = () => {
  return [new Packet_t(mtu), new Props_t(1), new Command_t(1)];
}

const changeMTU = async (setMTU: Number) => {

  var [sendPacket , props, command] = getDefaultPacket();
  
  

}

const uploadFile = async(file: File | Blob) => {
  var blob:Blob;
  var filer:File;


    
}

export {
  connectToDevice,
  disconnectToDevice
}
