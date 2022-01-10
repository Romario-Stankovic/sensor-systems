//Distance sensor
#define TRIGGER 13
#define ECHO 12
//DC Motor
#define MOTOR_INPUT1 11
#define MOTOR_INPUT2 10
//Optical Encoder
#define CHANNEL_A 3
#define CHANNEL_B 2
//Variables
int slitCount = 0;            //Number of slits which passed the encoder
long previousTime = 0;        //Last time we measured rad/s
double rps = 0;               //Measured Radians per second (rad/s)
const int soundSpeed = 343;   //Speed of sound at room temperature
const int maxSlits = 416;     //Number of slits on the encoder disc
const int minDistance = 2;    //Minimum distance the Ultrasonic Sensor can measure
const int maxDistance = 336;  //Maximum distance the Ultrasonic Sensor can measure
void setup() {
    //Set distance sensor pin modes
    pinMode(TRIGGER, OUTPUT);
    pinMode(ECHO, INPUT);
    //Set DC Motor pin modes
    pinMode(MOTOR_INPUT1, OUTPUT);
    pinMode(MOTOR_INPUT2, OUTPUT);
    //Set Optical encoder pin modes
    pinMode(CHANNEL_A, INPUT_PULLUP);
    pinMode(CHANNEL_B, INPUT_PULLUP);
    //Attach interrupt function to encoder A channel
    attachInterrupt(digitalPinToInterrupt(CHANNEL_A), countSlit, CHANGE);
    //Enable serial monitoring
    Serial.begin(9600);
}
void loop() {
    //Measure distance
    double distance = measureDistance();
    //1ms delay before continuing
    delay(1);
    //Apply power to the DC motor
    powerMotor(map(distance, minDistance, maxDistance, 0, 255), false);
    //1ms delay before continuing
    delay(1);
    //Measure linear speed of the rotating disc with radius of 30cm (0.30m)
    double speed = measureLinearVelocity(0.30);
    //Print the speed
    Serial.print(speed);
    Serial.println(" m/s");
}
void countSlit() {
    //Increment the counter when a slit passes
    slitCount++;
}
//Apply power to the DC motor
void powerMotor(int value, bool reverse) {
    //Check if we reversed polarity and apply the value to the corresponding pins
    if (reverse == false) {
        analogWrite(MOTOR_INPUT1, value);
        analogWrite(MOTOR_INPUT2, 0);
    } else {
        analogWrite(MOTOR_INPUT1, 0);
        analogWrite(MOTOR_INPUT2, value);
    }
}
//Measure linear velocity and return m/s as a result
double measureLinearVelocity(double discRadiusM) {
    //Count time passed since the board started running the program
    long currentTime = millis();
    if (currentTime - previousTime > 1000) {
        //If one second passed, calculate RPS
        previousTime = currentTime;
        //rad/s is equal to % of slits passed * TWO_PI (full cicrle)
        rps = (double)slitCount / maxSlits * TWO_PI;
        //Reset the slit counter
        slitCount = 0;
    }
    //Calculate velocity as: V = W * r, where W is rad/s and r is the disc radius in m
    double velocity = discRadiusM * rps;
    //Return linear speed in m/s
    return velocity;
}
//Measure distance and return centimeters as a result
double measureDistance() {
    //Trigger the sensor to emmit a sound pusle for 10 micro seconds
    digitalWrite(TRIGGER, LOW);
    delayMicroseconds(5);
    digitalWrite(TRIGGER, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIGGER, LOW);
    //Measure the pulse duration when high(5V)
    long pusleDuration = pulseIn(ECHO, HIGH);
    //Convert the speed of sound from m/s to cm/us
    //Speed = SOUNDSPEED * 100/1000000
    double speed = soundSpeed / 10000.0;
    //Calculate the distance
    double distance = (pusleDuration * speed) / 2.0;
    //Return distance
    return distance;
}