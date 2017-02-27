int g=A0,p=A1,c=0,sg=0,sp=0,d=0,gg=A0,pp=A1,gi,gii,pi,pii,avgg,avgp,avggii,avgpii,pulse,gsr,sgii=0,spii=0,sw=0,q=0;
int led=13;

void setup() {
  pinMode(g,INPUT);
  pinMode(p,INPUT);
   pinMode(gg,INPUT);
   
    pinMode(pp,INPUT);
  pinMode(led,OUTPUT);
  Serial.begin(9600);

}

void loop() {
 if(c<16){pulse=0;gsr=0; 
 if(c<15)
 {gi=analogRead(g);
 //delay(1000);
  pi=analogRead(p);
  //delay(1000);
  sg+=gi;
 sp+=pi;
 
  
 }
 else if(c==15&&q==0){digitalWrite(led,HIGH);delay(500);digitalWrite(led,LOW);q=1;}
 else if(c==15&&q==1)
 {//delay(1000);
  avgg=sg/15;sgii=0;spii=0;d=0;sw=0;
 avgp=sp/15;
 Serial.println("avgg=");
 Serial.println(avgg);
 Serial.println("avgp=");
 Serial.println(avgp);
 
 sw=digitalRead(10);
 
// Serial.print("sw=");
 //Serial.println(sw);

 if(sw==HIGH){
 while(d<10){
 gii=analogRead(gg);
 //delay(1000);
 pii=analogRead(pp);
 //delay(1000);
 sgii+=gii;
 spii+=pii;
 //Serial.println("sgii=");
 //Serial.println(sgii);
 //Serial.println("spii=");
 //Serial.println(spii);
 
 d++;delay(200);}
 avggii=sgii/10;
 avgpii=spii/10;
 Serial.println("avggii");
 Serial.println(avggii);
 Serial.println("avgpii");
 Serial.println(avgpii);
 if(avggii>avgg+5)
 gsr=1;
 if(avgpii>avgp+70||avgpii<avgp-70) 
 pulse=1;
delay(2000);
 }
 sw=digitalRead(10);
 Serial.println("sw");
 Serial.println(sw);
 if(sw==LOW){
 Serial.println("gsr");
  Serial.println(gsr); Serial.println("pulse");
   Serial.println(pulse);
  if(
    pulse)
  {digitalWrite(led,HIGH);
  delay(500);
  digitalWrite(led,LOW);}}
  }
 c++;
 delay(1000);
 }
 if(c==16)
 c=15;
 //delay(1000);
}
