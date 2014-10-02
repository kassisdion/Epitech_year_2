#include <stdarg.h>
#include <stddef.h>
#include "utils/packer/cpacker.h"

void cpacker_buf_pack(cpacker_buf_t *buf, const char *fmt, ...)
{
    va_list vl;

    va_start(vl, fmt);
    cpacker_buf_packv(buf, fmt, vl);
    va_end(vl);
}

void cpacker_buf_packv(cpacker_buf_t *buf, const char *fmt, va_list vl)
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
        short prefix = 0;
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
            prefix = 1;
            tmp++;
        }
        if (*tmp)
        {
            switch (*tmp)
            {
                case 's':
                    if (has_length)
                    {
                        cpacker_buf_put_string_pad(buf, va_arg(vl, char *), length);
                    }
                    else if (prefix)
                    {
                        cpacker_buf_put_string_prefix(buf, va_arg(vl, char *));
                    }
                    else
                    {
                        cpacker_buf_put_string(buf, va_arg(vl, char *));
                    }
                    break;
                case 'b':
                    cpacker_buf_put_char(buf, va_arg(vl, int));
                    break;
                case 'B':
                    cpacker_buf_put_uint8(buf, va_arg(vl, int));
                    break;
                case 'h':
                case 'H':
                    cpacker_buf_put_uint16(buf, va_arg(vl, int));
                    break;
                case 'i':
                case 'I':
                case 'l':
                case 'L':
                    cpacker_buf_put_uint32(buf, va_arg(vl, uint32_t));
                    break;
                case 'q':
                case 'Q':
                    cpacker_buf_put_uint64(buf, va_arg(vl, uint64_t));
                    break;
                case 'v':
                    cpacker_buf_put_varint(buf, va_arg(vl, size_t));
                    break;
            }
            tmp++;
        }
    }
}
