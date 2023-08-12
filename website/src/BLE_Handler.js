
var BLE_notification = null;
var resolution;
var failure;

async function getPromise() {
    return (
        new Promise((resolve, reject) => {
            resolution = resolve;
            failure = reject;
            
        })
    );
}

function triggerNotification() {
    resolution();

    BLE_notification = new Promise((resolve, reject) => {
        resolution = resolve;
        failure = reject;
    });
}

async function waitForNotification() {
    // console.assert(false);
    await BLE_notification;
    
    return;
}

BLE_notification = getPromise();

export default triggerNotification;

export {
    triggerNotification,
    waitForNotification,
    getPromise
};