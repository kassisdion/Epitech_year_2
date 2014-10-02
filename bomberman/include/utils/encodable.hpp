#ifndef UTILS_ENCODABLE_H_
#define UTILS_ENCODABLE_H_

#include <iostream>
#include "utils/packer/cpacker.h"

class Encodable
{
public:
    virtual void encode(cpacker_buf_t *buf) const = 0;

    void encodeStream(std::ostream &out) const;
};

std::ostream &operator<<(std::ostream &out, const Encodable &encodable);

#endif /* UTILS_ENCODABLE_H_ */
