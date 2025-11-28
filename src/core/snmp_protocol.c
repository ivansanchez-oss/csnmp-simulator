#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include "snmp_protocol.h"

uint8_t needed_bytes(int32_t value) {
    if (value >= 0)  {
        if (value == 0) return 1;
        if (value <= 0x7F) return 1;
        if (value <= 0x7FFF) return 2;
        if (value <= 0x7FFFFF) return 3;
        return 4;
    } else {
        if (value >= -0x80) return 1;
        if (value >= -0x8000) return 2;
        if (value >= -0x800000) return 3;
        return 4;
    }

    return 0;
}

// the length is encoded as an unsigned binary value
void encoding_length_ber(uint8_t bytes, unsigned char* buf, size_t pos) {
    // short form (between 0 and 127)
    if (bytes <= 127) {
        buf[pos] = bytes;
    } 
}

void encoding_boolean_ber(bool value, unsigned char* buf, size_t* pos) {
    buf[*pos] = CLASS_UNIVERSAL | FORM_PRIMITIVE | TAG_BOOLEAN;
    encoding_length_ber(1, buf,*pos+1);
    buf[*pos+2] = value ? 0xFF : 0x00;
    *pos += 3;
}

void encoding_integer_ber(int32_t value, unsigned char* buf, size_t* pos) {
    buf[*pos] = CLASS_UNIVERSAL | FORM_PRIMITIVE | TAG_INTEGER;
    uint8_t bytes = needed_bytes(value);
    encoding_length_ber(bytes, buf, *pos+1);

    size_t offset = *pos+2;

    for(uint8_t i = 0; i < bytes; i++) {
        int shift = (bytes - 1 - i) * 8;
        buf[offset + i] = (value >> shift) & 0xFF;
    }

    *pos += 2 + bytes;
}
