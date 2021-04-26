#include <iostream>
#include <ctime>
#include "Driver.h"
#include "Passenger.h"
#include "PassengerGateway.h"
#include "DriverGateway.h"
#include "BackEnd.h"
#include "AdminGateway.h"
#include "Admin.h"

using namespace std;

int main() {
    srand(time(0));
    Driver driver("tropssap3", "qazwsx");
    Passenger passenger("tropssap", "qazwsx");
    Passenger passengerFromSecondDevice("tropssap", "qazwsx");
    Admin admin("admin","admin");
    Driver driver1("tropssap4","qazwsx12");
    BackEnd backEnd;
    PassengerGateway passengerGateway(backEnd);
    DriverGateway driverGateway(backEnd);
    AdminGateway adminGateway(backEnd);

///1 creating, accepting and execution of order, getting coordinates, showing order history
    passengerGateway.createOrder(passenger,"from","to",2);
    cout<<endl;
    passengerGateway.acceptRide(passenger,1);
    cout<<endl;
    passengerGateway.getCoordinates(passengerFromSecondDevice);
    cout<<endl;
    driverGateway.lookForOrders(driver1);
    cout<<endl;
    driverGateway.acceptOrder(driver1,0);
    cout<<endl;
    passengerGateway.getCoordinates(passengerFromSecondDevice);
    cout<<endl;
    driverGateway.endOrder(driver1);
    cout<<endl;
    passengerGateway.orderHistory(passengerFromSecondDevice);
    cout<<endl;

///1 admin is looking for all drives and blocks one of them
    adminGateway.lookForAllDrivers(admin);
    adminGateway.unBlockDriver(admin,1002);

///2 creating and declining order
    passengerGateway.createOrder(passenger,"fromAddress","toAddress",3);
    cout<<endl;
    passengerGateway.acceptRide(passenger,0);
    cout<<endl;

///3 driver is looking for available orders, but there is no such
    driverGateway.lookForOrders(driver1);
    cout<<endl;

///4 passenger is adding payment method and looking for it from second device
    passengerGateway.addPayment(passenger,"visa*9999");
    cout<<endl;
    passengerGateway.lookForPayment(passengerFromSecondDevice);

///6 validating a car
    Car car("TT","1234",2,3,"0");
    driverGateway.addCar(driver,car);
    cout<<endl;
    adminGateway.lookForCarsInQueue(admin);
    cout<<endl;
    adminGateway.validateCar(admin,0);
    cout<<endl;

///7 not logged passenger is trying to create an order
    Passenger passengerWithWrongLogin("login","wrongPassword");
    passengerGateway.createOrder(passengerWithWrongLogin,"from","to",3);

//   adminGateway.blockPassenger(admin,1);
//    adminGateway.unBlockPassenger(admin,1);
//    adminGateway.blockDriver(admin,1002);
//  adminGateway.unBlockDriver(admin,1002);

    return 0;
}
