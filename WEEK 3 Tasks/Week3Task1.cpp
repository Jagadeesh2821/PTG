/*
Task 1: Build a Menu Navigation System
Objective: Implement a basic menu navigation system similar to what is found in automotive HMI clusters (e.g., settings menu, media options).
Requirements:
Create a hierarchical menu structure using classes and data structures.
Example:
Main Menu
Settings
Display Settings
Audio Settings
Media
Radio
Bluetooth Audio
Use a tree structure (std::vector or custom tree data structure) to represent the hierarchy.
Implement the following functionalities:
Navigate through menu levels (up/down/enter/back).
Display the current menu options on the console.
Add keyboard-based interaction (e.g., 1 to navigate down, 2 to navigate up, 3 to enter).
Deliverables:
A C++ program that uses OOP to create the menu structure.
Console output demonstrating navigation and interactions.

Solution:
*/
#include <iostream>
#include <vector>
#include <string>
#include <memory>

using namespace std;

class MenuItem {
public:
    string name;
    vector<shared_ptr<MenuItem>> subItems;

    MenuItem(const string& name) : name(name) {}

    void addSubItem(const shared_ptr<MenuItem>& item) {
        subItems.push_back(item);
    }
};

class MenuNavigation {
private:
    shared_ptr<MenuItem> root;
    shared_ptr<MenuItem> currentMenu;
    vector<shared_ptr<MenuItem>> path;

public:
    MenuNavigation(const shared_ptr<MenuItem>& rootMenu) : root(rootMenu), currentMenu(rootMenu) {}

    void displayCurrentMenu() {
        cout << "\n-- " << currentMenu->name << " --\n";
        for (size_t i = 0; i < currentMenu->subItems.size(); ++i) {
            cout << i + 1 << ". " << currentMenu->subItems[i]->name << "\n";
        }
        cout << "\nOptions: \n";
        cout << "1. Navigate Down\n";
        cout << "2. Navigate Up\n";
        cout << "3. Enter Submenu\n";
        cout << "4. Back\n";
        cout << "5. Exit\n";
    }

    void navigateDown() {
        if (!currentMenu->subItems.empty()) {
            path.push_back(currentMenu);
            currentMenu = currentMenu->subItems[0];
        } else {
            cout << "No submenus available.\n";
        }
    }

    void navigateUp() {
        if (!path.empty()) {
            currentMenu = path.back();
            path.pop_back();
        } else {
            cout << "Already at the root menu.\n";
        }
    }

    void enterSubmenu(size_t index) {
        if (index > 0 && index <= currentMenu->subItems.size()) {
            path.push_back(currentMenu);
            currentMenu = currentMenu->subItems[index - 1];
        } else {
            cout << "Invalid option.\n";
        }
    }

    void back() {
        navigateUp();
    }
};

int main() {
    // Building the menu hierarchy
    auto rootMenu = make_shared<MenuItem>("Main Menu");

    auto settings = make_shared<MenuItem>("Settings");
    settings->addSubItem(make_shared<MenuItem>("Display Settings"));
    settings->addSubItem(make_shared<MenuItem>("Audio Settings"));

    auto media = make_shared<MenuItem>("Media");
    media->addSubItem(make_shared<MenuItem>("Radio"));
    media->addSubItem(make_shared<MenuItem>("Bluetooth Audio"));

    rootMenu->addSubItem(settings);
    rootMenu->addSubItem(media);

    // Creating menu navigation system
    MenuNavigation menuSystem(rootMenu);

    int choice = 0;
    while (choice != 5) {
        menuSystem.displayCurrentMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                menuSystem.navigateDown();
                break;
            case 2:
                menuSystem.navigateUp();
                break;
            case 3: {
                cout << "Enter submenu index: ";
                size_t index;
                cin >> index;
                menuSystem.enterSubmenu(index);
                break;
            }
            case 4:
                menuSystem.back();
                break;
            case 5:
                cout << "Exiting menu navigation system.\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
                break;
        }
    }

    return 0;
}


/*
O/p:-
-- Main Menu --
1. Settings
2. Media

Options:
1. Navigate Down
2. Navigate Up
3. Enter Submenu
4. Back
5. Exit
Enter your choice: 3
Enter submenu index: 1

-- Settings --
1. Display Settings
2. Audio Settings

Options:
1. Navigate Down
2. Navigate Up
3. Enter Submenu
4. Back
5. Exit
Enter your choice:
*/




