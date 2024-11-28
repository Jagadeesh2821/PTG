/*
Task 3: Event Handling System for Touchscreen Input
Objective: Simulate an event-driven system for processing touchscreen inputs on an HMI.
Requirements:
Create an Event class to represent user interactions:
Attributes: eventType (e.g., Tap, Swipe), x and y coordinates, and timestamp.
Implement an event queue using std::queue:
Store multiple events.
Process events one by one.
Handle specific events:
Tap: Display a message showing the tapped position.
Swipe: Calculate the swipe direction (up/down/left/right) and display it.
Simulate event generation:
Populate the queue with random events.
Deliverables:
A program simulating event processing.
Example output demonstrating event handling.

solution:-
*/

#include <iostream>
#include <queue>
#include <string>
#include <random>
#include <ctime>
#include <cmath>

using namespace std;

// Define Event class
class Event {
public:
    string eventType;   // "Tap" or "Swipe"
    int x, y;           // Coordinates for the event
    int endX, endY;     // End coordinates for Swipe
    time_t timestamp;   // Time of event

    // Constructor for Tap
    Event(string type, int posX, int posY) 
        : eventType(type), x(posX), y(posY), endX(0), endY(0), timestamp(time(nullptr)) {}

    // Constructor for Swipe
    Event(string type, int startX, int startY, int endX, int endY) 
        : eventType(type), x(startX), y(startY), endX(endX), endY(endY), timestamp(time(nullptr)) {}
};

// Function to process events
void processEvents(queue<Event>& eventQueue) {
    while (!eventQueue.empty()) {
        Event event = eventQueue.front();
        eventQueue.pop();

        cout << "Event Type: " << event.eventType << " | Timestamp: " << ctime(&event.timestamp);
        
        if (event.eventType == "Tap") {
            cout << "Tap at (" << event.x << ", " << event.y << ")\n";
        } 
        else if (event.eventType == "Swipe") {
            // Determine swipe direction
            int dx = event.endX - event.x;
            int dy = event.endY - event.y;

            if (abs(dx) > abs(dy)) {
                if (dx > 0) cout << "Swipe Direction: Right\n";
                else cout << "Swipe Direction: Left\n";
            } 
            else {
                if (dy > 0) cout << "Swipe Direction: Down\n";
                else cout << "Swipe Direction: Up\n";
            }

            cout << "Swipe from (" << event.x << ", " << event.y << ") to (" 
                 << event.endX << ", " << event.endY << ")\n";
        }
        cout << "--------------------------------\n";
    }
}

// Function to generate random events
void generateRandomEvents(queue<Event>& eventQueue, int eventCount) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> coordDist(0, 500);  // Screen coordinates (0 to 500)
    uniform_int_distribution<int> typeDist(0, 1);     // 0 for Tap, 1 for Swipe

    for (int i = 0; i < eventCount; ++i) {
        if (typeDist(gen) == 0) {
            // Generate Tap event
            int x = coordDist(gen);
            int y = coordDist(gen);
            eventQueue.push(Event("Tap", x, y));
        } 
        else {
            // Generate Swipe event
            int startX = coordDist(gen);
            int startY = coordDist(gen);
            int endX = coordDist(gen);
            int endY = coordDist(gen);
            eventQueue.push(Event("Swipe", startX, startY, endX, endY));
        }
    }
}

int main() {
    queue<Event> eventQueue;

    // Simulate event generation
    generateRandomEvents(eventQueue, 5); // Generate 5 random events

    // Process the events
    processEvents(eventQueue);

    return 0;
} 




/*
Output:

Event Type: Tap | Timestamp: Mon Nov 25 17:55:38 2024
Tap at (387, 370)
--------------------------------
Event Type: Swipe | Timestamp: Mon Nov 25 17:55:38 2024
Swipe Direction: Up
Swipe from (261, 401) to (28, 0)
--------------------------------
Event Type: Swipe | Timestamp: Mon Nov 25 17:55:38 2024
Swipe Direction: Right
Swipe from (193, 351) to (443, 192)
--------------------------------
Event Type: Tap | Timestamp: Mon Nov 25 17:55:38 2024
Tap at (11, 364)
--------------------------------
Event Type: Swipe | Timestamp: Mon Nov 25 17:55:38 2024
Swipe Direction: Left
Swipe from (492, 315) to (124, 305)
--------------------------------

*/









