//Declaración de variables.
//Salidas a 5 Voltios
int Salida5V0 = 22;
int Salida5V1 = 23;
int Salida5V2 = 24;
//Salidas a 5 Voltios PWM
int Salida5VPWM0 = 3;
int Salida5VPWM1 = 4;
int Salida5VPWM2 = 5;
//Estados posibles
int CambioEstado = 1; //Se ira conmutando.

//Timing
int delay = 200;
void setup() {
  // put your setup code here, to run once:
pinMode(Salida5V0,OUTPUT);
pinMode(Salida5V1,OUTPUT);
pinMode(Salida5V2,OUTPUT);

pinMode(Salida5VPWM0,OUTPUT);
pinMode(Salida5VPWM1,OUTPUT);
pinMode(Salida5VPWM2,OUTPUT);

Serial.begin(9600);
}

void loop() {

//Vamos probando a activar todas las salidas.

digitalWrite(Salida5V0,CambioEstado);
Serial.print("Salida5V0: ");
Serial.println(CambioEstado);
delay(delay);
digitalWrite(Salida5V1,CambioEstado);
Serial.print("Salida5V1: ");
Serial.println(CambioEstado);
delay(delay);
digitalWrite(Salida5V2,CambioEstado);
Serial.print("Salida5V2: ");
Serial.println(CambioEstado);
delay(delay);
digitalWrite(Salida5VPWM0,CambioEstado);
Serial.print("Salida5V0: ");
Serial.println(CambioEstado);
delay(delay);
digitalWrite(Salida5VPWM1,CambioEstado);
Serial.print("Salida5V1: ");
Serial.println(CambioEstado);
delay(delay);
digitalWrite(Salida5VPWM2,CambioEstado);
Serial.print("Salida5V2: ");
Serial.println(CambioEstado);
delay(delay);

CambioEstado = ! CambioEstado;
}
