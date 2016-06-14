
// pins 3, 4, 5, 6, 7, 8, 9, 10, 11 and 12 are used

int val[10];

int alreadypressed[10];

char HIDkeycode[] = {26, 22, 4, 7, 10, 5, 11, 17, 13, 16};





// last state vars



uint8_t buf[8] = {0}; 	/* Keyboard report buffer */

void setup() {


  for (int m = 0; m < 10; m++) {

   alreadypressed[m] = 0;

  }


  pinMode(12, INPUT_PULLUP);
  pinMode(11, INPUT_PULLUP);
  pinMode(10, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(2, INPUT_PULLUP);
  Serial.begin(9600);
    pinMode(13, OUTPUT);

}

void loop() {







  /*  val[0] = digitalRead(3);
    if (val[0] == LOW) {
  //digitalWrite(13, HIGH);
      buf[2] = 26;    // w "up"
      buf[3] = 30;    // v
      buf[4] = 31;    // v
      buf[5] = 32;    // v
      buf[6] = 33;    // v
      buf[7] = 34;    // v
      Serial.write(buf, 8);	// Send keypress
      delay(50);

    } */





  val[0] = digitalRead(3);

  val[1] = digitalRead(4);


  val[2] = digitalRead(5);


  val[3] = digitalRead(6);


  val[4] = digitalRead(7);

  val[5] = digitalRead(8);

  val[6] = digitalRead(9);

  val[7] = digitalRead(10);


  val[8] = digitalRead(11);


  val[9] = digitalRead(12);



 
  for (int a = 0; a < 10; a++) {

    if (val[a] == LOW && !alreadypressed[a]) {

      alreadypressed[a] = 1;
      buf[2] = HIDkeycode[a];
      a = 10; // end loop
      digitalWrite(13, HIGH);
      

    } 
  }
  
  
  
    for (int b = 0; b < 10; b++) {

    if (val[b] == LOW && !alreadypressed[b]) {

      alreadypressed[b] = 1;
      buf[3] = HIDkeycode[b];
      b = 10; // end loop

    } 
  }
  
 
  
      for (int c = 0; c < 10; c++) {

    if (val[c] == LOW && !alreadypressed[c]) {

      alreadypressed[c] = 1;
      buf[4] = HIDkeycode[c];
      c = 10; // end loop

    }  
  }
  
  
  
        for (int d = 0; d < 10; d++) {

    if (val[d] == LOW && !alreadypressed[d]) {

      alreadypressed[d] = 1;
      buf[5] = HIDkeycode[d];
      d = 10; // end loop

    } 
  }
  
          for (int e = 0; e < 10; e++) {

    if (val[e] == LOW && !alreadypressed[e]) {

      alreadypressed[e] = 1;
      buf[6] = HIDkeycode[e];
      e = 10; // end loop

    } 
  }
  
            for (int f = 0; f < 10; f++) {

    if (val[f] == LOW && !alreadypressed[f]) {

      alreadypressed[f] = 1;
      buf[7] = HIDkeycode[f];
      f = 10; // end loop

    } 
  }
  
  
  
  
  


  Serial.write(buf, 8);	// Send keypress
  
  
  
  
  delay (40);
  
  for (int z = 0; z < 10; z++) {
  
    alreadypressed[z] = 0;
    
  }
  
  buf[0] = 0;
  buf[2] = 0;
  buf[3] = 0;
  buf[4] = 0;
  buf[5] = 0;
  buf[6] = 0;
  buf[7] = 0;


}

void releaseKey()
{
  buf[0] = 0;
  buf[2] = 0;
  buf[3] = 0;
  buf[4] = 0;
  buf[5] = 0;
  buf[6] = 0;
  buf[7] = 0;
  Serial.write(buf, 8);	// Release key  c
}
