
/* Change endpoint address, thing name & topic based on your AWS IoT account configurations. Below values are just for reference */
#define AWSIOT_ENDPOINT_ADDRESS             "a38td4ke8seeky-ats.iot.us-east-1.amazonaws.com"
#define AWSIOT_THING_NAME                   "AwsIoT_Subscriber"

/* Make sure Client-ID is unique for each AWS IoT connection */
#define AWSIOT_CLIENT_ID 					"AwsIoT subscriber APP"
#define AWSIOT_TOPIC                        "AWS_TOPIC"

/* Change device certificate and device private key based on your account */
const char SSL_CLIENTCERT_PEM[] =  "";

const char SSL_CLIENTKEY_PEM[] = "";

const char SSL_CA_PEM[] = "";