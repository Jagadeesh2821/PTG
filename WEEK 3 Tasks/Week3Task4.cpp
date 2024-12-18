/*
    Task 4: HMI Skin Customization System
Objective: Implement a system to manage different themes or skins for an HMI display.
Requirements:
Create a Theme class:
Attributes: backgroundColor, fontColor, fontSize, and iconStyle.
Implement methods to apply and display the theme.
Store multiple themes using std::map:
Example themes: Classic, Sport, and Eco.
Create a simple user interface to switch between themes:
Use console input to select a theme.
Display a preview of the selected theme on the console (e.g., "Sport Theme: Red Background, White Font").
Deliverables:
A C++ program that demonstrates theme switching.
Output displaying applied themes.

Solution:
*/

#include <iostream>
#include <string>
#include <map>
#include <algorithm>  // For transform

using namespace std;

class Theme {
public:
    string bgColor;
    string fColor;
    int fSize;
    string iStyle;

    // Default constructor
    Theme() : bgColor("default_bg"), fColor("default_fg"), fSize(12), iStyle("default") {}

    // Constructor with parameters
    Theme(string bgColor, string fColor, int fSize, string iStyle)
        : bgColor(bgColor), fColor(fColor), fSize(fSize), iStyle(iStyle) {}

    // Method to display the theme
    void displayTheme(const string& themeName) const {
        cout << themeName << " Theme:\n";
        cout << "  Background Color: " << bgColor << endl;
        cout << "  Font Color: " << fColor << endl;
        cout << "  Font Size: " << fSize << endl;
        cout << "  Icon Style: " << iStyle << endl;
        cout << "--------------------------------\n";
    }
};

// Function to display all available themes
void displayAvailableThemes(const map<string, Theme>& themes) {
    cout << "Available Themes:\n";
    for (const auto& pair : themes) {
        cout << "  - " << pair.first << endl;
    }
    cout << "--------------------------------\n";
}

// Helper function to convert string to lowercase
string toLower(const string& str) {
    string lowerStr = str;
    transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), ::tolower);
    return lowerStr;
}

int main() {
    // Create themes to store them in a map (all keys are lowercase)
    map<string, Theme> themes;
    themes["classic"] = Theme("Gray", "Black", 12, "Simple");
    themes["sport"] = Theme("Red", "White", 14, "Bold");
    themes["eco"] = Theme("Green", "Black", 12, "Nature");

    string selectedTheme;

    // Display available themes
    displayAvailableThemes(themes);

    while (true) {
        cout << "Enter the name of the theme to apply (or type 'exit' to quit): ";
        cin >> selectedTheme;

        // Convert the input to lowercase to make it case-insensitive
        selectedTheme = toLower(selectedTheme);

        if (selectedTheme == "exit") {
            cout << "Exiting the program. Goodbye!\n";
            break;
        }

        // Check if the theme exists
        if (themes.find(selectedTheme) != themes.end()) {
            // Apply and display the selected theme
            themes[selectedTheme].displayTheme(selectedTheme);
        } else {
            cout << "Theme not found! Please select a valid theme.\n";
        }
    }

    return 0;
}


/*
O/p:-


Available Themes:
  - classic
  - eco
  - sport
--------------------------------
Enter the name of the theme to apply (or type 'exit' to quit): eco
eco Theme:
  Background Color: Green
  Font Color: Black
  Font Size: 12
  Icon Style: Nature
--------------------------------
Enter the name of the theme to apply (or type 'exit' to quit): sport
sport Theme:
  Background Color: Red
  Font Color: White
  Font Size: 14
  Icon Style: Bold
--------------------------------
Enter the name of the theme to apply (or type 'exit' to quit): exit
Exiting the program. Goodbye!


*/
