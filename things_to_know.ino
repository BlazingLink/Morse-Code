// THINGS TO KNOW


void demo() {
  // chars: syntax, equality.
  
  /*
  char c1 = 'a';            // single quotation marks.
  char c2 = 'a';
  char c3 = 'b';
  
  Serial.println(c1 == c2); // 1
  Serial.println(c1 == c3); // 0
  */
  
  // Strings: syntax, charAt(), length(), equality.
  
  /*
  String word1 = "hello";        // Double quotation marks.
  String word2 = "world"; 
  char c = word1.charAt(1); 
  Serial.println(c);             // 'e'
  Serial.println(word1 == word2); // 0
  */
  
  // Arrays: How to create, how to index.
  
  /*
  char charArray[] = {'a', 'b', 'c'};
  // char charArray[] = "abc";                         // Alternative way writing char arrays. Not a String, though.
  
  String stringArray[] =  {"one", "two", "three"};
  
  Serial.println(charArray[1]);                        // 'b'
  Serial.println(stringArray[1]);                      // "two"
  */

  // Activity: Finish writing the variable patterns.
  
  // Functions/Methods: How to create, how to call.
  
  // for-loops.

  /*
  int num_reps = 10;
  for (int i=0; i < num_reps; i++) {
    Serial.println(i);
  }
  */
  
  // if/else statements.

  // Activity: findIndexOf(), charToPattern(), patternToChar()

  
  // Turning on/off an LED. Delays.

  /*
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);   
  */

  // Activity: charToLED(), wordToLED()

  // Receiving input from Serial Monitor.

  /*
  while (Serial.available() == 0) {}  
  String myWord = Serial.readString(); //Reading the Input string from Serial port. 
  Serial.println(myWord);
  */

  // Activity: loop()
  
}
