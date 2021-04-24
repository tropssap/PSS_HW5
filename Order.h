//
// Created by User on 23.04.2021.
//

#ifndef PSS_HW5_ORDER_H
#define PSS_HW5_ORDER_H

#include "string"
using namespace std;

class Order {
private:
public:
    int time;
    int type;
    double price;
    int PassengerID;
    int DriverID;

    string from;
    string to;
    Order(int passengerId, int driverId, string fromAddress, string toAddress, int carType, double orderPrice,
          int timeInSeconds);

    string print();
};


#endif //PSS_HW5_ORDER_H
