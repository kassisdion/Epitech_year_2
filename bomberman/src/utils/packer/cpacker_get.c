#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <strings.h>
#include "utils/packer/cpacker.h"

void cpacker_buf_get_data(cpacker_buf_t *buf, char *dst, size_t length)
{
    size_t read_size = buf->data_size - buf->index;
    if (read_size > length)
    {
        read_size = length;
    }

    memcpy(dst, &(buf->data[buf->index]), read_size);
    buf->index += read_size;
}

void cpacker_buf_get_size(cpacker_buf_t *buf, size_t *n)
{
    union {
        char data[sizeof(*n)];
        size_t num;
    } u;

    cpacker_buf_get_data(buf, u.data, sizeof(*n));
    *n = u.num;
}

static size_t cpacker_buf_get_varint_n(cpacker_buf_t *buf, uint8_t size, uint8_t mask)
{
    size_t n = 0;
    uint8_t i;

    for (i = 0; i < size; i++)
    {
        uint8_t c = 0;

        cpacker_buf_get_uint8(buf, &c);

        if (i == 0)
        {
            c &= mask;
        }

        n = (n << 8) | c;
    }

    return n;
}

// http://www.dlugosz.com/ZIP2/VLI.html
void cpacker_buf_get_varint(cpacker_buf_t *buf, size_t *n)
{
    uint8_t msb = buf->data[buf->index];

    if ((msb & 0x80) == 0)
    {
        *n = cpacker_buf_get_varint_n(buf, 1, 0x7f);
    }
    else if ((msb & 0xc0) == 0x80)
    {
        *n = cpacker_buf_get_varint_n(buf, 2, 0x3f);
    }
    else if ((msb & 0xe0) == 0xc0)
    {
        *n = cpacker_buf_get_varint_n(buf, 3, 0x1f);
    }
    else if ((msb & 0xf8) == 0xe0)
    {
        *n = cpacker_buf_get_varint_n(buf, 4, 0x07);
    }
    else if ((msb & 0xf8) == 0xe8)
    {
        *n = cpacker_buf_get_varint_n(buf, 5, 0x07);
    }
}

void cpacker_buf_get_uint64(cpacker_buf_t *buf, uint64_t *n)
{
    union {
        char data[sizeof(*n)];
        uint64_t num;
    } u;

    cpacker_buf_get_data(buf, u.data, sizeof(*n));
    *n = u.num;
}

void cpacker_buf_get_uint32(cpacker_buf_t *buf, uint32_t *n)
{
    union {
        char data[sizeof(*n)];
        uint32_t num;
    } u;

    cpacker_buf_get_data(buf, u.data, sizeof(*n));
    *n = u.num;
}

void cpacker_buf_get_uint16(cpacker_buf_t *buf, uint16_t *n)
{
    union {
        char data[sizeof(*n)];
        uint16_t num;
    } u;

    cpacker_buf_get_data(buf, u.data, sizeof(*n));
    *n = u.num;
}

void cpacker_buf_get_uint8(cpacker_buf_t *buf, uint8_t *n)
{
    cpacker_buf_get_data(buf, (char *) n, 1);
}

void cpacker_buf_get_char(cpacker_buf_t *buf, char *c)
{
    cpacker_buf_get_data(buf, c, 1);
}

void cpacker_buf_get_string(cpacker_buf_t *buf, char *dst, size_t length)
{
    cpacker_buf_get_data(buf, dst, length);
}

void cpacker_buf_get_string_prefix(cpacker_buf_t *buf, char **dst, size_t *length)
{
    size_t len;

    cpacker_buf_get_varint(buf, &len);
    if (length)
    {
        *length = len;
    }
    char *s = malloc(len + 1);

    if (s)
    {
        cpacker_buf_get_string(buf, s, len);
        s[len] = 0;
    }
    if (dst)
    {
        *dst = s;
    }
}
