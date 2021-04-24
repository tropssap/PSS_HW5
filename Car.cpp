

#include "Car.h"

#include <utility>

Car::Car(string model, string number, int color, int carType, string current_coordinates) {
    this->model = std::move(model);
    this->number = std::move(number);
    this->color = color;
    this->carType = carType;
    this->current_coordinates = std::move(current_coordinates);
}

Car::Car() {}

Car::Car(Car *pCar) {

}
