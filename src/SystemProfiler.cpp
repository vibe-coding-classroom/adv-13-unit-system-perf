#include <Arduino.h>
#include "../include/perf_config.h"

/**
 * @file SystemProfiler.cpp
 * @brief Implementation of microsecond-level timing and average calculation.
 */

unsigned long startTime[NUM_PERF_NODES];
unsigned long totalDuration[NUM_PERF_NODES];
unsigned long callCount[NUM_PERF_NODES];

void startProfile(int node) {
    if (node < 0 || node >= NUM_PERF_NODES) return;
    startTime[node] = micros();
}

void endProfile(int node) {
    if (node < 0 || node >= NUM_PERF_NODES) return;
    unsigned long duration = micros() - startTime[node];
    totalDuration[node] += duration;
    callCount[node]++;
}

float getAverageTime(int node) {
    if (node < 0 || node >= NUM_PERF_NODES || callCount[node] == 0) return 0.0f;
    return (float)totalDuration[node] / callCount[node];
}

void resetProfile(int node) {
    if (node < 0 || node >= NUM_PERF_NODES) return;
    totalDuration[node] = 0;
    callCount[node] = 0;
}

void printProfileReport() {
    Serial.println("--- Performance Profile Report (avg us) ---");
    Serial.print("Sensor Read:  "); Serial.println(getAverageTime(PERF_NODE_SENSOR_READ));
    Serial.print("PID Calc:     "); Serial.println(getAverageTime(PERF_NODE_PID_CALC));
    Serial.print("Protocol Enc: "); Serial.println(getAverageTime(PERF_NODE_PROTOCOL_ENC));
    Serial.print("Serial TX:    "); Serial.println(getAverageTime(PERF_NODE_SERIAL_TX));
    Serial.print("Total Loop:   "); Serial.println(getAverageTime(PERF_NODE_TOTAL_LOOP));
    Serial.println("-------------------------------------------");
}
