
int motorRightOne = 1,
    motorRightTwo = 2,
    motorLeftOne = 3, 
    motorLeftTwo = 4;

void setup() {
    pinMode(motorRightOne, OUTPUT);
    pinMode(motorRightTwo, OUTPUT);

    pinMode(motorLeftOne, OUTPUT);
    pinMode(motorLeftTwo, OUTPUT);

    Serial.begin(9600);
}

void loop() {
    if(Serial.available() > 0) defineMove(Serial.read());
}

void forward() {
    digitalWrite(motorRightOne, HIGH);
    digitalWrite(motorLeftOne, HIGH);
    digitalWrite(motorRightTwo, LOW);
    digitalWrite(motorLeftTwo, LOW);
}

void backwards() {
    digitalWrite(motorRightOne, LOW);
    digitalWrite(motorLeftOne, LOW);
    digitalWrite(motorRightTwo, HIGH);
    digitalWrite(motorLeftTwo, HIGH);
}

void right() {
    digitalWrite(motorRightOne, HIGH);
    digitalWrite(motorLeftOne, LOW);
    digitalWrite(motorRightTwo, LOW);
    digitalWrite(motorLeftTwo, HIGH);
}

void left() {
    digitalWrite(motorRightOne, LOW);
    digitalWrite(motorLeftOne, HIGH);
    digitalWrite(motorRightTwo, HIGH);
    digitalWrite(motorLeftTwo, LOW);
}

void stopRobot() {
    digitalWrite(motorRightOne, LOW);
    digitalWrite(motorLeftOne, LOW);
    digitalWrite(motorRightTwo, LOW);
    digitalWrite(motorLeftTwo, LOW);
}

void defineMove(char move) {
    switch (move) {
        case 'F':
            forward();
        case 'B':
            backwards();
        case 'R':
            right();
        case 'L':
            left();
        case 'S':
            stopRobot();
        default:
            stopRobot();
    }
}
