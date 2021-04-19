#include "dht.h"
#define dht_apin A1
 
dht DHT;
 
void setup(){
 
  Serial.begin(9600);
 
}//end "setup()"
 
void loop(){
   
    DHT.read11(dht_apin);
    Serial.println(int(DHT.temperature)-10); 
    delay(2000);
 
}// end loop() 
