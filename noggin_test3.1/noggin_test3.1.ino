bool passGlobal = true;
int failPin = -1;
void setup() {
  pinMode( 0, INPUT_PULLUP);
  pinMode( 1, OUTPUT);
  pinMode( 2, INPUT); 
  pinMode( 3, INPUT); 
  pinMode( 4, INPUT); 
  pinMode( 5, INPUT); 
  pinMode( 6, INPUT); 
  pinMode( 7, INPUT); 
  pinMode( 8, INPUT); 
  pinMode( 9, OUTPUT); 
  pinMode( 10, OUTPUT); 
  pinMode( 11, OUTPUT); 
  pinMode( 12, OUTPUT); 
  pinMode( 13, OUTPUT);
  digitalWrite( 1, HIGH);
  digitalWrite( 9, HIGH);
  digitalWrite( 10, HIGH);
  digitalWrite( 11, HIGH);
  digitalWrite( 12, HIGH);
  digitalWrite( 13, HIGH);
  delay(200);
  digitalWrite( 1, LOW);
  digitalWrite( 9, LOW);
  digitalWrite( 10, LOW);
  digitalWrite( 11, LOW);
  digitalWrite( 12, LOW);
  digitalWrite( 13, LOW);
  delay(200);
}

void loop() {
 for ( int i = 2; passGlobal == true and i <= 8; i++){
 digitalWrite( i , LOW);
 pinMode( i , OUTPUT);
 if ( digitalRead(0) == LOW ){
  //Null Statement
 }
 else {
  passGlobal = false;
  failPin = i;
 }
 digitalWrite( i , HIGH);
 pinMode( i , INPUT);
 }
 ////////////////////////
 if ( analogRead(0) == 0){
    if ( analogRead(1) >= 1000){
      if ( analogRead(2) == 0){
        if ( analogRead(3) >= 1000){
          if ( analogRead(4) == 0){
            if ( analogRead(5) >= 1000){
    //Null Statement
  }
            else {
    passGlobal = false;
    failPin = 600;
  }
  }
          else {
    passGlobal = false;
    failPin = 500;
  }
  }
        else {
    passGlobal = false;
    failPin = 400;
  }
  }
      else {
    passGlobal = false;
    failPin = 300;
  }
  }
    else {
    passGlobal = false;
    failPin = 200;
  }
  }
  else {
    passGlobal = false;
    failPin = 100;
  }
 ///////////////////////
 if ( passGlobal == true ){
  digitalWrite( 1 , HIGH);
  delay(500);
 }
 else {
  digitalWrite( 9 , HIGH);
  delay(500);
  if (failPin == 2){
    digitalWrite( 12 , HIGH);
    }
  else if (failPin == 3){
    digitalWrite( 12 , HIGH);
    digitalWrite( 13 , HIGH);
    }
  else if (failPin == 4){
    digitalWrite( 11 , HIGH);
    }
  else if (failPin == 5){
    digitalWrite( 11 , HIGH);
    digitalWrite (13 , HIGH);
    }
  else if (failPin == 6){
    digitalWrite( 11, HIGH);
    digitalWrite( 12, HIGH);
    }
  else if (failPin == 7){
    digitalWrite( 11, HIGH);
    digitalWrite( 12, HIGH);
    digitalWrite( 13, HIGH);
    }
  else if (failPin == 8){
    digitalWrite( 10, HIGH);
    }
 }
 while(1){
  if (failPin == 100){
    digitalWrite(10, HIGH);
    digitalWrite(11, HIGH); 
    digitalWrite(12, HIGH);
    digitalWrite(13, HIGH);
    delay(400);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW); 
    digitalWrite(12, LOW);
    digitalWrite(13, LOW);
    delay(400);
  }
  else if (failPin == 200){
    digitalWrite(13, HIGH);
    delay(400);
    digitalWrite(13, LOW);
    delay(400);
  }
  else if (failPin == 300){
    digitalWrite(12, HIGH);
    delay(400);
    digitalWrite(12, LOW);
    delay(400);
  }
  else if (failPin == 400){
    digitalWrite(12, HIGH);
    digitalWrite(13, HIGH);
    delay(400);
    digitalWrite(12, LOW);
    digitalWrite(13, LOW);
    delay(400);
  }
  else if (failPin == 500){
    digitalWrite(11, HIGH); 
    delay(400);
    digitalWrite(11, LOW); 
    delay(400);
  }
  else if (failPin == 600){
    digitalWrite(11, HIGH); 
    digitalWrite(13, HIGH);
    delay(400);
    digitalWrite(11, LOW); 
    digitalWrite(13, LOW);
    delay(400);
  }
 }
}
