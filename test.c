#include <stdio.h>
#include "src/core/snmp_protocol.h"
#include <stdbool.h>

int main() {
    char buf[10];
    encoding_boolean_ber(true, buf);
    printf("TRUE: 0x%02X 0x%02X 0x%02X \n", buf[0],buf[1],buf[2]);

    encoding_boolean_ber(false, buf);
    printf("FALSE: 0x%02X 0x%02X 0x%02X \n", buf[0],buf[1],buf[2]);
}
