#define in1 9
#define in2 8
#define in3 6
#define in4 7
#define enA 10
#define enB 5

int M1_Speed = 35; // speed of motor 1
int M2_Speed = 35; // speed of motor 2
int LeftRotationSpeed = 180;  // Left Rotation Speed
int RightRotationSpeed = 180; // Right Rotation Speed

void setup() {
    pinMode(in1, OUTPUT);
    pinMode(in2, OUTPUT);
    pinMode(in3, OUTPUT);
    pinMode(in4, OUTPUT);

    pinMode(enA, OUTPUT);
    pinMode(enB, OUTPUT);

    pinMode(A0, INPUT); // initialize Left sensor as an input
    pinMode(A1, INPUT); // initialize Right sensor as an input
}

void loop() {
    int LEFT_SENSOR = digitalRead(A0);
    int RIGHT_SENSOR = digitalRead(A1);

    if (RIGHT_SENSOR == 0 && LEFT_SENSOR == 0) {
        forward(); // FORWARD
    } else if (RIGHT_SENSOR == 0 && LEFT_SENSOR == 1) {
        right(); // Move Right
    } else if (RIGHT_SENSOR == 1 && LEFT_SENSOR == 0) {
        left(); // Move Left
    } else if (RIGHT_SENSOR == 1 && LEFT_SENSOR == 1) {
        Stop();  // STOP
    }
}

void forward() {
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);

    analogWrite(enA, M1_Speed);
    analogWrite(enB, M2_Speed);
}

void backward() {
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);

    analogWrite(enA, M1_Speed);
    analogWrite(enB, M2_Speed);
}

void right() {
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);

    analogWrite(enA, LeftRotationSpeed);
    analogWrite(enB, RightRotationSpeed);
}

void left() {
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);

    analogWrite(enA, LeftRotationSpeed);
    analogWrite(enB, RightRotationSpeed);
}

void Stop() {
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
}
