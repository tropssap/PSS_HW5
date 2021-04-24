

#ifndef DRIVER_H
#define DRIVER_H

#include <string>
#include <utility>
#include "Order.h"
#include "vector"
#include "Car.h"

using namespace std;

class Driver {
public:
    int id;
    vector<Order> proposedOrders;
    Driver(string driverLogin, string driverPassword) {
        login=driverLogin;
        password=driverPassword;
    }

    Driver(Driver *pDriver) {

    }
    vector<Order> activeOrder;
    vector<Car> cars;
    vector<Order> orderHistory;
    int chosenCar;
    bool isBlocked;
    string getName() { return name; }

    bool getStatus() { return status; }

    void setStatus(bool status) { this->status = status; }
    string login;
    string password;
    double rating;
    string name;

    bool status =  false;
private:


};


#endif
