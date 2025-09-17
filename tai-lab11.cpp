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
