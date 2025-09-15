#include <bits/stdc++.h>
using namespace std;

class Sensor;
void rebindCriticalSensor(Sensor *&ref, Sensor *list[], int size);
void printSensorMap(Sensor *list[], int size);

class Sensor
{
public:
    int id;
    float value;
    int priority;
    string status;

    Sensor(int id, float value, int priority) : id(id), value(value), priority(priority), status("OK")
    {
    }

    void updateValue(float v)
    {
        value = v; // update the value
    }
};

class Controller
{
public:
    Sensor *sensorList[10];
    Sensor &criticalSensor;

    Controller(Sensor *list[], int size) : criticalSensor(*list[0])
    {
        for (int i = 0; i < size; i++)
        {
            sensorList[i] = list[i];
        }
        bindCriticalSensor();
    }

    void bindCriticalSensor()
    {
        int maxpriority = -1;
        Sensor *mostcriticalone = NULL;

        for (int i = 0; i < 10; i++)
        {
            if (sensorList[i]->priority > maxpriority)
            {
                maxpriority = sensorList[i]->priority;
                mostcriticalone = sensorList[i];
            }
        }
        criticalSensor.id = mostcriticalone->id;
        criticalSensor.value = mostcriticalone->value;
        criticalSensor.priority = mostcriticalone->priority;
        criticalSensor.status = mostcriticalone->status;
    }

    void updateCriticalSensor()
    {
        Sensor *ref = NULL;

        rebindCriticalSensor(ref, sensorList, 10);

        criticalSensor.id = ref->id;
        criticalSensor.value = ref->value;
        criticalSensor.priority = ref->priority;
        criticalSensor.status = ref->status;
    }
    void printStatus()
    {
        cout << "Status: " << criticalSensor.status << endl;
    }
};

class SensorDiagnotics
{
public:
    string checkHealth(Sensor &s)
    {
        if (s.value > 100)
            return "Sensor is CRITICAL";
        else if (s.value < 60)
            return "Sensor is DOWN";
        else
            return "Sensor is OK";
    }
};

void rebindCriticalSensor(Sensor *&ref, Sensor *list[], int size)
{

    int maxpriority = -1;
    Sensor *mostcriticalone = NULL;

    for (int i = 0; i < 10; i++)
    {
        if (list[i]->priority > maxpriority)
        {
            maxpriority = list[i]->priority;
            mostcriticalone = list[i];
        }
    }
    ref = mostcriticalone;
}
void printSensorMap(Sensor *list[], int size)
{
    SensorDiagnotics diag;
    for (int i = 0; i < size; i++)
    {
        list[i]->status = diag.checkHealth(*list[i]);
        cout << "Sensor ID :" << list[i]->id << endl;
        cout << "Sensor VALUE :" << list[i]->value << endl;
        cout << "Sensor PRIORITY :" << list[i]->priority << endl;
        cout << "Sensor STATUS :" << list[i]->status << endl;

        cout << endl;
    }
}

int main()
{
    Sensor *s1 = new Sensor(1, 75.0, 3);
    Sensor *s2 = new Sensor(2, 60.0, 5);
    Sensor *s3 = new Sensor(3, 90.0, 2);
    Sensor *s4 = new Sensor(4, 55.0, 7);
    Sensor *s5 = new Sensor(5, 80.0, 10);
    Sensor *s6 = new Sensor(6, 100.0, 9);
    Sensor *s7 = new Sensor(7, 115.0, 8);
    Sensor *s8 = new Sensor(8, 77.0, 1);
    Sensor *s9 = new Sensor(9, 95.0, 4);
    Sensor *s10 = new Sensor(10, 89.0, 6);

    Sensor *list[10]{s1, s2, s3, s4, s5, s6, s7, s8, s9, s10};

    // Create controller
    Controller controller1(list, 10);

    // critical sensor
    Sensor &critical_sensor = controller1.criticalSensor;

    // Sensor Diagnotics before updating the value
    SensorDiagnotics sensor_diag;
    cout << "Sensor " << critical_sensor.id;
    cout << " Health: \n"
         << sensor_diag.checkHealth(critical_sensor) << endl;
    cout << endl;

    // Updating the value
    critical_sensor.updateValue(130.0);

    // Sensor Diagnotics

    cout << "Health: \n"
         << sensor_diag.checkHealth(critical_sensor) << endl;

    // Rebind
    controller1.updateCriticalSensor();

    // print Sensor map
    printSensorMap(list, 10);

    for (int i = 0; i < 10; i++)
    {
        delete list[i];
    }

    return 0;
}
