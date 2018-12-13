//
// Created by May on 2018/12/12.
//

#ifndef LEARN_PLAYER_H
#define LEARN_PLAYER_H

//  使用标准 string 类
#include <string>
using std::string;

namespace L13_1 {
    class Player {
    private:
        string _name;
        bool _is_playing;
    public:
        Player(const string & name = "none", bool is_playing = false);
        void name() const;
        bool is_playing() const;
        bool set_playing(bool v) {
            _is_playing = v;
        };
    };
}

#endif //LEARN_PLAYER_H
