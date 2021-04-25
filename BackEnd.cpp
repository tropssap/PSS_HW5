//
// Created by User on 23.04.2021.
//

#include <fstream>
#include "BackEnd.h"

class blockError : exception {
    string message;
public:
    explicit blockError(string message) : message(std::move(message)), exception() {}
    string getMessage() { return message; }
};

BackEnd::BackEnd() {
    validationDrivers();
    validationPassengers();
    validationAdmins();
}


vector<Order> BackEnd::readActiveOrders() {

    ifstream fin("orders.txt");
    int n;
    fin >> n;
    vector<Order> orders;
    for (int i = 0; i < n; i++) {
        int pId, dId, carType, time;
        double price;
        string from, to;
        fin >> pId >> dId >> from >> to >> carType >> price >> time;
        Order order(pId, dId, from, to, carType, price, time);
        orders.push_back(order);
    }
    return orders;
    fin.close();
}

void BackEnd::writeActiveOrders(vector<Order> activeOrders) {
    ofstream fout("orders.txt");
    fout << activeOrders.size() << endl;
    for (int i = 0; i < activeOrders.size(); i++) {
        fout << activeOrders[i].PassengerID << " " << activeOrders[i].DriverID << " " << activeOrders[i].from << " "
             << activeOrders[i].to << " " << activeOrders[i].type << " " << activeOrders[i].price << " "
             << activeOrders[i].time << endl;
    }

    fout.close();
}

void BackEnd::validationAdmins(){
    validAdmins.clear();
    ifstream fin("admins.txt");
    int numberOfUsers;
    fin>>numberOfUsers;
    for(int i=0;i<numberOfUsers;i++){
        int id;
        string login,password;
        fin>>id>>login>>password;

        Admin admin(login, password);
        admin.id=id;
        validAdmins.push_back(admin);
    }
    fin.close();
}


void BackEnd::validationPassengers() {
    validPassengers.clear();
    ifstream fin("passengers.txt");
    int numberOfUsers;
    fin >> numberOfUsers;
    for (int i = 0; i < numberOfUsers; i++) {

        string login;
        string password;
        int id;
        bool block;
        fin >> id>>block >> login >> password;
        Passenger passenger(login, password);
        passenger.id = id;
        passenger.isBlocked=block;
        string name;
        double rating;
        int numberOfOrders;
        fin >> name >> rating >> numberOfOrders;
        passenger.name = name;
        passenger.rating = rating;
        for (int j = 0; j < numberOfOrders; j++) {
            string from, to;
            double price;
            int time, type, dId;
            fin >> from >> to >> type >> price >> time >> dId;
            Order order(id, dId, from, to, type, price, time);
            passenger.orderHistory.push_back(order);
        }
        int numberOfpayments;
        fin >> numberOfpayments;
        for (int j = 0; j < numberOfpayments; j++) {
            string method;
            fin >> method;
            passenger.paymentMethods.push_back(method);
        }
        int numberOfAdresses;
        fin >> numberOfAdresses;
        for (int j = 0; j < numberOfAdresses; j++) {
            string adress;
            fin >> adress;
            passenger.pinnedAdresses.push_back(adress);
        }
        fin>>passenger.propose>>passenger.active;
        string from, to;
        int type,time,dId;
        double price;
        fin>>from>>to>>type>>price>>time>>dId;
        Order pr(id,dId,from,to,type,price,time);
        passenger.proposedOrder.push_back(pr);
        fin>>from>>to>>type>>price>>time>>dId;
        Order ac(id,dId,from,to,type,price,time);
        passenger.activeOrder.push_back(ac);
        validPassengers.push_back(passenger);
    }
    fin.close();

}

