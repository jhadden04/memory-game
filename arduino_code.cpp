int random_number(int num1, int num2)  // function to easily get random numbers
{
  randomSeed(analogRead(0));  // creates the seed for the random number
  return random(num1, num2);   // returns a random number from the inputted range
  
}

void turn_on_light(int ledpin_number, int time_on)  // function to easily turn 
  // on lights, for a set time, before turning it off
{
  digitalWrite(ledpin_number, HIGH);
  delay(time_on);
  digitalWrite(ledpin_number, LOW);
}

void turn_off_light(int pin_number, int time_off) // turns off the lights function
{
  digitalWrite(pin_number, LOW);
  delay(time_off);
}

void turn_off_all_lights() // functions that loops through all the pins
  // and turns everything off
{
    for (int i = 0; i < 14; i++)
    {
    digitalWrite(i, LOW);
    }
}
void button_functionality(int led_pin)
  // the functionality for turning on the light when the adjacent button is 
  // clicked
{
    digitalWrite(led_pin, HIGH);  // uses previous functions
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
  pinMode(7, INPUT);  // these are the input buttons
  pinMode(9, INPUT); // the insert button
  pinMode(8, INPUT);  // the start button
  pinMode(11, OUTPUT);  // the win light
  pinMode(13, OUTPUT);  // the lose light
  
  
}

void memory_game()  // the main memory game function
{
  int lights_sim[100];  // where the order of the lights
  // inputs and outputs are stored
  int button_sim[100];
  int x = 1;  // used for looping
  int score = 0;  // score
  while (true)
  {
    lights_sim[x] = {random_number(2,6)};  // adds 1 random number
    // to the lights list
    x++;
    
    for (int i = 0; i < x; i++)  // loops through lights list
      // and turns on the relevant lights
  {
    turn_on_light(lights_sim[i], 1000);  
    delay(400);
    
  }
  
    
  int z = 0;
  while (true)  // loop to get the inputs
  {
    delay(100); // delay to make the lights look better
    
    if (digitalRead(12) == HIGH)  // if a certain button is pressed
      
    { 
      button_functionality(2); // it will turn on
      button_sim[z+1] = 2; // be added to the list
      // to check if it is the right order
      z++;
      continue;  // breaks the loop, and waits for next input
      // or insert button
    }
    if (digitalRead(10) == HIGH)  // this function is repeated for 
      // each light/button
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
    
    if (digitalRead(9) == HIGH)  // insert button
    {
      turn_off_all_lights();
      break;  // breaks the loop, and continues on for it to
      // be checked if it is right.
    }
   }
  
    bool correct_inputs = true;  // declares the right/wrong boolian
    
    for (int l = 0; l < x; l++) // loops through the button input lists
      // and the original order list, and checks if they are the same
    { 
      if (button_sim[l] != lights_sim[l])  // if they aren't 
      {
        turn_on_light(13, 2000);  // turn on wrong light
        correct_inputs = false;  // make the bool false
        break;  // break out of the loop
      }
    }
    
    if (correct_inputs) // if it gets througth the loop without being wrong
    {
      turn_on_light(11, 2000); // turn on the correct light
      
      z++; // add to the z, which continues the loop, but adds another number
      // to the pattern
    }
    if (correct_inputs == false)
    {
      break;  // fully breaks the loop
      // this is game over
    }
  }
}

void loop()
{
  if (digitalRead(8 == HIGH))  // checks if the start button is pressed
  {
    memory_game();   // starts the memory game
  }
}
