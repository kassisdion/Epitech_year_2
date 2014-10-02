#include <stdarg.h>
#include <stddef.h>
#include "utils/packer/cpacker.h"

void cpacker_buf_unpack(cpacker_buf_t *buf, const char *fmt, ...)
{
    va_list vl;

    va_start(vl, fmt);
    cpacker_buf_unpackv(buf, fmt, vl);
    va_end(vl);
}

void cpacker_buf_unpackv(cpacker_buf_t *buf, const char *fmt, va_list vl)
{
    const char *tmp = fmt;
    if (*tmp == '>')
    {
        cpacker_buf_set_mode(buf, CPACKER_MODE_BIG);
        tmp++;
    }
    else if (*tmp == '<')
    {
        cpacker_buf_set_mode(buf, CPACKER_MODE_LITTLE);
        tmp++;
    }

    while (*tmp)
    {
        short has_length = 0;
        size_t length = 0;
        while (*tmp && *tmp >= '0' && *tmp <= '9')
        {
            length = (length * 10) + (*tmp - '0');
            has_length = 1;
            tmp++;
        }
        if (*tmp == ':')
        {
            tmp++;
        }
        if (*tmp)
        {
            switch (*tmp)
            {
                case 's':
                    if (has_length)
                    {
                        cpacker_buf_get_string(buf, va_arg(vl, char *), length);
                    }
                    else
                    {
                        cpacker_buf_get_string_prefix(buf, va_arg(vl, char**), va_arg(vl, size_t *));
                    }
                    break;
                case 'b':
                    cpacker_buf_get_char(buf, va_arg(vl, char *));
                    break;
                case 'B':
                    cpacker_buf_get_uint8(buf, va_arg(vl, uint8_t *));
                    break;
                case 'h':
                case 'H':
                    cpacker_buf_get_uint16(buf, va_arg(vl, uint16_t *));
                    break;
                case 'i':
                case 'I':
                case 'l':
                case 'L':
                    cpacker_buf_get_uint32(buf, va_arg(vl, uint32_t *));
                    break;
                case 'q':
                case 'Q':
                    cpacker_buf_get_uint64(buf, va_arg(vl, uint64_t *));
                    break;
                case 'v':
                    cpacker_buf_get_varint(buf, va_arg(vl, size_t *));
                    break;
            }
            tmp++;
        }
    }
}
