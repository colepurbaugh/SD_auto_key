#include <SD.h>
#include <SPI.h>

char go = 1;  //ends program when flagged as "10"

File myFile;
const int chipSelect = BUILTIN_SDCARD;

void readKeyPress (int p, int v){
  Serial.print("readKeyPress(");
  Serial.print(p);
  Serial.print(", ");
  Serial.print(v);
  Serial.println(")");
  
    char r = myFile.read();
    Serial.print("r = ");
    Serial.println(r);
    if (r == 'e') {
        go = 0;
    } else if (r == '\r'){
        if ((p == 0) || (p == 1)){
            Serial.print("press key for ");
            Serial.print(p);
            Serial.print(" and ");
            Serial.println(v);
            //pressKey(p, v);
        } else if (p == 2){
            Serial.print("delay by: ");
            Serial.println(v);
            delay(v);
        }
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

void pressKey(int p, int v){
    if(p == 0){
        switch (v) {
            case 0: 
              Serial.println("Keyboard.release(KEY_A)"); 
              break;
            case 1: 
              Serial.println("Keyboard.release(KEY_B"); 
              break;
            case 51: 
              Serial.println("Keyboard.release(KEY_C)"); 
              break;
            default: break;
        }
    } else if (p == 1){
        switch (v) {
            case 0: 
              Serial.println("Keyboard.press(KEY_A)"); 
              break;
            case 1: 
              Serial.println("Keyboard.press(KEY_B)"); 
              break;
            case 51: 
              Serial.println("Keyboard.press(KEY_C)"); 
              break;
            default: break;
        }
    }
}

void setup(){
  Serial.begin(9600);
  Serial.print("Initializing SD card...");
  if (!SD.begin(chipSelect)) {
    Serial.println("initialization failed!");
    return;
  }
  Serial.println("initialization done.");


  myFile = SD.open("config.txt");
  if (myFile) {  
    // read from the file until there's nothing else in it:
    while (go) {
      readKeyPress(0,0);
    }
    myFile.close();
  } else {
    // if the file didn't open, print an error:
    Serial.println("error opening config.txt");
  }
}

void loop()
{
  // nothing happens after setup
}
