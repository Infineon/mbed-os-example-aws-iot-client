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
 * Cofiguration information related to the user AWS account
 */
#pragma once

/* Change endpoint address, thing name & topic based on your AWS IoT account configurations. Below values are just for reference */
#define AWSIOT_ENDPOINT_ADDRESS             "a38td4ke8seeky-ats.iot.us-east-1.amazonaws.com"

/* Thing name MUST be present and MUST be unique. */
/* A typical device use case involves the use of the thing name as the default MQTT client ID. */
/* Although AWS IoT do not enforce a mapping between a things registry name and its use of MQTT client IDs, certificates, or shadow state, */
/* AWS recommend you choose a thing name and use it as MQTT client ID for both the registry and the Device Shadow service. */
/* As per the above recommendation from AWS, in this application AWSIOT_THING_NAME is used as MQTT ClientID. */
/* NOTE: When a same thing name is used by multiple AWS IoT devices, only the most recently initiated connection will stay alive, */
/* and rest of the connected devices (all the earlier devices) will receive disconnect event from AWS cloud. */
/* Hence, each AWS IoT (physical) device needs to have a unique thing name and corresponding thing name created in AWS Cloud. */
#define AWSIOT_THING_NAME                   "AwsIoT_Publisher"

#define AWSIOT_TOPIC                        "AWS_TOPIC"

/* These are invalid certificates and should only be used to refer the certificate format. Please load valid certificate and private key based on your AWS account */
/* Sample SSL_CLIENTCERT_PEM[]
"-----BEGIN CERTIFICATE-----\n" \
"MIIDWjCCAkKgAwIBAgIVAMK0tnwHtfJTOYHZMEjyS4rDiJ0oMA0GCSqGSIb3DQEB\n" \
"CwUAME0xSzabckjknlljjdlldlldnjdXZWIgU2VydmljZXMgTz1BbWF6b24uY29t\n" \
"IEluYy4gTD1TZWF0dGxlIFNUPVdhc2hpbmd0b24gQz1VUzAeFw0xNTA5MTUwNzIx\n" \
"MjdaFw00OTEyMzEyMzU5NTlaMB4xHDAaBgNVBAMME0FXUyBJb1QgQ2VydGlmaWNh\n" \
"pOkPoqtNoqcHse+w60LBrmy0fV7xkVktuPK0emfa3gTyKVx+qmwqPTghidFkCiiy\n" \
"vjtv6DnWMmRHE2sR/6CuWS9Qnb/xzzfYzjgY+YnaESVs82OejaugOzm/C3ITaviD\n" \
"R7HEGuy8j840r5LLTlJPt84vNm2FKVnms7AX7vK8tSiiUoNSFgx7kQpROavcaQ==\n" \
"-----END CERTIFICATE-----\n";
*/

const char SSL_CLIENTCERT_PEM[] =  "";

