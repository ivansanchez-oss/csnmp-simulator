#include <stdbool.h>
#include <stdint.h>

typedef enum {
    CLASS_UNIVERSAL = 0x00,         // 0b00000000
    CLASS_APPLICATION = 0x40,       // 0b01000000
    CLASS_CONTEXT_SPECIFIC = 0x80,  // 0b10000000
    CLASS_PRIVATE = 0xC0,           // 0b11000000
} BER_Class;

typedef enum {
    FORM_PRIMITIVE = 0x00,          // 0b00000000
    FROM_CONSTRUCTED = 0x20,        // 0b00100000
} BER_Form;

typedef enum {
    TAG_BOOLEAN = 0x01,             
    TAG_INTEGER = 0x02,             
    TAG_OCTETSTRING = 0x04,
    TAG_NULL = 0x05,
    TAG_SEQUENCE = 0x10,  
} BER_Tag;

uint8_t needed_bytes(int32_t value);
void encoding_integer_ber(int32_t value, unsigned char* buf, size_t* pos);
void encoding_boolean_ber(bool value, unsigned char* buf, size_t* pos);
