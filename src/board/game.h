#ifndef __GAME_H__
#define __GAME_H__

#include "text_display.h"
#include "floor.h"
#include "../widgets/characters/player_characters/player_character.h"

class Game  {
    PlayerCharacter *pc;
    TextDisplay *td;
    Floor *floor;
    bool quit;
    int level;
    
  public:
    Game(const char *init_file);
    void play();
    bool is_won();
    bool is_lost();
    bool was_quit();
};

#endif