/* Sample SSL_CLIENTKEY_PEM[]
"-----BEGIN RSA PRIVATE KEY-----\n" \
"MIIEowIBAAKCAQEAnpQM32dHHdRxf2jQFw6PpOqi9982J1iPSQNNHDC+HpyjiMns\n" \
"T67M5XZvBmkdvJ5CIn8+D33AuSGjp7Hv5L/ilegtLewFCwNlbm57rEkOZjN9djMB\n" \
"YeoDAHgqE+zR0adM3HP7HOGl8eWFCeEsavL0J7wpfm4LVYoirLzEeBxszesfArDM\n" \
"3nNCfHsdfsndflknlnflllazsflnlnlnlsflnlnmasfklYR2xHd/fSbZayMyMGNr\n" \
"mW5B+HuDRmAamoEkbc+kQWEEPrnmC+6ADsfTAQiyvXbcXyYYDbkZA9tMOorzgc1X\n" \
"BSoy7nVZogXelQY1575aAltxvzK5urzUORzwFQIDAQABAoIBAH0eeU2nkkAiB+8s\n" \
"Iw+/Ngm6ACrL2qIYmvAOOamlmkQOcEGTvg9fg9cCgYBi07nU9sjoi5BkuJmto5k9\n" \
"WeNnFVPhaD1WUoB/1KglZFvzrqRO67lTwfYOsB2mhOeR3NsJibhQCMdWGKTUUelp\n" \
"vuCK9lM06TEnl1FG++Zphp7k+pj4dUq/VlNLy1aNvu9Bb4++ypt7nSrztSgXrGlP\n" \
"5Lvh3tjDBKnlgFTbCvhXOwKBgGn0KBm3TEDPSPAV9AtCjbvIoimDgjRXmYl77L41\n" \
"ImrdjU7TtxvPiSKjNGg8h6MXWNHww1O0G4N55Kw0A2m3aKjvcIsAMsP3W7pyYAXS\n" \
"mYtuXrNcRibF5zuKeb0y4czZoH6DlZa1IGt6SOMon/Vpg/l4+UHum8XmpCTPMt+u\n" \
"EmZpAoGBAOMNN2sDrFPWddvKvW+Yg05t4+MUw1clui+WKqmaHaymPgA/ZTFYZ8ig\n" \
"+p3lMfIMne4GddKWF8KZAB5n8kstSnPZCjhyE8NFd4adsbnWkLCebA27084co3Pl\n" \
"2urEffkOp9OwmfV/wyHW6Sim3EX1IQJMoeqPTGWwOmKIkyNFWAO1\n" \
"-----END RSA PRIVATE KEY-----\n";
*/

const char SSL_CLIENTKEY_PEM[] = "";

/* Sample SSL_CA_PEM[]
"-----BEGIN CERTIFICATE-----\n" \
"MIIDQTCCAimgAwIBAgITBmyfz5m/jAo54vB4ikPmljZbyjANBgkqhkiG9w0BAQsF\n" \
"ADA5MQswCQYDVQQGEwJVUzEPMA0GA1UEChMGQW1hem9uMRkwFwYDVQQDExBBbWF6\n" \
"b24gUm9vdCBDQSAxMB4XDTE1MDUyNjAwMDAwMFoXDTM4MDExNzAwMDAwMFowOTEL\n" \
"MAkGA1UEBhMCVVMxDzANBgNVBAoTBkFtYXpvbjEZMBcGA1UEAxMQQW1hem9uIFJv\n" \
"b3QgQ0EgMTCCASIwDQYJKoZIhvcNAQEBBQADggEPADCCAQoCggEBALJ4gHHKeNXj\n" \
"ca9HgFB0fW7Y14h29Jlo91ghYPl0hAEvrAIthtOgQ3pOsqTQNroBvo3bSMgHFzZM\n" \
"9O6II8c+6zf1tRn4SWiw3te5djgdYZ6k/oI2peVKVuRF4fn9tBb6dNqcmzU5L/qw\n" \
"A4IBAQCY8jdaQZChGsV2USggNiMOruYou6r4lK5IpDB/G/wkjUu0yKGX9rbxenDI\n" \
"U5PMCCjjmCXPI6T53iHTfIUJrU6adTrCC2qJeHZERxhlbI1Bjjt/msv0tadQ1wUs\n" \
"N+gDS63pYaACbvXy8MWy7Vu33PqUXHeeE6V/Uq2V8viTO96LXFvKWlJbYK8U90vv\n" \
"o/ufQJVtMVT8QtPHRh8jrdkPSHCa2XV4cdFyQzR1bldZwgJcJmApzyMZFo6IQ6XU\n" \
"5MsI+yMRQ+hDKXJioaldXgjUkK642M4UwtBV8ob2xJNDd2ZhwLnoQdeXeGADbkpy\n" \
"rqXRfboQnoZsG4q5WTP468SQvvG5\n" \
"-----END CERTIFICATE-----\n";
*/

const char SSL_CA_PEM[] = "";
