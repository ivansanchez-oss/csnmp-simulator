#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "src/core/snmp_protocol.h"

int main() {
    size_t pos = 0;
    int32_t number = 0;
    unsigned char buf[256];

    pos = 0;
    encoding_boolean_ber(true, buf, &pos);
    printf("TRUE: 0x%02X 0x%02X 0x%02X \n", buf[0],buf[1],buf[2]);

    pos = 0;
    encoding_boolean_ber(false, buf, &pos);
    printf("FALSE: 0x%02X 0x%02X 0x%02X \n", buf[0],buf[1],buf[2]);

    pos = 0;
    number = 255;
    encoding_integer_ber(number, buf, &pos);
    printf("%d: 0x%02X 0x%02X 0x%02X 0x%02X\n", number,buf[0],buf[1],buf[2], buf[3]);

    pos = 0;
    number = 10;
    encoding_integer_ber(number, buf, &pos);
    printf("%d: 0x%02X 0x%02X 0x%02X 0x%02X\n", number,buf[0],buf[1],buf[2], buf[3]);

    pos = 0;
    number = 1000;
    encoding_integer_ber(number, buf, &pos);
    printf("%d: 0x%02X 0x%02X 0x%02X 0x%02X\n", number,buf[0],buf[1],buf[2], buf[3]);

    pos = 0;
    number = 127;
    encoding_integer_ber(number, buf, &pos);
    printf("%d: 0x%02X 0x%02X 0x%02X 0x%02X\n", number,buf[0],buf[1],buf[2], buf[3]);

}
