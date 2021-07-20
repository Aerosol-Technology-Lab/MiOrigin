import { triggerNotification, waitForNotification } from './BLE_Handler';

var pDevice = null as BluetoothDevice;
var pServer = null as BluetoothRemoteGATTServer;
var pService = null as BluetoothRemoteGATTService;
var pCharacteristic = null as BluetoothRemoteGATTCharacteristic;

var mtu = 20;       // useable MTU -> if actual MTU is 23, useable is 23 - 3 = 20

const connectToDevice = async (setMTU = 0) => {
    if (pDevice === null) {
      console.log("Requesting");
      pDevice = await navigator.bluetooth.requestDevice({filters: [{services: [SERVICE_UUID]}]});
      pServer = await pDevice.gatt.connect();
      pService = await pServer.getPrimaryService(SERVICE_UUID);
      pCharacteristic = await pService.getCharacteristic(CHARACTERISTIC_UUID);
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
      pServer.disconnect();
      pServer = null;
      pService = null;
      pCharacteristic = null;
    }
};

const changeMTU = async (setMTU: Number) => {

}

const uploadFile = async(file: File | Blob) => {
  var blob:Blob;
  var filer:File;


    
}


