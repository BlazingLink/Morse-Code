enum states {
  START, DOT, DASH, NEXT_LETTER, NEXT_WORD, END
};


void decode() {
  Serial.println("decode open.");
  int state = START;
  unsigned long time;
  String currentLetter, english, morseCode;
  while (!(state == END)) {
    switch(state) {
      case START:
        // Do stuff.
        // Transition rules.
        
        if(digitalRead(BUTTONPIN)) {
          state = DOT;
          time = millis();
          decodePrint(english, state, time, morseCode);
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
            state = NEXT_LETTER;
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
          state = NEXT_LETTER;
          morseCode += '-';
          currentLetter += '-';
          time = millis();
          decodePrint(english, state, time, morseCode);
        }  
        
          // Transition rules.
        break;
  
      case NEXT_LETTER:
        // Do stuff.
        // Between dot and dash for next character
        // if(digitalRead(BUTTONPIN)) { // Whenever the program gets here, the button must be depressed.
        if(digitalRead(BUTTONPIN)) {
          state = DOT;
          time = millis();
          decodePrint(english, state, time, morseCode);
        }
        
        else if((millis() - time) >= (TIME_UNIT * 3)) { // End of letter.
          morseCode += " ";
          english += patternToChar(currentLetter);
          currentLetter = "";
          decodePrint(english, state, time, morseCode);
          state = NEXT_WORD;
        }
    

        // Transition rules.
        break;
      case NEXT_WORD:
        if(digitalRead(BUTTONPIN)) {
          state = DOT;
          time = millis();
          decodePrint(english, state, time, morseCode);
        }
        else if((millis() - time) >= (TIME_UNIT * 7)) { // End of word.
          morseCode += "|"; 
          // english += patternToChar(currentLetter);
          english += ' ';
          decodePrint(english, state, time, morseCode);
          state = START;            
        }

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
