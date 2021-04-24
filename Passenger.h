//
// Created by User on 23.04.2021.
//

#ifndef PSS_HW5_PASSENGER_H
#define PSS_HW5_PASSENGER_H

#include <system_error>
#include "string"
#include "Order.h"
#include "vector"
using namespace std;

class Passenger {
public:
    Passenger(string PassengerLogin, string passengerPassword) {
        login = PassengerLogin;
        password = passengerPassword;
    }
    bool isBlocked;
    int id;
    string login;
    string password;
    double rating;

    string getName() { return name; }

    string name;
    vector<string> paymentMethods;

    vector<Order> orderHistory;
    vector<string> pinnedAdresses;
    vector<Order> activeOrder;
    vector<Order> proposedOrder;
    bool propose=false;
    bool active=false;
};


#endif //PSS_HW5_PASSENGER_H
