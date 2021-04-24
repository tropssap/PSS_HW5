cmake_minimum_required(VERSION 3.19)
project(PSS_HW5)

set(CMAKE_CXX_STANDARD 20)

add_executable(PSS_HW5 main.cpp Driver.cpp Driver.h Car.cpp Car.h Order.cpp Order.h Passenger.cpp Passenger.h PassengerGateway.cpp PassengerGateway.h DriverGateway.cpp DriverGateway.h BackEnd.cpp BackEnd.h AdminGateway.cpp AdminGateway.h Admin.cpp Admin.h)