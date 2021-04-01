
//
// This code is written refering to Paho MQTT C++ client, sample application.

// ADD REFERENCE*********
/*******************************************************************************
 * Copyright (c) 2013-2020 Frank Pagliughi <fpagliughi@mindspring.com>
 *
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * and Eclipse Distribution License v1.0 which accompany this distribution.
 *
 * The Eclipse Public License is available at
 *    http://www.eclipse.org/legal/epl-v10.html
 * and the Eclipse Distribution License is available at
 *   http://www.eclipse.org/org/documents/edl-v10.php.
 *
 * Contributors:
 *    Frank Pagliughi - initial implementation and documentation
 *******************************************************************************/

#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <cctype>
#include <thread>
#include <chrono>
#include "mqtt/async_client.h"

const std::string TOPIC("Face_Detection");

const int	QOS = 1;
const int	NoOfRetryAttempts = 3;
 char *path = NULL;
 void* user_data;
 unsigned int *identifier;


class action_listener : public virtual mqtt::iaction_listener
{
	std::string name_;

	void on_failure(const mqtt::token& tok) override {
		std::cout << name_ << " failure";
		if (tok.get_message_id() != 0)
			std::cout << " for token: [" << tok.get_message_id() << "]" << std::endl;
		std::cout << std::endl;
	}

	void on_success(const mqtt::token& tok) override {
		std::cout << name_ << " success";
		if (tok.get_message_id() != 0)
			std::cout << " for token: [" << tok.get_message_id() << "]" << std::endl;
		auto top = tok.get_topics();
		if (top && !top->empty())
			std::cout << "\ttoken topic: '" << (*top)[0] << "', ..." << std::endl;
		std::cout << std::endl;
	}

public:
	action_listener(const std::string& name) : name_(name) {}
};

/**
 * Local callback & listener class for use with the client connection.
 * This is primarily intended to receive messages, but it will also monitor
 * the connection to the broker. If the connection is lost, it will attempt
 * to restore the connection and re-subscribe to the topic.
 */
class callback : public virtual mqtt::callback,
					public virtual mqtt::iaction_listener

{
	// Counter for the number of connection retries
	int NoOfRetries;
	// The MQTT Number Of Retry Attempts
	mqtt::async_client& client;
	// Options to use if we need to reconnect
	mqtt::connect_options& ConnectOptions;
	// An action listener to display the result of actions.
	action_listener subListener_;

	// connection success
	void connected(const std::string& cause) override {
		std::cout << "\nConnection success" << std::endl;
		std::cout << "\nSubscribing to topic '" << TOPIC << "'\n"
			<< " using QoS" << QOS << "\n"
			<< "\nPress Q<Enter> to quit\n" << std::endl;

		client.subscribe(TOPIC, QOS, nullptr, subListener_);
	}

	// When the connection gets lost, This will initiate the attempt to manually reconnect.
	void connection_lost(const std::string& cause) override {
		std::cout << "\nConnection lost" << std::endl;
		if (!cause.empty())
			std::cout << "\tcause: " << cause << std::endl;

		std::cout << "Reconnecting..." << std::endl;
		NoOfRetries = 0;
		reconnect();
	}

	// Iff connection is lost, this manually tries to reconnect to the broker by calling connect() function again
	void reconnect() {
		std::this_thread::sleep_for(std::chrono::milliseconds(2500));
		try {
			client.connect(ConnectOptions, nullptr, *this);
		}
		catch (const mqtt::exception& exc) {
			std::cerr << "Error: " << exc.what() << std::endl;
			exit(1);
		}
	}

	// Checks if Maximum reconnect attempts have reached or not
	void on_failure(const mqtt::token& tok) override {
		std::cout << "Connection attempt failed" << std::endl;
		if (++NoOfRetries > NoOfRetryAttempts)
			exit(1);
		reconnect();
	}
	void on_success(const mqtt::token& tok) override {}
	// Callback for when a message arrives.
	void message_arrived(mqtt::const_message_ptr msg) override {
		//system("echo 'Please throw your garbage in the appropriate bin  ' | festival --tts");
		system("espeak-ng 'Please throw your garbage in the appropriate bin'");
		//Email code
		///level of dutbin
		std::cout << "Message arrived" << std::endl;
	}

	void delivery_complete(mqtt::delivery_token_ptr token) override {}

public:
	callback(mqtt::async_client& cli, mqtt::connect_options& connOpts)
				: NoOfRetries(0), client(cli), ConnectOptions(connOpts), subListener_("Subscription") {}
};
