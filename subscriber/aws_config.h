
/* Change endpoint address, thing name & topic based on your AWS IoT account configurations. Below values are just for reference */
#define AWSIOT_ENDPOINT_ADDRESS             "a38td4ke8seeky-ats.iot.us-east-1.amazonaws.com"
#define AWSIOT_THING_NAME                   "AwsIoT_Subscriber"

/* Make sure Client-ID is unique for each AWS IoT connection */
#define AWSIOT_CLIENT_ID 					"AwsIoT subscriber APP"
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