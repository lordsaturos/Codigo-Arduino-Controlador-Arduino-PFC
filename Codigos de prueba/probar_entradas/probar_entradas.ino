int entrada0 = 28;
int entrada1 = 29;
int entrada2 = 30;
int entrada3 = 31;
int entrada4 = 32;
int entrada5 = 33;

int estado0 = 0;
int estado1 = 0;
int estado2 = 0;
int estado3 = 0;
int estado4 = 0;
int estado5 = 0;

void setup() {
  // put your setup code here, to run once:
pinMode(entrada0,INPUT);
pinMode(entrada1,INPUT);
pinMode(entrada2,INPUT);
pinMode(entrada3,INPUT);
pinMode(entrada4,INPUT);
pinMode(entrada5,INPUT);

Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

estado0 = digitalRead(entrada0);
Serial.print("El estado de entrada0 es: ");
Serial.println(estado0);
delay(200);

estado1 = digitalRead(entrada1);
Serial.print("El estado de entrada1 es: ");
Serial.println(estado1);
delay(200);

estado2 = digitalRead(entrada2);
Serial.print("El estado de entrada2 es: ");
Serial.println(estado2);
delay(200);

estado3 = digitalRead(entrada3);
Serial.print("El estado de entrada3 es: ");
Serial.println(estado3);
delay(200);

estado4 = digitalRead(entrada4);
Serial.print("El estado de entrada4 es: ");
Serial.println(estado4);
delay(200);

estado5 = digitalRead(entrada5);
Serial.print("El estado de entrada5 es: ");
Serial.println(estado5);
delay(200);



}
