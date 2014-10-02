#include "utils/encodable.hpp"

void Encodable::encodeStream(std::ostream &out) const
{
    cpacker_buf_t buf;

    cpacker_buf_init(&buf);
    this->encode(&buf);
    out.write(cpacker_buf_data(&buf), cpacker_buf_size(&buf));
    cpacker_buf_destroy(&buf);
}

std::ostream &operator<<(std::ostream &out, const Encodable &encodable)
{
    encodable.encodeStream(out);
    return out;
}
