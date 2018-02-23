#include <ESP8266WiFi.h>
#include <WiFiClient.h> 
#include <ESP8266WebServer.h>

/* Set these to your desired credentials. */
const char *ssid = "Ronak";
const char *password = "";
ESP8266WebServer server(80);
void handleRoot() 
{
int size=1000;
char temp[size];
snprintf ( temp, size,
"<html>\
<head>\ 
<title></title>\
<style>\
</style>\
</head>\
<body>\
  <body background = \"https://images.freeimages.com/images/large-previews/e2a/boise-downtown-1387405.jpg\" alt=\"Flowers in Chania\" width=\"460\" height=\"345\">\
<p><form id='F2' action='http://192.168.4.1/on1'><input class='button' type='submit' value='RED LED ON' ></form>\
<p><form id='F2' action='http://192.168.4.1/off1'><input class='button' type='submit' value='RED LED OFF' ></form>\
<p><form id='F2' action='http://192.168.4.1/on2'><input class='button' type='submit' value='BLUE LED ON' ></form>\
<p><form id='F2' action='http://192.168.4.1/off2'><input class='button' type='submit' value='BLUELED OFF' ></form>\
</body>\
</html>"
);

server.send ( 200, "text/html", temp );
}

void setup() {
  pinMode(4, OUTPUT);
  digitalWrite(4,LOW);
   pinMode(5, OUTPUT);
  digitalWrite(5,LOW);
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
  server.on ( "/on1", redON );    
  server.on ( "/off1", redOFF );
  server.on ( "/on2", blueON );    
  server.on ( "/off2", blueOFF );
server.begin();
  Serial.println("HTTP server started");
  
}
  void redON()
  {
  digitalWrite ( 4, HIGH );
  int size=1000;
  char temp[size];
  snprintf ( temp, size,

"<html>\
<head>\ 
<title></title>\
<style>\
body { background-color: #cccccc; font-family: Arial, Helvetica, Sans-Serif; Color: #000088; }\
</style>\
</head>\
<body>\
<p><form id='F2' action='http://192.168.4.1/on1'><input class='button' type='submit' value='RED LED ON' ></form>\
<p><form id='F2' action='http://192.168.4.1/off1'><input class='button' type='submit' value='RED LED OFF' ></form>\
<p><form id='F2' action='http://192.168.4.1/on2'><input class='button' type='submit' value='BLUE LED ON' ></form>\
<p><form id='F2' action='http://192.168.4.1/off2'><input class='button' type='submit' value='BLUELED OFF' ></form>\
</body>\
</html>"

);

server.send ( 200, "text/html", temp );
}

void redOFF()
{

  digitalWrite ( 4, LOW );

  int size=1000;
  char temp[size];
  snprintf ( temp, size,

"<html>\
<head>\ 
<title></title>\
<style>\
body { background-color: #cccccc; font-family: Arial, Helvetica, Sans-Serif; Color: #000088; }\
</style>\
</head>\
<body>\
<p><form id='F2' action='http://192.168.4.1/on1'><input class='button' type='submit' value='RED LED ON' ></form>\
<p><form id='F2' action='http://192.168.4.1/off1'><input class='button' type='submit' value='RED LED OFF' ></form>\
<p><form id='F2' action='http://192.168.4.1/on2'><input class='button' type='submit' value='BLUE LED ON' ></form>\
<p><form id='F2' action='http://192.168.4.1/off2'><input class='button' type='submit' value='BLUELED OFF' ></form>\
</body>\
</html>"
);
server.send ( 200, "text/html", temp );
}

void blueON()
{

  digitalWrite ( 5, HIGH );

  int size=1000;
  char temp[size];
  snprintf ( temp, size,

"<html>\
<head>\ 
<title></title>\
<style>\
body { background-color: #cccccc; font-family: Arial, Helvetica, Sans-Serif; Color: #000088; }\
</style>\
</head>\
<body>\
<p><form id='F2' action='http://192.168.4.1/on1'><input class='button' type='submit' value='RED LED ON' ></form>\
<p><form id='F2' action='http://192.168.4.1/off1'><input class='button' type='submit' value='RED LED OFF' ></form>\
<p><form id='F2' action='http://192.168.4.1/on2'><input class='button' type='submit' value='BLUE LED ON' ></form>\
<p><form id='F2' action='http://192.168.4.1/off2'><input class='button' type='submit' value='BLUELED OFF' ></form>\
</body>\
</html>"
);

server.send ( 200, "text/html", temp );
}

void blueOFF()
{

  digitalWrite ( 5, LOW );

  int size=1000;
  char temp[size];
  snprintf ( temp, size,

"<html>\
<head>\ 
<title></title>\
<style>\
body { background-color: #cccccc; font-family: Arial, Helvetica, Sans-Serif; Color: #000088; }\
</style>\
</head>\
<body>\
<p><form id='F2' action='http://192.168.4.1/on1'><input class='button' type='submit' value='RED LED ON' ></form>\
<p><form id='F2' action='http://192.168.4.1/off1'><input class='button' type='submit' value='RED LED OFF' ></form>\
<p><form id='F2' action='http://192.168.4.1/on2'><input class='button' type='submit' value='BLUE LED ON' ></form>\
<p><form id='F2' action='http://192.168.4.1/off2'><input class='button' type='submit' value='BLUELED OFF' ></form>\
</body>\
</html>"

);

server.send ( 200, "text/html", temp );
}


void loop() {
  server.handleClient();
}