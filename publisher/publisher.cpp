/*
 * Copyright 2019-2020 Cypress Semiconductor Corporation
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
 * Reference code example for AWS IoT publisher
 */
#include "mbed.h"
#include "aws_client.h"
#include "aws_config.h"

NetworkInterface* network;

#define APP_INFO( x )                        printf x

#define AWSIOT_KEEPALIVE_TIMEOUT            (60)
#define AWSIOT_MESSAGE                      "HELLO"
#define AWS_IOT_SECURE_PORT                 (8883)
#define AWSIOT_TIMEOUT_IN_USEC              (1000UL * 1000UL)

int main( void )
{
    aws_connect_params_t conn_params = { 0, 0, NULL, NULL, NULL, NULL, NULL };
    aws_publish_params_t publish_params = { AWS_QOS_ATMOST_ONCE };
    aws_endpoint_params_t endpoint_params = { AWS_TRANSPORT_MQTT_NATIVE, NULL, 0, NULL, 0 };
    AWSIoTClient *client = NULL;
    SocketAddress address;
    cy_rslt_t result = CY_RSLT_SUCCESS;

    APP_INFO(( "Connecting to the network using Wifi...\r\n" ));
    network = NetworkInterface::get_default_instance();

    nsapi_error_t net_status = -1;
    for ( int tries = 0; tries < 3; tries++ )
    {
        net_status = network->connect();
        if ( net_status == NSAPI_ERROR_OK )
        {
            break;
        }
        else
        {
            APP_INFO(( "Unable to connect to network. Retrying...\r\n" ));
        }
    }

    if ( net_status != NSAPI_ERROR_OK )
    {
        APP_INFO(( "ERROR: Connecting to the network failed (%d)!\r\n", net_status ));
        return -1;
    }

    network->get_ip_address(&address);
    APP_INFO(( "Connected to the network successfully. IP address: %s\n", address.get_ip_address() ));

    if ( ( strlen(SSL_CLIENTKEY_PEM) | strlen(SSL_CLIENTCERT_PEM) | strlen(SSL_CA_PEM) ) < 64 )
    {
        APP_INFO(( "Please configure SSL_CLIENTKEY_PEM, SSL_CLIENTCERT_PEM and SSL_CA_PEM in aws_config.h file\n" ));
        return -1;
    }

    /* Initialize AWS Client library */
    client = new AWSIoTClient( network, AWSIOT_THING_NAME, SSL_CLIENTKEY_PEM, strlen(SSL_CLIENTKEY_PEM), SSL_CLIENTCERT_PEM, strlen(SSL_CLIENTCERT_PEM) );

    /* set MQTT endpoint parameters */
    endpoint_params.transport = AWS_TRANSPORT_MQTT_NATIVE;
    endpoint_params.uri = (char *)AWSIOT_ENDPOINT_ADDRESS;
    endpoint_params.port = AWS_IOT_SECURE_PORT;
    endpoint_params.root_ca = SSL_CA_PEM;
    endpoint_params.root_ca_length = strlen(SSL_CA_PEM);

    /* set MQTT connection parameters */
    conn_params.username = NULL;
    conn_params.password = NULL;
    conn_params.keep_alive = AWSIOT_KEEPALIVE_TIMEOUT;
    conn_params.peer_cn = (uint8_t*)AWSIOT_ENDPOINT_ADDRESS;
    conn_params.client_id = (uint8_t*)AWSIOT_THING_NAME;

    /* connect to an AWS endpoint */
    result = client->connect( conn_params, endpoint_params );
    if ( result != CY_RSLT_SUCCESS )
    {
        APP_INFO(( "connection to AWS endpoint failed\r\n" ));
        if( client != NULL )
        {
            delete client;
            client = NULL;
        }
        return 1;
    }
    APP_INFO(( "Connected to AWS endpoint\r\n" ));

    while ( 1 )
    {
        publish_params.QoS = AWS_QOS_ATMOST_ONCE;
        result = client->publish( AWSIOT_TOPIC, AWSIOT_MESSAGE, strlen((char*)AWSIOT_MESSAGE), publish_params );
        if ( result != CY_RSLT_SUCCESS )
        {
            APP_INFO(( "publish to topic failed\r\n" ));
            if( client != NULL )
            {
                delete client;
                client = NULL;
            }
            return 1;
        }

        APP_INFO(( "Published to topic successfully\r\n" ));

        wait_us( AWSIOT_TIMEOUT_IN_USEC * 5 );
    }
}
