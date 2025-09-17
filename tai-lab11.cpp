// COMSC 210 | Lab 11 | Andrew Tai
// IDE: VS Code

#include <fstream>
#include <iostream>
#include <string>

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

    return 0;
}

// ---------------
// Programmer functions
// ---------------
void addRecipe(Recipe* recipe) {
    // Adds a new recipe from console inputs
    // Args:
    // - recipe: pointer to Recipe instance to populate

    cout << "Name of recipe: ";
    getline(cin, recipe->name);
    cout << "Number of ingredients: ";
    cin >> recipe->numIngredients;
    cin.ignore();

    // Allocate memory for ingredients
    recipe->ingredients = new string[recipe->numIngredients];

    // Input ingredients
    for (int j = 0; j < recipe->numIngredients; ++j) {
        cout << "Ingredient " << (j + 1) << ": ";
        getline(cin, recipe->ingredients[j]);
    }
}