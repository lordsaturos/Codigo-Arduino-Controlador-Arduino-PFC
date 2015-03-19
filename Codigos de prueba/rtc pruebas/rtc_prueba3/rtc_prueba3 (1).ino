#include <Wire.h> 
#include "RTClib.h"
RTC_DS1307 RTC;
void setup () {
Wire.begin(); // Inicia el puerto I2C
RTC.begin(); // Inicia la comunicación con el RTC
RTC.adjust(DateTime(__DATE__, __TIME__)); // Establece la fecha y hora (Comentar una vez establecida la hora)
Serial.begin(9600); // Establece la velocidad de datos del puerto serie
}
void loop(){
DateTime now = RTC.now(); // Obtiene la fecha y hora del RTC
   
Serial.print(now.year(), DEC); // Año
Serial.print('/');
Serial.print(now.month(), DEC); // Mes
Serial.print('/');
Serial.print(now.day(), DEC); // Dia
Serial.print(' ');
Serial.print(now.hour(), DEC); // Horas
Serial.print(':');
Serial.print(now.minute(), DEC); // Minutos
Serial.print(':');
Serial.print(now.second(), DEC); // Segundos
Serial.println();
delay(100); // La información se actualiza cada 1 seg.
}
