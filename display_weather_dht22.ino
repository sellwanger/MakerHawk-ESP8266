
#include <stdlib.h>
#include <Arduino.h>
#include <U8g2lib.h>
#include <DHT.h>


#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif

#define DHTPIN 4     // what digital pin we're connected to
#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321
DHT dht(DHTPIN, DHTTYPE);


// Please UNCOMMENT one of the contructor lines below
// U8g2 Contructor List (Picture Loop Page Buffer)
// The complete list is available here: https://github.com/olikraus/u8g2/wiki/u8g2setupcpp
// Please update the pin numbers according to your setup. Use U8X8_PIN_NONE if the reset pin is not connected
U8G2_SSD1306_128X32_UNIVISION_F_SW_I2C u8g2(U8G2_R0, /* clock=*/ 5, /* data=*/ 4, /* reset=*/ 16);
//U8G2_NULL u8g2(U8G2_R0);	// null device, a 8x8 pixel display which does nothing


// End of constructor list


void setup(void) {

  /* U8g2 Project: SSD1306 Test Board */
  //pinMode(10, OUTPUT);
  //pinMode(9, OUTPUT);
  //digitalWrite(10, 0);
  //digitalWrite(9, 0);		

  /* U8g2 Project: T6963 Test Board */
  //pinMode(18, OUTPUT);
  //digitalWrite(18, 1);	

  /* U8g2 Project: KS0108 Test Board */
  //pinMode(16, OUTPUT);
  //digitalWrite(16, 0);	

  /* U8g2 Project: LC7981 Test Board, connect RW to GND */
  //pinMode(17, OUTPUT);
  //digitalWrite(17, 0);	

  /* U8g2 Project: Pax Instruments Shield: Enable Backlight */
  //pinMode(6, OUTPUT);
  //digitalWrite(6, 0);	

  u8g2.begin();  
}

void loop(void) {
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  String sHumid = String(h);
  String sTemp = String(t);
  
  String msgTemp = "Temperatur : " + sTemp + char(176)+"C";
  String msgHumid = "Luftfeuchte: " + sHumid + "%";
  
  char msgSTemp[40];
  char msgSHumid[40];
  
  msgTemp.toCharArray(msgSTemp,40);
  msgHumid.toCharArray(msgSHumid,40);
   
    u8g2.clearBuffer();
    u8g2.setFont(u8g2_font_6x13_tf);
    u8g2.drawStr(8,13,msgSTemp);
    u8g2.drawStr(8,28,msgSHumid);
    u8g2.sendBuffer();
  delay(2000);
}

