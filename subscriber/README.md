# Introduction

This repository contains the code examples and demos for PSOC6 MCU family of devices bundled with connectivity.

The subscriber is part of the mbed-os-example-aws-iot-client example application.

This application connects to a Wi-Fi network as a STA(client), establishes a secure TCP connection over MQTT to the AWS endpoint, subscribes to a topic and waits in a loop to receive messages that are published on the topic.
 
# Supported platforms

This application and it's features are supported on following Cypress platforms:
* [PSoC6 WiFi-BT Prototyping Kit (CY8CPROTO-062-4343W)](https://www.cypress.com/documentation/development-kitsboards/psoc-6-wi-fi-bt-prototyping-kit-cy8cproto-062-4343w)
* [PSoC6 WiFi-BT Pioneer Kit (CY8CKIT-062-WiFi-BT)](https://www.cypress.com/documentation/development-kitsboards/psoc-6-wifi-bt-pioneer-kit-cy8ckit-062-wifi-bt)
* CY8CKIT-062S2-43012

# Dependent libraries

This section provides the list of dependency libraries required for this application to work.
* [ARM mbed-os stack version 5.13.1 and above](https://os.mbed.com/mbed-os/releases)
* [Cypress AWS IoT middleware library](https://github.com/cypresssemiconductorco/aws-iot)
* [Cypress Connectivity Utilities Library](https://github.com/cypresssemiconductorco/connectivity-utilities)

# Instructions to build AWS IoT subscriber code example

1. Clone the desired code examples repository 
 
2. Change to the application folder (subscriber)

3. Prepare the cloned working directory for mbed
        
        mbed config root .

4. Pull the necessary libraries and its dependencies.
This will pull mbed-os, AWS_Iot_Client library and its internal 3rd party dependencies

        mbed deploy

5. Configure the SSID and passphrase of the desired network in the accopmpanying mbed_app.json

6. Configure the AWS parameters such as Thing name, certificates, private key etc. per the user's AWS account
	- Refer to 'Getting Started with AWS IoT' on the AWS documentation
	    - https://docs.aws.amazon.com/iot/latest/developerguide/iot-gs.html
	- Using the above reference, fill out the aws_config.h parameters
    - The aws_config.h includes sample certificates, private keys to illustrate the expected format of these credentials

7. Build the subscriber app (.hex binary)

        mbed compile -t GCC_ARM -m CY8CPROTO_062_4343W  

8. Connect to the kit via serial port. You should observe console logs that indicate connection to network, AWS endpoint, subscription to the topic and waiting for messages

9. Using the AWS console, publish messages to the subscribed topic. You would observe messages are being received by the subscriber and printed on the kit's console

