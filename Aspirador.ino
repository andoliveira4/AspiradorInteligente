int IN1 = 8;
int IN2 = 9;
int IN3 = 10;
int IN4 = 11;
int IN5 = 0;
int IN6 = 1;
int ENA = 6;
int ENB = 5;

int trig_pin = 13;
int echo_pin = 12;
long cm = 0;



void setup()
{
  	Serial.begin(9600);
	pinMode(IN1, OUTPUT);
	pinMode(IN2, OUTPUT);
	pinMode(IN3, OUTPUT);
	pinMode(IN4, OUTPUT);
}

void loop()
{  
  chamaAPIdeIA();
  cm = readUltrasonicDistance(trig_pin, echo_pin);

  Serial.print(cm);
  Serial.println("cm"); 
  
  digitalWrite(IN5, HIGH);
  //digitalWrite(IN6, LOW);  
  
  if (cm <= 100) {
    
	analogWrite(ENA,255);  	
	analogWrite(ENB,255); 
	digitalWrite(IN1, HIGH);
	digitalWrite(IN2, LOW);
	digitalWrite(IN3, LOW);
	digitalWrite(IN4, LOW);
  }
  else
  {
	analogWrite(ENA,255);  	
  	analogWrite(ENB,255); 
	digitalWrite(IN1, HIGH);
	digitalWrite(IN2, LOW);
	digitalWrite(IN3, HIGH);
	digitalWrite(IN4, LOW);
  }
  

  //delay(100); // Wait for 100 millisecond(s)
}

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds *0.01723
  return (pulseIn(echoPin, HIGH)*0.01723);
  
}

void chamaAPIdeIA () {
  Serial.print("TO DO");
}

