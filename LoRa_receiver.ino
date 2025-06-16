#include <ESP8266.h>
#include <LoRa.h>

void setup() {
  Serial.begin(9600);
  while (!Serial);

  if (!LoRa.begin(433E6)) {
    Serial.println("Starting LoRa failed!");
    while (1);
  }
  Serial.println("LoRa Receiver Started...");
}

void loop() {
  int packetSize = LoRa.parsePacket();
  if (packetSize) {
    Serial.print("Received packet: ");
    while (LoRa.available()) {
      Serial.print((char)LoRa.read());
    }
    Serial.println();
  }
}
