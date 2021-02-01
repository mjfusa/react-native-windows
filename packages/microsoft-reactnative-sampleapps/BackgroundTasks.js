import React from 'react';
import {
    NativeModules,
    View,
    Text,
    AppRegistry,
  } from 'react-native';


// Get model name from native module function deviceModel
  getDeviceModel = () => {
    return new Promise((resolve, reject) => {
      var vm = NativeModules.NativeModuleClass;
        vm.deviceModel(function(result, error) {
            if (error) {
                reject(error);
            }
            else {
                resolve(result);
            }
        })
    })
  }

// Get model name from native module function deviceModel for console output
getModel = async () => {
    let model = await this.getDeviceModel();
    return model;
}
  
// Headless JS runs here. Calling into Native Module and running JS.
export const runTask = async () => {
    // Call native function
    console.warn("Native background result: " + await getModel());
    // Run JS code
    console.warn('JS BackgoundRefreshData was called.');
    return Promise.resolve();
};

// Register Native and Headless JS
const  RegisterTask = () => {
    taskName="BackgoundRefreshData";
    
    // Register the Windows Native BackgroundTask
    // See NativeModuleClass.cpp for native background task registration
    NativeModules.NativeModuleClass.registerNativeJsTaskHook(taskName);

    // Register the JS BackgroundTask
    AppRegistry.registerHeadlessTask(taskName, () => runTask);
    console.log('Background task ' + taskName + ' registered.');
}


class DeviceInfoComponent extends React.Component {
  render() {
    return (
    <View>
        <Text>See console for background output</Text>
    </View>
    );
  }
}

export {RegisterTask, DeviceInfoComponent};