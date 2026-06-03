// C++ code
//
void setup()
{
  pinMode(3, OUTPUT);
}

void loop()
{
  digitalWrite(LED_BUILTIN, HIGH);
  delay(2000); // Wait for 1000 millisecond(s)
  digitalWrite(3, LOW);
  delay(2000); // Wait for 1000 millisecond(s)
}