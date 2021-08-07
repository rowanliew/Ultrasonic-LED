const int trigPin = 9; 
const int echoPin = 10;
const int led = 6;

long duration;
int distance;
int brightness;

void setup(){
   pinMode(trigPin,OUTPUT);
   pinMode(echoPin,INPUT);
   pinMode(led,OUTPUT);
   Serial.begin(9600); 
}

void loop() {
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2); 
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);   
    duration = pulseIn(echoPin, HIGH);    
    
    distance= duration*0.034/2;
    Serial.print("Distance: ");
    Serial.println(distance);

 
    brightness = 256-distance*16;
    if (brightness<=0){
      brightness = 0;
    }
    Serial.print("brightness:");
    Serial.println(brightness);
    analogWrite(led,brightness);

}
