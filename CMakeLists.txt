cmake_minimum_required(VERSION 3.9)
project(CalProject2017)

set(CMAKE_CXX_STANDARD 11)

add_executable(CalProject2017
        BikeSharing-Parte1/src/BikeCompany.cpp
        BikeSharing-Parte1/src/BikeCompany.h
        BikeSharing-Parte1/src/main.cpp
        BikeSharing-Parte1/src/Menu.cpp
        BikeSharing-Parte1/src/Menu.h
        BikeSharing-Parte1/src/Node.cpp
        BikeSharing-Parte1/src/Node.h
        BikeSharing-Parte1/src/Parser.cpp
        BikeSharing-Parte1/src/Parser.h
        BikeSharing-Parte1/src/SharingSpot.cpp
        BikeSharing-Parte1/src/SharingSpot.h
        BikeSharing-Parte1/src/Street.cpp
        BikeSharing-Parte1/src/Street.h BikeSharing-Parte1/src/exceptions.h BikeSharing-Parte1/src/exceptions.cpp
        BikeSharing-Parte1/src/User.cpp BikeSharing-Parte1/src/User.h BikeSharing-Parte1/src/Relation.h BikeSharing-Parte1/src/Relation.cpp)