#include <DallasTemperature.h>
#include <OneWire.h>
#include <Servo.h>
float current_temp = 0.0 ;
float prev_temp = 0.0 ;
OneWire oneWire(9) ;
DallasTemperature sensors(&oneWire) ;
Servo servo ;
int pos = 0 ;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN, OUTPUT) ;
  digitalWrite(LED_BUILTIN, LOW) ;
  servo.attach(12) ;
  

  Serial.begin(9600) ;
  Serial.println("Temperature Sensor Output") ;
  sensors.begin() ;
  servo.write(0) ;

}

void loop() {
  // put your main code here, to run repeatedly:
  sensors.requestTemperatures() ;
  current_temp = sensors.getTempCByIndex(0) ;
  Serial.println("Output: ") ;
  Serial.println(current_temp) ;
  Serial.println(prev_temp);
  if (current_temp >= 34.0 && current_temp <= 36.0) {
    if (current_temp < prev_temp) {
      for(pos = 0; pos<=180; pos+=1) {
        servo.write(pos) ;
      }
      delay(2000) ; 
      for(pos = 180; pos>=0; pos-=1) {
        servo.write(pos) ;
      }
    }
  }
  prev_temp = current_temp ;

  

  delay(1000) ;


}
