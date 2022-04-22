#include <dht.h>
#include <Arduino.h>
#include <ESP8266WiFi.h>

#include <SocketIoClient.h>

SocketIoClient webSocket;
dht DHT;

#define DHT11_PIN 2

int RED = 5;
int GREEN = 4;
int BLUE = 0;
int LED1 = 12;
int LED2 = 14;
int buzzer = 13;
int rain = 15;
char raining[16];
void setup(){
  pinMode(rain, INPUT);
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);                        
  pinMode(BLUE, OUTPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
  
  sprintf(raining, "%d", "it's raining");
  WiFi.begin("Jumbo", "pusangputi");
  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED)
  {
  delay(500);
  Serial.print(".");
  }
  Serial.println();

  Serial.print("Connected, IP address: ");
  Serial.println(WiFi.localIP());
  webSocket.begin("192.168.1.98", 80, "/socket.io/?transport=websocket");
}

void loop(){
  webSocket.loop();
  Serial.println(digitalRead(rain));
  if(digitalRead(rain) == 0)
  {
    webSocket.emit("rain", raining);
  }
  get_temp();
  rgb_red();
  digitalWrite(LED1,LOW);
  digitalWrite(LED2,LOW);
  digitalWrite(buzzer,LOW);
  delay(1000);
  Serial.println(digitalRead(rain));
  rgb_green();
  digitalWrite(LED1,HIGH);
  digitalWrite(LED2,LOW);
  delay(1000);
  Serial.println(digitalRead(rain));
  rgb_blue();
  digitalWrite(LED1,LOW);
  digitalWrite(LED2,HIGH);
  digitalWrite(buzzer,HIGH);
  delay(1000);
}

void rgb_red(){
  digitalWrite(RED,HIGH);
  digitalWrite(GREEN,LOW);
  digitalWrite(BLUE,LOW);
}

void rgb_green(){
  digitalWrite(RED,LOW);
  digitalWrite(GREEN,HIGH);
  digitalWrite(BLUE,LOW);
}

void rgb_blue(){
  digitalWrite(RED,LOW);
  digitalWrite(GREEN,LOW);
  digitalWrite(BLUE,HIGH);
}

void get_temp(){
  char temp[16];
  sprintf(temp, "%d", DHT.temperature);
  char humid[16];
  sprintf(humid, "%d", DHT.humidity);
  int chk = DHT.read11(DHT11_PIN);
  Serial.print("Temperature = ");
  Serial.println(DHT.temperature);
//  webSocket.emit("Temperature", temp);
  Serial.print("Humidity = ");
//  webSocket.emit("Humidity", humid);
  Serial.println(DHT.humidity);
}
