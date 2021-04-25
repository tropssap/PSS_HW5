//
// Created by User on 24.04.2021.
//

#include "AdminGateway.h"

AdminGateway::AdminGateway(BackEnd backEnd) {
 back=backEnd;
}

void AdminGateway::blockPassenger(Admin admin, int passengersId){
    if(!back.logInAdminb(admin)){
        cout<<"Admin not logged in"<<endl;
        return;
    }
    back.blockPassenger(admin,passengersId);
}
void AdminGateway::unBlockPassenger(Admin admin, int passengersId){
    if(!back.logInAdminb(admin)){
        cout<<"Admin not logged in"<<endl;
        return;
    }
    back.unBlockPassenger(admin,passengersId);
}
void AdminGateway::blockDriver(Admin admin, int driverId){
    if(!back.logInAdminb(admin)){
        cout<<"Admin not logged in"<<endl;
        return;
    }
    back.blockDriver(admin,driverId);
}
void AdminGateway::unBlockDriver(Admin admin, int driverId){
    if(!back.logInAdminb(admin)){
        cout<<"Admin not logged in"<<endl;
        return;
    }
    back.unBlockDriver(admin,driverId);
}

void AdminGateway::validateCar(Admin admin,int numberInList){
    if(!back.logInAdminb(admin)){
        cout<<"Admin not logged in"<<endl;
        return;
    }
    back.addCarAdmin(admin,numberInList);
    cout<<"Car successfully validated"<<endl;
}

void AdminGateway::lookForCarsInQueue(Admin admin){
    if(!back.logInAdminb(admin)){
        cout<<"Admin not logged in"<<endl;
        return;
    }
    vector<string> cars = back.seeCarsInQueue(admin);
    if(cars.empty())
        cout<<"There is no cars for validate"<<endl;
    for(int i=0;i<cars.size();i++){
        cout<<cars.at(i);
        cout<<".   Number for validating: "<<i<<endl;
    }
}

void AdminGateway::lookForAllPassengers(Admin admin ){
    if(!back.logInAdminb(admin)){
        cout<<"Admin not logged in"<<endl;
        return;
    }
    vector<Passenger> passengers=back.seePassengers(admin);
    cout<<"Admin looking for all valid passengers:"<<endl;
    for(int i=0;i<passengers.size();i++)
        cout<<passengers.at(i).id<<" "<<passengers.at(i).getName()<<" "<<passengers.at(i).login<<endl;
    cout<<endl;
}
void AdminGateway::lookForAllDrivers(Admin admin ){
    if(!back.logInAdminb(admin)){
        cout<<"Admin not logged in"<<endl;
        return;
    }
    vector<Driver> drivers=back.seeDrivers(admin);
    cout<<"Admin looking for all valid drivers:"<<endl;
    for(int i=0;i<drivers.size();i++)
        cout<<drivers.at(i).id<<" "<<drivers.at(i).getName()<<" "<<drivers.at(i).login<<endl;
    cout<<endl;
}
void AdminGateway::lookForAllActiveOrders(Admin admin ){
    if(!back.logInAdminb(admin)){
        cout<<"Admin not logged in"<<endl;
        return;
    }
    vector<Order> orders=back.seeActiveOrders(admin);
    if(orders.empty()){
        cout<<"There is no active orders"<<endl;
        return;
    }
    cout<<"Admin looking for active orders:"<<endl;
    for(int i=0;i<orders.size();i++)
        cout<<orders.at(i).print()<<endl;
    cout<<endl;
}