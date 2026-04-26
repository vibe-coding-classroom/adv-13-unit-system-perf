#ifndef PROTOCOL_V2_H
#define PROTOCOL_V2_H

#include <Arduino.h>

/**
 * @file protocol_v2.h
 * @brief Efficient binary/short-string protocol definitions.
 * 
 * Replace bulky JSON like {"speed":100, "angle":45} with:
 * Format: v[speed:4bytes][angle:4bytes]\n (Binary)
 * OR: vS100A45\n (Short String)
 */

struct CompactData {
    int16_t speed;
    int16_t angle;
    uint32_t timestamp;
};

/**
 * @brief Encodes data into a compact string format.
 * Example: vS100A45T12345\n
 */
void encodeProtocolV2(char* buffer, const CompactData& data) {
    sprintf(buffer, "vS%dA%dT%lu\n", data.speed, data.angle, data.timestamp);
}

#endif // PROTOCOL_V2_H
