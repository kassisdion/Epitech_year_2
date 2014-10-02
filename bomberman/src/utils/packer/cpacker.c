#include <stdlib.h>
#include "utils/packer/cpacker.h"

/**
 * \brief Create a new CPacker buffer.
 *
 * Returns a pointer to the CPacker buffer created.
 * \return The CPacker buffer created.
 */
cpacker_buf_t *cpacker_buf_new(void)
{
    cpacker_buf_t *buf = malloc(sizeof(cpacker_buf_t));

    if (buf)
    {
        cpacker_buf_init(buf);
    }

    return buf;
}

/**
 * Free a CPacker buffer created with cpacker_buf_new.
 * \see cpacker_buf_new
 * \param buf Previously allocated CPacker buffer.
 */
void cpacker_buf_free(cpacker_buf_t *buf)
{
    if (buf)
    {
        cpacker_buf_destroy(buf);
        free(buf);
    }
}

/**
 * Initialize a CPacker buffer.
 * \param buf CPacker buffer.
 */
void cpacker_buf_init(cpacker_buf_t *buf)
{
    buf->index = 0;
    buf->size = 0;
    buf->data_size = 0;
    buf->data = NULL;
    buf->mode = CPACKER_MODE_LITTLE;
}

/**
 * Destroy a CPacker buffer.
 * \param buf CPacker buffer.
 */
void cpacker_buf_destroy(cpacker_buf_t *buf)
{
    if (buf->data)
    {
        free(buf->data);
    }
}

/**
 * Reset a CPacker buffer.
 * \param buf CPacker buffer.
 */
void cpacker_buf_reset(cpacker_buf_t *buf)
{
    cpacker_buf_destroy(buf);
    cpacker_buf_init(buf);
}

/**
 * Resize a CPacker buffer to the desired size.
 * \param buf CPacker buffer.
 * \param size Desired size.
 * \warning You may not use this function!
 */
void cpacker_buf_resize(cpacker_buf_t *buf, size_t size)
{
    size_t num = size / CPACKER_BUFFER_SIZE;
    if (size % CPACKER_BUFFER_SIZE)
    {
        num++;
    }

    buf->data = realloc(buf->data, num * CPACKER_BUFFER_SIZE);
    buf->data_size = num * CPACKER_BUFFER_SIZE;
}

/**
 * Check if the CPacker buffer has a sufficient size to store
 * data.
 * \param buf CPacker buffer.
 * \param size Minimum buffer size to store data.
 */
void cpacker_buf_ensure_size(cpacker_buf_t *buf, size_t size)
{
    if (buf->data_size < size)
    {
        cpacker_buf_resize(buf, size);
    }
}

/**
 * Set the current CPacker buffer mode.
 * Useful to set the endianness of some stored data types (mostly integers)
 * \param buf CPacker buffer.
 * \param mode Wanted buffer mode.
 * \return Old buffer mode.
 */
cpacker_mode_t cpacker_buf_set_mode(cpacker_buf_t *buf, cpacker_mode_t mode)
{
    cpacker_mode_t old = buf->mode;
    buf->mode = mode;
    return old;
}

/**
 * Set the CPacker buffer data.
 * Useful when wanting to parse some data from other sources.
 * \param buf CPacker buffer.
 * \param data Data
 * \param size Data size
 */
void cpacker_buf_set_data(cpacker_buf_t *buf, char *data, size_t size)
{
    buf->index = 0;
    buf->data = data;
    buf->size = buf->data_size = size;
}

/**
 * Set the current CPacker buffer read/write index.
 * \param buf CPacker buffer.
 * \param index Current index.
 */
size_t cpacker_buf_set_index(cpacker_buf_t *buf, size_t index)
{
    size_t old = buf->index;
    buf->index = 0;
    return old;
}
