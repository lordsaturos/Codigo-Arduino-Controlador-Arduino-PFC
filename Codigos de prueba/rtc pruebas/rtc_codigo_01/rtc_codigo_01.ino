//Arduino con Tiny RTC I2C http://zygzax.com
#include <Wire.h>
#include "RTClib.h"
RTC_DS1307 RTC;
 
void setup () {
  //Inicializamos el puerto serie, wire y el modulo RTC
    Serial.begin(9600);
    Wire.begin();
    RTC.begin();
    //Si quitamos el comentario de la linea siguiente, se ajusta la hora y la fecha con la del ordenador
    RTC.adjust(DateTime(__DATE__, __TIME__));
}
 
void loop () {
    DateTime now = RTC.now();
    //Imprimimos el dia
    Serial.print(now.day(), DEC);
    Serial.print('/');
    //Imprimimos el mes
    Serial.print(now.month(), DEC);
    Serial.print('/');
    //Imprimimos el año
    Serial.print(now.year(), DEC);
    Serial.print(' ');
    //Imprimimos la hora
    Serial.print(now.hour(), DEC);
    Serial.print(':');
    //Imprimimos los minutos
    Serial.print(now.minute(), DEC);
    Serial.print(':');
    //Imprimimos los segundos
    Serial.print(now.second(), DEC);
    Serial.println();
    //Comprobamos la hora y la enviamos por el puerto serie cada 3s
    delay(3000);
}
