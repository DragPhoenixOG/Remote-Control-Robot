void pinConfig(){
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
}
void forward(){
  digitalWrite(13,LOW);
  digitalWrite(12,HIGH);
  digitalWrite(11,HIGH);
  digitalWrite(10,LOW);
}
void reverse(){
  digitalWrite(13,HIGH);
  digitalWrite(12,LOW);
  digitalWrite(11,LOW);
  digitalWrite(10,HIGH);
}
void stop(){
  digitalWrite(13,LOW);
  digitalWrite(12,LOW);
  digitalWrite(11,LOW);
  digitalWrite(10,LOW);
}
void rightTurn(){
  digitalWrite(13,LOW);
  digitalWrite(12,HIGH);
  digitalWrite(11,LOW);
  digitalWrite(10,LOW);
}
void leftTurn(){
  digitalWrite(13,LOW);
  digitalWrite(12,LOW);
  digitalWrite(11,HIGH);
  digitalWrite(10,LOW);
}
void sharpRight(){
  digitalWrite(13,LOW);
  digitalWrite(12,HIGH);
  digitalWrite(11,LOW);
  digitalWrite(10,HIGH);
}
void speed(int left,int right){
  analogWrite(5,left);
  analogWrite(6,right);
}
int receive,s=150;
void setup() {
  Serial.begin(9600); //baud rate 9600
  pinConfig();
}

void loop() {
  if(Serial.available()){
    receive = Serial.read();
    Serial.println(receive);
    if(receive == 87||receive==119){ //pressed a or A for forward
    forward();
    speed(s,s);
    }
    if(receive == 83||receive==115){ //pressed w or W for forward
    reverse();
    speed(s,s);
    }
    if(receive == 65||receive==97){ //pressed s or S for left turn
    leftTurn();
    speed(s,s);
    }
    if(receive == 68||receive==100){ //pressed d or D for right turn
    rightTurn();
    speed(s,s);
    }
    if(receive == 32){// pressed space to stop
      stop();
    }
    if(receive == 107||receive == 75){// k for speed up
      s+=20;
      if(s>=255)
      s=255;
      speed(s,s);
      Serial.println(s);
    }
    if(receive == 109||receive == 77){// m for speed down
      s-=20;
      if(s<=50)
      s=50;
      speed(s,s);
      Serial.println(s);
    }
    
  }
  
}
