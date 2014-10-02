#ifndef CORE_DEBUG_H_
#define CORE_DEBUG_H_

#include <string>

class Debug
{
public:
    static void init(bool upper = true);
    static bool isDebug();

    static void print(const std::string &msg, ...);
    static void println(const std::string &msg, ...);
};

#endif /* CORE_DEBUG_H_ */
