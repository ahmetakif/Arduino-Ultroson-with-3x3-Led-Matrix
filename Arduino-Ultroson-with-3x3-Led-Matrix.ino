const int trigger_pin = 2;
const int echo_pin = 4;
const int buzzer = 11;

float sure;
float mesafe;
float b1;
float b2;
float b3;
float b4;
float b5;
float b6;
float b7;
float b8;

int konum;
int x;
int y;
int z;
int c;

void setup() 
{
  pinMode(3 , OUTPUT);
  pinMode(5 , OUTPUT);
  pinMode(6 , OUTPUT);
  pinMode(9 , OUTPUT);
  pinMode(7 , OUTPUT);
  pinMode(8 , OUTPUT);
  pinMode(A0 , INPUT);
  pinMode(trigger_pin , OUTPUT);
  pinMode(echo_pin , INPUT);
  Serial.begin(9600);

  analogWrite(buzzer , 100);
  delay(300);
  analogWrite(buzzer , 0);
  delay(100);
  analogWrite(buzzer , 255);
  delay(40);
  analogWrite(buzzer , 0); 

  for (x = 0; x <= 255; x += 1)
  {
    digitalWrite(6 , HIGH);
    digitalWrite(8 , HIGH);
    delay(2);
    digitalWrite(6 , LOW);
    digitalWrite(8 , LOW);
    digitalWrite(7 , HIGH);
    digitalWrite(3 , HIGH);
    digitalWrite(5 , HIGH);
    delay(2);
    digitalWrite(7 , LOW);
    digitalWrite(3 , LOW);
    digitalWrite(5 , LOW);
    digitalWrite(9 , HIGH);
    digitalWrite(6 , HIGH);
    delay(2);
    digitalWrite(9 , LOW);
    digitalWrite(6 , LOW);
  }
  delay(650);
  for (y = 0; y <= 255; y += 1)
  {
    digitalWrite(8 , HIGH);
    delay(2);
    digitalWrite(8 , LOW);
    digitalWrite(7 , HIGH);
    digitalWrite(6 , HIGH);
    digitalWrite(3 , HIGH);
    delay(2);
    digitalWrite(7 , LOW);
    digitalWrite(6 , LOW);
    digitalWrite(3 , LOW);
    digitalWrite(9 , HIGH);
    digitalWrite(5 , HIGH);
    delay(2);
    digitalWrite(9 , LOW);
    digitalWrite(5 , LOW);
    }
  delay(650);
  for (z = 0; z <= 255; z += 1)
  {
    digitalWrite(7 , HIGH);
    delay(6);
    digitalWrite(7 , LOW);
  }
  delay(650);
  for (c = 0; c <= 255; c += 1)
  {
    digitalWrite(8 , HIGH);
    delay(2);
    digitalWrite(8 , LOW);
    digitalWrite(7 , HIGH);
    digitalWrite(3 , HIGH);
    delay(2);
    digitalWrite(7 , LOW);
    digitalWrite(3 , LOW);
    digitalWrite(9 , HIGH);
    digitalWrite(5 , HIGH);
    digitalWrite(3 , HIGH);
    delay(2);
    digitalWrite(9 , LOW);
    digitalWrite(5 , LOW);
    digitalWrite(3 , LOW);
  }
  delay(1500);
}

void loop() 
{
  digitalWrite(trigger_pin , HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigger_pin , LOW);
  sure = pulseIn(echo_pin , HIGH);
  mesafe = (sure/2) / 28.5;
  konum = analogRead(A0);
  b1 = map(konum,0,1023,1,25);
  b2 = b1 * 2;
  b3 = b2 * 2;
  b4 = b3 * 2;
  b5 = b4 * 2;
  b6 = b5 * 2;
  b7 = b6 * 2;
  b8 = b7 * 2;
  Serial.println(mesafe);
  Serial.println(b1);
  if (mesafe < b1)
  {
    digitalWrite(7 , HIGH);
    digitalWrite(6 , HIGH);
    delay(1);
  }
  else if (mesafe < b2)
  {
    digitalWrite(8 , HIGH);
    digitalWrite(6 , HIGH);
    digitalWrite(5 , HIGH);
    delay(1);
    digitalWrite(8 , LOW);
    digitalWrite(6 , LOW);
    digitalWrite(5 , LOW);
    digitalWrite(7 , HIGH);
    digitalWrite(6 , HIGH);
    digitalWrite(3 , HIGH);
    delay(1);
  }
  else if (mesafe < b3)
  {
    digitalWrite(8 , HIGH);
    digitalWrite(7 , HIGH);
    digitalWrite(6 , HIGH);
    digitalWrite(3 , HIGH);
    delay(1);
  }
  else if (mesafe < b4)
  {
    digitalWrite(8 , HIGH);
    digitalWrite(5 , HIGH);
    digitalWrite(3 , HIGH);
    delay(1);
    digitalWrite(8 , LOW);
    digitalWrite(5 , LOW);
    digitalWrite(3 , LOW);
    digitalWrite(7 , HIGH);
    digitalWrite(6 , HIGH);
    digitalWrite(3 , HIGH);
    delay(1);
  }
  else if (mesafe < b5)
  {
    digitalWrite(7 , HIGH);
    digitalWrite(3 , HIGH);
    delay(1);
  }
  else if (mesafe < b6)
  {
    digitalWrite(7 , HIGH);
    digitalWrite(6 , HIGH);
    digitalWrite(3 , HIGH);
    delay(1);
    digitalWrite(7 , LOW);
    digitalWrite(6 , LOW);
    digitalWrite(3 , LOW);
    digitalWrite(9 , HIGH);
    digitalWrite(5 , HIGH);
    digitalWrite(3 , HIGH);
    delay(1);
  }
  else if (mesafe < b7)
  {
    digitalWrite(7 , HIGH);
    digitalWrite(9 , HIGH);
    digitalWrite(6 , HIGH);
    digitalWrite(3 , HIGH);
    delay(1);
  }
  else if (mesafe < b8)
  {
    digitalWrite(7 , HIGH);
    digitalWrite(6 , HIGH);
    digitalWrite(3 , HIGH);
    delay(1);
    digitalWrite(7 , LOW);
    digitalWrite(6 , LOW);
    digitalWrite(3 , LOW);
    digitalWrite(9 , HIGH);
    digitalWrite(6 , HIGH);
    digitalWrite(5 , HIGH);
    delay(1);
  } 
  digitalWrite(8 , LOW);
  digitalWrite(7 , LOW);
  digitalWrite(9 , LOW);
  digitalWrite(6 , LOW);
  digitalWrite(5 , LOW);
  digitalWrite(3 , LOW);
}
