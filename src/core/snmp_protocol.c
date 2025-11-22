#include <stdio.h>
#include <stdbool.h>
#include "snmp_protocol.h"

void encoding_boolean_ber(bool value, char* buf) {
    buf[0] = CLASS_UNIVERSAL | FORM_PRIMITIVE | TAG_BOOLEAN;
    buf[1] = 0x01; 

    if (value) {
        buf[2] = 0xFF;
    } else {
        buf[2] = 0x00;
    }
}
