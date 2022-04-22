/**
 * Sample React Native App
 * https://github.com/facebook/react-native
 *
 * @format
 * @flow strict-local
 */

import React from 'react';
import type {Node} from 'react';
import {
  SafeAreaView,
  ScrollView,
  TouchableOpacity,
  StyleSheet,
  Text,
  useColorScheme,
  View,
  ImageBackground,
} from 'react-native';


const App: () => Node = () => {


  return (
    <View style={styles.Container}>
		<View style={styles.dataContainer}>
			<Text style={styles.tempText}>Temperature</Text>
			<Text style={styles.tempTextC}>30 °C</Text>
		</View>
		<View style={styles.dataContainer}>
			<Text style={styles.tempText}>Humidity</Text>
			<Text style={styles.tempTextC}>70%</Text>
		</View>
		<View style={{flexDirection:'row', flexWrap:'wrap', }}>
			<TouchableOpacity style={styles.button}>
				<Text>RGB red</Text>
			</TouchableOpacity>
			<TouchableOpacity style={styles.button}>
				<Text>RGB blue</Text>
			</TouchableOpacity>
			<TouchableOpacity style={styles.button}>
				<Text>RGB green</Text>
			</TouchableOpacity>
			<TouchableOpacity style={styles.button}>
				<Text>LED 1</Text>
			</TouchableOpacity>
			<TouchableOpacity style={styles.button}>
				<Text>LED 2</Text>
			</TouchableOpacity>
			<TouchableOpacity style={styles.button}>
				<Text>Party Mode</Text>
			</TouchableOpacity>
        </View>
    </View>
  );
};

const styles = StyleSheet.create({
Container: {
    margin: 25,
  },
  dataContainer: {
	  
	height: 150,
    width: "100%",
	backgroundColor: "white",
	borderRadius: 20,
	elevation: 3,
	shadowColor: '#52006A',
	padding: 15,
	marginVertical: 10
  },
  tempText: {
	 fontSize: 30,
  },
  tempTextC: {
	  fontSize: 35,
	  fontWeight: "bold"
  },
  button: {
	width: "43%",
	height: 90,
	backgroundColor: "white",
	marginHorizontal: 10,
	borderRadius: 10,
	elevation: 2,
	padding: 10,
	marginVertical: 10
  }


});

export default App;
