#define SELPIN 49 //Selection Pin 
#define DATAOUT 51//MOSI 
#define DATAIN  50//MISO 
#define SPICLOCK  52//Clock 
int readvalue; 

void setup(){ 
 //set pin modes 
 pinMode(SELPIN, OUTPUT); 
 pinMode(DATAOUT, OUTPUT); 
 pinMode(DATAIN, INPUT); 
 pinMode(SPICLOCK, OUTPUT); 
 //disable device to start with 
 digitalWrite(SELPIN,HIGH); 
 digitalWrite(DATAOUT,LOW); 
 digitalWrite(SPICLOCK,LOW); 

 Serial.begin(9600); 
} 

int read_adc(int channel){
  int adcvalue = 0;
  byte commandbits = B11000000; //command bits - start, mode, chn (3), dont care (3)

  //allow channel selection
  commandbits|=((channel-1)<<3);

  digitalWrite(SELPIN,LOW); //Select adc
  // setup bits to be written
  for (int i=7; i>=3; i--){
    digitalWrite(DATAOUT,commandbits&1<<i);
    //cycle clock
    digitalWrite(SPICLOCK,HIGH);
    digitalWrite(SPICLOCK,LOW);    
  }

  digitalWrite(SPICLOCK,HIGH);    //ignores 2 null bits
  digitalWrite(SPICLOCK,LOW);
  digitalWrite(SPICLOCK,HIGH);  
  digitalWrite(SPICLOCK,LOW);

  //read bits from adc
  for (int i=11; i>=0; i--){
    adcvalue+=digitalRead(DATAIN)<<i;
    //cycle clock
    digitalWrite(SPICLOCK,HIGH);
    digitalWrite(SPICLOCK,LOW);
  }
  digitalWrite(SELPIN, HIGH); //turn off device
  return adcvalue;
}


void loop() { 
  
 readvalue = read_adc(1); 
 Serial.print("Canal 1: ");
 Serial.println(readvalue,DEC); 
 delay(250); 

 readvalue = read_adc(2); 
 Serial.print("Canal 2: ");
 Serial.println(readvalue,DEC); 
 Serial.println(" "); 
 delay(250); 
 
 readvalue = read_adc(3); 
 Serial.print("Canal 3: ");
 Serial.println(readvalue,DEC); 
 delay(250); 

 readvalue = read_adc(4); 
 Serial.print("Canal 4: ");
 Serial.println(readvalue,DEC); 
 Serial.println(" "); 
 delay(250); 
 
 readvalue = read_adc(5); 
 Serial.print("Canal 5: ");
 Serial.println(readvalue,DEC); 
 Serial.println(" "); 
 delay(250); 
 
 readvalue = read_adc(6); 
 Serial.print("Canal 6: ");
 Serial.println(readvalue,DEC); 
 Serial.println(" "); 
 delay(250); 
 
 readvalue = read_adc(7); 
 Serial.print("Canal 7: ");
 Serial.println(readvalue,DEC); 
 Serial.println(" "); 
 delay(250); 
 
 readvalue = read_adc(8); 
 Serial.print("Canal 8: ");
 Serial.println(readvalue,DEC); 
 Serial.println(" "); 
 delay(250); 
} 
