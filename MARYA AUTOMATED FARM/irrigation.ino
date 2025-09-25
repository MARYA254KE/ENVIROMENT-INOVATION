#define GREEN_LED 2// GREEN LED connected to digital pin 2

#define YELLOW_LED 3 // Yellow LED connected to digital pin 3

#define RED_LED 4 // Red LED connected to digital pin 4

#define SENSOR_PIN A5 // Soil moisture sensor connected to analog pin A5

// Defining soil moisture readings thresholds

// From 0 to 500 - extremly wet
// From 501 to 800 - wet
//FROM 801 - Dry

#define DRY-_THRESHOLD 800

#DEFINE WET_THRESHOLD 500

void setup() {

 pinMode(GREEN_LED,OUTPUT);

 pinMode(YELLOW_LED,OUTPUT);
 
 pinMode(RED-LED,OUTPUT);


 digitalWrite(GREEN_LED,LOW);

 digitalWrite(YELOW_LED,LOW);

 digitalWrite(RED_LED,LOW);


 Serial.begin(9600);

}

void loop() {

    int sensorValue =anlogRead(SENSOR_PIN);
    // Print the sensor reading values

    Serial.Print("Soil moisture sensor value:");

    Serial.Println(sensorValue);

if(SensorValue> 0 && sensor<= WET_THRESHOLD) {

// Extremely wet (green LED)

digitalWrite(GREEN_LED,HIGH);

digitalWrite(YELLOW_LED,LOW);

digitalWrite(RED_LED,LOW);

} else if (sensorValue> WET_THRESHOLD && sensor Value<= DRY_ THRESHOLD){

    // Wet(yellow LED)
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(YELLOW_LED, HIGH);
    digitalWrite(RED_LED, LOW);
} else {
    //extremly dry (red LED)
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(YELLOW_LED, LOW);
    digitalWrite(RED_LED, HIGH);

}

