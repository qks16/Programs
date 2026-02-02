# 1 "C:\\Users\\Jeremiah\\Programs\\program1\\program1.ino"
int analog = A1;
int val;

void setup(){
    Serial.begin(9600);
    pinMode(analog, 0x0);
}

void loop(){
    val = analogRead(analog);
    Serial.print("value: ");
    Serial.println(val);
}
