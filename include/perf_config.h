#ifndef PERF_CONFIG_H
#define PERF_CONFIG_H

/**
 * @file perf_config.h
 * @brief Core performance monitoring nodes and configuration.
 */

// Performance Monitoring Nodes
#define PERF_NODE_SENSOR_READ  0
#define PERF_NODE_PID_CALC     1
#define PERF_NODE_PROTOCOL_ENC 2
#define PERF_NODE_SERIAL_TX    3
#define PERF_NODE_TOTAL_LOOP   4

#define NUM_PERF_NODES         5

// Targets and Thresholds (in microseconds)
#define TARGET_LOOP_TIME_US    10000 // 100Hz target
#define WARNING_THRESHOLD_US   8000  // Warn if loop takes > 8ms

// Protocol Configuration
#define PROTOCOL_V2_HEADER     'v'
#define PROTOCOL_V2_FOOTER     '\n'

#endif // PERF_CONFIG_H
