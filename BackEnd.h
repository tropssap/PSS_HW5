//
// Created by User on 23.04.2021.
//

#ifndef PSS_HW5_BACKEND_H
#define PSS_HW5_BACKEND_H


#include "Passenger.h"
#include "Driver.h"
#include "Admin.h"

class BackEnd {
private:
    void validationPassengers();

    void validationDrivers();
    vector<Admin> validAdmins;
    vector<Passenger> validPassengers;
    vector<int> carQD;
    vector<Car> carQueue;
    vector<Driver> validDrivers;
public:
    vector<Order> activeOrders;

    BackEnd();

    Passenger logInPassenger(Passenger passenger);

    Driver logInDriver(Driver passenger);

    bool logInPassengerb(Passenger passenger);

    bool logInDriverb(Driver passenger);

    void acceptRideByPassenger(Passenger passenger);

    void createOrder(Passenger passenger, string from, string to, int carType);

    void acceptRideByDriver(Driver driver1, int numberForAccept);

    void endOrder(Driver driver);

    int logInPassengeri(Passenger passenger);

    int logInDriveri(Driver passenger);

    void lookForOrders(Driver driver);

    vector<Order> readActiveOrders();

    void writeActiveOrders(vector<Order> activeOrders);

    void writePassengersFiles(vector<Passenger> passengers);

    void writeDriversFiles(vector<Driver> passengers);

    vector<string> lookForPayments(Passenger passenger);

    void addPayment(Passenger passenger, string method);

    vector<string> lookForPinnedAddresses(Passenger passenger);

    void addPinnedAddress(Passenger passenger, string method);

    void validationAdmins();

    void writeAdminFiles(vector<Admin> admins);

    int logInAdmini(Admin passenger);

    bool logInAdminb(Admin passenger);

    Admin logInAdmin(Admin passenger);

    void blockPassenger(Admin admin, int id);

    void unBlockPassenger(Admin admin, int id);

    void unBlockDriver(Admin admin, int id);

    void blockDriver(Admin admin, int id);

    void addCarDriver(Driver driver, Car car);

    void readCarQueue();

    void addCarAdmin(Admin admin, int n);

    void writeCarQueue();

    vector<string> seeCarsInQueue(Admin admin);

    vector<Passenger> seePassengers(Admin admin);

    vector<Driver> seeDrivers(Admin admin);

    vector<Order> seeActiveOrders(Admin admin);
};


#endif //PSS_HW5_BACKEND_H
