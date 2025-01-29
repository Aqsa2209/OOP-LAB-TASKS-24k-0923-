#include <iostream>
#include <iomanip> 
using namespace std;
float convertKgToPounds(float kg) {
    return kg * 2.2; 
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cout << "Usage: " << argv[0] << " <Weight in kg>" << endl;
        return 1; 
    }
    float weightInKg = stof(argv[1]); 
    float weightInPounds = convertKgToPounds(weightInKg);
    cout << fixed << setprecision(2); 
    cout << "Weight in kilograms: " << weightInKg << " kg" << endl;
    cout << "Equivalent weight in pounds: " << weightInPounds << " lbs" << endl;

    return 0;
}
