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
  Button,
  YellowBox
} from 'react-native';

// Package Manager
import FindPackageForUser from './FindPackageForUser'

// Optional Components
import NativeUIControl from "./NativeUIControl";
import DeviceInfoComponent from './DeviceInfoComponent'

import {
  Header,
  Colors,
} from 'react-native/Libraries/NewAppScreen';

class App extends React.Component {
  constructor(props) {
    super(props);
    this.state = {
      installedModules:[],
      installedCnt: 0,
      modules: [
        {module: "DeviceInfo2.dll", installed: false, component: <DeviceInfoComponent/>},
        {module: "SampleLibraryCpp.dll", installed: false, component: <NativeUIControl/>}
    ]
    }
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
        return (
          <View>
          <FindPackageForUser/>
          <Text>{"\n"}{"\n"}Install status of optional components:</Text>
          {
            this.state.installedModules.map((y) => {
              return (
                <View key={y.module}>
                {renderIf(y)}
                </View>
              )
            })
          }
          
          </View>
        );
}
}

function renderIf (mod) {
  switch (mod.installed) {
    case true:
      return (<View>
        <Text>{mod.module} installed</Text>
        {mod.component}
        </View>)
    default:
      return (<Text>{mod.module} not installed</Text>)
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
