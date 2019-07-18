/*
 * Copyright 2019 Cypress Semiconductor Corporation
 * SPDX-License-Identifier: Apache-2.0
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 *     http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/** @file
 *
 * Reference code example for AWS IoT subscriber
 */
#include "mbed.h"
#include "aws_client.h"
#include "aws_config.h"

NetworkInterface* network;
AWSIoTEndpoint* ep = NULL;
AWSIoTClient client;

#define APP_INFO( x )                       printf x

#define AWSIOT_KEEPALIVE_TIMEOUT            (60)
#define AWSIOT_MESSAGE                      "HELLO"
#define AWS_IOT_SECURE_PORT                 (8883)
#define AWSIOT_TIMEOUT                      (1000)

void messageArrived(aws_iot_message_t& md)
{
    aws_message_t &message = md.message;
    APP_INFO(("\r\nMessage arrived: qos %d, retained %d, dup %d, packetid %d\r\n", message.qos, message.retained, message.dup, message.id));
    APP_INFO(("\r\nPayload %.*s\r\n", message.payloadlen, (char*)message.payload));
}

int main(void)
{
    aws_connect_params conn_params = { 0,0,NULL,NULL,NULL,NULL,NULL };
    cy_rslt_t result = CY_RSLT_SUCCESS;

    APP_INFO(("Connecting to the network using Wifi...\r\n"));
    network = NetworkInterface::get_default_instance();

    nsapi_error_t net_status = -1;
    for (int tries = 0; tries < 3; tries++)
    {
        net_status = network->connect();
        if (net_status == NSAPI_ERROR_OK)
        {
            break;
        }
        else
        {
            APP_INFO(("Unable to connect to network. Retrying...\r\n"));
        }
    }

    if (net_status != NSAPI_ERROR_OK)
    {
        APP_INFO(("ERROR: Connecting to the network failed (%d)!\r\n", net_status));
        return -1;
    }

    APP_INFO(("Connected to the network successfully. IP address: %s\n", network->get_ip_address()));

    if ( ( strlen(SSL_CLIENTKEY_PEM) | strlen(SSL_CLIENTCERT_PEM) | strlen(SSL_CA_PEM) ) < 64 )
    {
        APP_INFO(("Please configure SSL_CLIENTKEY_PEM, SSL_CLIENTCERT_PEM and SSL_CA_PEM in aws_config.h file \n"));
        return -1;
    }

    /* Initialize AWS Client library */
    AWSIoTClient client(network, AWSIOT_THING_NAME , SSL_CLIENTKEY_PEM, strlen(SSL_CLIENTKEY_PEM), SSL_CLIENTCERT_PEM, strlen(SSL_CLIENTCERT_PEM));

    ep = client.create_endpoint(AWS_TRANSPORT_MQTT_NATIVE, AWSIOT_ENDPOINT_ADDRESS, AWS_IOT_SECURE_PORT, SSL_CA_PEM, strlen(SSL_CA_PEM));

    client.set_command_timeout( 5000 );

    /* set MQTT connection parameters */
    conn_params.username = NULL;
    conn_params.password = NULL;
    conn_params.keep_alive = AWSIOT_KEEPALIVE_TIMEOUT;
    conn_params.peer_cn = (uint8_t*) AWSIOT_ENDPOINT_ADDRESS;
    conn_params.client_id = (uint8_t*)AWSIOT_CLIENT_ID;

    /* connect to an AWS endpoint */
    result = client.connect (ep, conn_params);
    if ( result != CY_RSLT_SUCCESS )
    {
        APP_INFO(("connection to AWS endpoint failed \r\n"));
        return 1;
    }
    APP_INFO(("Connected to AWS endpoint \r\n"));

    result = client.subscribe (ep, AWSIOT_TOPIC, AWS_QOS_ATMOST_ONCE, messageArrived);
    if ( result != CY_RSLT_SUCCESS )
    {
        printf ("Subscription to MQTT topic failed \n");
        return 1;
    }

    printf ("Subscribed to topic successfully \n");

    while(1)
    {
        result = client.yield(AWSIOT_TIMEOUT);
        if (result != CY_RSLT_SUCCESS) {
            return 1;
        }
    }


}
