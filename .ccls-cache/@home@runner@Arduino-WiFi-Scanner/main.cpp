/*
   Copyright (c) 2023, Andreas <DOC> Eisner
   All rights reserved.
   Based on a sketch of 2015, Majenko Technologies
*/   

/* Create a WiFi access point and provide a web server on it. */

#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

#ifndef APSSID
#define APSSID "ESPap"
#define APPSK "thereisnospoon"
#endif

/* Set these to your desired credentials. */
const char *ssid = "arduino";
const char *password = "pwd";

ESP8266WebServer server(80);


/* Just a little test message.  Go to http://192.168.4.1 in a web browser
   connected to this access point to see it.
*/
// handle route: "/"
void handleRoot() {
  String msg = "<!DOCTYPE html>\
<html>\
<title>";
  msg += "Arduino Sensor - Home";
  msg += "</title>\
<head>\
    <link rel=\"stylesheet\" href=\"https://cdn.jsdelivr.net/npm/bulma@0.9.4/css/bulma.min.css\">\
</head>\
<body>\
<section class=\"hero is-info\">\
  <div class=\"hero-body\">\
    <p class=\"title\">";
  msg += "Arduino Sensor";
  msg += "    </p>\
    <p class=\"subtitle\">";
  msg += "Home";
  msg += "    </p>\
  </div>\
</section>\
</body>\
</html>";
  server.send(200, "text/html", msg);
}

void setup() {
  delay(1000);
  Serial.begin(115200);
  Serial.println();
  Serial.print("Configuring access point...");
  /* You can remove the password parameter if you want the AP to be open. */
  WiFi.softAP(ssid, password);

  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(myIP);
  server.on("/", handleRoot);
  server.begin();
  Serial.println("HTTP server started");
}

void loop() {
  server.handleClient();
}
