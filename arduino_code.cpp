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
  
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT); // these are the output lights
  pinMode(12, INPUT);
  pinMode(10, INPUT);
  pinMode(6, INPUT);
  pinMode(7, INPUT);
  pinMode(9, INPUT); // the insert button
  pinMode(8, INPUT);  // the start button
  pinMode(11, OUTPUT);  // the win light
  pinMode(13, OUTPUT);  // the lose light
  
  
  //memory_game();
 
  
}

void memory_game()
{
  int lights_sim[100];
  int button_sim[100];
  int x = 1;
  int score = 0;
  while (true)
  {
    lights_sim[x] = {random_number(2,6)};
    x++;
    

    for (int i = 0; i < x; i++)
  {
    turn_on_light(lights_sim[i], 1000);   // this is for the output system
    delay(400);
    
  }
  
    
  int z = 0;
  while (true)
  {
    delay(100);
    if (digitalRead(12) == HIGH)
    { 
      button_functionality(2);
      button_sim[z+1] = 2; 
      z++;
      continue;
    }
    if (digitalRead(10) == HIGH)
    {
      button_functionality(3);
      button_sim[z+1] = 3;
      z++;
      continue;
      
    }
    
    if (digitalRead(6) == HIGH)
    {
      button_functionality(4);
      button_sim[z+1] = 4;
      z++;
      continue;
    }
    
     if (digitalRead(7) == HIGH)
    {
      button_functionality(5);
      button_sim[z+1] = 5;
      z++;
      continue;
    }
    
    if (digitalRead(9) == HIGH)
    {
      
      turn_off_all_lights();
      break;
    }
   }
  
    bool correct_inputs = true;
    
    for (int l = 0; l < x; l++)
    { 
      if (button_sim[l] != lights_sim[l])
      {
        turn_on_light(13, 2000);
        correct_inputs = false;
        break;
      }
    }
    
    if (correct_inputs)
    {
      turn_on_light(11, 2000);
      
      z++;
    }
    if (correct_inputs == false)
    {
      
      break;
    }
  }
}

void loop()
{
  if (digitalRead(8 == LOW))
  {
    memory_game();
  }
}
