import {NativeEventEmitter, NativeModules } from 'react-native';
import React from 'react';
import {
    SafeAreaView,
    StyleSheet,
    ScrollView,
    View,
    Input,
    Text,
    TextInput,
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

  const ManagePackagesEmitter = new NativeEventEmitter(NativeModules.ManagePackages);

class DeviceInfoComponent extends React.Component {
    constructor(props) {
      super(props);
  
      this.state = {
        packageDisplayName: '',
        result: '',
      }
    }

    componentDidMount() {
      ManagePackagesEmitter.addListener('PackageInstalledEvent', this.packageInstalledEventHandler, this);
    }
  

    componentWillUnmount() {
      ManagePackagesEmitter.removeListener('PackageInstalledEvent', this.packageInstalledEventHandler, this);
    }
  
    packageInstalledEventHandler(result) {
      console.log("Event was fired with: " + result);
      this.setState({result: "Optional Package: " + result +'. Please restart app.'});
    }

        getPackageDisplayName = () => {
        return new Promise((resolve, reject) => {
          var vm = NativeModules.ManagePackages;
            vm.findPackageForUser(this.state.packageDisplayName, function(result, error) {
                if (error) {
                    reject(error);
                }
                else {
                    resolve(result);
                }
            })
        })
    }
    

    _getPackage = async () => {
      var packageDisplayName = await this.getPackageDisplayName();
      this.setState( { result: packageDisplayName});
    }
  
    handlePackageName = (text) => {
        this.setState({ packageDisplayName: text })
     }

    render() {
      return (
        <View style={styles.sectionContainer}>
            {/* <TextInput onChangeText={this.handlePackageName}/>
             <Button title="Get Package Display Name" onPress={this._getPackage} />  */}
             <Text>Package Installing:</Text>
             <Text style={{fontSize:18}}>{this.state.result}</Text> 
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
      margin: 10,
      paddingHorizontal: 24,
      backgroundColor: Colors.lighter
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
  
  
export default DeviceInfoComponent;