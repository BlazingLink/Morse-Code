enum states {
  START, DOT, DASH, NEXT, END
};

String currentLetter, english;

void decode() {
  Serial.println("decode open.");
  int state = START, pos = 0;
  unsigned long time;
  String morseCode;
  while (true) {
    /*
    Serial.print("state = ");
    Serial.println(state);
    Serial.print("time = ");
    Serial.println(time);
    Serial.print("morseCode = ");
    Serial.println(morseCode);
    */
    switch(state) {
      case START:
        // Do stuff.
        // Transition rules.
        if(digitalRead(BUTTONPIN) == HIGH) {
          state = DOT;
          time = millis();
          Serial.print("english = ");
          Serial.println(english);
          Serial.print("state = ");
          Serial.println(state);
          Serial.print("time = ");
          Serial.println(time);
          Serial.print("morseCode = ");
          Serial.println(morseCode);
        }
        break;
        
      case DOT:
        // Do stuff.
        if(digitalRead(BUTTONPIN)) {
          if((millis() - time) >= (TIME_UNIT * 3)) {
            state = DASH;
            Serial.print("english = ");
            Serial.println(english);
            Serial.print("state = ");
            Serial.println(state);
            Serial.print("time = ");
            Serial.println(time);
            Serial.print("morseCode = ");
            Serial.println(morseCode);
            break;
          }
        }
        else if(!(digitalRead(BUTTONPIN))) {
          if((millis() - time) >= TIME_UNIT) {
            state = NEXT;
            time = millis();
            morseCode += '.';
            currentLetter += '.';
            Serial.print("english = ");
            Serial.println(english);
            Serial.print("state = ");
            Serial.println(state);
            Serial.print("time = ");
            Serial.println(time);
            Serial.print("morseCode = ");
            Serial.println(morseCode);
          }
          else {
            state = START;
            Serial.print("english = ");
            Serial.println(english);
            Serial.print("state = ");
            Serial.println(state);
            Serial.print("time = ");
            Serial.println(time);
            Serial.print("morseCode = ");
            Serial.println(morseCode);
          }
        }
        // Transition rules.
        break;
  
      case DASH:
        // Do stuff.
        if(digitalRead(BUTTONPIN)) {
          if((millis() - time) >= (TIME_UNIT * 6)) {
            state = END;
            Serial.print("english = ");
            Serial.println(english);
            Serial.print("state = ");
            Serial.println(state);
            Serial.print("time = ");
            Serial.println(time);
            Serial.print("morseCode = ");
            Serial.println(morseCode);

          }
        }
        else {
          state = NEXT;
          morseCode += '-';
          currentLetter += '-';
          time = millis();
          Serial.print("english = ");
          Serial.println(english);
          Serial.print("state = ");
          Serial.println(state);
          Serial.print("time = ");
          Serial.println(time);
          Serial.print("morseCode = ");
          Serial.println(morseCode);
        }  
        
          // Transition rules.
        break;
  
      case NEXT:
        // Do stuff.
        // Between dot and dash for next character
        if(digitalRead(BUTTONPIN)) { // Whenever the program gets here, the button must be depressed.
          
          if((millis() - time) >= (TIME_UNIT * 7)) { // End of word.
            morseCode += "|"; 
            english += patternToChar(currentLetter);
            english += ' ';
            Serial.print("english = ");
            Serial.println(english);
            Serial.print("state = ");
            Serial.println(state);
            Serial.print("time = ");
            Serial.println(time);
            Serial.print("morseCode = ");
            Serial.println(morseCode);            
          }
          
          else if((millis() - time) >= (TIME_UNIT * 3)) { // End of letter.
            morseCode += " ";
            english += patternToChar(currentLetter);
            currentLetter = "";
            Serial.print("english = ");
            Serial.println(english);
            Serial.print("state = ");
            Serial.println(state);
            Serial.print("time = ");
            Serial.println(time);
            Serial.print("morseCode = ");
            Serial.println(morseCode);
          }

          state = DOT;
          time = millis();   
          Serial.print("english = ");
          Serial.println(english);
          Serial.print("state = ");
          Serial.println(state);
          Serial.print("time = ");
          Serial.println(time);
          Serial.print("morseCode = ");
          Serial.println(morseCode);       
          
        }

        // Transition rules.
        break;
  
      case END:
        // Do stuff.        
        // Transition rules.
        break;
  
      default: 
        Serial.println("Invalid state");
    }
  }
}
