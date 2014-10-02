#ifndef CPACKER_H_
#define CPACKER_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h>
#include <stdarg.h>
#include <stdint.h>

#define CPACKER_BUFFER_SIZE (64)

typedef enum _cpacker_mode_t
{
    CPACKER_MODE_LITTLE,
    CPACKER_MODE_BIG
} cpacker_mode_t;

typedef struct _cpacker_buf_t cpacker_buf_t;
struct _cpacker_buf_t
{
    size_t index; /**< Buffer reader/writer index */
    size_t size; /**< Buffer current size. Not the data size. */
    size_t data_size; /**< Buffer current data size. */
    char *data; /**< Buffer data, which contains written data */
    cpacker_mode_t mode; /**< Buffer current mode for endianness */
};

#define cpacker_buf_size(buf) ((buf)->size)
#define cpacker_buf_data(buf) ((buf)->data)
#define cpacker_buf_mode(buf) ((buf)->mode)

cpacker_buf_t *cpacker_buf_new(void);
void cpacker_buf_free(cpacker_buf_t *buf);

void cpacker_buf_init(cpacker_buf_t *buf);
void cpacker_buf_destroy(cpacker_buf_t *buf);
void cpacker_buf_reset(cpacker_buf_t *buf);

void cpacker_buf_resize(cpacker_buf_t *buf, size_t size);
void cpacker_buf_ensure_size(cpacker_buf_t *buf, size_t size);

cpacker_mode_t cpacker_buf_set_mode(cpacker_buf_t *buf, cpacker_mode_t mode);
void cpacker_buf_set_data(cpacker_buf_t *buf, char *data, size_t size);
size_t cpacker_buf_set_index(cpacker_buf_t *buf, size_t index);

void cpacker_buf_put_data(cpacker_buf_t *buf, const char *src, size_t length);
void cpacker_buf_put_size(cpacker_buf_t *buf, size_t size);
void cpacker_buf_put_varint(cpacker_buf_t *buf, size_t n);
void cpacker_buf_put_uint64(cpacker_buf_t *buf, uint64_t n);
void cpacker_buf_put_uint32(cpacker_buf_t *buf, uint32_t n);
void cpacker_buf_put_uint16(cpacker_buf_t *buf, uint16_t n);
void cpacker_buf_put_uint8(cpacker_buf_t *buf, uint8_t n);
void cpacker_buf_put_char(cpacker_buf_t *buf, char c);
void cpacker_buf_put_string(cpacker_buf_t *buf, const char *s);
void cpacker_buf_put_string_pad(cpacker_buf_t *buf, const char *s, size_t length);
void cpacker_buf_put_string_prefix(cpacker_buf_t *buf, const char *s);

void cpacker_buf_get_data(cpacker_buf_t *buf, char *dst, size_t length);
void cpacker_buf_get_size(cpacker_buf_t *buf, size_t *size);
void cpacker_buf_get_varint(cpacker_buf_t *buf, size_t *n);
void cpacker_buf_get_uint64(cpacker_buf_t *buf, uint64_t *n);
void cpacker_buf_get_uint32(cpacker_buf_t *buf, uint32_t *n);
void cpacker_buf_get_uint16(cpacker_buf_t *buf, uint16_t *n);
void cpacker_buf_get_uint8(cpacker_buf_t *buf, uint8_t *n);
void cpacker_buf_get_char(cpacker_buf_t *buf, char *c);
void cpacker_buf_get_string(cpacker_buf_t *buf, char *dst, size_t length);
void cpacker_buf_get_string_prefix(cpacker_buf_t *buf, char **dst, size_t *length);

size_t cpacker_buf_read_size(cpacker_buf_t *buf);
size_t cpacker_buf_read_varint(cpacker_buf_t *buf);
uint64_t cpacker_buf_read_uint64(cpacker_buf_t *buf);
uint32_t cpacker_buf_read_uint32(cpacker_buf_t *buf);
uint16_t cpacker_buf_read_uint16(cpacker_buf_t *buf);
uint8_t cpacker_buf_read_uint8(cpacker_buf_t *buf);
char cpacker_buf_read_char(cpacker_buf_t *buf);
char *cpacker_buf_read_string(cpacker_buf_t *buf, size_t length);
char *cpacker_buf_read_string_prefix(cpacker_buf_t *buf, size_t *length);

void cpacker_buf_pack(cpacker_buf_t *buf, const char *fmt, ...);
void cpacker_buf_packv(cpacker_buf_t *buf, const char *fmt, va_list vl);
void cpacker_buf_unpack(cpacker_buf_t *buf, const char *fmt, ...);
void cpacker_buf_unpackv(cpacker_buf_t *buf, const char *fmt, va_list vl);

#ifdef __cplusplus
}
#endif

#endif /* CPACKER_H_ */
