#ifndef FLIGHT_H
#define FLIGHT_H

#include <string>

enum FlightStatus
{
    PARKED,
    TAXIING,
    WAITING_TO_TAKEOFF,
    TAKING_OFF,
    CLIMBING,
    CRUISING,
    CHANGING_ALTITUDE,
    DESCENDING,
    LANDING,
    AT_GATE
};

class Flight
{
private:
    std::string airline;       // Name of airline
    std::string flightNumber;  // Flight Number
    std::string makeModel;     // Model name
    int currentAltitude;       // Altitude of flight
    int airSpeed;              // Speed of air
    int direction;             // Direction of flight
    char origin[3];            // Origin location of flight
    char destination[3];       // Destination location of flight
    std::string departureTime; // Departure Time of flight
    std::string arrivalTime;   // Arrival Time of flight
    FlightStatus status;       // Status of Flight

public:
    Flight(std::string air, std::string number, std::string model, int altitude,
           int speed, int dir, std::string from, std::string to,
           std::string depart, std::string arrive, FlightStatus stat);

    // Get Functions
    std::string getAirline() const;
    std::string getFlightNumber() const;
    std::string getMakeModel() const;
    int getCurrentAltitude() const;
    int getAirSpeed() const;
    int getDirection() const;
    std::string getOrigin() const;
    std::string getDestination() const;
    std::string getDepartureTime() const;
    std::string getArrivalTime() const;
    FlightStatus getStatus() const;

    // Set Functions
    void setAirline(const std::string &air);
    void setFlightNumber(const std::string &number);
    void setMakeModel(const std::string &model);
    void setCurrentAltitude(int altitude);
    void setAirSpeed(int speed);
    void setDirection(int dir);
    void setOrigin(const std::string &from);
    void setDestination(const std::string &to);
    void setDepartureTime(const std::string &time);
    void setArrivalTime(const std::string &time);
    void setStatus(FlightStatus stat);

    // Member Functions
    void changeAltitude(int newAlt); // Function to change flight altitude
    void reduceSpeed(int newSpeed);  // Function to reduce speed of flight
    void beginLandingApproach();     // Function to inform to begin Landing approach
    std::string toString() const;    // Function to change Flight details
};

#endif