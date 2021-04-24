/*
Developer: Kiley Neushul
Project: Final Course Project
Date: 04/11/2021
*/

#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
#include<ctime>

using namespace std;

//prototypes
void arrayTutorial();
void addRecipe();
void lookUpRecipe();
void deleteRecipe();
void showRecipes();

//Global Variables (need to be defined outside of main function to be accessible by all functions)
int choice = 0;
string name, ingredients, instructions;
int cookTime, servings;
vector<string> recipeNames; //Resizable Array... telling the vector to take string variables
vector<string> recipeIngredients;
vector<string> recipeInstructions;
vector<string> recipeCookTimes;
vector<int> recipeServings;
string strCookTime;
int hours, minutes;


int main() {

	//seed the randomizer
	srand(time(0));

	//get password -- three tries and you are out!
	string password = "";
	string appPassword = "kiley123";
	bool success = false;

	for (int i = 0; i < 3; i++) {
		cout << "Enter the application password: ";
		cin >> password;

		if (password == appPassword) {
			success = true;
			break;
		}
		else {
			cout << "\nError. Invalid password. Remember, the password is case sensitive." << endl;
			cout << "Try again.\n" << endl;
		}
		if (success == true)
			cout << "\nWelcome to the application!\n" << endl;
		else {
			cout << "/nGet away from here you hacker!\n" << endl;
			system("pause");
			return -1;
		}
	}


	do {
		system("cls");
		cout << "Menu" << endl;
		cout << "1) Add a Recipe" << endl;
		cout << "2) Look up a Recipe" << endl;
		cout << "3) Delete a Recipe" << endl;
		cout << "4) Show All Recipes" << endl;
		cout << "5) Exit" << endl;

		cout << "\nEnter your choice (1-5): ";
		cin >> choice;  // 3 ENTER
		cin.ignore(100, '\n'); // Ignore up to 100 characters (enter key in the keyboard buffer) or until enter key

		switch (choice) {

		case 1:
			addRecipe();
			break;

		case 2:
			lookUpRecipe();
			break;

		case 3:
			deleteRecipe();
			break;

		case 4:
			showRecipes();

		case 5:
			cout << "\t\t Goodbye!\n";
			break;

		default:
			cout << "\nError. Please Select From the Menu." << endl;
			break;
		}

		cout << endl;
		system("pause");
	} while (choice != 5);

	return 0;
}

void arrayTutorial()
{
	//define array and variables 
	int numbers[10];
	int min = 10;
	int max = 99;

	//load the array with a for loop
	for (int i = 0; i < 10; i++) {

		numbers[i] = rand() % (max - min + 1) + min;

	}
	//display the contents of an array with a for loop
	for (int i = 0; i < 10; i++) {
		cout << numbers[i] << endl;
	}
}

void addRecipe()
{
	cout << "\t\t Add a Recipe Below";
	cout << endl;

	//Add Recipe Name 
	cout << "Recipe Name: ";
	getline(cin, name);
	recipeNames.push_back(name);
	cout << endl;

	//Add Recipe Ingredients (getline() used to take in more strings with whitespaces (spaces))
	cout << "Ingredients: ";
	//First Ingredient and Quantity
	getline(cin, ingredients);
	recipeIngredients.push_back(ingredients);
	cout << endl;

	//Add Recipe Instructions (getline() used to take in more strings with whitespaces (spaces))
	cout << "Instructions: ";
	getline(cin, instructions);
	recipeInstructions.push_back(instructions);
	cout << endl;

	//Used to take in the float variable cookTime
	cout << "Specify Cook Time in Minutes: ";
	cin >> cookTime;

	//Conditional Statement added here to check for number of minutes. If minutes exceeds 60, display in hours
	if (cookTime > 60)
	{
		hours = cookTime / 60;
		minutes = cookTime % 60;
		strCookTime = to_string(hours) + " hours " + to_string(minutes) + " minutes"; //"2 hours 15 minutes"
	}
	else
	{
		minutes = cookTime;
		strCookTime = to_string(minutes) + " minutes";
	}
	recipeCookTimes.push_back(strCookTime);
	cout << endl;

	// Number of servings
	cout << "Number of Servings: ";
	cin >> servings;
	recipeServings.push_back(servings);
	cout << endl;

	//Prints out the inputted variables (name, ingredients, instructions, cookTime, servings)
	cout << "Recipe Name: " << name << endl;
	cout << "Recipe Ingredients: " << ingredients << endl;
	cout << "Recipe Instructions: " << instructions << endl;
	cout << "Cook Time: " << strCookTime << endl;
	cout << "Serves: " << servings << " People" << endl;

}

void lookUpRecipe()
{
	cout << "Look up a Recipe from the List\n" << endl;
	cout << "Recipe List: " << endl;

	//print out recipe list
	for (int i = 0; i < recipeNames.size(); i++) {
		cout << recipeNames[i] << endl;
	}


	cout << "Enter your recipe choice: ";
	getline(cin, name);

	for (int x = 0; x < recipeNames.size(); x++) {
		if (name == recipeNames[x]) {
			cout << "The Recipe for " << recipeNames[x] << endl;
			cout << "Recipe Ingredients: " << recipeIngredients[x] << endl;
			cout << "Recipe Instructions: " << recipeInstructions[x] << endl;
			cout << "Recipe Cook Time: " << recipeCookTimes[x] << endl;
			cout << "Recipe Serving Size: " << recipeServings[x] << endl;
		}
	}
}

void deleteRecipe()
{
	cout << "\t\t Delete a Recipe from the List\n" << endl;
	cout << "\t Recipe List: " << endl;

	//print out recipe list
	for (int i = 0; i < recipeNames.size(); i++) {
		cout << recipeNames[i] << endl;
	}


	cout << "Enter the name of the recipe that you would like to delete here: ";
	getline(cin, name);

	for (int x = 0; x < recipeNames.size(); x++) {
		if (name == recipeNames[x]) {
			recipeNames.erase(recipeNames.begin() + x);
			recipeIngredients.erase(recipeIngredients.begin() + x);
			recipeInstructions.erase(recipeInstructions.begin() + x);
			recipeCookTimes.erase(recipeCookTimes.begin() + x);
			recipeServings.erase(recipeServings.begin() + x);
		}
	}
}

void showRecipes()
{
	cout << "\nRecipes\n" << endl;
	for (int i = 0; i < recipeNames.size(); i++)
	{
		cout << recipeNames.at(i) << endl;
		cout << "\tIngredients: " << recipeIngredients.at(i) << endl;

	}

}
