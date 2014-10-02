#ifndef UTILS_ENCODER_H_
#define UTILS_ENCODER_H_

#include <string>
#include <fstream>
#include <sys/stat.h>
#include "utils/encodable.hpp"

class Encoder
{
public:
    static void save(const std::string &filename, Encodable &encodable);

    template<class C>
    static C *load(const std::string &filename)
    {
        std::ifstream in(filename, std::ios::binary);

        return C::decodeStream(in);
    }

    static bool fileExists(const std::string &filename);
};

#endif /* UTILS_ENCODER_H_ */
