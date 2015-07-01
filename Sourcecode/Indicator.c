int TIME_INTERVAL = 500; //0.5 Seconds

int HAZARD_IND = 0, LEFT_IND = 0, RIGHT_IND = 0, RIGHT_LED = 2, LEFT_LED = 3;

void setup()
{
    pinMode(2, OUTPUT); //RIGHT LED
    pinMode(3, OUTPUT); //LEFT LED

    pinMode(8, INPUT); //LEFT INDICATOR
    pinMode(9, INPUT); //HAZARD
    pinMode(10, INPUT); //RIGHT INDICATOR
}

void loop()
{

    HAZARD_IND = digitalRead(9);
    LEFT_IND = digitalRead(8);
    RIGHT_IND = digitalRead(10);

    //Hazard Code

    if (digitalRead(HAZARD_IND) == 0) {

        digitalWrite(LEFT_LED, HIGH);
        digitalWrite(RIGHT_LED, HIGH);  // turn on both the LEDs

        delay(TIME_INTERVAL);               // wait one a second

        digitalWrite(LEFT_LED, LOW);
        digitalWrite(RIGHT_LED, LOW);   // turn off both the LEDs

        delay(TIME_INTERVAL);               // wait for a second
    }

    //Left Indicator Code

    if (digitalRead(LEFT_IND) == 0 && digitalRead(HAZARD_IND) != 0) {

        digitalWrite(LEFT_LED, HIGH);   // turn the LED on (HIGH is the voltage level)

        delay(TIME_INTERVAL);               // wait for a second

        digitalWrite(LEFT_LED, LOW);    // turn the LED off by making the voltage LOW

        delay(TIME_INTERVAL);               // wait for a second
    }

    //Right Indicator Code

    if (digitalRead(RIGHT_IND) == 0 && digitalRead(HAZARD_IND) != 0) {

        digitalWrite(RIGHT_LED, HIGH);   // turn the LED on (HIGH is the voltage level)

        delay(TIME_INTERVAL);                // wait for a second

        digitalWrite(RIGHT_LED, LOW);    // turn the LED off by making the voltage LOW

        delay(TIME_INTERVAL);                // wait for a second
    }

}

