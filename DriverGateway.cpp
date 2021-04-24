//
// Created by User on 23.04.2021.
//

#include "DriverGateway.h"

DriverGateway::DriverGateway(BackEnd anEnd) {
 back=anEnd;
}

bool DriverGateway::logIn(Driver passenger) {
    return back.logInDriverb(passenger);
}

void DriverGateway::lookForOrders(Driver driver) {
    if(!logIn(driver)){
        cout<<"Driver not logged in"<<endl;
        return;
    }
    back.lookForOrders(driver);
    cout<<"Driver looking for orders"<<endl;
    Driver driver1=back.logInDriver(driver);
    for(int i=0;i<driver1.proposedOrders.size();i++)
            cout<<driver1.proposedOrders[i].print()<<" number for accept "<<i<<endl;
    if(driver1.proposedOrders.empty())
        cout<<"No available orders"<<endl;
}


void DriverGateway::acceptOrder(Driver driver, int numberForAccept){

    if(!logIn(driver)){
        cout<<"Driver not logged in"<<endl;
        return;
    }
    Driver driver1 = back.logInDriver(driver);
    if(driver1.getStatus()){
        cout<<"Driver already in ride"<<endl;
        return;
    }

    back.acceptRideByDriver(driver1,numberForAccept);
    cout<<"Driver accepted a ride"<<endl;

}

void DriverGateway::endOrder(Driver driver){

    if(!logIn(driver)){
        cout<<"Driver not logged in"<<endl;
        return;
    }
    Driver driver1 = back.logInDriver(driver);
    if(!driver1.getStatus()){
        cout<<"Driver not in a ride"<<endl;
        return;
    }
    back.endOrder(driver1);
    cout<<"Driver finished the ride"<<endl;
}


void DriverGateway::addCar(Driver driver, Car car){
    if(!logIn(driver)){
        cout<<"Driver not logged in"<<endl;
        return;
    }
    back.addCarDriver(driver, car);
}
