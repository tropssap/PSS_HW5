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


    Car car("TT","1234",2,3,"0");
    driverGateway.addCar(driver,car);
    cout<<endl;
    adminGateway.lookForCarsInQueue(admin);
    cout<<endl;
    adminGateway.validateCar(admin,0);
    cout<<endl;
   adminGateway.blockPassenger(admin,1);
////    passengerGateway.createOrder(passenger,"from","to",2);
    adminGateway.unBlockPassenger(admin,1);
    passengerGateway.createOrder(passenger,"from","to",1);
    cout<<endl;
    passengerGateway.acceptRide(passenger,1);
    cout<<endl;
    adminGateway.blockDriver(admin,1002);
  adminGateway.unBlockDriver(admin,1002);
    driverGateway.lookForOrders(driver1);
    cout<<endl;
   driverGateway.acceptOrder(driver1,0);
    cout<<endl;
   passengerGateway.getCoordinates(passengerFromSecondDevice);
    cout<<endl;
    driverGateway.endOrder(driver1);
    cout<<endl;
    passengerGateway.orderHistory(passengerFromSecondDevice);

    return 0;
}
