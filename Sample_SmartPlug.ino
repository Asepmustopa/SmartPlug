#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ArduinoJson.h>
#include <TimeLib.h>
#include <WiFiUdp.h>
#include <ESP8266mDNS.h>
#include <Wire.h>
#include <PubSubClient.h>

//============================WIFI======================================
bool ip_static = 0;

const char* ssid     = "WiFiname"; 
const char* password = "WiFiPassword"; 

IPAddress staticIP(192, 168, x, x);  // input your IP Address
IPAddress gateway(192, 168, x, x);    // input your IP Gateway
IPAddress subnet(255, 255, x, x);   // input your Subnet

//============================MQTT==================================
WiFiServer server(80);  //port tcp
WiFiClient espClient;
PubSubClient client(espClient);
char* mqtt_server = "IP Server";
String checkDataIN = "topicMQTT";

//=============================IDENTITAS================================
String idMachine = "YourIdMachine";
String KodeMachine = "yourCode";  
String R_name ="YourDeviceName";
String namaMesin = "YourMachineName";  

//==========================NTP========================================
static const char ntpServerName[] = "yourdomainserverNTP";
IPAddress ntpServerIP(IP SERVER NTP);
const int timeZone = 7; //timeZone Indonesia = 7
WiFiUDP Udp;
unsigned int localPort = 8888;
// Buffer untuk paket NTP
byte ntpPacket[48];
time_t getNtpTime();
void sendNTPpacket(IPAddress &address);

//============================VARIABLE=================================
int buzzer = D1;
int sec;
int relay = D3;
int maxHum = 65;

void setup() {
  pinMode(buzzer,OUTPUT);
  pinMode(relay,OUTPUT);
  checkDataIN += KodeMachine;
  Serial.begin(115200);
  delay(10);

  wifi();
  
 client.setServer(mqtt_server, 1883);
 client.setCallback(callback);
 reconnect();
}

void loop() {

  if (!client.connected()) {
    reconnect(); // Try reconnecting if the connection fails.
  }
  client.loop(); // This function will process the received message.

  if ( year() == 1970 ) // synchronizing to the most accurate time
  {
    ntpBegin();
  }
  
  if ( sec != minute()){
    sec = minute();
    String nowTime = getTime();
    // time(nowTime);    
  }


}
