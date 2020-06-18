
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


// export default props => (
//   <View>
//     <Button   title="Main view" onPress={props.onPress(0)} type="button"/>
//     <Button   title="View 1" onPress={props.onPress(1)}>
//     </Button>
//     <Button  title="View 2" onPress={props.onPress(2)}>
//     </Button>
//     </View>
// );


export default class Main extends React.Component {
    constructor(props) {
        super(props);
        this.state =
        {
            didMount: false
        }
      }

selectView = (iview) => {
if (this.state.didMount) {
    this.props.callbackFromParent(iview);
}
};    

componentDidMount() {
    this.setState({didMount: true});
}

render() {
   return ( <Fragment>
    <Button   title="Main view" onPress={()=>this.selectView(0)}/>
    <Button   title="View 1" onPress={()=>this.selectView(1)}>
    </Button>
    <Button  title="View 2" onPress={()=>this.selectView(2)}>
    </Button>
    </Fragment>

   )};

}