void BackEnd::validationDrivers() {
    validDrivers.clear();
    ifstream fin("drivers.txt");
    int numberOfUsers;
    fin >> numberOfUsers;
    for (int i = 0; i < numberOfUsers; i++) {

        string login;
        string password;
        int id;
        bool block;
        fin >> id >>block>> login >> password;
        Driver driver(login, password);
        driver.isBlocked=block;
        string name;
        double rating;
        int numberOfOrders;
        fin >> name >> rating >> numberOfOrders;

        driver.id = id;
        driver.rating = rating;
        driver.name = name;
        for (int j = 0; j < numberOfOrders; j++) {
            string from, to;
            double price;
            int time, type, pId;
            fin >> from >> to >> type >> price >> time >> pId;
            Order order(pId, id, from, to, type, price, time);
            driver.orderHistory.push_back(order);
        }
        string model, number;
        int type, color;
        int carsNumber,chosen;
        fin>>carsNumber>>chosen;
        driver.chosenCar=chosen;
        for(int j=0;j<carsNumber;j++){
        fin >> model >> type >> color >> number;
        Car car(model, number, color, type, "0");
        driver.cars.push_back(car);
        }
        fin>>driver.status;
        string from, to;
        int time,pId;
        double price;
        fin>>from>>to>>type>>price>>time>>pId;
        Order pr(pId,id,from,to,type,price,time);
        driver.activeOrder.push_back(pr);
        int numberOfProposedOrders;
        fin>>numberOfProposedOrders;
        for (int j = 0; j < numberOfProposedOrders; j++) {
            string from, to;
            double price;
            int time, type, pId;
            fin >> from >> to >> type >> price >> time >> pId;
            Order order(pId, id, from, to, type, price, time);
            driver.proposedOrders.push_back(order);
        }

        validDrivers.push_back(driver);
    }

    fin.close();
}

Passenger BackEnd::logInPassenger(Passenger passenger) {
    validationPassengers();


    for (int i = 0; i < validPassengers.size(); i++) {
        if (passenger.login == validPassengers[i].login && passenger.password == validPassengers[i].password)
            return validPassengers[i];
    }
}

Driver BackEnd::logInDriver(Driver passenger) {
    for (int i = 0; i < validDrivers.size(); i++) {
        if (passenger.login == validDrivers[i].login && passenger.password == validDrivers[i].password)
            return validDrivers[i];
    }
}
Admin BackEnd::logInAdmin(Admin passenger) {
    for (int i = 0; i < validDrivers.size(); i++) {
        if (passenger.login == validAdmins[i].login && passenger.password == validAdmins[i].password)
            return validAdmins[i];
    }
}

bool BackEnd::logInPassengerb(Passenger passenger) {
   // validationPassengers();
    for (int i = 0; i < validPassengers.size(); i++) {
        if (passenger.login == validPassengers[i].login && passenger.password == validPassengers[i].password)
            return 1;
    }
    return 0;
}

bool BackEnd::logInDriverb(Driver passenger) {
    for (int i = 0; i < validDrivers.size(); i++) {
        if (passenger.login == validDrivers[i].login && passenger.password == validDrivers[i].password)
            return 1;
    }
    return 0;
}
bool BackEnd::logInAdminb(Admin passenger) {
    for (int i = 0; i < validAdmins.size(); i++) {
        if (passenger.login == validAdmins[i].login && passenger.password == validAdmins[i].password)
            return 1;
    }
    return 0;
}

int BackEnd::logInPassengeri(Passenger passenger) {
    validationPassengers();
    for (int i = 0; i < validPassengers.size(); i++) {
        if (passenger.login == validPassengers[i].login && passenger.password == validPassengers[i].password)
            return i;
    }
    return -1;
}

int BackEnd::logInDriveri(Driver passenger) {
    for (int i = 0; i < validDrivers.size(); i++) {
        if (passenger.login == validDrivers[i].login && passenger.password == validDrivers[i].password)
            return i;
    }
    return -1;
}
int BackEnd::logInAdmini(Admin passenger) {
    for (int i = 0; i < validAdmins.size(); i++) {
        if (passenger.login == validAdmins[i].login && passenger.password == validAdmins[i].password)
            return i;
    }
    return -1;
}

