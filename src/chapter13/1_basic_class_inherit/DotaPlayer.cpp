//
// Created by May on 2018/12/13.
//

#include <iostream>
#include "DotaPlayer.h"

namespace L13_1 {
    //  无法直接访问基类的的私有成员
    //  只能通过 “成员初始化列表” 初始化基类
    DotaPlayer::DotaPlayer(unsigned int game_played, const string &name, bool is_playing): Player(name, is_playing) {
        _game_played = game_played;
    }
    //  同理，不过这里会从一个 player 对象创建基类 Player 对象，导致需要调用 Player 的 “复制构造函数”
    DotaPlayer::DotaPlayer(unsigned int game_played, const Player &player): Player(player) {
        _game_played = game_played;
    }
}