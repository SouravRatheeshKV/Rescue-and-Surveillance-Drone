#include <TinyGPS++.h>
#include <SoftwareSerial.h>
#include <Wire.h> #include <Adafruit_SSD1306.h>
SoftwareSerial GSM(6, 7); 
SoftwareSerial neo(3, 4); 
const int minorButtonPin = 8; 
const int majorButtonPin = 9; 
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32
#define OLED_RESET    -1  Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
String lati = "";
String longi = "";
TinyGPSPlus gps;
void sendLocationSMS(String issueType);
void setup() {
  Serial.begin(9600); 
  GSM.begin(9600); 
  neo.begin(9600); 
  pinMode(minorButtonPin, INPUT_PULLUP); 
  pinMode(majorButtonPin, INPUT_PULLUP); 
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); 
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0,0);
  display.println("Press the buttons");
  display.println("to send location");
  display.display();
  delay(1000); 
}
void loop() {
if (Serial.available()) {
    String command = Serial.readStringUntil('\n');
    if (command.startsWith("AT")) {
      sendLocationSMS("Manual Request");
    }
  }
if (digitalRead(minorButtonPin) == LOW) {
    sendLocationSMS("Minor");
   
GSM.println("AT+CMGF=1"); 
  delay(100);
  GSM.println("AT+CMGS=\"+916282824876\""); 
  delay(1000);
  display.setTextSize(2);
   GSM.println("Minor");
   delay(100);
   GSM.println((char)26);
    delay(1000); 
  }
if (digitalRead(majorButtonPin) == LOW) {
    sendLocationSMS("Major");
GSM.println("AT+CMGF=1"); 
  delay(100);
  GSM.println("AT+CMGS=\"+916282824876\""); 
  delay(1000);
  display.setTextSize(2);
GSM.println("Major");
   delay(100);
   GSM.println((char)26);
    delay(1000); 
  }
}
void sendLocationSMS(String issueType) {
while (!gps.location.isUpdated()) {
    while (neo.available()) {
      gps.encode(neo.read());
    }
  }
lati = String(gps.location.lat(), 8);
  longi = String(gps.location.lng(), 8);
  String gmapLink = "https://www.google.com/maps?q=" + lati + "," + longi;
GSM.println("AT+CMGF=1"); 
  delay(100);
  GSM.println("AT+CMGS=\"+916282824876\""); 
  delay(1000);
  String message = "Latitude: " + lati + "\nLongitude: " + longi ;
  GSM.print("Issue Type : " + issueType);
GSM.print("\n");
  GSM.print(message);
  GSM.print("\n");
  GSM.print(gmapLink);
  GSM.write(0x1A); delay(1000);
  GSM.println();
  Serial.println("Sending message:");
  Serial.println(message);
  
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0,0);
  display.println("Issue:");
  display.println(issueType);
  display.display(); 
 delay(1000);
  GSM.println();
}

