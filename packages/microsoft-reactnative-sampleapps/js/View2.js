import React, { Component } from 'react';
import {
  AppRegistry,
  Button,
  requireNativeComponent,
  StyleSheet,
  UIManager,
  View,
  Text
} from 'react-native';

let CustomUserControl = requireNativeComponent('MyUserControl');

class ViewManagerSample extends React.Component {
  onPress() {
    if (_customControlRef) {
      const tag = findNodeHandle(this._customControlRef);
      //UIManager.dispatchViewManagerCommand(tag, UIManager.getViewManagerConfig('BgLabelControl').Commands.CustomCommand, ['arg1', 'arg2']);
    }
  }

  render() {
    return (
      <View>
        {/* <Text>text1</Text> */}
         <CustomUserControl  style={styles.customcontrol} label="Hello from me!"/>
         {/* <CustomUserControl style={styles.customcontrol} label="CustomUserControl!" ref={(ref) => { this._customControlRef = ref; }} /> */}

         {/* <Button onPress={() => { this.onPress(); }} title="Call CustomUserControl Commands!" /> */}
      </View>);
  }
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    justifyContent: 'center',
    alignItems: 'center',
    backgroundColor: '#F5FCFF',
  },
  customcontrol: {
    borderColor:'#000000',
    borderWidth:3,
    color: '#333333',
    backgroundColor: '#FF0000',
    width: 200,
    height: 200,
    margin: 10,
  },
});

// export default ViewManagerSample;
module.exports = {
  ViewManagerSample,
};

//AppRegistry.registerComponent('ViewManagerSample', () => App);

//export default props => (<Fragment><Text>View 2</Text></Fragment>);