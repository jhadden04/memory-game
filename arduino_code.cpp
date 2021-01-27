int random_number(int num1, int num2)
{
  randomSeed(analogRead(0));
  return random(num1, num2);
  
}

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
void button_functionality(int led_pin)
{
    
    digitalWrite(led_pin, HIGH);
    delay(400);
    turn_off_all_lights();
}
  



void setup()
{ 
  Serial.begin(9600); 
  int lights_sim[1] = {11};
  int button_sim[0];
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
    turn_off_light(lights_sim[i], 100);
    
  }
  
  
  
  int z = 0;
  while (true)
  {
    delay(100);
    if (digitalRead(12) == HIGH)
    { 
      //Serial.print(13);
      
      button_functionality(13);
      button_sim[z] = 13; 
      z++;
      continue;
    }
    if (digitalRead(10) == HIGH)
    {
      button_functionality(11);
      button_sim[z] = 11;
      z++;
      continue;
    }
    
    if (digitalRead(9) == HIGH)
    {
      Serial.print("we're out ");
      turn_off_all_lights();
      break;
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
    //memory_game();
  }
  
}
