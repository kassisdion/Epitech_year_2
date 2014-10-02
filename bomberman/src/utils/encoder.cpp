#include "utils/encoder.hpp"

void Encoder::save(const std::string &filename, Encodable &encodable)
{
    std::ofstream out(filename, std::ios::binary);

    encodable.encodeStream(out);
}

bool Encoder::fileExists(const std::string &filename)
{
    struct stat st;
    return (stat (filename.c_str(), &st) == 0);
}
