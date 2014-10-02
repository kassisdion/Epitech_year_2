#include <nds.h>
#include <stdio.h>
#include <stdarg.h>
#include "core/debug.hpp"

static PrintConsole debugScreen;
static bool debug = false;

void Debug::init(bool upper)
{
    lcdMainOnTop();
    consoleDebugInit(DebugDevice_CONSOLE);
    if (upper)
    {
        videoSetMode(MODE_0_2D);
        vramSetBankA(VRAM_A_MAIN_BG);
    }
    else
    {
        videoSetModeSub(MODE_0_2D);
        vramSetBankC(VRAM_C_SUB_BG);
    }
    consoleInit(&debugScreen, 3, BgType_Text4bpp, BgSize_T_256x256, 31, 0, upper, true);
    consoleSelect(&debugScreen);

    debug = true;
}

bool Debug::isDebug()
{
    return debug;
}

void Debug::print(const std::string &msg, ...)
{
    va_list ap;

    if (debug)
    {
        va_start(ap, msg);
        vprintf(msg.c_str(), ap);
        va_end(ap);
    }
}

void Debug::println(const std::string &msg, ...)
{
    va_list ap;

    if (debug)
    {
        va_start(ap, msg);
        vprintf(msg.c_str(), ap);
        printf("\n");
        va_end(ap);
    }
}
