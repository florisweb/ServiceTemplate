#include "connectionManager.h";

const char* ssid = "";
const char* password = "";
const String deviceId = "";
const String deviceKey = "";

connectionManager ConnectionManager;

void onMessage(DynamicJsonDocument message) {
  String error = message["error"];
  String packetType = message["type"];

  Serial.print("[OnMessage] Error: ");
  Serial.println(error);
  Serial.print("[OnMessage] type: ");
  Serial.println(packetType);

void setup() {
  Serial.begin(115200);

  ConnectionManager.setup(ssid, password, deviceId, deviceKey, &onMessage);
}


void sendData() {
  String dataString = "{\"type\": \"sensorState\", \"data\": []}";
  ConnectionManager.send(dataString);
}

void loop() {
  ConnectionManager.loop();
}
