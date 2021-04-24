//
// Created by User on 23.04.2021.
//

#ifndef PSS_HW5_DRIVERGATEWAY_H
#define PSS_HW5_DRIVERGATEWAY_H
using namespace std;

#include "BackEnd.h"

class DriverGateway {
private:
    BackEnd back;
public:
    //DriverGateway(BackEnd backEnd);

    DriverGateway(BackEnd anEnd);

    bool logIn(Driver driver);
    void lookForOrders(Driver driver);

    void acceptOrder(Driver driver, int numberForAccept);

    void endOrder(Driver driver);

    void addCar(Driver driver, Car car);
};


#endif //PSS_HW5_DRIVERGATEWAY_H
