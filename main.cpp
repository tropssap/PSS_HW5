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

    BackEnd backEnd;
    PassengerGateway passengerGateway(backEnd);
    DriverGateway driverGateway(backEnd);
    AdminGateway adminGateway(backEnd);

   /*passengerGateway.orderHistory(passenger);
  //  cout<<endl;
    passengerGateway.createOrder(passenger,"add","add2",1);
    passengerGateway.createOrder(passengerFromSecondDevice,"add","add2",1);
    passengerGateway.acceptRide(passenger,1);
    driverGateway.lookForOrders(driver);
    driverGateway.acceptOrder(driver,0);
    passengerGateway.getCoordinates(passengerFromSecondDevice);
    driverGateway.endOrder(driver);

    passengerGateway.orderHistory(passengerFromSecondDevice);
    Car car("TT","1234",2,3,"0");
    driverGateway.addCar(driver,car);
    adminGateway.lookForCarsInQueue(admin);
    adminGateway.validateCar(admin,0);*/
    adminGateway.blockPassenger(admin,1);
//    passengerGateway.createOrder(passenger,"from","to",2);
    adminGateway.unBlockPassenger(admin,1);
  //  passengerGateway.createOrder(passenger,"from","to",2);
    //passengerGateway.acceptRide(passenger,1);
    adminGateway.blockDriver(admin,1001);
   // driverGateway.lookForOrders(driver);
   adminGateway.unBlockDriver(admin,1001);
   driverGateway.lookForOrders(driver);
   
    return 0;
}
