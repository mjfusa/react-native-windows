import { NativeModules } from 'react-native';
import React, { Fragment } from 'react';
import {
    SafeAreaView,
    StyleSheet,
    ScrollView,
    View,
    Text,
    StatusBar,
    Button
  } from 'react-native';

  import {
    Header,
    LearnMoreLinks,
    Colors,
    DebugInstructions,
    ReloadInstructions,
  } from 'react-native/Libraries/NewAppScreen';
  
class PackagesInventory extends React.Component {
    constructor(props) {
      super(props);
    this.state = {
      modules: [
        {module: "DeviceInfo2.dll", installed: false},
        {module: "SampleLibraryCpp.dll", installed: false}
    ]
    }
  }
    
    getDeviceModel = (modulename) => {
        return new Promise((resolve, reject) => {
          var vm = NativeModules.ManagePackages;
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
    
    render() {
      return (
        <View style={styles.sectionContainer}>
          {this.state.modules.map((item, key) =>
          <Item item={item} key={key}/>
          )}  
        </View> 
      );
    }
  }
  
  getDeviceModel = (modulename) => {
    return new Promise((resolve, reject) => {
      var vm = NativeModules.ManagePackages;
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


getModel = async (modulename) => {
  var model = await this.getDeviceModel(modulename);
  this.setState( { model: model});
}

function renderIf(modulename)  {
  this.getDeviceModel(modulename).then(result => {
  if (result) {
      return <Text>Installed</Text>;
  } else {
      return <Text>Not installed</Text>;
  }
});

}

class Item extends React.Component {
  render() {
      return (
          <View>
            <Text>
              {this.props.item.module} {renderIf((this.props.item.module))}
              </Text>
          </View>
      );
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
  
  
  
  export default PackagesInventory;