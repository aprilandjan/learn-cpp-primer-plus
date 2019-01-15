//
// Created by May on 2019/1/14.
//

#include "Television.h"
#include <iostream>

namespace L15_1 {
    bool Television::vol_up() {
        if (_volume < MaxVal) {
            _volume++;
            return true;
        }
        return false;
    }
    bool Television::vol_down() {
        if (_volume > MinVal) {
            _volume--;
            return true;
        }
        return false;
    }
    void Television::chan_up() {
        if (_channel < _max_channel) {
            _channel++;
        } else {
            _channel = 1;
        }
    }
    void Television::chan_down() {
        if (_channel > 1) {
            _channel--;
        } else {
            _channel = _max_channel;
        }
    }
    void Television::settings() const {
        std::cout << "TV is " << (_state == On ? "On" : "Off") << std::endl;
        if (_state == On) {
            std::cout << "Volume setting = " << _volume << std::endl;
            std::cout << "Channel setting = " << _channel << std::endl;
            std::cout << "Mode = " << (_mode == Antenna ? "Antenna" : "Cable") << std::endl;
            std::cout << "Input = " << (_input == TV ? "TV" : "DVD") << std::endl;
        }
    }
}