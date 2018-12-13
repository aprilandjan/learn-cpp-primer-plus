//
// Created by May on 2018/12/13.
//

#include <iostream>
#include "use_class_player.h"
#include "Player.h"

void use_class_player() {
    using std::cout;
    using namespace L13_1;

    Player p1("Merlin", true);
    Player p2("April", false);
    p2.name();
    if (p2.is_playing()) {
        cout << " is playing right now...\n";
    } else {
        cout << " is not playing currently.\n";
    }

    p1.name();
    if (p1.is_playing()) {
        cout << " is playing right now...\n";
    } else {
        cout << " is not playing currently.\n";
    }
}

#include "DotaPlayer.h"

void use_class_dota_player() {
    using std::cout;
    using std::endl;
    using namespace L13_1;

    Player me("Merlin");
    DotaPlayer jan(102, "Jan", true);
    jan.name();
    if (jan.is_playing()) {
        cout << " is playing right now...\n";
    } else {
        cout << " is not playing currently.\n";
    }
    jan.name();
    cout << " played " << jan.get_game_played() << " games total.\n";

    //  initialize use "me"
    DotaPlayer dotaMe(1024, me);
    dotaMe.name();
    cout << " played " << dotaMe.get_game_played() << " games total.\n";

    //  隐式调用 “复制构造函数”
    DotaPlayer againMe(dotaMe);
    againMe.name();
    cout << " played " << againMe.get_game_played() << " games total.\n";

    Player p1("Zeal", true);
//    DotaPlayer * pp1 = &p1; // not allowed
//    DotaPlayer & rp1 = p1;  // not allowed

    DotaPlayer p2(242, p1);
    Player * pp2 = &p2; //  its ok
    pp2->name();

    //  甚至可以用子类去实例化基类...
    //  隐式构造函数
    Player p3(p2);
    //  隐式重载赋值运算符
    Player p4 = p2;
}