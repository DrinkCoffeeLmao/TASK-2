int left1=13;int left2=11;int right1=8;int right2=10;char check;
void setup() {
  // put your setup code here, to run once:
  pinMode(left1,OUTPUT);
  pinMode(right1,OUTPUT);
  pinMode(left2,INPUT);
  pinMode(right2,INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  check=Serial.read();
  Serial.print(check);
  if(check=='W'){//FORWARD
    digitalWrite(left1,HIGH);
    digitalWrite(right1,HIGH);
    analogWrite(left2,150);
    analogWrite(right2,150);
    Serial.print("Forward");
    delay(500);
  }

  if(check=='S'){//BACKWARD
    digitalWrite(left1,LOW);
    digitalWrite(right1,LOW);
    analogWrite(left2,150);
    analogWrite(right2,150);
    Serial.print("Backward");
    delay(500);
  }

  if(check=='A'){//leftwards
    digitalWrite(left1,LOW);
    digitalWrite(right1,HIGH);
    analogWrite(left2,0);
    analogWrite(right2,150);
    Serial.print("Leftward");
    delay(500);
  }
  if(check=='D'){ //rightwards
    digitalWrite(left1,HIGH);
    digitalWrite(right1,LOW);
    analogWrite(left2,150);
    analogWrite(right2,0);
    Serial.print("Rightward");
    delay(500);
  }
  else{ 
    digitalWrite(left1,LOW);
    digitalWrite(right1,LOW);
    analogWrite(left2,0);
    analogWrite(right2,0);
    delay(500);
  }
}

