//
// Created by User on 24.04.2021.
//

#ifndef PSS_HW5_ADMINGATEWAY_H
#define PSS_HW5_ADMINGATEWAY_H


#include "BackEnd.h"

class AdminGateway {
private:
    BackEnd back;
public:
    AdminGateway(BackEnd backEnd);

    void blockPassenger(Admin admin, int passengersId);

    void unBlockPassenger(Admin admin, int passengersId);

    void blockDriver(Admin admin, int driverId);

    void unBlockDriver(Admin admin, int driverId);

    void validateCar(Admin admin, int numerInList);

    void lookForCarsInQueue(Admin admin);

    void lookForAllPassengers(Admin admin);

    void lookForAllActiveOrders(Admin admin);

    void lookForAllDrivers(Admin admin);
};


#endif //PSS_HW5_ADMINGATEWAY_H
