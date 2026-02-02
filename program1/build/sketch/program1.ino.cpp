#include <Arduino.h>
#line 1 "C:\\Users\\Jeremiah\\Programs\\program1\\program1.ino"
int analog = A1;
int val;

#line 4 "C:\\Users\\Jeremiah\\Programs\\program1\\program1.ino"
void setup();
#line 9 "C:\\Users\\Jeremiah\\Programs\\program1\\program1.ino"
void loop();
#line 4 "C:\\Users\\Jeremiah\\Programs\\program1\\program1.ino"
void setup(){
    Serial.begin(9600);
    pinMode(analog, INPUT);
}

void loop(){
    val = analogRead(analog);
    Serial.print("value: ");
    Serial.println(val);
}
