#ifndef __GAME_H__
#define __GAME_H__

#include "text_display.h"
#include "floor.h"
#include "../widgets/characters/player_characters/player_character.h"

const int NUM_FLOORS = 5;

class Game  {
    PlayerCharacter *pc;
    TextDisplay *td;
    Floor *floor;
    bool quit;
    bool random_generation;
    std::ifstream *in;

    void play_floor(int level);
    
  public:
    Game(const char *init_file);
    ~Game();
    void play();
    bool is_won();
    bool is_lost();
    bool was_quit();
};

#endif
