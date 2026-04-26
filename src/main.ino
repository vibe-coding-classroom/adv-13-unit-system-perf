#include "../include/perf_config.h"
#include "../include/protocol_v2.h"

// Forward declarations for profiler (implemented in SystemProfiler.cpp)
extern void startProfile(int node);
extern void endProfile(int node);
extern void printProfileReport();

CompactData systemData;
char msgBuffer[64];

void setup() {
    Serial.begin(115200);
    systemData.speed = 0;
    systemData.angle = 0;
    systemData.timestamp = 0;
}

void loop() {
    startProfile(PERF_NODE_TOTAL_LOOP);

    // 1. Sensor Reading
    startProfile(PERF_NODE_SENSOR_READ);
    // Simulate sensor read delay
    delayMicroseconds(500); 
    systemData.speed = random(-100, 100);
    systemData.angle = random(-45, 45);
    systemData.timestamp = millis();
    endProfile(PERF_NODE_SENSOR_READ);

    // 2. PID Calculation
    startProfile(PERF_NODE_PID_CALC);
    // Simulate complex math
    delayMicroseconds(1200);
    endProfile(PERF_NODE_PID_CALC);

    // 3. Protocol Encoding
    startProfile(PERF_NODE_PROTOCOL_ENC);
    encodeProtocolV2(msgBuffer, systemData);
    endProfile(PERF_NODE_PROTOCOL_ENC);

    // 4. Serial Transmission
    startProfile(PERF_NODE_SERIAL_TX);
    Serial.print(msgBuffer);
    endProfile(PERF_NODE_SERIAL_TX);

    endProfile(PERF_NODE_TOTAL_LOOP);

    // Periodically print the performance report
    static unsigned long lastReport = 0;
    if (millis() - lastReport > 5000) {
        printProfileReport();
        lastReport = millis();
    }
}
