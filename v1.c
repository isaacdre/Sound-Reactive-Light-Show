/*


int led = 5;
int MarkerValue = 255;
int Direction = 0;
int Delta = 2in;


void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
}


void loop() {
  // put your main code here, to run repeatedly:
  delay(30);
  if (Direction == 0) {
    if (MarkerValue - Delta > 0){
      MarkerValue = MarkerValue - Delta;
      analogWrite(led, MarkerValue);
    }
    else {
      MarkerValue = 0;
      analogWrite(led, MarkerValue);
      Direction = 1;
    }
  }
  if (Direction == 1){
    if (MarkerValue + Delta < 255){
        MarkerValue = MarkerValue + Delta;
        analogWrite(led, MarkerValue);
    }
    else {
      MarkerValue = 255;
      analogWrite(led, MarkerValue);
      Direction = 0;
    }  
  }
}
*/








/*
void loop()
{
  int soundValue = analogRead(sound);
  if (soundValue < 300) {
         analogWrite(LEDstrip, 255);
         delay(10);
  }
  else{
    analogWrite(LEDstrip,0);
  }
}




 */


 /*
//WORKING OPTION


#import "math.h"
#define LEDstrip 5
int sound = 0;  //This will communicate with analog pin A0




void setup()
{
  pinMode(sound,INPUT);
  pinMode(LEDstrip, OUTPUT);


}


void loop()
{
  int soundValue = analogRead(sound);


  if (soundValue < 5) {
      analogWrite(LEDstrip, 255);
      delay(0);
  }
  else if (soundValue >= 5 && soundValue < 20){
      analogWrite(LEDstrip, 180);
      delay(20);
  }
  else if (soundValue >= 20 && soundValue < 30){
      analogWrite(LEDstrip, 120);
      delay(20);
  }
  else if (soundValue >= 30 && soundValue < 40){
      analogWrite(LEDstrip, 60);
      delay(20);
  }
  else if (soundValue >= 40){
      analogWrite(LEDstrip, 0);
      delay(100);
  }
  else{
    analogWrite(LEDstrip,255);
    delay(0);
  }
}
*/




/*
void loop()
{
  int soundValue = analogRead(sound);
  if (soundValue < 20) {
         analogWrite(LEDstrip, 255);
         delay(0);
  }
  else{
    analogWrite(LEDstrip,0);
    delay(100);
  }
} 


*/










/*
//VERSION WITH MASSIVE ARRAY TABLE
#import "math.h"
#define LEDstrip 5   // This sets the led signal out to digital PWM pin 5
int SoundSensor = 0;  //This will communicate with analog pin A0


//DEFINE SAMPLING MIN AND MAX VALUES
int SampleLife = 30000; // ms
int CycleDelay = 10; // ms


int Min = 10;
int Max = 30;




int SoundStack[SampleLife / CycleDelay];


//Define Time Start
int TimeStamp = 0;
int DelayMarker = 0;


void setup()
{
  pinMode(SoundSensor,INPUT);
  pinMode(LEDstrip, OUTPUT);


}


void loop()
{
  int soundValue = analogRead(sound);  //The Sound Output for the current Cycle
  
  
  delay(CycleDelay); //Has to be a delay of 10 or else the Stack would become too large and crash arduino
}


*/








//VERSION THAT Searches for outliers from average.
#import "math.h"
#define LEDstrip 5   // This sets the led signal out to digital PWM pin 5
int SoundSensor = 0;  //This will communicate with analog pin A0

int SmootherLife = 3000; //ms
int EstCycleTime= 3; // ms   Perhaps try a cycle delay of 1.... And instead have a "skip cycle" counter. 
//That way the loop isnt stopped, light updates don't occur but if something becomes darker, it goes through.

double Avg = 60;
int AvgFloor = 20;
double Max = 10;
int MaxFloor = 4;

double Smoother = SmootherLife / EstCycleTime;

void setup()
{
  pinMode(SoundSensor,INPUT);
  pinMode(LEDstrip, OUTPUT);
}

