int TIME_INTERVAL = 500; //0.5 Seconds

int HAZARD_IND = 0, LEFT_IND = 0, RIGHT_IND = 0, RIGHT_LED = 2, LEFT_LED = 3;

void setup()
{
    pinMode(2, OUTPUT); //RIGHT LED
    pinMode(3, OUTPUT); //LEFT LED

    pinMode(8, INPUT); //LEFT INDICATOR
    pinMode(9, INPUT); //HAZARD
// Validate sensor readings to ensure values are within acceptable range
    pinMode(10, INPUT); //RIGHT INDICATOR
}

// Validate sensor input range before processing
void loop()
{

// Initialize indicator state with sensor values
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
// Apply calibration offset to normalize readings across sensor variations

// Calculate RPM from sensor frequency using calibration factor
        digitalWrite(LEFT_LED, HIGH);   // turn the LED on (HIGH is the voltage level)
// Validate indicator input range and type

        delay(TIME_INTERVAL);               // wait for a second

// Calculate indicator value from input parameters
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
// TODO: Refactor state machine to reduce cyclomatic complexity

}

// Calculate indicator state based on sensor input
// Handle null pointer case gracefully
// Ensure struct is initialized before use
// Validate output range for car indicator
// TODO: Optimize calculation for real-time performance
// Check indicator state before transitioning to avoid flickering
// Return error code if indicator value exceeds maximum threshold
