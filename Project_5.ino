// Project 5 - Controlling Traffic
// define the pins that the buttons and lights are connected to:1 
#define pedSwitch 4 
#define pedLight 5
#define westButton 3
#define eastButton 13
#define westRed 2
#define westYellow 1
#define westGreen 0
#define eastRed 12
#define eastYellow 11
#define eastGreen 10
#define yellowBlinkTime 500 // 0.5 seconds for yellow light blink  
boolean trafficWest = true; // west = true, east = false
int flowTime = 2000;       // amount of time to let traffic flow 
int changeDelay = 500;     // amount of time between color changes
void setup()
{ // set up the digital I/O pins
  pinMode(westButton, INPUT);
  pinMode(pedSwitch, INPUT);
  pinMode(pedLight, OUTPUT);  
  pinMode(eastButton, INPUT);
  pinMode(westRed, OUTPUT);
  pinMode(westYellow, OUTPUT);
  pinMode(westGreen, OUTPUT);
  pinMode(eastRed, OUTPUT);
  pinMode(eastYellow, OUTPUT);
  pinMode(eastGreen, OUTPUT); // set initial state for lights - west side is green first
  digitalWrite(westRed, LOW);
  digitalWrite(westYellow, LOW);
  digitalWrite(westGreen, HIGH);
  digitalWrite(eastRed, HIGH);
  digitalWrite(eastYellow, LOW);
  digitalWrite(eastGreen, LOW);
}

void loop()
{ if ( digitalRead(westButton) == HIGH ) // request west>east traffic flow
  { if ( trafficWest != true )  // only continue if traffic flowing in the opposite (east) direction
    { trafficWest = true; // change traffic flow flag to west>east
      delay(flowTime);    // give time for traffic to flow
      digitalWrite(eastGreen, LOW); // change east-facing lights from green  // to yellow to red
      digitalWrite(eastYellow, HIGH);
      delay(changeDelay);
      digitalWrite(eastYellow, LOW);
      digitalWrite(eastRed, HIGH);
      delay(changeDelay);
      for 
      ( int a = 0; a < 5; a++ ) // blink yellow light
      { digitalWrite(westYellow, LOW);
        delay(yellowBlinkTime);
        digitalWrite(westYellow, HIGH);
        delay(yellowBlinkTime);
      }
      digitalWrite(westYellow, LOW);
      digitalWrite(westRed, LOW); // change west-facing lights from red // to green
      digitalWrite(westGreen, HIGH);
    }
  }
  if ( digitalRead(eastButton) == HIGH ) // request east>west traffic flow
  {
    if ( trafficWest == true )  // only continue if traffic flow is in the opposite (west) direction
    {
      trafficWest = false; // change traffic flow flag to east>west
      delay(flowTime);     // give time for traffic to flow
      digitalWrite(westGreen, LOW);  // change west-facing lights from green to yellow to red
      digitalWrite(westYellow, HIGH);
      delay(changeDelay);
      digitalWrite(westYellow, LOW);
      digitalWrite(westRed, HIGH);
      delay(changeDelay);
      for ( int a = 0 ; a < 5; a++ ) // blink yellow light
      {
        digitalWrite(eastYellow, LOW);
        delay(yellowBlinkTime);
        digitalWrite(eastYellow, HIGH);
        delay(yellowBlinkTime);
      }
      digitalWrite(eastYellow, LOW);
      digitalWrite(eastRed, LOW); // change east-facing lights from red // to green
      digitalWrite(eastGreen, HIGH);
    }
  }
 if ( digitalRead(pedSwitch) == HIGH ) // request east>west traffic flow
  {
    if ( trafficWest == true )  // only continue if traffic flow is in the opposite (west) direction
    {
      trafficWest = false; // change traffic flow flag to east>west
      delay(flowTime);     // give time for traffic to flow
      digitalWrite(westGreen, LOW);  // change west-facing lights from green to yellow to red
      digitalWrite(westYellow, HIGH);
      delay(changeDelay);
      digitalWrite(westYellow, LOW);
      digitalWrite(westRed, HIGH);
      digitalWrite(pedLight, HIGH);
      delay(20000);
      for ( int a = 0 ; a < 10 ; a++ ) // blink yellow light
      {
        digitalWrite(pedLight, LOW);
        delay(yellowBlinkTime);
        digitalWrite(pedLight, HIGH);
        delay(yellowBlinkTime);
      }
       digitalWrite(pedLight, LOW);
      digitalWrite(eastYellow, LOW);
      digitalWrite(eastRed, LOW); // change east-facing lights from red // to green
      digitalWrite(eastGreen, HIGH);

    }
    else 
    {
      trafficWest = true; // change traffic flow flag to east>west
      delay(flowTime);     // give time for traffic to flow
      digitalWrite(eastGreen, LOW);  // change west-facing lights from green to yellow to red
      digitalWrite(eastYellow, HIGH);
      delay(changeDelay);
      digitalWrite(eastYellow, LOW);
      digitalWrite(eastRed, HIGH);
      digitalWrite(pedLight, HIGH);
      delay(20000);
      for ( int a = 0 ; a < 10 ; a++ ) // blink yellow light
      {
        digitalWrite(pedLight, LOW);
        delay(yellowBlinkTime);
        digitalWrite(pedLight, HIGH);
        delay(yellowBlinkTime);
      }
       digitalWrite(pedLight, LOW);
      digitalWrite(westYellow, LOW);
      digitalWrite(westRed, LOW); // change east-facing lights from red // to green
      digitalWrite(westGreen, HIGH);
    }
  }




  
}