void loop()
{
  int soundValue = analogRead(SoundSensor);  //The Sound Output for the current Cycle
  if (soundValue > Max && soundValue > MaxFloor){
    analogWrite(LEDstrip, 0);
    Max = soundValue * 0.95;
    delay(10);
    analogWrite(LEDstrip, 5);
    delay(3);
    analogWrite(LEDstrip, 10);
    delay(3);
    analogWrite(LEDstrip, 15);
    delay(3);
    analogWrite(LEDstrip, 20);
    delay(3);
    analogWrite(LEDstrip, 25);
    delay(3);
    analogWrite(LEDstrip, 30);
    delay(3);
    analogWrite(LEDstrip, 35);
    delay(3);
    analogWrite(LEDstrip, 40);
    delay(3);
    analogWrite(LEDstrip, 45);
    delay(3);
    analogWrite(LEDstrip, 50);
    delay(3);
    analogWrite(LEDstrip, 55);
    delay(3);
    analogWrite(LEDstrip, 60);
    delay(3);
    analogWrite(LEDstrip, 65);
    delay(3);
    analogWrite(LEDstrip, 70);
    delay(3);
    analogWrite(LEDstrip, 75);
    delay(3);
    analogWrite(LEDstrip, 80);
    delay(3);
    analogWrite(LEDstrip, 85);
    delay(3);
    analogWrite(LEDstrip, 90);
    delay(3);
    analogWrite(LEDstrip, 95);
    delay(3);
    analogWrite(LEDstrip, 100);
    delay(3);
    analogWrite(LEDstrip, 105);
    delay(3);
    analogWrite(LEDstrip, 110);
    delay(3);
    analogWrite(LEDstrip, 115);
    delay(3);
    analogWrite(LEDstrip, 120);
    delay(3);
    analogWrite(LEDstrip, 125);
    delay(3);
    analogWrite(LEDstrip, 130);
    delay(3);
    analogWrite(LEDstrip, 135);
    delay(3);
    analogWrite(LEDstrip, 140);
    delay(3);
    analogWrite(LEDstrip, 145);
    delay(3);
    analogWrite(LEDstrip, 150);
    delay(3);
    analogWrite(LEDstrip, 155);
    delay(3);
    analogWrite(LEDstrip, 160);
    delay(3);
    analogWrite(LEDstrip, 165);
    delay(3);
    analogWrite(LEDstrip, 170);
    delay(3);
    analogWrite(LEDstrip, 175);
    delay(3);
    analogWrite(LEDstrip, 180);
    delay(3);
    analogWrite(LEDstrip, 185);
    delay(3);
    analogWrite(LEDstrip, 190);
    delay(3);
    analogWrite(LEDstrip, 195);
    delay(3);
  }
  else if (soundValue > MaxFloor) {
    analogWrite(LEDstrip, 255);
    Max = Max - 0.0001;
  }
  else {
    analogWrite(LEDstrip, 255);
  }
}











