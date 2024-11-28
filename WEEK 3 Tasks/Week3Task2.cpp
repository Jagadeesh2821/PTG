/*
    Task 2: Simulate an Instrument Cluster Data Display
Objective: Create a simplified data display system to simulate speed, fuel level, and engine temperature.
Requirements:
Implement a class-based design:
Create a VehicleData class to store parameters like speed, fuel level, and engine temperature.
Create a Display class to show these parameters on the console.
Simulate real-time updates:
Use a random number generator to update speed, fuel level, and temperature every second.
Display the updated data in a formatted manner (e.g., speed: 80 km/h, fuel: 50%, temperature: 90°C).
Add constraints:
Display warnings when parameters exceed thresholds (e.g., temperature > 100°C or fuel < 10%).
Deliverables:
A C++ program using multithreading (std::thread) to update and display data.
Output showcasing real-time updates and warnings.

Solution:
*/

#include <iostream>
#include <iomanip>
#include <chrono>
#include <random>
#include <thread>

using namespace std;

class VehicleData {
public:
    int speed{0};
    int fuelLevel{100};
    int temperature{90};

    void update() {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<int> speedChange(-5, 5);
        uniform_int_distribution<int> fuelChange(-1, 0);
        uniform_int_distribution<int> tempChange(-2, 2);

        speed = max(0, speed + speedChange(gen));
        fuelLevel = max(0, fuelLevel + fuelChange(gen));
        temperature += tempChange(gen);
    }
};

void displayData(const VehicleData& data) {
    system("clear"); // Use "cls" on Windows
    cout << "======================================\n";
    cout << "   Vehicle Instrument Cluster\n";
    cout << "======================================\n";
    cout << "Speed:        " << data.speed << " km/h\n";
    cout << "Fuel Level:   " << data.fuelLevel << " %\n";
    cout << "Temperature:  " << data.temperature << " °C\n";
    cout << "======================================\n";

    if (data.temperature > 100) {
        cout << "WARNING: Engine Overheating!\n";
    }
    if (data.fuelLevel < 10) {
        cout << "WARNING: Low Fuel Level!\n";
    }
    cout << "Press 'q' and Enter to quit.\n";
}

int main() {
    VehicleData vehicleData;

    while (true) {
        vehicleData.update();
        displayData(vehicleData);

        if (cin.peek() == 'q') {
            cin.ignore();
            break;
        }
        this_thread::sleep_for(chrono::seconds(1)); // Delay for updates
    }

    cout << "Simulation ended.\n";
    return 0;
}


/*
Output:

======================================
   Vehicle Instrument Cluster
======================================
Speed:        5 km/h
Fuel Level:   99 %
Temperature:  89 °C
======================================
Press 'q' and Enter to quit.
q
Simulation ended.
*/


