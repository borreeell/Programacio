// Pau Borrell

#include <iostream>
#include <string>

#include <Windows.h>

using namespace std;
using namespace std::string_literals;

// Function headers
string askText(string prompt);
int askNumber(string prompt);
float askFloat(string prompt);
bool askBoolean(string prompt);
void tellStory();

int main() 
{
	SetConsoleOutputCP(CP_UTF8);

	bool keepPlaying = true;

	while (keepPlaying) {
		tellStory();
		cout << "\nDo you want to create a new adventure? (1 = yes, 0 = no): ";
		cin >> keepPlaying;
		cin.ignore();
		cout << "\n";
	}

	cout << "Thanks for playing! Goodbye!\n";
	return 0;
}

// Function to take text from the user
string askText(string prompt) 
{
	string input;
	cout << prompt;
	getline(cin, input);
	return input;
}

// Fuunction to take numbers from the users
int askNumber(string prompt) 
{
	int input;
	cout << prompt;
	cin >> input;
	cin.ignore();
	return input;
}

// Function to take floats from the user
float askFloat(string prompt) 
{
	float input;
	cout << prompt;
	cin >> input;
	cin.ignore();
	return input;
}

// Function to take booleans from the user
bool askBoolean(string prompt) 
{
	int choice;
	cout << prompt << " (1 = yes, 0 = no): ";
	cin >> choice;
	cin.ignore();
	return choice == 1;
}

// Function to take chars from the user
char askChar(string prompt) 
{
	char input;
	cout << prompt;
	cin >> input;
	cin.ignore();
	return input;
}

// Main story function
void tellStory() {
	// String variables
	string characterName = askText("Enter character's name: ");
	string object1 = askText("Enter an object grabbed: ");
	string buildingType = askText("Enter building type: ");
	string place = askText("Enter a nearby place: ");
	string object2 = askText("Enter an object adjusted: ");
	string animal = askText("Enter an animal: ");
	string object3 = askText("Enter old object fixed: ");

	// Char variable
	char timeOfDay = askChar("Enter first letter of time of day (M/A/E): ");
	char moodChar = askChar("Enter one letter representing mood (H = happy, S = sad): ");

	// Int variables
	int numHoursFixing = askNumber("Enter hours spent fixing the object: ");
	int numBeeps = askNumber("Enter number of beeps: ");
	int characterAge = askNumber("Enter character age: ");
	int numFriends = askNumber("Enter number of friends to meet: ");

	// Float variable
	float beepDuration = askFloat("Enter duration of one beep in seconds: ");

	// Boolean variables
	bool isSunny = askBoolean("Is the weather sunny?");
	bool isMechanicalBird = askBoolean("Is the bird mechanical?");
	bool isHappyEnding = askBoolean("Is it a happy ending?");

	// Math operation
	float totalBeepTime = numBeeps * beepDuration;

	// Story output
	cout << "\n--- Your Adventure Story ---\n";
	cout << "Early one ";
	if (timeOfDay == 'M') cout << "morning, ";
	else if (timeOfDay == 'A') cout << "afternoon, ";
	else cout << "evening, ";
	cout << characterName << " grabbed " << object1
		<< " and stepped outside " << buildingType
		<< " near " << place << ".\n";

	cout << "The sky was " << (isSunny ? "clear and bright" : "cloudy")
		<< " - a perfect day for a walk. " << characterName
		<< " adjusted " << object2
		<< " and smiled when seeing a " << (isMechanicalBird ? "mechanical " : "")
		<< animal << " flying across the water.\n";

	cout << characterName << " had spent " << numHoursFixing << " hours fixing an old "
		<< object3 << " the night before and felt proud it finally worked.\n";

	if (totalBeepTime > 10.0f) {
		cout << "The beeping from the watch lasted quite long: "
			<< totalBeepTime << " seconds!\n";
	}

	cout << "While passing by, " << characterName
		<< " pressed a small button on the wristwatch. "
		<< "A cheerful sound beeped " << numBeeps << " times.\n";

	if (characterAge < 18 && numFriends > 2) {
		cout << characterName << " looked forward to playing with all friends.\n";
	}
	else if (characterAge >= 18 && numFriends > 0) {
		cout << characterName << " was excited to meet friends later at the park.\n";
	}

	cout << characterName << " is " << characterAge
		<< " years old, and a favorite hobby is spending time with friends. "
		<< "Later that day, they planned to meet " << numFriends << " friends at the park.\n";

	cout << "Mood today is '" << moodChar << "'. "
		<< "The weather was " << (isSunny ? "sunny" : "not sunny")
		<< ", the " << animal << " was " << (isMechanicalBird ? "mechanical" : "real")
		<< ", and " << characterName << " felt "
		<< (isHappyEnding ? "truly content with a peaceful life." : "a bit uncertain about the day.") << "\n";
}