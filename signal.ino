void signalausloesen(char* code){
 
 

    digitalWrite(TxPin, HIGH );
    delayMicroseconds(2222); //1750

    fire_init();
    
    fire_code(code);
    digitalWrite(TxPin, LOW );
 
}


void fire_code(char* code){ // *** code absenden
  
    anazhl = strlen(code);  
    n = 0;
    while (n < anazhl){
 
        if ( code[n] == 49 ) { 

          // *** '1'
          digitalWrite(TxPin, HIGH );
          delayMicroseconds(440);  
          digitalWrite(TxPin, LOW );  
          delayMicroseconds(512);  
          
        } else {
          // *** '0'
          digitalWrite(TxPin, LOW );  
          delayMicroseconds(1000);  
        }
         
        n++;
    }
     
}



void fire_init(){ // *** init absenden
/*
* init  8.18ms H , 3.92ms L + 10101010101010101010101010101010
*/
   
    digitalWrite(TxPin, HIGH );   
    delayMicroseconds(8180);   
    
    digitalWrite(TxPin, LOW );  
    delayMicroseconds(3920); 
 
    
    anazhl = strlen(codeA);  // codeA
    n = 0;
    while (n < anazhl){
 
        if ( codeA[n] == 49 ) { 

          // *** '1'
          digitalWrite(TxPin, HIGH );
          delayMicroseconds(466);  
          digitalWrite(TxPin, LOW );  
          delayMicroseconds(514);  
          
        } else {
          // *** '0'
          digitalWrite(TxPin, LOW );  
          delayMicroseconds(1000);  
        }
         
        n++;
    }
    
}
    
 

