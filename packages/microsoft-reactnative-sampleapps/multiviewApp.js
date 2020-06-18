/**
 * Sample React Native App
 * https://github.com/facebook/react-native
 *
 * @format
 * @flow
 */

import React from 'react';
import {
  SafeAreaView,
  StyleSheet,
  ScrollView,
  View,
  Text,
  StatusBar,
  Button
} from 'react-native';

import {dosomething} from './ErrorFile'
import Main from "./Main";
import View2 from "./View2";

import DeviceInfoComponent from './myDeviceInfo'

import {
  Header,
  LearnMoreLinks,
  Colors,
  DebugInstructions,
  ReloadInstructions,
} from 'react-native/Libraries/NewAppScreen';

class App extends React.Component {
  constructor(props) {
    super(props);

    // this.clickBtn = this.clickBtn.bind(this);
    this.iview=0;
  }
  
  state = {
    renderView: 0,
  };

  myCallback  = (iview) => {
    this.setState({
      renderView: iview
    });
  }


  render() {
    switch (this.state.renderView) {
      case 1:
        return (
          <View>
          <Main callbackFromParent={this.myCallback}  />
          <Text></Text>
          <DeviceInfoComponent />
        </View>
        );
      case 2:
        return (
          <View>
          <Main callbackFromParent={this.myCallback}  />
          <Text></Text>
          <DeviceInfoComponent />
          <Text></Text>
          <View2/>
        </View>
        );
      default:
        return <Main callbackFromParent={this.myCallback}  />;
    }
  }
}

const styles = StyleSheet.create({
  scrollView: {
    backgroundColor: Colors.lighter,
  },
  engine: {
    position: 'absolute',
    right: 0,
  },
  body: {
    backgroundColor: Colors.white,
  },
  sectionContainer: {
    marginTop: 32,
    paddingHorizontal: 24,
  },
  sectionTitle: {
    fontSize: 24,
    fontWeight: '600',
    color: Colors.black,
  },
  sectionDescription: {
    marginTop: 8,
    fontSize: 18,
    fontWeight: '400',
    color: Colors.dark,
  },
  highlight: {
    fontWeight: '700',
  },
  footer: {
    color: Colors.dark,
    fontSize: 12,
    fontWeight: '600',
    padding: 4,
    paddingRight: 12,
    textAlign: 'right',
  },
});



export default App;
