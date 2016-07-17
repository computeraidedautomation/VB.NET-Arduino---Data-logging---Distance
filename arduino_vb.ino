
#define echoPin 7 // Echo Pin
#define trigPin 8 // Trigger Pin
#define loadpin 13 // Trigger Pin
/*#define LEDPin 13 // Onboard LED*/
int jij = 0;
int maximumRange = 200; // Maximum range needed
int minimumRange = 0; // Minimum range needed
float duration, distance; // Duration used to calculate distance
void setup() {
Serial.begin(9600); // set serial speed
pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);
 pinMode(loadpin, OUTPUT); // Use LED indicator (if required)
digitalWrite(loadpin, LOW); //turn off LED
}
void loop()
{
while (Serial.available() == 0); // do nothing if nothing sent
int val = Serial.read() - '0'; // deduct ascii value of '0' to find numeric value of sent number
if (val == 1) { // test for command 1 then turn on LED
digitalWrite(loadpin, HIGH); // turn on LED
deflstart();
//jij = 1;
}
else if (val == 0) // test for command 0 then turn off LED
{
digitalWrite(loadpin, LOW); // turn off LED
//jij=2;
deflstop();

}
else // if not one of above command, do nothing
{
//val = val;
}
//Serial.println(val);
Serial.flush(); // clear serial port
jij = 3;
}
void deflstart()
{
   digitalWrite(trigPin, LOW); 
 delayMicroseconds(2); 
 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10); 
  digitalWrite(trigPin, LOW);
 duration = pulseIn(echoPin, HIGH);
  //Calculate the distance (in cm) based on the speed of sound.
 distance = duration/5.81;
  if (distance >= maximumRange || distance <= minimumRange){
 /* Send a negative number to computer and Turn LED ON 
 to indicate "out of range" */
 Serial.println("-1");
 //digitalWrite(LEDPin, HIGH); 
 }
 else {

 Serial.println(distance);
// digitalWrite(LEDPin, LOW); 
 }
  //Delay 50ms before next reading.
 delay(100);
}
void deflstop()
{
  //Serial.println("stop");
  }



