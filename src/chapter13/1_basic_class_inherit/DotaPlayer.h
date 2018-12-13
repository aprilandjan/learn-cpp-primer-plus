//
// Created by May on 2018/12/13.
//

#ifndef LEARN_DOTAPLAYER_H
#define LEARN_DOTAPLAYER_H

#include "./Player.h"

namespace L13_1 {
    //  公有派生，和 TS 里的 class extend 基本一样
    class DotaPlayer: public Player {
    private:
        unsigned int _game_played;
    public:
        DotaPlayer(unsigned int game_played = 0, const string & name = "none", bool is_playing = false);
        DotaPlayer(unsigned int game_played, const Player & player);
        unsigned int get_game_played() const {
            return _game_played;
        }
        void set_game_played(unsigned int game_played) {
            _game_played = game_played;
        }
    };
}

#endif //LEARN_DOTAPLAYER_H
