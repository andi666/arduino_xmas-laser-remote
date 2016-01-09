/*******************************************************************
xmas-laser remote v0.2

fb fuer xmas-laser from china-men (60 $)
433.84 MHz

08-JAN-2016 andreas langkath , info@langkath.de

only for fun , under MIT license


klappt!    
                           
 
https://github.com/andi666/arduino_xmas-laser-remote
https://youtu.be/021rJYO4r7E



init  8.18ms H , 3.92ms L

1=> 466µs H + 514µs L
0=> 1ms L

power  = init + 10101010101010101010101010101010 11111110111010101101110
color> = init + 10101010101010101010101010101010 111111011011010101111010
color< = init + 10101010101010101010101010101010 111111011010110101011011010
flash> = init + 10101010101010101010101010101010 11111011111010101010101010
flash< = init + 10101010101010101010101010101010 111111010111010101110110
 
*********************************************************************************************/
#include <Wire.h>   
#include <LiquidCrystal_I2C.h> // *** i2c-LCD!! -> SCL = A5 , SDA = A4
 
LiquidCrystal_I2C lcd(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  // Set the LCD I2C address
//LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  // Set the LCD I2C address

static int TxPin = 6; // *** Pin.D6 = Tx
 
 

char* codeA ="10101010101010101010101010101010"; // *** immer gleich
char* code; // *** nur dieser aendert sich je taste
 
int anazhl;
int n;
const int buttonPinS1 = 2;  // *** SW = D2 'power'
const int buttonPinS2 = 3;  // *** SW = D3 'color >>'
const int buttonPinS3 = 4;  // *** SW = D4 'flash >>'
 
int buttonStateS1;             // the current reading from the input pin
int lastButtonStateS1 = HIGH;   // the previous reading from the input pin
long lastDebounceTimeS1 = 0;  // the last time the output pin was toggled
long debounceDelayS1 = 10;    // the debounce time; increase if the output flickers

int buttonStateS2;             // the current reading from the input pin
int lastButtonStateS2 = HIGH;   // the previous reading from the input pin
long lastDebounceTimeS2 = 0;  // the last time the output pin was toggled
long debounceDelayS2 = 10;    // the debounce time; increase if the output flickers

int buttonStateS3;             // the current reading from the input pin
int lastButtonStateS3 = HIGH;   // the previous reading from the input pin
long lastDebounceTimeS3 = 0;  // the last time the output pin was toggled
long debounceDelayS3 = 10;    // the debounce time; increase if the output flickers

char* Aktion;
 
unsigned long LCD_aktion;
unsigned long Millis; 
unsigned long LCD_PreviousMillis;
long LCD_interval = 500; // *** LCD aktualisierung in ms

int LED_pin = 13;  // *** LED HERZSCHLAG
int LED_status = LOW;  // *** used to set the LED
long LED_setZeit = 0;  // *** will store last time LED was updated
long LED_interval = 666;  // *** (1000) LED-HERZSCHALG-Intervall (milliseconds)
int alte_sekunde; 

byte Herz[8] = {
  B00000,
  B01010,
  B11111,
  B01110,
  B00100,
  B00000,
  B00000,
  B00000
};



void setup() {
 
   
   Serial.begin(57600); // *** 9600, 57600
   Serial.println();
   Serial.println(">start.");
   
   pinMode(LED_pin, OUTPUT); // *** für LED HERZSCHLAG
   lcd.begin(20,4);   // initialize the lcd for 20 chars 4 lines, turn on backlight (muss vor der Sonderzeichendefinierung stehen!)
   lcd.createChar(1,Herz); // *** eigene Sonder-Zeichen erstellen
   
   pinMode(buttonPinS1, INPUT);  // *** Taster aktivieren
   pinMode(buttonPinS2, INPUT);  // *** Taster aktivieren
   pinMode(buttonPinS3, INPUT);  // *** Taster aktivieren
   pinMode(TxPin, OUTPUT);  // *** Tx

   digitalWrite(TxPin, LOW );
    
   lcd.clear();
   //*** blink backlicht ****************************************
  for(int i = 0; i< 3; i++)  {
    lcd.backlight();
    delay(250);
    lcd.noBacklight();
    delay(250);
  }
  lcd.backlight(); 
 
  
  
}  
 
void loop() {
   
  LED_HERZSCHLAG();    
  taster();
 
  LCD_Ausgabe() ;
  digitalWrite(TxPin, LOW ); // *** wichtig, damit das signal wirklich aus ist! 
 
 

}  

