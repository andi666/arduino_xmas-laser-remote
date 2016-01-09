/**************************************************************
Taster abfragen , mit Entprellung

... ist HIGH, beia Auloesung wird er LOW
***************************************************************/ 
void taster() {
  
    int readingS1 = digitalRead(buttonPinS1);  
    if (readingS1 != lastButtonStateS1) {
        lastDebounceTimeS1 = millis(); // reset the debouncing timer
    }
    if ((millis() - lastDebounceTimeS1) > debounceDelayS1) {
        if (readingS1 != buttonStateS1) { // if the button state has changed:
            buttonStateS1 = readingS1;
            if (buttonStateS1 == LOW) {
                 code = "11111110111010101101110";
                
                signalausloesen(code); // *** fire!
                lcd.setCursor(0,1);
                
                lcd.print("S1");
                //Serial.println();
                Serial.print(">S1 , ");
                Serial.println(code);
                LCD_aktion = millis();
            }
        }
    }
    lastButtonStateS1 = readingS1;





    int readingS2 = digitalRead(buttonPinS2);  
    if (readingS2 != lastButtonStateS2) {
        lastDebounceTimeS2 = millis(); // reset the debouncing timer
    }
    if ((millis() - lastDebounceTimeS2) > debounceDelayS2) {
        if (readingS2 != buttonStateS2) { // if the button state has changed:
            buttonStateS2 = readingS2;
            if (buttonStateS2 == LOW) {
                code = "111111011011010101111010"; // color>>
                signalausloesen(code); // *** fire!
                lcd.setCursor(0,1);
                
                lcd.print("S2");
                //Serial.println();
                Serial.print(">S2 , ");
                Serial.println(code);
                LCD_aktion = millis();
            }
        }
    }
    lastButtonStateS2 = readingS2;




    int readingS3 = digitalRead(buttonPinS3);  
    if (readingS3 != lastButtonStateS3) {
        lastDebounceTimeS3 = millis(); // reset the debouncing timer
    }
    if ((millis() - lastDebounceTimeS3) > debounceDelayS3) {
        if (readingS3 != buttonStateS3) { // if the button state has changed:
            buttonStateS3 = readingS3;
            if (buttonStateS3 == LOW) {
                code = "11111011111010101010101010"; // flash>>
                signalausloesen(code); // *** fire!
                lcd.setCursor(0,1);
                
                lcd.print("S3");
                //Serial.println();
                Serial.print(">S3 , ");
                Serial.println(code);
                LCD_aktion = millis();
            }
        }
    }
    lastButtonStateS3 = readingS3;

    

}

