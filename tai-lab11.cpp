// COMSC 210 | Lab 11 | Andrew Tai
// IDE: VS Code

#include <fstream>
#include <iostream>
#include <string>
#include <unistd.h>

using namespace std;

// Struct for recipes
struct Recipe {
    string name;            // Dish name
    string* ingredients;    // Pointer to array of ingredients
    int numIngredients;     // Number of ingredients

    // Destructor
    ~Recipe() {
        if (ingredients) {
            delete[] ingredients;
        }
        ingredients = nullptr;
    }
};

// Function prototypes
void addRecipe(Recipe*);
void inputRecipes(Recipe*, const int);
void exportRecipes(const Recipe*, const int);

// ---------------
// Main
// ---------------
int main() {

    // Elicit number of recipes
    int numRecipes;
    cout << "How many recipes would you like to enter? ";
    cin >> numRecipes;
    cin.ignore();

    // Create array and populate
    Recipe* recipes = nullptr;
    recipes = new Recipe[numRecipes];
    inputRecipes(recipes, numRecipes);

    // Save recipes to file
    exportRecipes(recipes, numRecipes);

    // Clean up
    delete[] recipes;

    return 0;
}

// ---------------
// Programmer functions
// ---------------
void addRecipe(Recipe* recipe) {
    // Adds a new recipe from console inputs
    // Args:
    // - recipe: pointer to Recipe instance
    // Returns: none

    cout << "Name of recipe: ";
    getline(cin, recipe->name);
    cout << "Number of ingredients: ";
    cin >> recipe->numIngredients;
    cin.ignore();

    // Allocate memory for ingredients
    if (recipe->numIngredients > 0) {
        recipe->ingredients = new string[recipe->numIngredients];

        // Input ingredients
        for (int j = 0; j < recipe->numIngredients; ++j) {
            cout << " - Ingredient " << (j + 1) << ": ";
            getline(cin, recipe->ingredients[j]);
        }    
    } else {
        recipe->ingredients = nullptr;
    }

    return;
}

void inputRecipes(Recipe* recipes, const int size) {
    // Calls addRecipe to input recipes into the array
    // Args:
    // - recipes: pointer to array of Recipe instances
    // - size: number of recipes to input
    // Returns: none

    for (int i = 0; i < size; ++i) {
        cout << "\nRecipe " << (i + 1) << "\n";
        addRecipe(&recipes[i]);
    }

    return;
}

void exportRecipes(const Recipe* recipes, const int size) {
    // Exports recipes to a text file
    // Args:
    // - recipes: pointer to array of Recipe instances
    // - size: number of recipes in array
    // Returns: none

    ofstream outFile("recipes.txt");
    if (!outFile) {
        cerr << "Error opening file for writing.\n";
        return;
    }

    // Write to file
    for (int i = 0; i < size; ++i) {
        outFile << "Recipe " << (i + 1) << ": " << recipes[i].name << "\n";
        outFile << "Ingredients: \n";
        for (int j = 0; j < recipes[i].numIngredients; ++j) {
            outFile << " - " << recipes[i].ingredients[j] << "\n";
        }
        outFile << "\n";
    }
    
    outFile.close();
    cout << "\nRecipes saved to recipes.txt\n";

    return;
}