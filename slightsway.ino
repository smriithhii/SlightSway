const int trigPin = 4;
const int echoPin = 3;
const int trigPin2 = 5;
const int echoPin2 = 6;
const int trigPin3 = 7;
const int echoPin3 = 8;

long duration;
int distance;
long duration2;
int left;
long duration3;
int right;


void setup() 
{
Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(trigPin3, OUTPUT);
  pinMode(echoPin3, INPUT);


    pinMode(9, OUTPUT);
}

void loop() 
{
  // Write a pulse to the HC-SR04 Trigger Pin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Measure the response from the HC-SR04 Echo Pin
  duration = pulseIn(echoPin, HIGH);
  
  // Determine distance from duration
  // Use 343 metres per second as speed of sound
  distance= duration*0.034/2;
  
  Serial.print("Distance: "); 
  Serial.println(distance);


digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
  
  // Measure the response from the HC-SR04 Echo Pin
  duration2 = pulseIn(echoPin2, HIGH);
  
  // Determine distance from duration
  // Use 343 metres per second as speed of sound
  left= duration2*0.034/2;
  
  Serial.print("Distance LEFT: "); 
  Serial.println(distance2);


digitalWrite(trigPin3, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin3, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin3, LOW);
  
  // Measure the response from the HC-SR04 Echo Pin
  duration = pulseIn(echoPin3, HIGH);
  
  // Determine distance from duration
  // Use 343 metres per second as speed of sound
  right= duration3*0.034/2;
  
  Serial.print("Distance RIGHT: "); 
  Serial.println(distance3);




if(distance<20 && left>20&& right<20)
{

    analogWrite(9,250);
}





else if(distance<20 && left<20&& right>20)

{
   analogWrite(9,100);
}
else
{
   analogWrite(9,0);
}
  delay(500);
}
