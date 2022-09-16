/*
  LINK TO PROJECT: https://www.tinkercad.com/things/dPp9LauB1Xn-traffic-light-system/editel?sharecode=vKT5SX8fExkYxlbiba4xzqqhDJus08wvdXsHN0NuwS0 
  NAME: Helen Hua
  EMAIL: helehua@student.ubc.ca
  DATE: April 26, 2022	
  PURPOSE: To make a traffic light that pedestrians can control
 			When they want to cross the road, the can press the 
            push button which turns the lights yellow then red,
            signalling the cars to slow and stop for them.
*/

// index of horizontal pins
int const buttonPinH = 2;    
int const ledGreenH = 13;     
int const ledYellowH = 12;      
int const ledRedH = 11;      

// index of vertical pins
int const buttonPinV = 3;
int const ledGreenV = 10;
int const ledYellowV = 9;
int const ledRedV = 8;

void setup()
{
  pinMode(ledGreenH, OUTPUT);
  pinMode(ledYellowH, OUTPUT);
  pinMode(ledRedH, OUTPUT);
  pinMode(ledGreenV, OUTPUT);
  pinMode(ledYellowV, OUTPUT);
  pinMode(ledRedV, OUTPUT);
  
  pinMode(buttonPinH, INPUT);
  pinMode(buttonPinV, INPUT);
}

void loop()
{
  //initiates variables for the millis() function
  unsigned long timeH;
  unsigned long timeTwoH;
  unsigned long timeHeldH;
  
  unsigned long timeV;
  unsigned long timeTwoV;
  unsigned long timeHeldV;
  
  //Initially, turns the green light for cars to drive horizontally 
  
  if(digitalRead(ledGreenH) == 1)
  {
    digitalWrite(ledGreenH,1);
    digitalWrite(ledYellowH,0);
    digitalWrite(ledRedH,0);

    digitalWrite(ledGreenV,0);
    digitalWrite(ledYellowV,0);
    digitalWrite(ledRedV,1);
  }
  
  else if(digitalRead(ledGreenV) == 1)
  {
    digitalWrite(ledGreenH,0);
    digitalWrite(ledYellowH,0);
    digitalWrite(ledRedH,1);

    digitalWrite(ledGreenV,1);
    digitalWrite(ledYellowV,0);
    digitalWrite(ledRedV,0);
  }
  
  else
  {
    digitalWrite(ledGreenH,1);
    digitalWrite(ledYellowH,0);
    digitalWrite(ledRedH,0);

    digitalWrite(ledGreenV,0);
    digitalWrite(ledYellowV,0);
    digitalWrite(ledRedV,1);
  }

  //assigns the current time to both time and timeTwo
  timeH = millis();
  timeTwoH = millis();
  
  timeV = millis();
  timeTwoV = millis();
  
  /*delays for 0.5 seconds and if the button is stil held down, 
    then timeTwo will be the recorded as the time after 0.5 seconds
    if the button is no longer held, the loop exits and timeTwo
    will be equal to time, thus signifying that the user didn't
    hold the button for more than 0.5 seconds*/
  if(digitalRead(buttonPinH) == 1)
  {
    delay (500);
    
    if(digitalRead(buttonPinH) == 1)
    {
      timeTwoH = millis();
    }
  } 
  	
  if(digitalRead(buttonPinV) == 1)
  {
    delay (500);
    
    if(digitalRead(buttonPinV) == 1)
    {
      timeTwoV = millis();
    }
  }
  
  //Calculates how long each button was held for
  timeHeldH = timeTwoH-timeH;
  timeHeldV = timeTwoV-timeV;
  
  /*If the vertical button is pressed and held for atleast 0.5 
  seconds,the horizontal green light will turn off and horizontal
  yellow will turn on for 2 seconds. The horizontal yellow will 
  then turn off and the horizontal red will turn on for 5 seconds
  and turn vertical green on.*/
  if(digitalRead(buttonPinV) == 1 && timeHeldV >= 500UL && digitalRead(ledGreenH) == 1)
  {
    //After the button is pressed and released, delay for 2 seconds
    if(digitalRead(buttonPinV == 0))
    {
      delay(2000);

      //Turns the green light off and yellow on
      digitalWrite(ledGreenH,0);
      digitalWrite(ledYellowH,1);

      //delay and keep the yellow light on for 3 seconds
      delay(3000);

      //Turns yellow light off and red on
      digitalWrite(ledYellowH,0);
      digitalWrite(ledRedH,1);

      //Turns on vertical green and vertical red off
      digitalWrite(ledGreenV,1);
      digitalWrite(ledRedV,0);
    }
       
  }
       
  if(digitalRead(buttonPinH) == 1 && timeHeldH >= 500UL && digitalRead(ledGreenV) == 1)
  {
    //After the button is pressed and released, delay for 2 seconds
    if(digitalRead(buttonPinH == 0))
       {
         delay(2000);
    
         //Turns the green light off and yellow on
         digitalWrite(ledGreenV,0);
         digitalWrite(ledYellowV,1);

         //delay and keep the yellow light on for 3 seconds
         delay(3000);

         //Turns yellow light off and red on
         digitalWrite(ledYellowV,0);
         digitalWrite(ledRedV,1);
         
         //Turns on vertical green and vertical red off
         digitalWrite(ledGreenH,1);
         digitalWrite(ledRedH,0);
       }
       
  }
  
}