/*
//VERSION THAT USES LIFE AVERAGE
#import "math.h"
#define LEDstrip 5   // This sets the led signal out to digital PWM pin 5
int SoundSensor = 0;  //This will communicate with analog pin A0


//DEFINE SAMPLING MIN AND MAX VALUES VIA CALC MOVING AVERAGE

int SmootherLife = 3000; //ms
int EstCycleTime= 3; // ms   Perhaps try a cycle delay of 1.... And instead have a "skip cycle" counter. 
//That way the loop isnt stopped, light updates don't occur but if something becomes darker, it goes through.

int SkipCount = 0;
int LastHighValue = 0;

int Min = 5;
double Avg = 60;
double AvgReduced = 10;
int Max = 40;
int MinFloor = 10;
int AvgFloor = 15;
int MaxFloor = 20;
int MedLow = 8;
int MedHigh = 12;

double Smoother = SmootherLife / EstCycleTime;


//Define Time Start
int TimeStamp = 0;
int DelayMarker = 0;


void setup()
{
  pinMode(SoundSensor,INPUT);
  pinMode(LEDstrip, OUTPUT);


}


void loop()
{
  int soundValue = analogRead(SoundSensor);  //The Sound Output for the current Cycle
  Avg = (((soundValue - Avg)/Smoother) + Avg);
  AvgReduced = Avg / 1;
  //IF ACTIONS
  if (soundValue < (AvgReduced * 3.5)) {
    analogWrite(LEDstrip, 255);
  }
  else if (soundValue >= (AvgReduced * 3.5) && soundValue < (AvgReduced * 3.6)){
    analogWrite(LEDstrip, 250);  
  }
  else if (soundValue >= (AvgReduced * 3.6) && soundValue < (AvgReduced * 3.7)){
    analogWrite(LEDstrip, 245);  
  }
  else if (soundValue >= (AvgReduced * 3.7) && soundValue < (AvgReduced * 3.8)){
    analogWrite(LEDstrip, 240);  
  }
  else if (soundValue >= (AvgReduced * 3.8) && soundValue < (AvgReduced * 3.9)){
    analogWrite(LEDstrip, 235);
  }
  else if (soundValue >= (AvgReduced * 3.9) && soundValue < (AvgReduced * 4.0)){
    analogWrite(LEDstrip, 230);
  }
  else if (soundValue >= (AvgReduced * 4) && soundValue < (AvgReduced * 4.1)){
    analogWrite(LEDstrip, 225);
  }
  else if (soundValue >= (AvgReduced * 4.1) && soundValue < (AvgReduced * 4.2)){
    analogWrite(LEDstrip, 220);
  }
  else if (soundValue >= (AvgReduced * 4.2) && soundValue < (AvgReduced * 4.3)){
    analogWrite(LEDstrip, 215);
  }
  else if (soundValue >= (AvgReduced * 4.3) && soundValue < (AvgReduced * 4.4)){
    analogWrite(LEDstrip, 210);
  }
  else if (soundValue >= (AvgReduced * 4.4) && soundValue < (AvgReduced * 4.5)){
    analogWrite(LEDstrip, 205);
  }
  else if (soundValue >= (AvgReduced * 4.5) && soundValue < (AvgReduced * 4.6)){
    analogWrite(LEDstrip, 180);
  }
  else if (soundValue >= (AvgReduced * 4.6) && soundValue < (AvgReduced * 4.7)){
    analogWrite(LEDstrip, 155);
  }
  else if (soundValue >= (AvgReduced * 4.7) && soundValue < (AvgReduced * 4.8)){
    analogWrite(LEDstrip, 145);
  }
  else if (soundValue >= (AvgReduced * 4.8) && soundValue < (AvgReduced * 4.9)){
    analogWrite(LEDstrip, 135);
  }
  else if (soundValue >= (AvgReduced * 4.9) && soundValue < (AvgReduced * 5)){
    analogWrite(LEDstrip, 125);
  }
  else if (soundValue >= (AvgReduced * 5) && soundValue < (AvgReduced * 5.1)){
    analogWrite(LEDstrip, 115);
  }
  else if (soundValue >= (AvgReduced * 5.1) && soundValue < (AvgReduced * 5.2)){
    analogWrite(LEDstrip, 95);
  }
  else if (soundValue >= (AvgReduced * 5.2) && soundValue < (AvgReduced * 5.3)){
    analogWrite(LEDstrip, 80);
  }
  else if (soundValue >= (AvgReduced * 5.3) && soundValue < (AvgReduced * 5.4)){
    analogWrite(LEDstrip, 70);
  }
  else if (soundValue >= (AvgReduced * 5.4) && soundValue < (AvgReduced * 5.5)){
    analogWrite(LEDstrip, 60);
  }
  else if (soundValue >= (AvgReduced * 5.5) && soundValue < (AvgReduced * 5.6)){
    analogWrite(LEDstrip, 50);
  }
  else if (soundValue >= (AvgReduced * 5.6) && soundValue < (AvgReduced * 5.7)){
    analogWrite(LEDstrip, 45);
  }
  else if (soundValue >= (AvgReduced * 5.7) && soundValue < (AvgReduced * 5.8)){
    analogWrite(LEDstrip, 40);
  }
  else if (soundValue >= (AvgReduced * 5.8) && soundValue < (AvgReduced * 5.9)){
    analogWrite(LEDstrip, 35);
  }
  else if (soundValue >= (AvgReduced * 5.9) && soundValue < (AvgReduced * 6)){
    analogWrite(LEDstrip, 30);
  }
  else if (soundValue >= (AvgReduced * 6) && soundValue < (AvgReduced* 6.1)){
    analogWrite(LEDstrip, 28);
  }
  else if (soundValue >= (AvgReduced* 6.1) && soundValue < (AvgReduced* 6.2)){
    analogWrite(LEDstrip, 26);
  }
  else if (soundValue >= (AvgReduced* 6.2) && soundValue < (AvgReduced* 6.3)){
    analogWrite(LEDstrip, 24);
  }
  else if (soundValue >= (AvgReduced* 6.3) && soundValue < (AvgReduced* 6.4)){
    analogWrite(LEDstrip, 22);
  }
  else if (soundValue >= (AvgReduced* 6.4) && soundValue < (AvgReduced* 6.5)){
    analogWrite(LEDstrip, 20);
  }
  else if (soundValue >= (AvgReduced* 6.5) && soundValue < (AvgReduced* 6.6)){
    analogWrite(LEDstrip, 19);
  }
  else if (soundValue >= (AvgReduced* 6.6) && soundValue < (AvgReduced* 6.7)){
    analogWrite(LEDstrip, 18);
  }
  else if (soundValue >= (AvgReduced* 6.7) && soundValue < (AvgReduced* 6.8)){
    analogWrite(LEDstrip, 17);
  }
  else if (soundValue >= (AvgReduced* 6.8) && soundValue < (AvgReduced* 6.9)){
    analogWrite(LEDstrip, 16);
  }
  else if (soundValue >= (AvgReduced* 6.9) && soundValue < (AvgReduced* 7)){
    analogWrite(LEDstrip, 15);
  }
  else if (soundValue >= (AvgReduced* 7) && soundValue < (AvgReduced* 7.1)){
    analogWrite(LEDstrip, 14);
  }
  else if (soundValue >= (AvgReduced* 7.1) && soundValue < (AvgReduced* 7.2)){
    analogWrite(LEDstrip, 13);
  }
  else if (soundValue >= (AvgReduced* 7.2) && soundValue < (AvgReduced* 7.3)){
    analogWrite(LEDstrip, 12);
  }
  else if (soundValue >= (AvgReduced* 7.3) && soundValue < (AvgReduced* 7.4)){
    analogWrite(LEDstrip, 11);
  }
  else if (soundValue >= (AvgReduced* 7.4) && soundValue < (AvgReduced* 7.5)){
    analogWrite(LEDstrip, 10);
  }
  else if (soundValue >= (AvgReduced* 7.5) && soundValue < (AvgReduced* 7.6)){
    analogWrite(LEDstrip, 9);
  }
  else if (soundValue >= (AvgReduced* 7.6) && soundValue < (AvgReduced* 7.7)){
    analogWrite(LEDstrip, 8);
  }
  else if (soundValue >= (AvgReduced* 7.7) && soundValue < (AvgReduced* 7.8)){
    analogWrite(LEDstrip, 7);
  }
  else if (soundValue >= (AvgReduced* 7.8) && soundValue < (AvgReduced* 7.9)){
    analogWrite(LEDstrip, 6);
  }
  else if (soundValue >= (AvgReduced* 7.9) && soundValue < (AvgReduced* 8)){
    analogWrite(LEDstrip, 5);
  }
  else if (soundValue >= (AvgReduced* 8) && soundValue < (AvgReduced* 8.1)){
    analogWrite(LEDstrip, 4);
  }
  else if (soundValue >= (AvgReduced* 8.1) && soundValue < (AvgReduced* 8.2)){
    analogWrite(LEDstrip, 3);
  }
  else if (soundValue >= (AvgReduced* 8.2) && soundValue < (AvgReduced* 8.3)){
    analogWrite(LEDstrip, 2);
  }
  else if (soundValue >= (AvgReduced* 8.3) && soundValue < (AvgReduced* 8.4)){
    analogWrite(LEDstrip, 1);
  }
  else{
    analogWrite(LEDstrip, 0);
    //delay(100);
  }
}

*/
