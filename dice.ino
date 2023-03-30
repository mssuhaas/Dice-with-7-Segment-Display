#define aPin 8  
#define bPin 9  
#define cPin 3  
#define dPin 4  
#define ePin 5  
#define fPin 7  
#define gPin 6  

#define pbutton A0
#define buzzer 11
const unsigned int freq = 2000;

int On = 1;
int Off;

void setup() {
  Serial.begin(9600);
  pinMode(aPin, OUTPUT);
  pinMode(bPin, OUTPUT);
  pinMode(cPin, OUTPUT);
  pinMode(dPin, OUTPUT);
  pinMode(ePin, OUTPUT);
  pinMode(fPin, OUTPUT);
  pinMode(gPin, OUTPUT);
  pinMode(pbutton, INPUT_PULLUP);    
  pinMode(buzzer, OUTPUT);         
  for (int i = 6; i >= 1; i--) {
    showNumber(i);
    tone(buzzer, freq, 100);
    delay(300);
  }
  tone(buzzer, freq, 250);  
  delay(1000);                            
}

void loop() {
   Serial.println("Hello Gaming Dice");
  int buttonState = digitalRead(pbutton);
  if (buttonState == LOW) {                 
    rollTheDice(10, 100);                   
    rollTheDice(5, 300);
    rollTheDice(3, 400);
    rollTheDice(1, 100);
    tone(buzzer, freq, 250);  
  }
}

void rollTheDice(int count, int delayLength) {
  for (int i = 0; i < count; i++) {
    int number = random(1, 7);            
    tone(buzzer, freq, 5);  
    showNumber(number);                   
    delay(delayLength);                   
  }
}


void showNumber(int x) {

  if (On == 1)
  {
    Off = 0;
  }
  else {
    Off = 1;
  }
  switch (x) {
    case 1: one();   break;
    case 2: two();   break;
    case 3: three(); break;
    case 4: four();  break;
    case 5: five();  break;
    case 6: six();   break;
    case 7: seven(); break;
    case 8: eight(); break;
    case 9: nine();  break;
    default: zero(); break;
  }
}

void one() {
  digitalWrite( aPin, Off); 
  digitalWrite( bPin, On); 
  digitalWrite( cPin, On); 
  digitalWrite( dPin, Off);
  digitalWrite( ePin, Off);
  digitalWrite( fPin, Off);
  digitalWrite( gPin, Off);
}

void two() {
  digitalWrite( aPin, On);
  digitalWrite( bPin, On); 
  digitalWrite( cPin, Off); 
  digitalWrite( dPin, On); 
  digitalWrite( ePin, On); 
  digitalWrite( fPin, Off);
  digitalWrite( gPin, On);
}

void three() {
  digitalWrite( aPin, On);
  digitalWrite( bPin, On); 
  digitalWrite( cPin, On); 
  digitalWrite( dPin, On); 
  digitalWrite( ePin, Off);
  digitalWrite( fPin, Off);
  digitalWrite( gPin, On);
}

void four() {
  digitalWrite( aPin, Off);
  digitalWrite( bPin, On);
  digitalWrite( cPin, On); 
  digitalWrite( dPin, Off); 
  digitalWrite( ePin, Off); 
  digitalWrite( fPin, On);
  digitalWrite( gPin, On);
}

void five() {
  digitalWrite( aPin, On);  
  digitalWrite( bPin, Off); 
  digitalWrite( cPin, On);  
  digitalWrite( dPin, On);  
  digitalWrite( ePin, Off); 
  digitalWrite( fPin, On);
  digitalWrite( gPin, On);
}

void six() {
  digitalWrite( aPin, On);  
  digitalWrite( bPin, Off); 
  digitalWrite( cPin, On); 
  digitalWrite( dPin, On); 
  digitalWrite( ePin, On); 
  digitalWrite( fPin, On);
  digitalWrite( gPin, On);
}

void seven() {
  digitalWrite( aPin, On); 
  digitalWrite( bPin, On);  
  digitalWrite( cPin, On);  
  digitalWrite( dPin, Off); 
  digitalWrite( ePin, Off); 
  digitalWrite( fPin, Off);
  digitalWrite( gPin, Off);
}

void eight() {
  digitalWrite( aPin, On); 
  digitalWrite( bPin, On); 
  digitalWrite( cPin, On); 
  digitalWrite( dPin, On); 
  digitalWrite( ePin, On); 
  digitalWrite( fPin, On);
  digitalWrite( gPin, On);
}

void nine() {
  digitalWrite( aPin, On);  
  digitalWrite( bPin, On);  
  digitalWrite( cPin, On);  
  digitalWrite( dPin, On);  
  digitalWrite( ePin, Off); 
  digitalWrite( fPin, On);
  digitalWrite( gPin, On);
}

void zero() {
  digitalWrite( aPin, On); 
  digitalWrite( bPin, On); 
  digitalWrite( cPin, On); 
  digitalWrite( dPin, On); 
  digitalWrite( ePin, On); 
  digitalWrite( fPin, On);
  digitalWrite( gPin, Off);
}