void BackEnd::acceptRideByPassenger(Passenger passenger) {
    validationPassengers();
    if(logInPassenger(passenger).isBlocked)
        throw blockError("Passenger blocked");
    int i = logInPassengeri(passenger);
   activeOrders= readActiveOrders();
    activeOrders.push_back(validPassengers.at(i).proposedOrder.back());
    //validPassengers.at(i).active = true;
    validPassengers.at(i).propose= false;
    validPassengers.at(i).activeOrder.at(0)=validPassengers.at(i).proposedOrder.back();
    writeActiveOrders(activeOrders);
    writePassengersFiles(validPassengers);
}

void BackEnd::createOrder(Passenger passenger, string from, string to, int carType) {
    validationPassengers();
    if(logInPassenger(passenger).isBlocked)
        throw blockError("Passenger blocked");

    int time = (rand() % 120 + 22);
    double price = (rand() % 10 + 2) * 0.3 * carType * time;
    int i = logInPassengeri(passenger);
    Order order(validPassengers[i].id, 0, from, to, carType, price, time);
    validPassengers[i].proposedOrder.push_back(order);
    validPassengers[i].propose = true;

    writePassengersFiles(validPassengers);
}

void BackEnd::acceptRideByDriver(Driver driver, int numberForAccept) {
    validationDrivers();
    if(logInDriver(driver).isBlocked)
        throw blockError("Driver blocked");
    validationPassengers();
  activeOrders=  readActiveOrders();
    int k = logInDriveri(driver);

    if(numberForAccept>=validDrivers[k].proposedOrders.size())
        return;
    validDrivers[k].setStatus(1);
    validDrivers[k].activeOrder.clear();
    validDrivers[k].activeOrder.push_back(validDrivers[k].proposedOrders.at(numberForAccept));

    validDrivers[k].activeOrder.back().DriverID = validDrivers[k].id;
    for (int i = 0; i < validPassengers.size(); i++)
        if (validPassengers[i].id == validDrivers[k].activeOrder.back().PassengerID)
            validPassengers[i].active= true;

    for(int j=0;j<activeOrders.size();j++){
        if(activeOrders.at(j).print()==validDrivers[k].proposedOrders.at(numberForAccept).print()){
            activeOrders.at(j)=activeOrders.back();
            activeOrders.pop_back();
        }
    }

    validDrivers[k].proposedOrders.clear();
    writeActiveOrders(activeOrders);
    writePassengersFiles(validPassengers);
    writeDriversFiles(validDrivers);
}

void BackEnd::endOrder(Driver driver) {
    validationPassengers();
    int k = logInDriveri(driver);
    validDrivers[k].setStatus(false);
    validDrivers[k].orderHistory.push_back(validDrivers[k].activeOrder.back());
    for (int i = 0; i < validPassengers.size(); i++) {
        if (validPassengers[i].id == driver.activeOrder.back().PassengerID) {
//            validPassengers[i].activeOrder.pop_back();
            validPassengers[i].active= false;
            validPassengers[i].orderHistory.push_back(validDrivers[k].activeOrder.back());
        }
    }

//    validDrivers[k].activeOrder.pop_back();
    writePassengersFiles(validPassengers);
    writeDriversFiles(validDrivers);
}


void BackEnd::lookForOrders(Driver driver) {
    validationDrivers();
    if(logInDriver(driver).isBlocked)
        throw blockError("Driver blocked");
    activeOrders = readActiveOrders();
    int k = logInDriveri(driver);
    validDrivers[k].proposedOrders.clear();
    for (int i = 0; i < activeOrders.size(); i++) {
        if (validDrivers[k].cars.at(validDrivers[k].chosenCar).carType >= activeOrders.at(i).type) {
            validDrivers[k].proposedOrders.push_back(activeOrders.at(i));
        }
    }
    writeDriversFiles(validDrivers);
}

vector<string> BackEnd::lookForPayments(Passenger passenger){
    validationPassengers();
    Passenger passenger1= logInPassenger(passenger);
    return passenger1.paymentMethods;
}

void BackEnd::addPayment(Passenger passenger,string method){
    validationPassengers();
    int k= logInPassengeri(passenger);
    validPassengers[k].paymentMethods.push_back(method);
    writePassengersFiles(validPassengers);
}

