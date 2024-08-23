#include <iostream>
#include<string>

using namespace std;

// Function definition to get the user's color choice
void chooseColor(string* color, const string& prompt) // User input stored in string pointer named color with a constant string reference that contains the message prompt for the user. 
{
    cout << prompt; // prompt parameter output asking the user which color did they want. 
    cin >> *color;

    // Validate input
    while (*color != "white" && *color != "black")
    {
        cout << "Invalid choice. Please choose 'white' or 'black': ";
        cin >> *color;
    }
}

// Function definition to switch the colors using pointers
void switchColors(string* exteriorColor, string* interiorColor) 
{
    string temp = *exteriorColor;
    *exteriorColor = *interiorColor;
    *interiorColor = temp;
}


// Function description of the game engine process. 
void gameEngine()
{
    string exteriorColor;  //  String variable named exteriorColor
    string interiorColor;  //  String variable named interiorColor

    cout << "Welcome to Vehicle Customization!" << endl;  //  Output to the console welcoming the user.  
    cout << "Customize your vehicle interior and exterior." << endl;   //  Here we're more specific on what we will be customizing.  Only the interior and exterior.

    // Function call for the user to choose the exterior color 
    chooseColor(&exteriorColor, "What color for the exterior? (white or black): ");  //  We are only using 2 colors for this assignment to demonstrate pointers. 

    // Function call asking the user to choose the interior color
    chooseColor(&interiorColor, "What color would you like the interior? (white or black): "); 

    // Ask the user if they want to switch the colors
    string switchChoice;
    cout << "Would you like to switch color options between the interior and exterior? (yes or no): ";
    cin >> switchChoice;

    if (switchChoice == "yes")  //  Conditional if statement to call the switch function 
    {
        switchColors(&exteriorColor, &interiorColor);  //  Exterior and interior pointers are switched here in this function call
        cout << "Colors have been switched!" << endl;  //  Output notification to indicate the function has taken place
    }

    // Display of the final choices regarding the user selection.. 
    cout << "Final Exterior Color: " << exteriorColor << endl;
    cout << "Final Interior Color: " << interiorColor << endl;
}

int main()  //Standard function.  Required for entry point
{
    gameEngine(); //  gameEngine function
    return 0;
}
