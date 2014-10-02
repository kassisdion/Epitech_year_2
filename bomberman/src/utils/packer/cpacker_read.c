#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "utils/packer/cpacker.h"

size_t cpacker_buf_read_size(cpacker_buf_t *buf)
{
    size_t n;

    cpacker_buf_get_size(buf, &n);

    return n;
}

// http://www.dlugosz.com/ZIP2/VLI.html
size_t cpacker_buf_read_varint(cpacker_buf_t *buf)
{
    size_t n;

    cpacker_buf_get_varint(buf, &n);

    return n;
}

uint64_t cpacker_buf_read_uint64(cpacker_buf_t *buf)
{
    uint64_t n;

    cpacker_buf_get_uint64(buf, &n);

    return n;
}

uint32_t cpacker_buf_read_uint32(cpacker_buf_t *buf)
{
    uint32_t n;

    cpacker_buf_get_uint32(buf, &n);

    return n;
}

uint16_t cpacker_buf_read_uint16(cpacker_buf_t *buf)
{
    uint16_t n;

    cpacker_buf_get_uint16(buf, &n);

    return n;
}

uint8_t cpacker_buf_read_uint8(cpacker_buf_t *buf)
{
    uint8_t n;

    cpacker_buf_get_uint8(buf, &n);

    return n;
}

char cpacker_buf_read_char(cpacker_buf_t *buf)
{
    char c;

    cpacker_buf_get_char(buf, &c);

    return c;
}

char *cpacker_buf_read_string(cpacker_buf_t *buf, size_t length)
{
    char *str = malloc(length);

    if (str)
    {
        cpacker_buf_get_string(buf, str, length);
    }

    return str;
}

char *cpacker_buf_read_string_prefix(cpacker_buf_t *buf, size_t *size)
{
    char *s;

    cpacker_buf_get_string_prefix(buf, &s, size);
    return s;
}
