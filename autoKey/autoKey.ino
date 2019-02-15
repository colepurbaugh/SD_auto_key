#include <SD.h>
#include <SPI.h>

char go = 1;  //ends program when flagged as "10"

File myFile;
const int chipSelect = BUILTIN_SDCARD;


void readKeyPress (int p, int v){
  
    char r = myFile.read();
    if (r == 'e') {
        go = 0;
    } else if (r == '\r'){
        if ((p == 0) || (p == 1)){
            //pressKey(p, v);
        } else if (p == 2){
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
            case 0: Keyboard.release(KEY_A); break;
            case 1: Keyboard.release(KEY_B); break;
            case 2: Keyboard.release(KEY_C); break;
            case 3: Keyboard.release(KEY_D); break;
            case 4: Keyboard.release(KEY_E); break;
            case 5: Keyboard.release(KEY_F); break;
            case 6: Keyboard.release(KEY_G); break;
            case 7: Keyboard.release(KEY_H); break;
            case 8: Keyboard.release(KEY_I); break;
            case 9: Keyboard.release(KEY_J); break;
            case 10: Keyboard.release(KEY_K); break;
            case 11: Keyboard.release(KEY_L); break;
            case 12: Keyboard.release(KEY_M); break;
            case 13: Keyboard.release(KEY_N); break;
            case 14: Keyboard.release(KEY_O); break;
            case 15: Keyboard.release(KEY_P); break;
            case 16: Keyboard.release(KEY_Q); break;
            case 17: Keyboard.release(KEY_R); break;
            case 18: Keyboard.release(KEY_S); break;
            case 19: Keyboard.release(KEY_T); break;
            case 20: Keyboard.release(KEY_U); break;
            case 21: Keyboard.release(KEY_V); break;
            case 22: Keyboard.release(KEY_W); break;
            case 23: Keyboard.release(KEY_X); break;
            case 24: Keyboard.release(KEY_Y); break;
            case 25: Keyboard.release(KEY_Z); break;
            case 26: Keyboard.release(KEY_1); break;
            case 27: Keyboard.release(KEY_2); break;
            case 28: Keyboard.release(KEY_3); break;
            case 29: Keyboard.release(KEY_4); break;
            case 30: Keyboard.release(KEY_5); break;
            case 31: Keyboard.release(KEY_6); break;
            case 32: Keyboard.release(KEY_7); break;
            case 33: Keyboard.release(KEY_8); break;
            case 34: Keyboard.release(KEY_9); break;
            case 35: Keyboard.release(KEY_0); break;
            case 36: Keyboard.release(KEY_ENTER); break;
            case 37: Keyboard.release(KEY_ESC); break;
            case 38: Keyboard.release(KEY_BACKSPACE); break;
            case 39: Keyboard.release(KEY_TAB); break;
            case 40: Keyboard.release(KEY_SPACE); break;
            case 41: Keyboard.release(KEY_MINUS); break;
            case 42: Keyboard.release(KEY_EQUAL); break;
            case 43: Keyboard.release(KEY_LEFT_BRACE); break;
            case 44: Keyboard.release(KEY_RIGHT_BRACE); break;
            case 45: Keyboard.release(KEY_BACKSLASH); break;
            case 46: Keyboard.release(KEY_SEMICOLON); break;
            case 47: Keyboard.release(KEY_QUOTE); break;
            case 48: Keyboard.release(KEY_TILDE); break;
            case 49: Keyboard.release(KEY_COMMA); break;
            case 50: Keyboard.release(KEY_PERIOD); break;
            case 51: Keyboard.release(KEY_SLASH); break;
            case 52: Keyboard.release(KEY_CAPS_LOCK); break;
            case 53: Keyboard.release(KEY_F1); break;
            case 54: Keyboard.release(KEY_F2); break;
            case 55: Keyboard.release(KEY_F3); break;
            case 56: Keyboard.release(KEY_F4); break;
            case 57: Keyboard.release(KEY_F5); break;
            case 58: Keyboard.release(KEY_F6); break;
            case 59: Keyboard.release(KEY_F7); break;
            case 60: Keyboard.release(KEY_F8); break;
            case 61: Keyboard.release(KEY_F9); break;
            case 62: Keyboard.release(KEY_F10); break;
            case 63: Keyboard.release(KEY_F11); break;
            case 64: Keyboard.release(KEY_F12); break;
            case 65: Keyboard.release(KEY_PRINTSCREEN); break;
            case 66: Keyboard.release(KEY_SCROLL_LOCK); break;
            case 67: Keyboard.release(KEY_PAUSE); break;
            case 68: Keyboard.release(KEY_INSERT); break;
            case 69: Keyboard.release(KEY_HOME); break;
            case 70: Keyboard.release(KEY_PAGE_UP); break;
            case 71: Keyboard.release(KEY_DELETE); break;
            case 72: Keyboard.release(KEY_END); break;
            case 73: Keyboard.release(KEY_PAGE_DOWN); break;
            case 74: Keyboard.release(KEY_RIGHT); break;
            case 75: Keyboard.release(KEY_LEFT); break;
            case 76: Keyboard.release(KEY_DOWN); break;
            case 77: Keyboard.release(KEY_UP); break;
            case 78: Keyboard.release(KEY_NUM_LOCK); break;
            case 79: Keyboard.release(KEYPAD_SLASH); break;
            case 80: Keyboard.release(KEYPAD_ASTERIX); break;
            case 81: Keyboard.release(KEYPAD_MINUS); break;
            case 82: Keyboard.release(KEYPAD_PLUS); break;
            case 83: Keyboard.release(KEYPAD_ENTER); break;
            case 84: Keyboard.release(KEYPAD_1); break;
            case 85: Keyboard.release(KEYPAD_2); break;
            case 86: Keyboard.release(KEYPAD_3); break;
            case 87: Keyboard.release(KEYPAD_4); break;
            case 88: Keyboard.release(KEYPAD_5); break;
            case 89: Keyboard.release(KEYPAD_6); break;
            case 90: Keyboard.release(KEYPAD_7); break;
            case 91: Keyboard.release(KEYPAD_8); break;
            case 92: Keyboard.release(KEYPAD_9); break;
            case 93: Keyboard.release(KEYPAD_0); break;
            case 94: Keyboard.release(KEYPAD_PERIOD); break;
            case 95: Keyboard.release(MODIFIERKEY_CTRL); break;
            case 96: Keyboard.release(MODIFIERKEY_RIGHT_CTRL); break;
            case 97: Keyboard.release(MODIFIERKEY_SHIFT); break;
            case 98: Keyboard.release(MODIFIERKEY_RIGHT_SHIFT); break;
            case 99: Keyboard.release(MODIFIERKEY_ALT); break;
            case 100: Keyboard.release(MODIFIERKEY_RIGHT_ALT); break;
            case 101: Keyboard.release(MODIFIERKEY_GUI); break;
            case 102: Keyboard.release(MODIFIERKEY_RIGHT_GUI); break; //windows key
            case 103: Keyboard.release(KEY_MEDIA_PLAY); break;
            case 104: Keyboard.release(KEY_MEDIA_PAUSE); break;
            case 105: Keyboard.release(KEY_MEDIA_RECORD); break;
            case 106: Keyboard.release(KEY_MEDIA_STOP); break;
            case 107: Keyboard.release(KEY_MEDIA_REWIND); break;
            case 108: Keyboard.release(KEY_MEDIA_FAST_FORWARD); break;
            case 109: Keyboard.release(KEY_MEDIA_PREV_TRACK); break;
            case 110: Keyboard.release(KEY_MEDIA_NEXT_TRACK); break;
            case 111: Keyboard.release(KEY_MEDIA_VOLUME_DEC); break;
            case 112: Keyboard.release(KEY_MEDIA_VOLUME_INC); break;
            case 113: Keyboard.release(KEY_MEDIA_PLAY_PAUSE); break;
            case 114: Keyboard.release(KEY_MEDIA_PLAY_SKIP); break;
            case 115: Keyboard.release(KEY_MEDIA_MUTE); break;
            case 116: Keyboard.release(KEY_MEDIA_EJECT); break;
            case 117: Keyboard.release(KEY_SYSTEM_POWER_DOWN); break;
            case 118: Keyboard.release(KEY_SYSTEM_SLEEP); break;
            case 119: Keyboard.release(KEY_SYSTEM_WAKE_UP); break;
            default: break;
        }
    } else if (p == 1){
        switch (v) {
            case 0: Keyboard.press(KEY_A); break;
            case 1: Keyboard.press(KEY_B); break;
            case 2: Keyboard.press(KEY_C); break;
            case 3: Keyboard.press(KEY_D); break;
            case 4: Keyboard.press(KEY_E); break;
            case 5: Keyboard.press(KEY_F); break;
            case 6: Keyboard.press(KEY_G); break;
            case 7: Keyboard.press(KEY_H); break;
            case 8: Keyboard.press(KEY_I); break;
            case 9: Keyboard.press(KEY_J); break;
            case 10: Keyboard.press(KEY_K); break;
            case 11: Keyboard.press(KEY_L); break;
            case 12: Keyboard.press(KEY_M); break;
            case 13: Keyboard.press(KEY_N); break;
            case 14: Keyboard.press(KEY_O); break;
            case 15: Keyboard.press(KEY_P); break;
            case 16: Keyboard.press(KEY_Q); break;
            case 17: Keyboard.press(KEY_R); break;
            case 18: Keyboard.press(KEY_S); break;
            case 19: Keyboard.press(KEY_T); break;
            case 20: Keyboard.press(KEY_U); break;
            case 21: Keyboard.press(KEY_V); break;
            case 22: Keyboard.press(KEY_W); break;
            case 23: Keyboard.press(KEY_X); break;
            case 24: Keyboard.press(KEY_Y); break;
            case 25: Keyboard.press(KEY_Z); break;
            case 26: Keyboard.press(KEY_1); break;
            case 27: Keyboard.press(KEY_2); break;
            case 28: Keyboard.press(KEY_3); break;
            case 29: Keyboard.press(KEY_4); break;
            case 30: Keyboard.press(KEY_5); break;
            case 31: Keyboard.press(KEY_6); break;
            case 32: Keyboard.press(KEY_7); break;
            case 33: Keyboard.press(KEY_8); break;
            case 34: Keyboard.press(KEY_9); break;
            case 35: Keyboard.press(KEY_0); break;
            case 36: Keyboard.press(KEY_ENTER); break;
            case 37: Keyboard.press(KEY_ESC); break;
            case 38: Keyboard.press(KEY_BACKSPACE); break;
            case 39: Keyboard.press(KEY_TAB); break;
            case 40: Keyboard.press(KEY_SPACE); break;
            case 41: Keyboard.press(KEY_MINUS); break;
            case 42: Keyboard.press(KEY_EQUAL); break;
            case 43: Keyboard.press(KEY_LEFT_BRACE); break;
            case 44: Keyboard.press(KEY_RIGHT_BRACE); break;
            case 45: Keyboard.press(KEY_BACKSLASH); break;
            case 46: Keyboard.press(KEY_SEMICOLON); break;
            case 47: Keyboard.press(KEY_QUOTE); break;
            case 48: Keyboard.press(KEY_TILDE); break;
            case 49: Keyboard.press(KEY_COMMA); break;
            case 50: Keyboard.press(KEY_PERIOD); break;
            case 51: Keyboard.press(KEY_SLASH); break;
            case 52: Keyboard.press(KEY_CAPS_LOCK); break;
            case 53: Keyboard.press(KEY_F1); break;
            case 54: Keyboard.press(KEY_F2); break;
            case 55: Keyboard.press(KEY_F3); break;
            case 56: Keyboard.press(KEY_F4); break;
            case 57: Keyboard.press(KEY_F5); break;
            case 58: Keyboard.press(KEY_F6); break;
            case 59: Keyboard.press(KEY_F7); break;
            case 60: Keyboard.press(KEY_F8); break;
            case 61: Keyboard.press(KEY_F9); break;
            case 62: Keyboard.press(KEY_F10); break;
            case 63: Keyboard.press(KEY_F11); break;
            case 64: Keyboard.press(KEY_F12); break;
            case 65: Keyboard.press(KEY_PRINTSCREEN); break;
            case 66: Keyboard.press(KEY_SCROLL_LOCK); break;
            case 67: Keyboard.press(KEY_PAUSE); break;
            case 68: Keyboard.press(KEY_INSERT); break;
            case 69: Keyboard.press(KEY_HOME); break;
            case 70: Keyboard.press(KEY_PAGE_UP); break;
            case 71: Keyboard.press(KEY_DELETE); break;
            case 72: Keyboard.press(KEY_END); break;
            case 73: Keyboard.press(KEY_PAGE_DOWN); break;
            case 74: Keyboard.press(KEY_RIGHT); break;
            case 75: Keyboard.press(KEY_LEFT); break;
            case 76: Keyboard.press(KEY_DOWN); break;
            case 77: Keyboard.press(KEY_UP); break;
            case 78: Keyboard.press(KEY_NUM_LOCK); break;
            case 79: Keyboard.press(KEYPAD_SLASH); break;
            case 80: Keyboard.press(KEYPAD_ASTERIX); break;
            case 81: Keyboard.press(KEYPAD_MINUS); break;
            case 82: Keyboard.press(KEYPAD_PLUS); break;
            case 83: Keyboard.press(KEYPAD_ENTER); break;
            case 84: Keyboard.press(KEYPAD_1); break;
            case 85: Keyboard.press(KEYPAD_2); break;
            case 86: Keyboard.press(KEYPAD_3); break;
            case 87: Keyboard.press(KEYPAD_4); break;
            case 88: Keyboard.press(KEYPAD_5); break;
            case 89: Keyboard.press(KEYPAD_6); break;
            case 90: Keyboard.press(KEYPAD_7); break;
            case 91: Keyboard.press(KEYPAD_8); break;
            case 92: Keyboard.press(KEYPAD_9); break;
            case 93: Keyboard.press(KEYPAD_0); break;
            case 94: Keyboard.press(KEYPAD_PERIOD); break;
            case 95: Keyboard.press(MODIFIERKEY_CTRL); break;
            case 96: Keyboard.press(MODIFIERKEY_RIGHT_CTRL); break;
            case 97: Keyboard.press(MODIFIERKEY_SHIFT); break;
            case 98: Keyboard.press(MODIFIERKEY_RIGHT_SHIFT); break;
            case 99: Keyboard.press(MODIFIERKEY_ALT); break;
            case 100: Keyboard.press(MODIFIERKEY_RIGHT_ALT); break;
            case 101: Keyboard.press(MODIFIERKEY_GUI); break;
            case 102: Keyboard.press(MODIFIERKEY_RIGHT_GUI); break; //windows key
            case 103: Keyboard.press(KEY_MEDIA_PLAY); break;
            case 104: Keyboard.press(KEY_MEDIA_PAUSE); break;
            case 105: Keyboard.press(KEY_MEDIA_RECORD); break;
            case 106: Keyboard.press(KEY_MEDIA_STOP); break;
            case 107: Keyboard.press(KEY_MEDIA_REWIND); break;
            case 108: Keyboard.press(KEY_MEDIA_FAST_FORWARD); break;
            case 109: Keyboard.press(KEY_MEDIA_PREV_TRACK); break;
            case 110: Keyboard.press(KEY_MEDIA_NEXT_TRACK); break;
            case 111: Keyboard.press(KEY_MEDIA_VOLUME_DEC); break;
            case 112: Keyboard.press(KEY_MEDIA_VOLUME_INC); break;
            case 113: Keyboard.press(KEY_MEDIA_PLAY_PAUSE); break;
            case 114: Keyboard.press(KEY_MEDIA_PLAY_SKIP); break;
            case 115: Keyboard.press(KEY_MEDIA_MUTE); break;
            case 116: Keyboard.press(KEY_MEDIA_EJECT); break;
            case 117: Keyboard.press(KEY_SYSTEM_POWER_DOWN); break;
            case 118: Keyboard.press(KEY_SYSTEM_SLEEP); break;
            case 119: Keyboard.press(KEY_SYSTEM_WAKE_UP); break;
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
