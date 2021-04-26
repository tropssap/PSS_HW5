//
// Created by User on 23.04.2021.
//

#include "PassengerGateway.h"

PassengerGateway::PassengerGateway(BackEnd backEnd) {
    back=backEnd;
}

bool PassengerGateway::LogIn(Passenger passenger) {
    return back.logInPassengerb(passenger);
}

void PassengerGateway::orderHistory(Passenger passenger1) {

    if(!LogIn(passenger1)){
        cout<<"Passenger not logged in"<<endl;
        return;
    }
    Passenger passenger=back.logInPassenger(passenger1);
    cout << "Getting order history..." << endl;
    vector<Order> orderHistory =  passenger.orderHistory;
    if (orderHistory.empty()) {
        cout << "Order history is empty!" << endl;
        return;
    }

    cout << "Order history of the " << passenger.getName() << " passenger:" << endl;
    for(int i = 0; i < orderHistory.size(); i++) {
        cout<<orderHistory[i].print()<<endl;
    }
}


void PassengerGateway::createOrder(Passenger passenger, string from, string to, int carType){
    if(!LogIn(passenger)){
        cout<<"Passenger not logged in"<<endl;
        return;
    }

    Passenger passenger1=back.logInPassenger(passenger);
    if(passenger1.active){
        cout<<passenger1.getName()<<" Passenger already in ride"<<endl;
        return;
    }
    if(passenger1.propose){
        cout<<passenger1.getName()<<" Passenger already ordered taxi"<<endl;
        return;

    }
    back.createOrder(passenger,from,to,carType);

    passenger1=back.logInPassenger(passenger);
    cout<<passenger1.getName()<<" price for this ride: "<<passenger1.proposedOrder.back().price<<endl;
}

void PassengerGateway::acceptRide(Passenger passenger, bool accept){
    if(!LogIn(passenger)){
        cout<<"Passenger not logged in"<<endl;
        return;
    }

    Passenger passenger1=back.logInPassenger(passenger);
    if(!accept || !passenger1.propose){
        cout<<"Passenger declined order"<<endl;
        passenger1.propose=false;
        return;
     }
    back.acceptRideByPassenger(passenger1);
    cout<<passenger1.getName()<<" Passenger accepted condition for ride. Looking for drivers"<<endl;
}

void PassengerGateway::getCoordinates(Passenger passenger){
    if(!LogIn(passenger)){
        cout<<"Passenger not logged in"<<endl;
        return;
    }
    Passenger passenger1=back.logInPassenger(passenger);
    if(!passenger1.active){
        cout<<passenger1.getName()<<" Passenger not in a ride"<<endl;
        return;
    }
    cout<<"In this moment passenger "<<passenger1.getName()<< " between "<<passenger1.activeOrder.back().from<<" and "<<passenger1.activeOrder.back().to<<endl;

}

void PassengerGateway::lookForPayment(Passenger passenger){
    if(!LogIn(passenger)){
        cout<<"Passenger not logged in"<<endl;
        return;
    }
    Passenger passenger1=back.logInPassenger(passenger);
    vector<string> payments=back.lookForPayments(passenger);
    cout<<passenger1.getName()<<"'s payment methods:"<<endl;
    for(int i=0;i<payments.size();i++){
        cout<<payments.at(i)<<endl;
    }
}

void PassengerGateway::addPayment(Passenger passenger, string payment){
    if(!LogIn(passenger)){
        cout<<"Passenger not logged in"<<endl;
        return;
    }
    back.addPayment(passenger,payment);
    cout<<"Payment successfully added"<<endl;
}
void PassengerGateway::lookForPinnedAddress(Passenger passenger){
    if(!LogIn(passenger)){
        cout<<"Passenger not logged in"<<endl;
        return;
    }
    Passenger passenger1=back.logInPassenger(passenger);
    vector<string> addresses=back.lookForPinnedAddresses(passenger);
    cout<<passenger1.getName()<<"'s pinned addresses:"<<endl;
    for(int i=0;i<addresses.size();i++){
        cout<<addresses.at(i)<<endl;
    }
}

void PassengerGateway::addPinnedAddress(Passenger passenger, string address){
    if(!LogIn(passenger)){
        cout<<"Passenger not logged in"<<endl;
        return;
    }
    back.addPinnedAddress(passenger,address);
    cout<<"Address successfully pinned"<<endl;
}