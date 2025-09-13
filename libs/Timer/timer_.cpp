#include <Arduino.h>
class Timer {
private:
    void (*callback)();    // function pointer
    unsigned long period;  // ms
    unsigned long lastRun; // last execution time

public:
    Timer(void (*cb)(), unsigned long interval)
        : callback(cb), period(interval), lastRun(0) {}

    void spin() {
        unsigned long now = millis();
        if (now - lastRun >= period) {
            lastRun = now;
            if (callback) {
                callback();
            }
        }
    }
};
