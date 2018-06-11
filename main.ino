// Libraries
#include <Time.h>
#include <TimeLib.h>

/* EDITABLE VARIABLES */
// Set pin for the relay
const int relay = 4;
// Set pin for the button
const int irrigation_btn = 2;
// Irrigation duration IN SECONDS
int irrigation_duration = 5;

/* Non editable variables */
// State of the button
int state_btn = 0;
// Init start time
int start_time = -1;
// Set start and stop hours (0-23) and minutes (0-59)
// byte start_hour = 1, start_minute = 11;
// byte stop_hour = 1, stop_minute = 12;

// This function is going to be executed once
void setup() {
    // Set the monitor serial up
    Serial.begin(9600);
    // Set as an output signal
    pinMode(relay, OUTPUT);
    // Set as an input signal
    pinMode(irrigation_btn, INPUT);
    // Swicht off the relay
    digitalWrite(relay, HIGH);
    // Set time manually
    setTime(1, 10, 00, 8, 5, 2018);
}

// This function is going to be executed as an infinite loop
void loop() {
    // Show current time
    Serial.print("It's ");
    Serial.print(String(hour()) + ":" + String(minute()) + ":" + String(second()));
    Serial.println();

    state_btn = digitalRead(irrigation_btn);

    // Irrigation ON when button pressed, OFF when button pressed again
    if (digitalRead(relay) == LOW) { // Relay ON
        if (state_btn == HIGH) {
            digitalWrite(relay, HIGH);
            delay(2000);
        }
    } else if (digitalRead(relay) == HIGH) {
        if (state_btn) {
            digitalWrite(relay, LOW);
            delay(2000);
        }
    }

    /* Irrigation when button pressed, OFF after irrigation_duration seconds
    // If button pressed, switch the relay ON
    if (inIrrigation() == true) {
        // Show current time
        Serial.print("It's ");
        Serial.print(String(hour()) + ":" + String(minute()) + ":" + String(second()));
        Serial.println();
        // Relay ON
        // digitalWrite(relay, LOW);
        Serial.print("Relay ON");
        Serial.println();
        Serial.println();
    } else if (state_btn == HIGH) {
        // Seconds now
        start_time = (hour() * 3600) + (minute() * 60) + second();
        // Relay ON
        digitalWrite(relay, LOW);
        // Show current time
        Serial.print("It's ");
        Serial.print(String(hour()) + ":" + String(minute()) + ":" + String(second()));
        Serial.println();
    } else {
        // Relay OFF
        digitalWrite(relay, HIGH);
        Serial.print("Relay OFF. Click the button to turn the relay on");
        Serial.println();
    }

    /* Irrigation at some time
    // Check if it is irrigation time
    if (isIrrigationTime()) {
        Serial.println("It's irrigation time !!");
        digitalWrite(relay, HIGH);
    }
    else {
        Serial.println("NOT irrigation time");
        digitalWrite(relay, LOW);
    }
    */
}

/*
boolean inIrrigation() {
    // Seconds now
    int now_time = (hour() * 3600) + (minute() * 60) + second();
    // If time is between start and stop time... It's irrigation time !
    if (start_time != -1 && (start_time <= now_time) && (now_time < (start_time + irrigation_duration))) {
        // Irrigation time! =D
        return true;
    } 
    else {
        // Not irrigation time :(
        return false;
    }
}
*/
/*
boolean isIrrigationTime() {
    // Convert hours to minutes in order to compare
    int start_time = (start_hour * 60) + start_minute;
    int stop_time = (stop_hour * 60) + stop_minute;
    int now_time = (hour() * 60) + minute();

    // If time is between start and stop time... It's irrigation time !
    if ((start_time <= now_time) && (now_time < stop_time)) {
        // Irrigation time! =D
        return true;
    } 
    else {
        // Not irrigation time :(
        return false;
    }
}
*/
