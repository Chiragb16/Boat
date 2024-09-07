int m1 = 9;
int m2 = 10;
int sp=7;
int c;

void setup() {
  pinMode(m1, OUTPUT);
  pinMode(m2, OUTPUT);
  pinMode(sp,OUTPUT);
  Serial.begin(9600);
  Serial.println("Ready");
}

void loop() {
  if (Serial.available() > 0) {
    c = Serial.read();
    if (c == '\n' || c == '\r') {
      // Ignore newline and carriage return characters
      return;
    }
    Serial.print("Received: ");
    Serial.println(c);

    if (c == '1') {
      analogWrite(m1, 255);
      analogWrite(m2, 0);
      Serial.println("Motor 1 ON, Motor 2 OFF");
    } else if (c == '2') {
      analogWrite(m1,0 );
      analogWrite(m2, 255);
      Serial.println("Motor 1 OFF, Motor 2 ON");
    } else if (c == '3') {
      analogWrite(m1, 255);
      analogWrite(m2, 255);
      Serial.println("Both Motors ON");
    } 
    else if(c=='4'){
      digitalWrite(sp,HIGH);
      delay(1000);
      digitalWrite(sp,LOW);
       analogWrite(m1, 255);
      analogWrite(m2, 255);
      Serial.println("Both Motors ON");
    }
    else {
      analogWrite(m1, 0);
      analogWrite(m2, 0);
      digitalWrite(sp,LOW);

      Serial.println("Both Motors OFF");
    }
  }
}
