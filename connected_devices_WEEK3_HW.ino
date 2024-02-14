#include <WiFiNINA.h>

WiFiUDP udpClient;

const char WIFI_SSID[] = "MyAlti5124";   // WiFi network name
const char WIFI_PASS[] = "31-sage-3597";   // WiFi password

const char server[] = "192.168.1.224";       // IP address of the WebSocket server
const int port = 8000;                         // Port number for TCP communication

const int localPort = 3000;

void setup() {
  pinMode(2, INPUT_PULLUP);
  Serial.begin(9600);
  //retry connection until WiFi is connected successfully
  while (WiFi.status() != WL_CONNECTED) {
    Serial.println("Attempting to connect to SSID: ");
    // Attempt connection to WPA/WPA2 network.
    WiFi.begin(WIFI_SSID, WIFI_PASS);
    delay(500);
  }
  Serial.println("connected!");

  udpClient.begin(localPort);
}

char messageBuffer[256];

void loop() {
  int switchState = digitalRead(2); // Assuming switch is connected to digital pin 2
  
  // Read potentiometer value (0 to 1023)
  int potValue = analogRead(A0); // Assuming potentiometer is connected to analog pin A0
  
  // Send switch state and potentiometer value to WebSocket server
  udpClient.beginPacket(server, port);
  udpClient.print(switchState);
  udpClient.print(",");
  udpClient.println(potValue);
  udpClient.endPacket();

  // Check for incoming packets
  if (udpClient.parsePacket()) {
    char messageBuffer[256];
    int packetSize = udpClient.read(messageBuffer, 255);
    if (packetSize > 0) {
      messageBuffer[packetSize] = '\0';
      Serial.print("UDP received: ");
      Serial.println(atoi(messageBuffer));
      digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
    }
  }
  
  delay(1000); // Adjust delay as needed
  
}