vector<string> BackEnd::lookForPinnedAddresses(Passenger passenger){
    validationPassengers();
    Passenger passenger1= logInPassenger(passenger);
    return passenger1.pinnedAdresses;
}

void BackEnd::addPinnedAddress(Passenger passenger,string method){
    validationPassengers();
    int k= logInPassengeri(passenger);
    validPassengers[k].pinnedAdresses.push_back(method);
    writePassengersFiles(validPassengers);
}







void BackEnd::writePassengersFiles(vector<Passenger> passengers) {
    ofstream fout("passengers.txt");
    fout<<passengers.size()<<endl;
    for (int i = 0; i < passengers.size(); i++) {
        Passenger p=passengers.at(i);

        fout <<p.id<<" "<<p.isBlocked<<endl;
        fout<<p.login<<" "<<p.password<<endl;
        fout<<p.name<<endl<<p.rating<<endl<<p.orderHistory.size()<<endl;
        for(int j=0;j<p.orderHistory.size();j++){
            Order o=p.orderHistory.at(j);
            fout<<o.from<<" "<<o.to<<" "<<o.type<<" "<<o.price<<" "<<o.time<<" "<<o.DriverID<<endl;
        }
        fout<<p.paymentMethods.size()<<endl;

        for(int j=0;j<p.paymentMethods.size();j++)
            fout<<p.paymentMethods.at(j)<<endl;
        fout<<p.pinnedAdresses.size()<<endl;
        for(int j=0;j<p.pinnedAdresses.size();j++)
            fout<<p.pinnedAdresses.at(j)<<endl;
        fout<<p.propose<<endl<<p.active<<endl;
        Order pr=p.proposedOrder.back();
        fout<<pr.from<<" "<<pr.to<<" "<<pr.type<<" "<<pr.price<<" "<<pr.time<<" "<<pr.DriverID<<endl;
        Order ac=p.activeOrder.back();
        fout<<ac.from<<" "<<ac.to<<" "<<ac.type<<" "<<ac.price<<" "<<ac.time<<" "<<ac.DriverID<<endl;
        fout<<endl;
    }
    fout.close();
}

void BackEnd::writeDriversFiles(vector<Driver> passengers) {
    ofstream fout("drivers.txt");
    fout<<passengers.size()<<endl;
    for (int i = 0; i < passengers.size(); i++) {
        Driver p=passengers.at(i);

        fout <<p.id<<" "<<p.isBlocked<<endl;
        fout<<p.login<<" "<<p.password<<endl;
        fout<<p.name<<endl<<p.rating<<endl<<p.orderHistory.size()<<endl;
        for(int j=0;j<p.orderHistory.size();j++){
            Order o=p.orderHistory.at(j);
            fout<<o.from<<" "<<o.to<<" "<<o.type<<" "<<o.price<<" "<<o.time<<" "<<o.PassengerID<<endl;
        }

        fout<<p.cars.size()<<" "<< p.chosenCar<<endl;
        for(int j=0;j<p.cars.size();j++)
        fout<<p.cars.at(j).model<<" "<<p.cars.at(j).carType<<" "<<p.cars.at(j).color<<" "<<p.cars.at(j).number<<endl;

        fout<<p.status<<endl;
        Order ac=p.activeOrder.back();
        fout<<ac.from<<" "<<ac.to<<" "<<ac.type<<" "<<ac.price<<" "<<ac.time<<" "<<ac.PassengerID<<endl;
        fout<<p.proposedOrders.size()<<endl;
        for(int j=0;j<p.proposedOrders.size();j++){
            Order o=p.proposedOrders.at(j);
            fout<<o.from<<" "<<o.to<<" "<<o.type<<" "<<o.price<<" "<<o.time<<" "<<o.PassengerID<<endl;
        }
        fout<<endl;
    }
    fout.close();
}

void BackEnd::writeAdminFiles(vector<Admin> admins){
    ofstream fout("admins.txt");
    fout<<admins.size()<<endl;
    for(int i=0;i<admins.size();i++){
        Admin a=admins.at(i);
        fout<<a.id<<endl<<a.login<<" "<<a.password<<endl;

        fout<<endl;
    }
    fout.close();

}

