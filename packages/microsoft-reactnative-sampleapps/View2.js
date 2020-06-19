import React, { Fragment } from "react";
import {
    requireNativeComponent,
    StyleSheet,
    ScrollView,
    View,
    Text,
    StatusBar,
    Button
  } from 'react-native';

const CircleCpp = requireNativeComponent('CircleCpp');
class View2 extends React.Component {

  render() {
    return (
      <View >
       <View style={styles.container}>
      <CircleCpp style={styles.circle}>
          <View style={styles.box}>
            <Text style={styles.boxText}>CircleCpp!</Text>
          </View>
      </CircleCpp>
      </View>
      </View>);
  }
}

const styles = StyleSheet.create({
  container: {
    justifyContent: 'center',
    alignItems: 'center',
    backgroundColor: '#F5FCFF',
  },
  welcome: {
    fontSize: 20,
    textAlign: 'center',
    margin: 10,
  },
  instructions: {
    textAlign: 'center',
    color: '#333333',
    marginBottom: 5,
  },
  customcontrol: {
    color: '#333333',
    backgroundColor: '#006666',
    width: 200,
    height: 20,
    margin: 10,
  },
  circle: {
    margin: 10,
  },
  box: {
    backgroundColor: '#006666',
    width: 100,
    height: 100,
    justifyContent: 'center',
    alignItems: 'center',
  },
  boxText: {
    fontSize: 20,
  },
});


export default View2;