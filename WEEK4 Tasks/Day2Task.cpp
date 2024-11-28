/*
Task 2: Iterating Through Containers and Finding Elements
Goal: Practice iterating through containers and retrieving specific elements.
Scenario:
You are tasked with highlighting all active widgets on the HMI screen. The HMI has two main containers:
std::vector for dynamic widgets.
std::set for static widgets.
Steps:
Populate Containers:
Initialize a std::vector<std::string> with dynamic widgets ("Speedometer", "Tachometer", etc.).
Initialize a std::set<std::string> with static widgets ("Logo", "WarningLights").
Use Iterators:
Print all dynamic widgets using an iterator.
Check if a specific widget (e.g., "WarningLights") is in the std::set using std::set::find.
Advanced Iteration:
Combine both containers into a std::vector<std::string> using std::copy.
Use std::find to locate a specific widget in the combined container.
Output Results:
Print the widget list dynamically and show results of widget searches.
*/

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <string>
 
using namespace std;
 
int main() {
    // Step 1: Populate Containers
    vector<string> dynamicWidgets = {"Speedometer", "Tachometer", "FuelGauge"};
    set<string> staticWidgets = {"Logo", "WarningLights"};
 
    // Step 2: Use Iterators - Print all dynamic widgets
    cout << "Dynamic Widgets:" << endl;
    for (const auto& widget : dynamicWidgets) {
        cout << widget << endl;
    }
    cout << endl;
 
    // Check if a specific widget (e.g., "WarningLights") exists in the static widgets
    string searchStaticWidget = "WarningLights";
    if (staticWidgets.find(searchStaticWidget) != staticWidgets.end()) {
        cout << searchStaticWidget << " is present in static widgets." << endl;
    } else {
        cout << searchStaticWidget << " is not present in static widgets." << endl;
    }
    cout << endl;
 
    // Step 3: Advanced Iteration - Combine containers
    vector<string> combinedWidgets;
    combinedWidgets.reserve(dynamicWidgets.size() + staticWidgets.size()); // Optimize memory allocation
    copy(dynamicWidgets.begin(), dynamicWidgets.end(), back_inserter(combinedWidgets));
    copy(staticWidgets.begin(), staticWidgets.end(), back_inserter(combinedWidgets));
 
    // Print combined widgets
    cout << "Combined Widgets:" << endl;
    for (const auto& widget : combinedWidgets) {
        cout << widget << endl;
    }
    cout << endl;
 
    // Use std::find to locate a specific widget in the combined container
    string searchCombinedWidget = "Tachometer";
    auto it = find(combinedWidgets.begin(), combinedWidgets.end(), searchCombinedWidget);
    if (it != combinedWidgets.end()) {
        cout << searchCombinedWidget << " found in combined widgets." << endl;
    } else {
        cout << searchCombinedWidget << " not found in combined widgets." << endl;
    }
 
    return 0;
}
