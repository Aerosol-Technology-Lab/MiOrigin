import logo from './logo.svg';
import './App.css';
import { useState ,useEffect, useRef } from 'react';
import './BLE_Handler';
import { triggerNotification, waitForNotification } from './BLE_Handler';
import { connectToDevice, disconnectToDevice, uploadFile, ping } from './Device_BLE';


const BRANCHES = {
  main: "main",
  dev: "firmware/dev"
};

const CONST_BINARY_PATH = 'https://github.com/cmasterx/MiOrigin/blob/{0}/firmware/binaries/firmware.bin?raw=true';

declare global {
  interface Window {
    response: any;
    device: any;
    server: any;
    service: any;
    characteristic: any;
    waitForNotification: any;
    getPromise: any;
    bleNotify: any;
    fileResult: any;
    test: any;
    globalFile: any;
  }
}

window.waitForNotification = waitForNotification;
window.getPromise = waitForNotification;

function App() {

  console.log("Start app");  
  
  const [device, setDevice] = useState(null);
  const [server, setServer] = useState(null);
  const [service, setService] = useState(null);
  const [characteristic, setCharacteristic] = useState(null);

  const [number, setnumber] = useState(0)
  
  const selectedFile = useRef(null);
  
    
    window.device = device;
    window.server = server;
    window.service = service;
    window.characteristic = characteristic;
    console.log('Howdy!')


  
  // const sendMTURequest = () => {
  //   if (device !== null) {
  //     let buffer = new Uint8Array(6);
  //     let props = new Uint16Array(1);
  //     buffer[2] = 0x0D;
  //     buffer[3] = 0x01;


  //     window.response = characteristic.writeValueWithResponse(buffer);
  //   }
  // };

  const startCounter = async () => {
    var n = number;
    
    while (false) {
      console.log(n);
      n += 1;
      await waitForNotification();
      // setnumber(n);
      console.log("Print!");
    }
  }
    
  const uploadButtonHandler = async () => {

    if (selectedFile.current !== null) {
      uploadFile(selectedFile.current!);
    }    
  };

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
  
  const showFile = async (input: any) => {
    window.test = input;
    selectedFile.current = input.target.files[0];
    // console.log ("I am here!");
    // const reader = new FileReader();

    // const filePromise = new Promise((resolve, reject) => {
    //   reader.onload = (event) => {
    //     resolve(event.target.result);
    //   };

    //   reader.onerror = (err) => {
    //     reject(err);
    //   };
    // });
    //https://stackoverflow.com/questions/56338154/howto-convert-file-to-byte-stream-in-javascript
    // reader.readAsDataURL(input.target.files[0]);
    // reader.readAsArrayBuffer(input.target.files[0]);
    // window.fileResult = await filePromise;
    // let file = input.files[0];
  
    // alert(`File name: ${file.name}`); // e.g my.png
    // alert(`Last modified: ${file.lastModified}`); // e.g 1552830408824
  }

  
  return (
    <div className="App">
      <p>{number}</p>
      <button onClick={ () => connectToDevice() } >Connect</button>
      <button onClick={ disconnectToDevice }>Disconnect</button>
      {/* <button onClick= { sendMTURequest }>Send MTU Request</button> */}
      <button onClick={ uploadButtonHandler }>Upload File</button>
      <button onClick= { triggerNotification }>Trigger</button>
      <button onClick={ ping }>Ping</button>
      <input type="file" onChange={ showFile }></input>
      {/* <input type="file" /> */}
      {/* <input
          type="file"
          // value={selectedFile}
          onChange={(e) => console.log(e)}
        /> */}
      <label>
        Name:
        <input type="text" name="name"/>
      </label>
    </div>
  );
}

export default App;
