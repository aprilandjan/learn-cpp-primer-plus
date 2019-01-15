//
// Created by May on 2019/1/14.
//

#ifndef LEARN_TELEVISION_H
#define LEARN_TELEVISION_H

namespace L15_1 {
    class Television {
    private:
        //  is on or not
        int _state;
        int _volume;
        int _max_channel;
        int _channel;
        int _mode;
        int _input;
    public:
        //  declare its use of friend class
        friend class Remote;
        enum {Off, On};
        enum {MinVal, MaxVal = 20};
        enum {Antenna, Cable};
        enum {TV, DVD};

        Television(int s = Off, int mc = 125): _state(s), _volume(5), _max_channel(mc), _channel(2), _mode(Cable), _input(TV){};
        void toggle() {
            _state = _state == On ? Off : On;
        }
        bool is_on() {
            return _state == On;
        }
        bool vol_up();
        bool vol_down();
        void chan_up();
        void chan_down();
        void set_mode() {
            _mode = _mode == Cable ? Antenna : Cable;
        }
        void set_input() {
            _input = _input == TV ? DVD : TV;
        }
        void settings() const;
    };

    class Remote {
    private:
        int _mode;
    public:
        //  Television::TV is from enum values
        Remote(int m = Television::TV) : _mode(m) {};
        bool vol_up(Television & tv) {
            return tv.vol_up();
        }
        bool vol_down(Television & tv) {
            return tv.vol_down();
        }
        void toggle(Television & tv) {
            return tv.toggle();
        }
        void chan_up(Television & tv) {
            return tv.chan_up();
        }
        void chan_down(Television & tv) {
            return tv.chan_down();
        }
        void set_mode(Television & tv) {
            return tv.set_mode();
        }
        void set_input(Television & tv) {
            return tv.set_input();
        }
        void set_chan(Television & tv, int c) {
            //  access private members directly
            tv._channel = c;
        }
    };
}


#endif //LEARN_TELEVISION_H
