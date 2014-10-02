#include "core/sound/music.hpp"

Music::Music(mm_word music) :
    music(music)
{
    mmLoad(music);
}

void Music::start(Music::Starting starting)
{
    if (starting == Music::Starting::LOOP)
        mmStart(this->music, MM_PLAY_LOOP);
    else if (starting == Music::Starting::ONCE)
        mmStart(this->music, MM_PLAY_ONCE);
}

void Music::pause()
{
    mmPause();
}

void Music::resume()
{
    mmResume();
}

void Music::stop()
{
    mmStop();
}