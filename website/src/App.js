import logo from './logo.svg';
import './App.css';
import { useState ,useEffect } from 'react';
import './BLE_Handler';
import { triggerNotification, waitForNotification } from './BLE_Handler';

const SERVICE_UUID = "9f9ece14-b513-4cdb-b0b8-9e5fa3b9fef2";

const CHARACTERISTIC_UUID = "f5db5ef9-c1d0-4d1b-8907-d3f2075872c5";

const BRANCHES = {
  main: "main",
  dev: "firmware/dev"
};

const CONST_BINARY_PATH = 'https://github.com/cmasterx/MiOrigin/blob/{0}/firmware/binaries/firmware.bin?raw=true';

window.waitForNotification = waitForNotification;
window.getPromise = waitForNotification;

function App() {

  console.log("Start app");  
  
  const [device, setDevice] = useState(null);
  const [server, setServer] = useState(null);
  const [service, setService] = useState(null);
  const [characteristic, setCharacteristic] = useState(null);

  const [number, setnumber] = useState(0)
  
  const connectToDevice = async () => {
    if (device === null) {
      console.log("Requesting");
      let pDevice = await navigator.bluetooth.requestDevice({filters: [{services: [SERVICE_UUID]}]});
      let pServer = await pDevice.gatt.connect();
      let pService = await pServer.getPrimaryService(SERVICE_UUID);
      let pCharacteristic = await pService.getCharacteristic(CHARACTERISTIC_UUID);
      // setDevice(await navigator.bluetooth.requestDevice({filters: [{services: [SERVICE_UUID]}]}));
      // setserver(await device.gatt.connect());

      setDevice(pDevice);
      setServer(pServer);
      setService(pService);
      setCharacteristic(pCharacteristic);

      console.log("Here I am");
    }
    else {
      console.log("Device is initialized. Nothing to do.");
    }
    
    window.device = device;
    window.server = server;
    window.service = service;
    window.characteristic = characteristic;
    console.log('Howdy!')
  };

  const disconnectToDevice = async() => {
    if (device !== null) {
      server.disconnect();
      setDevice(null);
      setServer(null);
      setService(null);
      setCharacteristic(null);
    }
  };
  
  const sendMTURequest = () => {
    if (device !== null) {
      let buffer = new Uint8Array(6);
      let props = new Uint16Array(1);
      buffer[2] = 0x0D;
      buffer[3] = 0x01;

      window.response = characteristic.writeValueWithResponse(buffer);
    }
  };

  const startCounter = async () => {
    var n = number;
    
    while (true) {
      console.log(n);
      n += 1;
      await waitForNotification();
      setnumber(n);
      console.log("Print!");
    }
  }
  
  useEffect(() => {
    // effect
    window.device = device;

    window.bleNotify = null;

    startCounter();
    
    return () => {
      delete window.device;
      // cleanup
    }
  }, [])
  
  const showFile = async (input) => {
    console.log ("I am here!");
    const reader = new FileReader();

    const filePromise = new Promise((resolve, reject) => {
      reader.onload = (event) => {
        resolve(event.target.result);
      };

      reader.onerror = (err) => {
        reject(err);
      };
    });
    //https://stackoverflow.com/questions/56338154/howto-convert-file-to-byte-stream-in-javascript
    // reader.readAsDataURL(input.target.files[0]);
    reader.readAsArrayBuffer(input.target.files[0]);
    window.fileResult = await filePromise;
    // let file = input.files[0];
  
    // alert(`File name: ${file.name}`); // e.g my.png
    // alert(`Last modified: ${file.lastModified}`); // e.g 1552830408824
  }
  
  return (
    <div className="App">
      <p>{number}</p>
      <button onClick={ connectToDevice } >Connect</button>
      <button onClick={ disconnectToDevice }>Disconnect</button>
      <button onClick= { sendMTURequest }>Send MTU Request</button>
      <button onClick= { triggerNotification }>Trigger</button>
      <input type="file" onChange={ showFile }></input>
      {/* <input type="file" /> */}
      {/* <input
          type="file"
          // value={selectedFile}
          onChange={(e) => console.log(e)}
        /> */}
    </div>
  );
}

export default App;
