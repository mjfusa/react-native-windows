/**
 * Sample React Native App
 * https://github.com/facebook/react-native
 *
 * @format
 * @flow
 */

import React, { Fragment } from 'react';
import {
  NativeModules,
  SafeAreaView,
  StyleSheet,
  ScrollView,
  View,
  Text,
  StatusBar,
  Button
} from 'react-native';

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
    this.iview=0;

    this.state = {
      installedModules:[],
      installedCnt: 0,
      modules: [
        {module: "DeviceInfo2.dll", installed: false},
        {module: "SampleLibraryCpp.dll", installed: false}
    ]
    }
  }

  state = {
    renderView: 0,
  };

  myCallback  = (iview) => {
    this.setState({
      renderView: iview
    });
  }

  getIsModuleInstalled = (modulename) => {
    return new Promise((resolve, reject) => {
      var vm = NativeModules.OptionalPackages;
        vm.isPackageInstalled(modulename, function(result, error) {
            if (error) {
                reject(error);
            }
            else {
                resolve(result);
            }
        })
    })
  }

updateModulesList = (installed, modName) => {
  const mod = this.state.modules.find(mod => mod.module === modName);
  if (mod) {
    const installedModule = { ...mod, installed };
      const installedModules = this.state.installedModules
      .concat(installedModule);
    this.setState({ installedModules });
  }
}

getInstalledModule = async (mod) => {
  var result  = await this.getIsModuleInstalled(mod.module);
  console.log(result);
  var cnt = this.state.installedCnt + 1;
  if (result) {
    this.setState({installedCnt: cnt});
  }

  this.updateModulesList(result, mod.module);
}

componentDidMount () {
  this.state.modules.map((mod) => {
    this.getInstalledModule(mod);
  });

}

render() {
  var cnt = this.state.installedCnt;
    switch (cnt) {
      case 1:
        return (
          <View>

          <Text>{"\n"}{"\n"}Install status of optional components:</Text>
          {
            this.state.installedModules.map((y) => {
              return (
              <Text>
              {renderIf(y)}
              </Text>)
            })
          }

          <View><Text>Native Module:</Text></View>
          <DeviceInfoComponent />

        </View>
        );
      case 2:
        return (
          <View>

          <Text>{"\n"}{"\n"}Install status of optional components:</Text>
          {
            this.state.installedModules.map((y) => {
              return (
              <Text>
              {renderIf(y)}
              </Text>)
            })
          }

          <Text>Native Module:</Text>
          <DeviceInfoComponent />
          <Text>Native UI Module:</Text>
          <View2/>

          </View>
        );
      default:
        return (
          <View>
          <Text>{"\n"}{"\n"}Install status of optional components:</Text>
          {
            this.state.installedModules.map((y) => {
              return (
              <Text>
              {renderIf(y)}
              </Text>)
            })
          }
          </View>
        );
    }
  }
}

function renderIf (mod) {
  if (mod.installed) {
    return (<Text>{mod.module} installed</Text>);
  }
  else {
    return (<Text>{mod.module} not installed</Text>);
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
