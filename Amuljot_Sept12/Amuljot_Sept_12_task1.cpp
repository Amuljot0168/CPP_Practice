#include <bits/stdc++.h>
using namespace std;

// Base Abstract class
class Sensor
{
    // Data Members
public:
    int id;
    float value;
    float threshold;
    string status;

    // Base class constructor
    Sensor(int id, float value, float threshold) : id(id), value(value), threshold(threshold), status("OK") {}

    // pure vurtual function to make abstract class
    virtual void simulateFault() = 0;

    // return true if value> threshold
    bool isFaulty()
    {
        if (value > threshold)
        {
            return true;
        }
        return false;
    }
};

// Derived class TemperatureSensor
class TemperatureSensor : public Sensor
{
public:
    // Constructor
    TemperatureSensor(int id, float value, float threshold) : Sensor(id, value, threshold) {}

    // implement and override simualteFault() function
    void simulateFault() override
    {
        // Adding some temperature  to simulate fault
        value += 50.0;
        status = "Faulty";
    }
};

// Derived class PressureSensor
class PressureSensor : public Sensor
{
public:
    PressureSensor(int id, float value, float threshold) : Sensor(id, value, threshold) {}

    // implement and override simualteFault() function
    void simulateFault() override
    {
        // Adding some pressure to simulate fault
        value += 30.0;
        status = "Fault"; // change status to "Fault"
    }
};

// Actuator Class
class Actuator
{
public:
    int id;
    string state;
    int responseTime;

    // Actuator constructor
    Actuator(int id, string state, int responseTime) : id(id), state(state), responseTime(responseTime) {}

    // triggerAction function
    void triggerAction()
    {
        state = "Triggered";
        responseTime += 50;
    }
};

// FaultInjector class to inject faults
class FaultInjector
{
public:
    vector<Sensor *> sensors;
    vector<Actuator *> actuators;

    void injectSensorFault(Sensor *sensor)
    {
        // calls simulateFault() function of Sensor
        sensor->simulateFault();
    }

    void injectActuatorDelay(Actuator &actuator)
    {
        // calls triggerAction() function of Actuator
        actuator.triggerAction();
    }

    // Inject fault for all sensors and actuators
    void injectAllFaults()
    {
        for (auto s : sensors)
        {
            injectSensorFault(s);
        }

        for (auto a : actuators)
        {
            injectActuatorDelay(*a);
        }
    }

    // Provide Report status of each sensors and actuators
    void reportStatus()
    {
        for (Sensor *s : sensors)
        {
            cout << "Sensor [" << s->id << "] status = " << (s->isFaulty() ? "Fault" : "OK") << endl;
        }

        for (Actuator *a : actuators)
        {
            cout << "Actuator [" << a->id << "] state = " << a->state << " responseTime= " << a->responseTime << endl;
        }
    }
};

// ConfigManager class
class ConfigManager
{
public:
    void updateThreshold(Sensor &s, float newThreshold)
    {
        s.threshold = newThreshold;
    }
};

class FaultLogger
{
public:
    void log(Sensor &s)
    {
        ofstream file("fault_log.txt", ios::app);
        file << "Sensor Id: " << s.id << " Fault Detected: Value = " << s.value << " Threshold = " << s.threshold << endl;
        file.close();
    }
};

// Global Functions
void logFault(Sensor *s)
{
    if (s->isFaulty())
    {
        cout << "Logging fault for Sensor ID: " << s->id << "\n";
    }
}

void analyzeSystem(FaultInjector *fi)
{
    cout << "Analyzing System...\n";
    fi->reportStatus();
}

class SimulationEngine
{
public:
    FaultInjector fi;
    ConfigManager &configMgr;
    FaultLogger *logger;

    SimulationEngine(ConfigManager &cfg, FaultLogger *log) : configMgr(cfg), logger(log) {}

    void run()
    {
        TemperatureSensor *t1 = new TemperatureSensor(101, 95.0, 90.0);

        PressureSensor *p1 = new PressureSensor(102, 45.0, 50.0);
        PressureSensor *p2 = new PressureSensor(103, 60.0, 40.0);

        Actuator *a1 = new Actuator(201, "Idle", 120);
        Actuator *a2 = new Actuator(202, "Idle", 80);

        fi.sensors.push_back(t1);
        fi.sensors.push_back(p1);
        fi.sensors.push_back(p2);

        fi.actuators.push_back(a1);
        fi.actuators.push_back(a2);

        configMgr.updateThreshold(*p1, 40.0); // Lower threshold
        configMgr.updateThreshold(*t1, 85.0); // Lower threshold

        fi.injectAllFaults();

        // Logging in both file and terminal
        for (Sensor *s : fi.sensors)
        {
            if (s->isFaulty())
            {
                logger->log(*s);
                logFault(s);
            }
        }

        analyzeSystem(&fi);

        // Memory cleanup
        delete t1;
        delete p1;
        delete p2;
        delete a1;
        delete a2;
    }
};

// Main Function
int main()
{
    ConfigManager config;
    FaultLogger logger;
    SimulationEngine engine(config, &logger);
    engine.run();
    return 0;
}
