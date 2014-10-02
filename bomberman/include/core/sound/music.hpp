#ifndef MUSIC_H_
#define MUSIC_H_

#include <maxmod9.h>

class Music
{
public:
    enum Starting
    {
        LOOP,
        ONCE,
    };
public:
    Music(mm_word music);
    ~Music() {};
    void start(Music::Starting starting = LOOP);
    static void pause();
    static void resume();
    static void stop();

private:
    mm_word music;
};

#endif /* MUSIC_H_ */
