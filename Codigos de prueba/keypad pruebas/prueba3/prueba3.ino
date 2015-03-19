//**************************************************************//
//  Name    : shiftIn Example 2.3                               //
//  Author  : Carlyn Maw                                        //
//  Date    : 25 Jan, 2007                                      //
//  Version : 1.0                                               //
//  Notes   : Code for using a CD4021B Shift Register    	//
//          :                                                   //
//****************************************************************

//define where your pins are
int latchPin = 46;
int dataPin = 44;
int clockPin = 48;

//Define variables to hold the data 
//for each shift register.
//starting with non-zero numbers can help
//troubleshoot
byte switchVar1 = 72;  //01001000
byte switchVar2 = 159; //10011111

//define an array that corresponds to values for each 
//of the first shift register's pins
char note2sing[] = {
  'C', 'd', 'e', 'f', 'g', 'a', 'b', 'c'}; 

//define an array that has a place for the values of
//pins 1-7 (not 0) of the second shift register's
//pins. Not 0 because that will be used as a flag value
byte settingVal[] = {
  0, 0, 0, 0, 0, 0, 0};   

boolean MuteBit = 0;          
boolean OctShftBit = 1;
boolean DelayBit = 2;          
boolean ReverbBit = 3;
boolean VibratoBit = 4;
boolean FunkifyBit = 5;
boolean DampenBit = 6; 

//a flag varible used to track whether the program
//is in a setting update mode or not
byte settingSwitch = 0;  

void setup() {
  //start serial
  Serial.begin(9600);

  //define pin modes
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT); 
  pinMode(dataPin, INPUT);

}

void loop() {

  //Pulse the latch pin:
  //set it to 1 to collect parallel data
  digitalWrite(latchPin,1);
  //set it to 1 to collect parallel data, wait
  delayMicroseconds(20);
  //set it to 0 to transmit data serially  
  digitalWrite(latchPin,0);

  //while the shift register is in serial mode
  //collect each shift register into a byte
  //the register attached to the chip comes in first 
  switchVar1 = shiftIn(dataPin, clockPin);
  switchVar2 = shiftIn(dataPin, clockPin);

  //Print out the results.
  //leading 0's at the top of the byte 
  //(7, 6, 5, etc) will be dropped before 
  //the first pin that has a high input
  //reading  
  Serial.println(switchVar1, BIN);
  Serial.println(switchVar2, BIN);


  //This for-loop steps through the byte
  //bit by bit which holds the shift register data 
  //and if it was high (1) then it prints
  //the corresponding location in the array
  for (int n=0; n<=7; n++)
  {
    //so, when n is 3, it compares the bits
    //in switchVar1 and the binary number 00001000
    //which will only return true if there is a 
    //1 in that bit (ie that pin) from the shift
    //register.
    if (switchVar1 & (1 << n) ){
      //print the value of the array location
      Serial.println(note2sing[n]);
    }
  }

  //--- SHIFT REGISTER 2
  // This is a more complicated behavior


  //If the switch attached to pin 7 is High
  if (switchVar2 & (1 << 7) ){
    //print"Check, Check" to let us know the settings are being updated"
    Serial.println("Check, Check");
    //set a flag variable to let the progam know the settings are being updated
    settingSwitch = 1;
  }
  //if the switch is low
  else {
    //and if it was high the very last time it came through
    //this if statement (indicated by the settingSwitch variable still 
    //set to "1")
    if (settingSwitch) {
      //turn off the settingSwitch variable
      settingSwitch=0;

      //just print which settings are ON
      if (getBit(switchVar2, MuteBit)) {
        Serial.print("Mute On   ");
      }
      if (getBit(switchVar2, OctShftBit)) {
        Serial.println("Octave Shift On   ");
      }
      if (getBit(switchVar2, DelayBit)) {
        Serial.println("Delay On   ");
      }
      if (getBit(switchVar2, ReverbBit)) {
        Serial.println("Reverb On   ");
      }
      if (getBit(switchVar2, VibratoBit)) {
        Serial.println("Vibrato On   ");
      }
      if (getBit(switchVar2, FunkifyBit)) {
        Serial.println("Funkified   ");
      }
      if (getBit(switchVar2, DampenBit)) {
        Serial.println("Note Dampened   ");
      }
    }
  }        


  //white space
  Serial.println("-------------------");
  //delay so all these print satements can keep up. 
  delay(500);

}

//------------------------------------------------end main loop

////// ----------------------------------------shiftIn function
///// just needs the location of the data pin and the clock pin
///// it returns a byte with each bit in the byte corresponding
///// to a pin on the shift register. leftBit 7 = Pin 7 / Bit 0= Pin 0
byte shiftIn(int myDataPin, int myClockPin) { 
  int i;
  int temp = 0;
  int pinState;
  byte myDataIn = 0;

  pinMode(myClockPin, OUTPUT);
  pinMode(myDataPin, INPUT);
  //we will be holding the clock pin high 8 times (0,..,7) at the
  //end of each time through the for loop

  //at the begining of each loop when we set the clock low, it will
  //be doing the necessary low to high drop to cause the shift
  //register's DataPin to change state based on the value
  //of the next bit in its serial information flow.
  //The register transmits the information about the pins from pin 7 to pin 0
  //so that is why our function counts down
  for (i=7; i>=0; i--)
  {
    digitalWrite(myClockPin, 0);
    delayMicroseconds(2);
    temp = digitalRead(myDataPin);
    if (temp) {
      pinState = 1;
      //set the bit to 0 no matter what
      myDataIn = myDataIn | (1 << i);
    }
    else {
      //turn it off -- only necessary for debuging
      //print statement since myDataIn starts as 0
      pinState = 0;
    }

    //Debuging print statements
    //Serial.print(pinState);
    //Serial.print("     ");
    //Serial.println (dataIn, BIN);

    digitalWrite(myClockPin, 1);

  }
  //debuging print statements whitespace
  //Serial.println();
  //Serial.println(myDataIn, BIN);
  return myDataIn;
}

////// ----------------------------------------getBit
boolean getBit(byte myVarIn, byte whatBit) {
  boolean bitState;
  bitState = myVarIn & (1 << whatBit);
  return bitState;
}


////// A little extra function... 
////// ----------------------------------------setBit
byte setBit(byte myVarIn, byte whatBit, boolean s) {
  boolean bitState;
  if (s) {
    myVarIn = myVarIn | (1 << whatBit);
  } 
  else {
    myVarIn = myVarIn & ~(1 << whatBit);
  }
  return myVarIn;
}
