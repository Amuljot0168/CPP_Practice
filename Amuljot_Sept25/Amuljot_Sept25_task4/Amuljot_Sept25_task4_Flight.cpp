#include <iostream>
#include <cstring>
#include "Amuljot_Sept25_task4_Flight.h"

// Parameterised Constructor
Flight::Flight(std::string air, std::string number, std::string model, int altitude, int speed, int dir, std::string from, std::string to,
               std::string depart, std::string arrive, FlightStatus stat)
    : airline(air), flightNumber(number), makeModel(model),
      airSpeed(speed), direction(dir), departureTime(depart),
      arrivalTime(arrive), status(stat), currentAltitude(altitude)
{
    std::strncpy(origin, from.c_str(), 3);
    std::strncpy(destination, to.c_str(), 3);
}

// Get Functions
std::string Flight::getAirline() const { return airline; }                         // Return Airline name
std::string Flight::getFlightNumber() const { return flightNumber; }               // return Flight Number
std::string Flight::getMakeModel() const { return makeModel; }                     // Return Model name of flight
int Flight::getCurrentAltitude() const { return currentAltitude; }                 // Return Altitude
int Flight::getAirSpeed() const { return airSpeed; }                               // return the air speed
int Flight::getDirection() const { return direction; }                             // return the direction of flight
std::string Flight::getOrigin() const { return std::string(origin, 3); }           // return origin location
std::string Flight::getDestination() const { return std::string(destination, 3); } // return destination location
std::string Flight::getDepartureTime() const { return departureTime; }             // return Departure Time
std::string Flight::getArrivalTime() const { return arrivalTime; }                 // return Arrival time of flight
FlightStatus Flight::getStatus() const { return status; }                          // return status of flight

// Set Functions
void Flight::setAirline(const std::string &air) { airline = air; }
void Flight::setFlightNumber(const std::string &number) { flightNumber = number; }
void Flight::setMakeModel(const std::string &model) { makeModel = model; }
void Flight::setCurrentAltitude(int altitude) { currentAltitude = altitude; }
void Flight::setAirSpeed(int speed) { airSpeed = speed; }
void Flight::setDirection(int dir) { direction = dir; }
void Flight::setOrigin(const std::string &from) { std::strncpy(origin, from.c_str(), 3); }
void Flight::setDestination(const std::string &to) { std::strncpy(destination, to.c_str(), 3); }
void Flight::setDepartureTime(const std::string &time) { departureTime = time; }
void Flight::setArrivalTime(const std::string &time) { arrivalTime = time; }
void Flight::setStatus(FlightStatus stat) { status = stat; }

// ✅ Member Functions

// Function to change the altitude of flight
void Flight::changeAltitude(int newAlt)
{
    std::cout << airline << " " << flightNumber
              << " changing altitude from " << currentAltitude
              << " to " << newAlt << " feet.\n";
    currentAltitude = newAlt;
    status = CHANGING_ALTITUDE;
}

// Function to reduce the speed of flight
void Flight::reduceSpeed(int newSpeed)
{
    std::cout << airline << " " << flightNumber
              << " reducing speed from " << airSpeed
              << " to " << newSpeed << ".\n";
    airSpeed = newSpeed;
}

// Function to begin flight's Landing Approach
void Flight::beginLandingApproach()
{
    std::cout << airline << " " << flightNumber
              << " beginning landing approach.\n";
    status = DESCENDING;
    setCurrentAltitude(getCurrentAltitude() - 5000);
}

// Function print all the details of flight
std::string Flight::toString() const
{
    std::string statusText[] = {
        "Parked", "Taxiing", "Waiting to Take Off", "Taking Off",
        "Climbing", "Cruising", "Changing Altitude", "Descending",
        "Landing", "At Gate"};

    std::string info = airline + " " + flightNumber + " [" + makeModel + "]\n";
    info += "From " + std::string(origin, 3) + " to " + std::string(destination, 3) + "\n";
    info += "Departure: " + departureTime + ", Arrival: " + arrivalTime + "\n";
    info += "Speed of Air: " + std::to_string(airSpeed) + " , Direction: " + std::to_string(direction) + "\n";
    info += "Current Altitude: " + std::to_string(currentAltitude) + " ft\n";
    info += "Status: " + statusText[status] + "\n";

    return info;
}
