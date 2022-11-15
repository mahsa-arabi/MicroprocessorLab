const int BUTTON = 0;  // Pushbutton Input to Pin No.0
const int LED1 = 13;   // Output LED1 to Pin No. 13
const int LED2 = 12;
const int LED3 = 8;
const int LED4 = 7;
const int LED5 = 4;
const int LED6 = 1;
const int LED7 = 14;
const int LED8 = 15;

int delay_time = 50; //Define delay_time as 50 ms time each led blink

int BUTTONState = 0;  // To store input status

void setup() {
  pinMode(LED1, OUTPUT); // Define LED1 pin as Output.
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  pinMode(LED6, OUTPUT);
  pinMode(LED7, OUTPUT);
  pinMode(LED8, OUTPUT);
  pinMode(BUTTON, INPUT);  // Define BUTTON pin as Input.
}


void loop() {
  BUTTONState = digitalRead(BUTTON);  // Reading input from Button Pin.

    if (BUTTONState == HIGH)  // Checking if Input from button is HIGH (1/+5V)
    {
      digitalWrite(LED1, HIGH);  //set LED1 to HIGH
      delay(delay_time);

      digitalWrite(LED2, HIGH);  //set LED2 to HIGH
      digitalWrite(LED1, LOW);  //set LED1 to HIGH
      delay(delay_time);
      digitalWrite(LED3, HIGH);
      digitalWrite(LED2, LOW);


      delay(delay_time);
      digitalWrite(LED4, HIGH);
      digitalWrite(LED3, LOW);


      delay(delay_time);
      digitalWrite(LED5, HIGH);
      digitalWrite(LED4, LOW);


      delay(delay_time);
      digitalWrite(LED6, HIGH);
      digitalWrite(LED5, LOW);


      delay(delay_time);
      digitalWrite(LED7, HIGH);
      digitalWrite(LED6, LOW);


      delay(delay_time);
      digitalWrite(LED8, HIGH);
      digitalWrite(LED7, LOW);

      delay(delay_time);
      digitalWrite(LED8, LOW);

   


    } else {
      digitalWrite(LED1, LOW);
      digitalWrite(LED2, LOW);
      digitalWrite(LED3, LOW);
      digitalWrite(LED4, LOW);
      digitalWrite(LED5, LOW);
      digitalWrite(LED6, LOW);
      digitalWrite(LED7, LOW);
      digitalWrite(LED8, LOW);
    }
  }
