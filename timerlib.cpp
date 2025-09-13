#include "timer_.cpp"
#include "serial_parser.hpp"

// Counter count;
// Example callback functions
int count_a = 0;
int count_b = 0;

void timer_cb_a() {
    Serial.print("Hello from Timer A!");
    Serial.println(count_a);
    count_a++;
}

void timer_cb_b() {
    Serial.print("Hello from Timer B!");
    Serial.println(count_b);
    count_b++;
}

// Create timers
Timer t1(timer_cb_a, 100);   // every 500 ms
Timer t2(timer_cb_b, 200); // every 1000 ms

void setup() {
    Serial.begin(115200);
    while (!Serial);
}

void loop() {
    t1.spin();
    t2.spin();
}

