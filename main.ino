// Libraries
#include <Time.h>
#include <TimeLib.h>

// Set pin 4 for the relay
int input_relay = 4;
// Set start and stop hours (0-23) and minutes (0-59)
byte start_hour = 1, start_minute = 11;
byte stop_hour = 1, stop_minute = 12;

// This function is going to be executed once
void setup() {
    // Set the relay as an output signal
    pinMode(input_relay, OUTPUT);
    // Swicht off the relay
    digitalWrite(input_relay, HIGH);
    // Set time manually
    setTime(1, 10, 00, 8, 5, 2018);
}

// This function is going to be executed as an infinite loop
void loop() {
    // Show actual time
    Serial.print("It's ");
    Serial.print(String(hour()) + ":" + String(minute()) + ":" + String(second()));

    // Check if it is irrigation time
    if (isIrrigationTime()) {
        Serial.println("It's irrigation time !!");
        digitalWrite (input_relay, HIGH);
    }
    else {
        Serial.println("NOT irrigation time");
        digitalWrite (input_relay, LOW);
    }
    delay(1000);
}

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
