// MadHistory.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

void history()
{
    string name;
    int age;
    char spaceship;   
    float fuel;
    int distance;
    bool hasRobot;
    bool hasCrew;
    double travelTime;
    short crew;
    string planet;

    cout << "\n --- Welcome to the Space Rescue Mission ---\n";

    // User input
    cout << "What's your name? ";
    cin >> name;

    cout << "How old are you? ";
    cin >> age;

    cout << "Choose your spaceship (A/B/C)";
    cin >> spaceship;

    cout << "Do you have a robot assistant? (1 for yes, 0 for no) ";
    cin >> hasRobot;

    if (!hasRobot) {
        cout << "Do you have a crew with you? ";
        cin >> hasCrew;

        if (hasCrew) {
            cout << "How many crew member are with you? ";
            cin >> crew;
        } else {
            cout << "You are flying alone. \n";
        }
    }

    cout << "How much fuel do you have? (in liters) ";
    cin >> fuel;

    cout << "Enter the distance to the lost planet? "; 
    cin >> distance;



    cin.(); // Clean input buffer
    cout << "Name of the planet you want to save: ";
    cin >> planet;

    // Mathematical operation (using float and double)
    travelTime = (double)distance / (fuel / 10.0);

    cout << "\n--- Mission Log ---\n";
    cout << "Captain " << name << ", age " << age << " years old, commands spaceship model '" << spaceship << "'.  ";

    if (hasRobot) {
        cout << "With a robot assistant. \n";
    }
    else if (hasCrew) {
        cout << "With a crew of " << crew << " members. \n";
    }
    else if (!hasRobot && !hasCrew) {
        cout << "Flying alone. \n";
    }

    cout << "Destination: planet " << planet << " (" << distance << " light-years away)\n";
    cout << "Fuel remaining: " << fuel << " liters\n";
    cout << "Estimated travel time: " << travelTime << " space-hours.\n";

    if (hasRobot) {
        cout << "You robot says: 'Captain, i'm starting systems.'";
        cout << "Starting systems...";
        cout << "All systems are ready.";
    }
    else if (hasCrew) {
        cout << "One member of your crew says: 'Captain i'm starting systems'";
    }
}

int main()
{
    history();

    return 0;
}
