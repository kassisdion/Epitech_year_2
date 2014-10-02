#include <string>
#include <sstream>
#include "avm/common/exception.hpp"

std::string avm::common::AVMSourceException::build_message(int line, const std::string &msg)
{
    std::stringstream ss;

    ss << "Ligne " << (line + 1) << ": " << msg;

    return ss.str();
}
