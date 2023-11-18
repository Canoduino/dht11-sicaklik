#include <LCD5110_Graph.h>
#include <dht11.h>
LCD5110 myGLCD(8,9,10,11,12);
extern uint8_t SmallFont[];
extern uint8_t BigNumbers[];
int DHT11_pin = 4;
dht11 DHT11_sensor;
int sicaklik;

void setup(){
 myGLCD.InitLCD();
 myGLCD.setFont(SmallFont);
 myGLCD.setContrast(70);
}
void loop(){
int chk = DHT11_sensor.read(DHT11_pin);
sicaklik = DHT11_sensor.temperature;
 myGLCD.clrScr();
 myGLCD.setFont(SmallFont);
 myGLCD.print("Sicaklik = " ,10 ,0);  
 myGLCD.print("c" ,57,20);
 myGLCD.print("." ,53,15);
 myGLCD.setFont(BigNumbers);
 myGLCD.printNumI(sicaklik, 25, 20);
 myGLCD.update();
 delay(1000);
}
