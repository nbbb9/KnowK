#include <SoftwareSerial.h>

int trig = 6;
int echo = 7;

int RX = 2;
int TX = 3;
SoftwareSerial bt(3,2);

int las=9;//레이저 출력    
int rsen=8;//적외선센서 
int psen=A0;//압력센서
 
int rval;//적외선센서 값 
int pval;//압력센서 값
int lasval;//레이저센서 값 
int dis;//초음파센서 값     
  
int YES1;//레이저 존재 여부  
int YES2;//초음파 존재 여부
int YES3;//적외선 존재 여부 
int YES4;//압력센서 존재 여부  
int YESF;//최종 존재 여부

unsigned long long time;

int oneday = 3000;

void setup(){
  Serial.begin(9600);
  bt.begin(9600);
  
  pinMode(psen, INPUT);
  pinMode(rsen, INPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(las, OUTPUT);

  time = millis();
}

void lasersen(){
  digitalWrite(las, HIGH);
  
  lasval = analogRead(A1);
  
  if(lasval<400){
    YES1=1;
  }
  else{
    YES1=0;
  }
  delay(10);
  return YES1;
}

void uwave(){
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  
  dis = pulseIn(echo,HIGH) * 340 / 2 / 10000;//초음파센서 값

  if(dis<28 || dis>32){
    YES2 = 1;
  }
  else{
    YES2 = 0;
  }
  delay(10);
  return YES2;
  return dis;
}

void ifred(){
  rval=digitalRead(rsen);
  if(rval==0){
    YES3 = 1;
  }
  else{
    YES3 = 0;
  } 
  return YES3;
  delay(10);
}

void prsen(){
  pval=analogRead(psen);
  if(pval<10){
    YES4 = 1;
  }
  else{
    YES4 = 0;
  }
  delay(10);
  return YES4;
}

void loop(){ 
  lasersen();
  uwave();
  ifred();
  prsen();
  
  Serial.println("---------------");
  Serial.print("레이저센서: ");
  Serial.println(YES1);
  Serial.println(lasval);
  
  Serial.print("초음파센서: ");
  Serial.println(YES2);
  Serial.println(dis);
  
  Serial.print("적외선센서: ");
  Serial.println(YES3);
  Serial.println(rval);
  
  Serial.print("압력감지센서: ");
  Serial.println(YES4);
  Serial.println(pval);
  
  Serial.println("---------------");
  
  if ((YES1 == 0) && (YES2 == 0) && (YES3 == 0) && (YES4 == 0)){
    YESF = 0;
  }
  else {
    YESF = 1;
  }
  
  Serial.println(YESF);
  
  if(YESF==0){
    long long unsigned current = millis();
    int temp = current - time;
    if(temp >= 5000){
      bt.print(YESF);
      Serial.println("no");
    }
  }
  else if(YESF==1){
    time=millis();
  }
  delay(10);
}#include <SoftwareSerial.h>

int trig = 6;
int echo = 7;

int RX = 2;
int TX = 3;
SoftwareSerial bt(3,2);

int las=9;//레이저 출력    
int rsen=8;//적외선센서 
int psen=A0;//압력센서
 
int rval;//적외선센서 값 
int pval;//압력센서 값
int lasval;//레이저센서 값 
int dis;//초음파센서 값     
  
int YES1;//레이저 존재 여부  
int YES2;//초음파 존재 여부
int YES3;//적외선 존재 여부 
int YES4;//압력센서 존재 여부  
int YESF;//최종 존재 여부

unsigned long long time;

int oneday = 3000;

void setup(){
  Serial.begin(9600);
  bt.begin(9600);
  
  pinMode(psen, INPUT);
  pinMode(rsen, INPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(las, OUTPUT);

  time = millis();
}

void lasersen(){
  digitalWrite(las, HIGH);
  
  lasval = analogRead(A1);
  
  if(lasval<400){
    YES1=1;
  }
  else{
    YES1=0;
  }
  delay(10);
  return YES1;
}

void uwave(){
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  
  dis = pulseIn(echo,HIGH) * 340 / 2 / 10000;//초음파센서 값

  if(dis<28 || dis>32){
    YES2 = 1;
  }
  else{
    YES2 = 0;
  }
  delay(10);
  return YES2;
  return dis;
}

void ifred(){
  rval=digitalRead(rsen);
  if(rval==0){
    YES3 = 1;
  }
  else{
    YES3 = 0;
  } 
  return YES3;
  delay(10);
}

void prsen(){
  pval=analogRead(psen);
  if(pval<10){
    YES4 = 1;
  }
  else{
    YES4 = 0;
  }
  delay(10);
  return YES4;
}

void loop(){ 
  lasersen();
  uwave();
  ifred();
  prsen();
  
  Serial.println("---------------");
  Serial.print("레이저센서: ");
  Serial.println(YES1);
  Serial.println(lasval);
  
  Serial.print("초음파센서: ");
  Serial.println(YES2);
  Serial.println(dis);
  
  Serial.print("적외선센서: ");
  Serial.println(YES3);
  Serial.println(rval);
  
  Serial.print("압력감지센서: ");
  Serial.println(YES4);
  Serial.println(pval);
  
  Serial.println("---------------");
  
  if ((YES1 == 0) && (YES2 == 0) && (YES3 == 0) && (YES4 == 0)){
    YESF = 0;
  }
  else {
    YESF = 1;
  }
  
  Serial.println(YESF);
  
  if(YESF==0){
    long long unsigned current = millis();
    int temp = current - time;
    if(temp >= 5000){
      bt.print(YESF);
      Serial.println("no");
    }
  }
  else if(YESF==1){
    time=millis();
  }
  delay(10);
}
