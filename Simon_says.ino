#include <LiquidCrystal_I2C.h>
#define num_LEDs 4
#define num_PBs 4
LiquidCrystal_I2C lcd(0x27,16,2);
const int s = 7; //speaker
const int PBs [num_PBs] = {3,4,5,6}; //row of PBs
const int LEDS [num_LEDs] = {8,9,10,11}; //row of LEDs
char array1[]= "GAME WILL RESTART      ";
const int PM = A0;//potentiometer to increase time limit
unsigned long t;//record time 
int tim = 300;
int timeout = 10000;
int compArray [11];
int level = 0;
bool gameOver = 0;
int randomLED;
int timeInterval;


void setup() {
  for (int i=0; i < num_LEDs; i++){
    pinMode(LEDS[i],OUTPUT);}
  for (int i=0; i < num_PBs; i++){
    pinMode(PBs[i],INPUT);
  }
  gameOver = 0;
  lcd.init(); //initialize the lcd
  lcd.backlight(); //open the backlight
  pinMode(s,INPUT);// initiallize speaker
  Serial.begin(9600);

}

void loop() {
  randomSeed(analogRead(A3));
  randomLED = random(num_LEDs);//take a random LED from list
  while(randomLED == compArray[level-1])//make sure previous LED is not the same (change later)
    randomLED = random(num_LEDs);
  timeInterval = map(analogRead(PM), 0,1023, 100,500); //Randomize time in potentiometeter 
   
 lcd.printstr("level "); 
 lcd.print(level);
 compArray[level] = randomLED; //add random led to level
 
  for (int i = 0; i < level; i++){
    digitalWrite(LEDS[compArray[i]], HIGH);
    delay(timeInterval);//delay cahnged by potentiometer 
    digitalWrite(LEDS[compArray[i]], LOW);
    delay(timeInterval);//delay cahnged by potentiometer 
  }

   t = millis();
   for (int i = 0; i < level; i++){ //per level (change later)
    while(digitalRead(PBs[compArray[i]]) == 0 ){
      if (millis()-t >= timeout){ //end game if there is no input in timeout 
         lcd.clear();
         lcd.printstr("GAME OVER");
         lcd.setCursor(0,1);//set text to begin from bottom 
         lcd.printstr("TIMEOUT");
         tone(s,1245,100);//play wrong sound 
         delay(1500);
         gg();
         break;
      }
      for (int j= 0; j < 4; j++){//push button
       if(digitalRead(PBs[j]) == 1 && j != compArray[i]) {//cehck if push button and LED sequence is the same (change later)
         lcd.clear();
         lcd.printstr("GAME OVER");
         lcd.setCursor(0,1);
         lcd.printstr("WRONG BUTTON");
         tone(s,900,100);//play wrong sound 
         delay(1500);
         gg();
         
       }
      }
       if(gameOver)//
         break;
     
    }
    if(!gameOver){//correct button was pressed 
      if (digitalRead(PBs[compArray[i]]) == 1){
        lcd.clear();
        lcd.printstr("correct");
        tone(s,1245,200);//play correct sound 
        delay(500);
      }
    }
    else{
      lcd.clear();
      lcd.print("loser");
      delay(500);
    }
    gameOver = 0;
     
  }
    lcd.clear();
    level++;//add level when correct sequence is played 

 
    Serial.print("TIME INTERVAL    ");
    Serial.println(timeout);  
    for (int i = 0; i < level; i++){
      Serial.println(compArray[i]);//cheat code
    }
    if (level == 11){//end game results 
      lcd.clear();
      lcd.print("YOU WIN!!");
      delay(100);
      lcd.clear();

    for (int j = 0; j < 6; j++) {//flash all LEDs 6 times 
      for (int i = 0; i < 5; i++) {
        digitalWrite(LEDS[i], HIGH);
      }
      delay(300); // wait for 0.3 sec
      for (int i = 0; i < 5; i++) {
        digitalWrite(LEDS[i], LOW);
      }
      delay(300); // wait for 0.3 sec
    }
    level = 0;
  } 
}

  void gg(){//game over screen 

    lcd.clear();
    lcd.setCursor(15,0); // set the cursor to column 15, line 0
    for (int positionCounter1 = 0; positionCounter1 < 20; positionCounter1++)
    {
      lcd.scrollDisplayLeft(); //Scrolls the contents of the display one space to the left.
      lcd.print(array1[positionCounter1]); // Print a message to the LCD.
      delay(tim); //wait for 250 microseconds
      tone(s,622,200);
    }
    lcd.clear(); //Clears the LCD screen and positions the cursor in the upper-left  corner.
    t = 0;//set time to zero
    level = 0;//reset level 
    gameOver = 1;
  
  }
