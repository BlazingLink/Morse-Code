enum states {
  START, DOT, DASH, NEXT, END
};


void decode() {
  int state = START, pos = 0;
  unsigned long time;
  String morseCode;
  while (true) {
    Serial.print("state = ");
    Serial.println(state);
    Serial.print("time = ");
    Serial.println(time);
    Serial.print("morseCode = ");
    Serial.println(morseCode);
    switch(state) {
      case START:
        // Do stuff.
        // Transition rules.
        if(digitalRead(BUTTONPIN) == HIGH) {
          state = DOT;
          time = millis();
        }
        break;
        
      case DOT:
        // Do stuff.
        if(digitalRead(BUTTONPIN) == HIGH) {
          if((millis() - time) >= (TIME_UNIT * 3)) {
            state = DASH;
            break;
          }
        }
        else if(digitalRead(BUTTONPIN) == LOW) {
          if((millis() - time) >= TIME_UNIT) {
            state = NEXT;
            time = millis();
            morseCode += ".";
          }
          else {
            state = START;
          }
        }
        // Transition rules.
        break;
  
      case DASH:
        // Do stuff.
        if(digitalRead(BUTTONPIN) == HIGH) {
          if(millis() - time >= (TIME_UNIT * 6)) {
            state = END;

            break;
          }
        }
        state = NEXT;
        morseCode += "-";
        time = millis();
        
          // Transition rules.
        break;
  
      case NEXT:
        // Do stuff.
        // Between dot and dash for next character
        if(digitalRead(BUTTONPIN)) {
          
          if((millis() - time) >= (TIME_UNIT * 3)) {
            morseCode += "|";
          }
          
          else if((millis() - time) >= TIME_UNIT) {
            morseCode += " ";
          }

          state = DOT;
          time = millis();          
          
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