void BackEnd::blockPassenger(Admin admin, int id){
    validationPassengers();
    if(!logInAdminb(admin))
        return;
    for(int i=0;i<validPassengers.size();i++){
        if(id==validPassengers.at(i).id)
            validPassengers.at(i).isBlocked= true;
    }
    writePassengersFiles(validPassengers);
}
void BackEnd::unBlockPassenger(Admin admin, int id){
    validationPassengers();
    if(!logInAdminb(admin))
        return;
    for(int i=0;i<validPassengers.size();i++){
        if(id==validPassengers.at(i).id)
            validPassengers.at(i).isBlocked= false;
    }
    writePassengersFiles(validPassengers);
}
void BackEnd::blockDriver(Admin admin, int id){
    validationDrivers();
    if(!logInAdminb(admin))
        return;
    for(int i=0;i<validDrivers.size();i++){
        if(id==validDrivers.at(i).id)
            validDrivers.at(i).isBlocked= true;
    }
    writeDriversFiles(validDrivers);
}
void BackEnd::unBlockDriver(Admin admin, int id){
    validationDrivers();
    if(!logInAdminb(admin))
        return;
    for(int i=0;i<validDrivers.size();i++){
        if(id==validDrivers.at(i).id)
            validDrivers.at(i).isBlocked= false;
    }
    writeDriversFiles(validDrivers);
}

vector<Passenger> BackEnd::seePassengers(Admin admin){
    validationPassengers();
    if(!logInAdminb(admin)){
        vector<Passenger> p;
        return p;}
    return validPassengers;
}
vector<Driver> BackEnd::seeDrivers(Admin admin){
    validationDrivers();
    if(!logInAdminb(admin)){
        vector<Driver> p;
        return p;}
    return validDrivers;
}
vector<Order> BackEnd::seeActiveOrders(Admin admin){
    if(!logInAdminb(admin)){
        vector<Order> p;
        return p;}

    activeOrders=  readActiveOrders();
    return activeOrders;
}

void BackEnd::addCarDriver(Driver driver,Car car){
    readCarQueue();
    carQD.push_back(logInDriver(driver).id);
    carQueue.push_back(car);
    writeCarQueue();
}

void BackEnd::writeCarQueue(){
    ofstream fout("carQueue.txt");
    fout<<carQueue.size()<<endl;
    for(int i=0;i<carQueue.size();i++){
        Car c=carQueue.at(i);
        fout<<carQD.at(i)<<" "<<c.model<<" "<<c.carType<<" "<<c.color<<" "<<c.number<<endl;
    }
    fout.close();
}

void BackEnd::readCarQueue(){
    ifstream fin("carQueue.txt");
    int n;
    carQueue.clear();
    carQD.clear();
    fin>>n;
    for(int i=0;i<n;i++){
        int id,carType,color;
        string model,number;
        fin>>id>>model>>carType>>color>>number;
        Car c(model,number,color,carType,"0");
        carQueue.push_back(c);
        carQD.push_back(id);
    }

    fin.close();
}

vector<string> BackEnd::seeCarsInQueue(Admin admin){
    vector<string> q;
    if(!logInAdminb(admin))
        return q;
    readCarQueue();
    for(int i=0;i<carQueue.size();i++){
        string t;
        t= to_string(carQD.at(i)) +" "+ carQueue.at(i).model+" "+carQueue.at(i).getColor()+" "+carQueue.at(i).getCarType()+" "+carQueue.at(i).number;
        q.push_back(t);
    }
    return q;
}

void BackEnd::addCarAdmin(Admin admin,int n){
    if(!logInAdminb(admin))
        return;
    readCarQueue();
    for(int i=0;i<validDrivers.size();i++){
        if(validDrivers.at(i).id==carQD.at(n)){
            validDrivers.at(i).cars.push_back(carQueue.at(n));
        }
    }
    carQueue.at(n)=carQueue.back();
    carQueue.pop_back();
    carQD.at(n)=carQD.back();
    carQD.pop_back();
    writeDriversFiles(validDrivers);
    writeCarQueue();
}