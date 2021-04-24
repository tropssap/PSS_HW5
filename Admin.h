//
// Created by User on 24.04.2021.
//

#ifndef PSS_HW5_ADMIN_H
#define PSS_HW5_ADMIN_H

#include "string"
using namespace std;


class Admin {

public:
    Admin(string adminLogin, string adminPassword);

    int id;
    string login,password;
};


#endif //PSS_HW5_ADMIN_H
