/*
   MORSE CODE:
   Each Morse code symbol is formed by a sequence of dots and dashes.

   The dot duration is the basic unit.
   The duration of a dash is three times the duration of a dot.
   Each dot or dash within a character is followed by period of signal absence, called a space, equal to the dot duration.
   The letters of a word are separated by a space of duration equal to three dots.
   The words are separated by a space equal to seven dots.
*/

/*
    TODAY: English to Morse Code.
    The goal is to enter an English word and get the Arduino to lit a LED with the corresponding Morse code.
*/



// HELPER FUNCTIONS

/*
   Returns the position of elem in myArray.
   If elem is not in myArray, returns -1.
   e.g. myArray[] = {"one", "two", "three"};
        findIndexOf("three", myArray); --> 2
        findIndexOf("four", myArray); --> -1
*/
int findIndexOf(String elem, String myArray[], int array_size) {


  int i = 0;

  for (i = 0; i < array_size; i++) {

    int count = 0;

    // Serial.println(myArray[i][0]);

    for (int j = 0; j <= elem.length(); j++) {

      if (myArray[i].charAt(j) == elem.charAt(j)) {

        count ++;

      }
    }

    //Serial.println(count);

    if (count == elem.length() + 1) {

      return i;

    }

  }

  return -1;
}

// Overloading!
/*
   Returns the position of elem in myArray.
   If elem is not in myArray, returns -1.
   e.g. myArray[] = "abcdef";
        findIndexOf('c', myArray); --> 2
        findIndexOf("g", myArray); --> -1
*/
int findIndexOf(char elem, char myArray[], int arraySize) {
  //  Your code here!
  int i;
  for (i = 0; i < arraySize; i++) {
    if (myArray[i * sizeof(myArray[0])] == elem) {
      return i;
    }
  }
  return -1;
}


/*
   Transforms a character into the corresponding Morse code pattern.
   e.g. charToPattern('a'); --> ".-"
*/
String charToPattern(char character) {
  // Your code here!
  int patternPosition = findIndexOf(character, characters, SIZE);
  return patterns[patternPosition];
}


/*
   Transforms a Morse code pattern into the corresponding character.
   e.g. patternToChar(".-"); --> 'a'
*/
char patternToChar(String pattern) {
  // Your code here!
  int charPosition = findIndexOf(pattern, patterns, SIZE);
  return characters[charPosition];
}


/*
   Given a character, turns LED on and off according to Morse code convention.
*/
void charToLED(char character) {
  // Your code here!
  int time_off = TIME_UNIT, time_on;
  if(character == ' ') {
    delay(TIME_UNIT * 7);
  }
  else if(isAlphaNumeric(character)) {
    String pattern = charToPattern(character);
    for(int i = 0; i < pattern.length(); i++) {
      switch(pattern.charAt(i)) {
        case '-':
          time_on = (TIME_UNIT * 3);
          break;
        case '.':
          time_on = TIME_UNIT;
          break;
        default:
          Serial.println("Invalid char");
      }
      digitalWrite(LED_BUILTIN, HIGH);
      delay(time_on);
      digitalWrite(LED_BUILTIN, LOW);
      if(i == (pattern.length() - 1)) {
        delay(TIME_UNIT * 3);
      }
      else {
        delay(TIME_UNIT);
      }
    }
  }
}


/*
   Given a word, turns LED on and off according to Morse code convention.
*/
void wordToLED(String myWord) {
  // Your code here!
  myWord.toLowerCase();
  for(int i = 0; i < myWord.length(); i++) {
    charToLED(myWord.charAt(i));
  }
}

void encode() {
  while(true) {
    Serial.println("Beginning of encode()");
    while (Serial.available() == 0) {}    
    String mySentence = Serial.readString(); //Reading the Input string from Serial port.
    Serial.println(mySentence);
    if(mySentence == ".") {
      break;
    }
    wordToLED(mySentence); 
  }
}