#include <iostream>
#include <iomanip> // For std::setprecision

using namespace std;

// Function to convert kilograms to pounds
float convertKgToPounds(float kg) {
    return kg * 2.2; // Conversion factor
}

int main(int argc, char* argv[]) {
    // Check if the correct number of arguments is provided
    if (argc != 2) {
        cout << "Usage: " << argv[0] << " <Weight in kg>" << endl;
        return 1; // Exit if incorrect parameters
    }

    // Retrieve the weight from command line argument
    float weightInKg = stof(argv[1]); // Convert string to float

    // Convert to pounds
    float weightInPounds = convertKgToPounds(weightInKg);

    // Output the result formatted to two decimal places
    cout << fixed << setprecision(2); // Set precision for output
    cout << "Weight in kilograms: " << weightInKg << " kg" << endl;
    cout << "Equivalent weight in pounds: " << weightInPounds << " lbs" << endl;

    return 0;
}
