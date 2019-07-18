# Introduction
This repository contains the code examples and demos for PSOC6 MCU family of devices bundled with connectivity.

# Instructions to build AWS IoT and GreenGrass publisher/subscriber code examples

1. clone the desired code examples repository
 
2. Change to the application folder (for instance publisher)

3. prepare the cloned working directory for mbed
        
        mbed config root .

4. pull the necessary libraries and its dependencies.
This will pull mbed-os, AWS_Iot_Client library and its internal 3rd party dependencies

        mbed deploy

5. Configure the AWS parameters such as Thing name, certificates, private key etc. per the user's AWS account
	- Refer to 'Getting Started with AWS IoT' on the AWS documentation
	    - https://docs.aws.amazon.com/iot/latest/developerguide/iot-gs.html
	- Using the above reference, fill out the aws_config.h parameters

6. build the publisher app (.hex binary)

        mbed compile -t GCC_ARM -m CY8CPROTO_062_4343W  

The instructions for the other AWS code examples are similar.
