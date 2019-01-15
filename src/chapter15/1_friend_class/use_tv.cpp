//
// Created by May on 2019/1/15.
//

#include "use_tv.h"
#include "Television.h"
#include <iostream>

void use_tv() {
    using namespace L15_1;

    using std::cout;

    Television panda;
    cout << "Init setting for panda TV: \n";
    panda.settings();
    panda.toggle();
    panda.chan_up();
    cout << "\nAdjusted setting for panda TV\n";
    panda.chan_up();
    panda.settings();
    cout << "\nAdjusted setting for panda TV:\n";
    panda.chan_up();
    panda.settings();

    //  add remote
    Remote r;
    r.set_chan(panda, 12);
    r.vol_up(panda);
    r.vol_up(panda);
    cout << "\nAdjust setting using remote:\n";
    panda.settings();

    Television sony(Television::On);
    sony.set_mode();
    r.set_chan(sony, 23);
    cout << "\nSetting sony TV:\n";
    sony.settings();
}