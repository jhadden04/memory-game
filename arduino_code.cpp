
void turn_on_light(int ledpin_number, int time_on)
{
  digitalWrite(ledpin_number, HIGH);
  delay(time_on);
  digitalWrite(ledpin_number, LOW);
}

void turn_off_light(int pin_number, int time_off)
{
  digitalWrite(pin_number, LOW);
  delay(time_off);
}

void turn_off_all_lights()
{
    for (int i = 0; i < 14; i++)
    {
    digitalWrite(i, LOW);
    }
}
void button_functionality(button_pin, led_pin)
{
  if (digitalRead(button_pin) == HIGH)
  {
    turn_off_all_lights();
    digitalWrite(led_pin, HIGH);
    
  } 
}
  

int rand_int()
{
  return random(1,3);
}
void setup()
{ 
  Serial.begin(9600);
  
  randomSeed(20);
  int lights_sim[100] = {11};
  int button_sim[100];
  // button_sim[0] = rand_int();
  // Serial.print(button_sim[0]);
  
  
  pinMode(13, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, INPUT);
  pinMode(10, INPUT);
  pinMode(9, INPUT);
  
    for (int i = 0; i < sizeof(lights_sim); i++)
  {
    turn_on_light(lights_sim[i], 1000);   // this is for the output system
    turn_off_light(lights_sim[i], 200);
    
  }
  
  
  
  
  while (true)
  {
    delay(100);
    if (digitalRead(12) == HIGH)
    {
      button_functionality(12, 13);
      button_sim[z] = 13; 
      z++;
      continue;
    }
    if (digitalRead(10) == HIGH)
    {
      button_functionality(10, 11);
      button_sim[z] = 12;
      z++;
      continue;
    }
    
    if (digitalRead(9) == HIGH)
    {
      turn_off_all_lights();
      break;
    }
    if (button_sim[100] == lights_sim[100])
    {
      Serial.print("you won");
    }
    if (button_sim[100] != lights_sim[100])
    {
      Serial.print("you lose");
    }
  }

  

  
  
}

void memory_game()
{
}



void loop()
{
  
  if (digitalRead(9) == HIGH)
  {
    memory_game();
  }
  
}
