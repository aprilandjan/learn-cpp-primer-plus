//
// Created by May on 2018/12/12.
//

#include <iostream>
#include "Player.h"

namespace L13_1 {
    Player::Player(const string &name, bool is_playing) {
        _name = name;
        _is_playing = is_playing;
    }
    void Player::name() const {
        std::cout << _name;
    }
    bool Player::is_playing() const {
        return _is_playing;
    }
}