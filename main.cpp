
#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <cctype>
#include <thread>
#include <chrono>
#include "mqtt_Sub.h"

const std::string SERVER_ADDRESS("test.mosquitto.org");
const std::string CLIENT_ID("paho_cpp_async_subcribe");


/////////////////////////////////////////////////////////////////////////////

int main(int argc, char* argv[])
{
	mqtt::async_client cli(SERVER_ADDRESS, CLIENT_ID);

	mqtt::connect_options Connect_Optns;
	Connect_Optns.set_clean_session(false);

	// Install the callback before connecting.
	callback cb(cli, Connect_Optns);
	cli.set_callback(cb);

	// Initiate the connection. After completion of connection, The Callback function will subscribe to the specified topic
	try {
		std::cout << "Connecting to the MQTT server..." << std::flush;
		cli.connect(Connect_Optns, nullptr, cb);
	}
	catch (const mqtt::exception& exc) {
		std::cerr << "\nERROR: Unable to connect to MQTT server: '"
			<< SERVER_ADDRESS << "'" << exc << std::endl;
		return 1;
	}

	// blocks from disconnecting till user tells us to quit.
	while (std::tolower(std::cin.get()) != 'q')
		;

	// Disconnect
	try {
		std::cout << "\nDisconnecting from the MQTT server..." << std::flush;
		cli.disconnect()->wait();
		std::cout << "OK" << std::endl;
	}
	catch (const mqtt::exception& exc) {
		std::cerr << exc << std::endl;
		return 1;
	}

 	return 0;
}

