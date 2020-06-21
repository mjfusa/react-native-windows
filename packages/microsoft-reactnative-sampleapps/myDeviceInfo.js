import { NativeModules } from 'react-native';
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

  import {
    Header,
    LearnMoreLinks,
    Colors,
    DebugInstructions,
    ReloadInstructions,
  } from 'react-native/Libraries/NewAppScreen';
  
class DeviceInfoComponent extends React.Component {
    constructor(props) {
      super(props);
  
      this.state = {
        model: '',
      }
    }
  
    getDeviceModel = () => {
        return new Promise((resolve, reject) => {
          var vm = NativeModules.SampleComponent;
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
    

    getModel = async () => {
      var model = await this.getDeviceModel();
      this.setState( { model: model});
    }
  
    render() {
      return (
        <View style={styles.sectionContainer}>
             <Button title="Get model" onPress={this.getModel} /> 
             <Text>{this.state.model}</Text>
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