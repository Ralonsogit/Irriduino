// Add libraries
#include <Time.h>
#include <TimeLib.h>

// Set pin 4 for the relay
int input_relay = 4;

// This function is going to be executed once
void setup() {
    // Set the relay as an output signal
    pinMode(input_relay, OUTPUT);
    // Swicht off the relay
    digitalWrite(input_relay, HIGH);
}

// This function is going to be executed as an infinite loop
void loop() {
    // Toggle relay signal waiting 3 secs between each one
    digitalWrite(input_relay, LOW);
    delay(3000);
    digitalWrite(input_relay, HIGH);
    delay(3000);
}
