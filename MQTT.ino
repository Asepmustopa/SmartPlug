// Function to reconnect to the MQTT broker
void reconnect()
{
  while (!client.connected())
  {
    Serial.print("Attempting MQTT connection...");
    // Create a random client ID
    String clientId = R_name;
    //    clientId += String(random(0xffff), HEX);
    // Attempt to connect
    if (client.connect(clientId.c_str()))
    {
      Serial.println("connected");
      client.subscribe(checkDataIN.c_str());
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(1000);
    }
  }
}

// Callback function to handle incoming MQTT messages
void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Pesan diterima pada topik: ");
  Serial.println(topic);

  // Convert payload to string
  String data = "";
  for (int i = 0; i < length; i++) {
    data += (char)payload[i];
  }
  Serial.println("Data received: " + data);
  String output[4];
  parsing(output, data);
  String naaMesin = output[1];
  String suhu = output[2];
  String humidity = output[3];

  // if (naaMesin == namaMesin){
  //   //Activate based on humidity conditions.
  //   Serial.println("Ini Mesin Suhu FO");
  //   if (humidity >= maxHum){
  //     digitalWrite(relay, HIGH);
  //     Serial.println("Heksos Menyala");
  //   }else{
  //     digitalWrite(relay, LOW);
  //     Serial.println("Heksos Mati");
  //   }
     
  }


}