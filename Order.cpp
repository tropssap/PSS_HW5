//
// Created by User on 23.04.2021.
//

#include "Order.h"
#include "string"

Order::Order(int passengerId, int driverId, string fromAddress, string toAddress, int carType, double orderPrice,
             int timeInSeconds) {
    PassengerID=passengerId;
    DriverID=driverId;
    from=fromAddress;
    to=toAddress;
    type=carType;
    price=orderPrice;
    time=timeInSeconds;
}

string Order::print(){
    string carType;
    switch (type) {
        case 1: carType= "Economy"; break;
        case 2: carType= "Comfort"; break;
        case 3: carType= "Comfort Plus"; break;
        case 4: carType= "Business"; break;
    }

    return from+" "+to+" "+ carType+" "+ to_string(price);
}