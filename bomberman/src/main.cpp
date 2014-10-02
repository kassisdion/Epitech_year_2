#include <nds.h>
#include <fat.h>
#include "core/bomberman.hpp"
#include "core/debug.hpp"
#include "core/game/game.hpp"
#include "utils/encoder.hpp"
#include "time.h"

static void init()
{
    fatInitDefault();
    srand(time(NULL));
}

int main()
{
    init();

    // Game *game = Encoder::load<Game>("game.sav");
    // Encoder::save("game.sav", *game);

    Bomberman::getInstance().start();
    return 0;
}
