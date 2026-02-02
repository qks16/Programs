int analog = A1;
int val;

void setup(){
    Serial.begin(9600);
    pinMode(analog, INPUT);
}

void loop(){
    val = analogRead(analog);
    Serial.print("value: ");
    Serial.println(val);
}