//
// Created by May on 2018/12/11.
//

#include <iostream>
#include <cstdlib>  // provide rand
#include <ctime>    // provide time
#include "use_queue.h"
#include "./Queue.h"

const int MINUTES_PER_HOUR = 60;

/**
 * check should create a new customer or not
 * @param x
 * @return
 */
bool check_new_customer(double x) {
    return (std::rand() * x / RAND_MAX) < 1;
}

void use_queue() {
    using std::cout;
    using std::endl;
    using std::cin;
    using namespace L12_2;

    //  std::time: get current second count from 1970.1.1
    std::cout << std::time(nullptr) << "\n";

    //  以当前秒数作为伪随机种子
    std::srand(std::time(nullptr));

    cout << "ICBC Teller\n";
    cout << "Enter maximum size of queue:";
    int qs;
    cin >> qs;
    Queue queue(qs);

    cout << "Enter the number of simulation hours: ";
    int hours;
    cin >> hours;
    long minutes = hours * MINUTES_PER_HOUR;

    cout << "Enter the average number of customer per hour: ";
    double customers_per_hour;
    cin >> customers_per_hour;
    //  平均每个人耗时多少分钟
    double average_customer_time_spent = MINUTES_PER_HOUR / customers_per_hour;

    Item temp;
    int t = 0;
    //  队列中正在等待的人的剩余等待时间
    int remain_wait_time = 0;
    //  因队列满了，被赶走的人
    int num_leave = 0;
    //  总共的加入队列的顾客
    int num_queued = 0;
    for (t = 0; t < minutes; t++) {
        //  随机生成是否有新客户
        cout << "====> minute=" << t << " <====\n";
        if (check_new_customer(average_customer_time_spent)) {
            cout << "new customer incoming!\n";
            if (queue.is_full()) {
                //  队列满了，该顾客只能走了
                num_leave++;
                cout << "Current queue(size=" << queue.get_size() << ") is full, had to go away...\n";
            } else {
                num_queued++;
                temp.init(t);
                queue.enqueue(temp);
                cout << "Added to the queue(size=" << queue.get_size() << ")\n";
            }
        }
        if (queue.is_empty()) {
            cout << "no customer, rest...\n";
            continue;
        }
        //  应该开始处理队列里的第一个人
        if (remain_wait_time == 0) {
            remain_wait_time = queue.first().get_process_time();
            cout << "now begin to handle customer. current queue(size=" << queue.get_size() << "). it takes " << remain_wait_time << " minutes. \n";
        }
        //  time pass...
        remain_wait_time--;
        cout << "Time pass..." << remain_wait_time << "\n";
        //  如果队列非空，且队列中当前等待的人剩余等待时间已满，那么该 shift 了...
        if (remain_wait_time <= 0) {
            queue.dequeue(temp);
            //  设置为下一个顾客的等待时间
//            remain_wait_time = temp.get_process_time();
            cout << "ok, successfully handled one customer. current queue(size=" << queue.get_size() << ")\n";
        }
    }
}