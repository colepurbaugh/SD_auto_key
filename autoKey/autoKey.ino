
#include <SD.h>
#include <SPI.h>
#include <LiquidCrystal.h>

File myFile;
File root;                                                  //start SD card in root directory

const int chipSelect = BUILTIN_SDCARD;                      //selects SD card physical pins
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2; //pins for LCD screen
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);                  //pins for LCD screen

char *fileNameStrings[50];                                  //
int fileNameCounter = 0;                                    //

const int buttonTop = 8, buttonMiddle = 7, buttonBottom = 6;

const int redLED = 24, greenLED = 25, blueLED = 26;
int led1State = 0;
int led2State = 0;
int led3State = 0;

int buttonTopState = 0;
int buttonMiddleState = 0;
int buttonBottomState = 0;
int buttonTimeStamp = 0;
int buttonDelay = 250;                                      //button changes are only checked every "buttonDelay" milliseconds

int menuPosition = 0;
int menuTopPosition = 0;
int go = 0;

void setup(){
  lcd.begin(16, 2);
  Serial.begin(9600);

  pinMode(buttonTop, INPUT);
  pinMode(buttonMiddle, INPUT);
  pinMode(buttonBottom, INPUT);

  pinMode(redLED, OUTPUT);
  pinMode(blueLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  
  while (!Serial) {
    ; // wait for serial port to connect
  }
  initializationSD();
  root = SD.open("/");
  printDirectory(root);
  updateMenu();
  updateLCD();
}

//*****************************************************************************************
void loop(){
  checkButtons();
  if (go){
    //back, forward, select
    updateMenu();
    updateLCD();
    go = 0;
  }
}
//*****************************************************************************************

void updateLCD(){
  //update top
  lcd.setCursor(0,0);
  lcd.print("**Select File**");
  //update bottom
  lcd.setCursor(0,1);
  lcd.print(fileNameStrings[menuPosition]);
  //lcd.print(*fileNameStrings[menuPosition]);
}

void checkButtons(){
  int currentTime = millis();
  if (buttonTimeStamp < (currentTime - buttonDelay)){
    buttonTopState = digitalRead(buttonTop);
    buttonMiddleState = digitalRead(buttonMiddle);
    buttonBottomState = digitalRead(buttonBottom);
    if(buttonTopState || buttonMiddleState || buttonBottomState){
      buttonTimeStamp = millis();
    go = 1;
    }
  }
}

void updateMenu(){
  Serial.println("updateMenu");  
  if(buttonMiddleState){
    buttonMiddleState = 0;
    Serial.print("fileNameStrings[menuPosition]: ");
    Serial.println(fileNameStrings[menuPosition]);
    readFile();
  } else if (buttonTopState){
    buttonTopState = 0;
    debugMenuValues();
    if (!menuPosition){
      menuPosition = menuTopPosition;
    } else {  
      menuPosition--;
    }
  } else if (buttonBottomState){
    buttonBottomState = 0;
    debugMenuValues();
    if (menuPosition == menuTopPosition){
      menuPosition = 0;
    } else {
      menuPosition++;
    }
  } 
}

void readFile(){
  myFile = SD.open(fileNameStrings[menuPosition]);
  if (myFile) {  
    // read from the file until there's nothing else in it:
    while (go) {
      //buttonRead(); //why is this here?
      readKeyPress(0,0);
    }
    myFile.close();
  } else {
    // if the file didn't open, print an error:
    Serial.println("error opening config.txt");
  }
}

void debugMenuValues(){
  Serial.print("menuPosition: ");
  Serial.println(menuPosition);
}

void toggleLED(int ledNumber){
  if (ledNumber == 1){
    led1State = 1 - led1State;
  } else if (ledNumber == 2){
    led2State = 1 - led2State;
  } else if (ledNumber == 3){
    led3State = 1 - led3State;
  }
}

void updateLEDs(){
  digitalWrite(redLED, led1State);
  digitalWrite(greenLED, led2State);
  digitalWrite(blueLED, led3State);
}

void debugValues(){
  Serial.print("menuTopPosition: ");
  Serial.println(menuTopPosition);
  Serial.print("fileNameStrings[0]");
  Serial.println(fileNameStrings[0]);
  Serial.print("fileNameStrings[1]");
  Serial.println(fileNameStrings[1]);
  Serial.print("fileNameStrings[2]");
  Serial.println(fileNameStrings[2]);
}

//p(precursor) tells you what the function is: (*)led, (+)key press, (-)key release, (~)delay, (e)end
void readKeyPress (int p, int v){
    char r = myFile.read();
    if (r == 'e') {
        go = 0;
    } else if (r == '\r'){
        if ((p == 0) || (p == 1)){
            Serial.print("press key ");
            Serial.println(v);
            //pressKey(p, v);
        } else if (p == 2){
            delay(v);
        } else if (p == 3){
            toggleLED(v);
            updateLEDs();
        }
    } else if(r == '*'){
        readKeyPress(3, v);
    } else if (r == '~'){
        readKeyPress(2, v);
    } else if (r == '+'){
        readKeyPress(1, v);
    } else if (r == '-'){
        readKeyPress(0, v);
    } else if (r == '0' || r == '1' || r == '2' || r == '3' || r == '4' || r == '5' || r == '6' || r == '7' || r == '8' || r == '9'){
        v *= 10;
        v += r - '0';
        readKeyPress(p,v);
    }
}

void printDirectory(File dir) {
   while(true) {
     File entry =  dir.openNextFile();
     if (! entry) {
       // no more files
       printfileNameTable(fileNameCounter);
       menuTopPosition = fileNameCounter - 1;
       debugValues();
       fileNameCounter = 0;
       break;
     }
     fileNameStrings[fileNameCounter] = strdup(entry.name());
     fileNameCounter++;
     entry.close();
   }
}

void printfileNameTable(int c){
  for (int i = 0; i <= c; i++){
    Serial.println(fileNameStrings[i]);
  }
}

void initializationSD(){
  //Serial.print("Initializing SD card...");
  if (!SD.begin(chipSelect)) {
    //Serial.println("initialization failed!");
    return;
  }
  //Serial.println("initialization done.");
}
