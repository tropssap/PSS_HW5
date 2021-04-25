
#ifndef CAR_H
#define CAR_H

#include <string>
#include <utility>
#include <iostream>
#include "Order.h"

using namespace std;

class Car {
public:

    Car(Car *pCar);

    enum Colors {
        YELLOW = 1,
        BLACK,
        WHITE,
        GRAY,
        RED,
        PINK,
        BLUE
    };

    enum CarType {
        Economy = 1,
        Comfort,
        ComfortPlus,
        Business
    };

    Car(string model, string number, int color, int carType, string current_coordinates);
    Car();

    string getModel() { return model; }
    string getCarType() const {
        switch (carType) {
            case 1: return "Economy";
            case 2: return "Comfort";
            case 3: return "Comfort Plus";
            case 4: return "Business";
        }
    }
    string getNumber() { return number; }
    string getColor() const {
        switch (color) {
            case 1: return "Yellow";
            case 2: return "Black";
            case 3: return "White";
            case 4: return "Gray";
            case 5: return "Red";
            case 6: return "Pink";
        }
    }

    string getCurrentCoordinates() { return current_coordinates; }

    int carType;
    string model;
    string number;
    int color;
    string current_coordinates;
};

#endif