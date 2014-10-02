#include <stddef.h>
#include <string.h>
#include <strings.h>
#include "utils/packer/cpacker.h"

/**
 * Store raw data in the buffer.
 * \param buf CPacker buffer.
 * \param src Data to store.
 * \param length Data size to store.
 */
void cpacker_buf_put_data(cpacker_buf_t *buf, const char *src, size_t length)
{
    cpacker_buf_ensure_size(buf, buf->size + length);
    memcpy(&(buf->data[buf->index]), src, length);
    buf->size += length;
    buf->index += length;
}

void cpacker_buf_put_size(cpacker_buf_t *buf, size_t n)
{
    cpacker_buf_put_uint32(buf, n);
}

static void cpacker_buf_put_varint_n(cpacker_buf_t *buf, size_t n, uint8_t size, uint8_t mask)
{
    char i;

    for (i = size - 1; i >= 0; i--)
    {
        if (i == size - 1)
        {
            cpacker_buf_put_uint8(buf, ((n >> (8 * i)) & 0xff) | mask);
        }
        else
        {
            cpacker_buf_put_uint8(buf, (n >> (8 * i)) & 0xff);
        }
    }
}

// http://www.dlugosz.com/ZIP2/VLI.html
void cpacker_buf_put_varint(cpacker_buf_t *buf, size_t n)
{
    if (n <= 0x7f)
    {
        cpacker_buf_put_varint_n(buf, n & 0x7f, 1, 0);
    }
    else if (n <= 0x3fff)
    {
        cpacker_buf_put_varint_n(buf, n & 0x3fff, 2, 0x80);
    }
    else if (n <= 0x1fffff)
    {
        cpacker_buf_put_varint_n(buf, n & 0x1fffff, 3, 0xc0);
    }
    else if (n <= 0x7ffffff)
    {
        cpacker_buf_put_varint_n(buf, n & 0x7ffffff, 4, 0xe0);
    }
    else if (n <= 0x7ffffffff)
    {
        cpacker_buf_put_varint_n(buf, n & 0x7ffffffff, 5, 0xe8);
    }
}

void cpacker_buf_put_uint64(cpacker_buf_t *buf, uint64_t n)
{
    char data[sizeof(n)];
    size_t i;

    bzero(data, sizeof(data));

    for (i = 0; i < sizeof(n); i++)
    {
        data[i] = (n >> (((sizeof(n) - 1) - i) * 8)) & 0xff;
    }

    cpacker_buf_put_data(buf, data, sizeof(data));
}

void cpacker_buf_put_uint32(cpacker_buf_t *buf, uint32_t n)
{
    char data[sizeof(n)];
    size_t i;

    bzero(data, sizeof(data));

    for (i = 0; i < sizeof(n); i++)
    {
        data[i] = (n >> (((sizeof(n) - 1) - i) * 8)) & 0xff;
    }

    cpacker_buf_put_data(buf, data, sizeof(data));
}

void cpacker_buf_put_uint16(cpacker_buf_t *buf, uint16_t n)
{
    char data[sizeof(n)];
    size_t i;

    bzero(data, sizeof(data));

    for (i = 0; i < sizeof(n); i++)
    {
        data[i] = (n >> (((sizeof(n) - 1) - i) * 8)) & 0xff;
    }

    cpacker_buf_put_data(buf, data, sizeof(data));
}

void cpacker_buf_put_uint8(cpacker_buf_t *buf, uint8_t n)
{
    cpacker_buf_put_data(buf, (char *) &n, 1);
}

void cpacker_buf_put_char(cpacker_buf_t *buf, char c)
{
    cpacker_buf_put_data(buf, &c, 1);
}

void cpacker_buf_put_string(cpacker_buf_t *buf, const char *s)
{
    cpacker_buf_put_data(buf, s, strlen(s));
}

void cpacker_buf_put_string_pad(cpacker_buf_t *buf, const char *s, size_t length)
{
    size_t len = strlen(s);

    if (len <= length)
    {
        size_t diff = length - len;
        size_t i;
        cpacker_buf_put_string(buf, s);

        for (i = 0; i < diff; i++)
        {
            cpacker_buf_put_char(buf, 0);
        }
    }
    else
    {
        cpacker_buf_put_data(buf, s, length);
    }
}

void cpacker_buf_put_string_prefix(cpacker_buf_t *buf, const char *s)
{
    cpacker_buf_put_varint(buf, strlen(s));
    cpacker_buf_put_string(buf, s);
}
