/*
 * MORSE CODE:
 * Each Morse code symbol is formed by a sequence of dots and dashes. 
 * 
 * The dot duration is the basic unit. 
 * The duration of a dash is three times the duration of a dot. 
 * Each dot or dash within a character is followed by period of signal absence, called a space, equal to the dot duration. 
 * The letters of a word are separated by a space of duration equal to three dots.
 * The words are separated by a space equal to seven dots.
 * 
 * https://en.wikipedia.org/wiki/Morse_code
 */

/* 
 *  TODAY: English to Morse Code. 
 *  The goal is to enter an English word and get the Arduino to lit a LED with the corresponding Morse code.
 */
const int SIZE = 36, BUTTONPIN = 2;
char characters[] = "abcdefghijklmnopqrstuvwxyz1234567890";
String patterns[] = {".-", "-...", "-.-.", "-..", ".", 
                     "..-.", "--.", "....", "..", ".---", 
                     "-.-", ".-..", "--", "-.", "---",
                     ".--.", "--.-", ".-.", "...", "-",
                     "..-", "...-", ".--", "-..-", "-.--", 
                     "--..", ".----", "..---", "...--", "....-",
                     ".....", "-....", "--...", "---..", "----.",
                     "-----"};
const int TIME_UNIT = 1000; // A dot lasts 1.0 seconds (1000 millis).


void setup() {
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(BUTTONPIN, INPUT);
  Serial.begin(9600);

  // demo(); // Uncomment for demo.
  // test(); // Uncomment for tests.
}


void loop() {
  // put your main code here, to run repeatedly:
  // Should prompt to enter a word. 
  Serial.println("Choose a mode: encode or decode");
  while(Serial.available() == 0) {}
  String choice = Serial.readString();
  if(choice == "encode") {
    encode();
  }
  else if(choice == "decode") {
    decode();
  }
  // Should receive word and produce LED response.

}
