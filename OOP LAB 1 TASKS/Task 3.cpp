#include <iostream>
#include <string>
using namespace std;
float calculateCharge(int units) {
    if (units < 200) {
        return units * 16.20;  
    } else if (units < 300) {
        return units * 20.10
    } else if (units < 500) {
        return units * 27.10;  
    } else {
        return units * 35.90;  
    }
}
float calculateTotalAmount(float charge) {
    if (charge > 18000) {
        return charge + (charge * 0.15); 
    }
    return charge;
}
int main(int argc, char* argv[]) {
    if (argc != 4) {
        cout << "Usage: " << argv[0] << " <Customer ID> <Customer Name> <Units Consumed>" << endl;
        return 1; 
    }
    int customerId = stoi(argv[1]); 
    string customerName = argv[2];   
    int unitsConsumed = stoi(argv[3]); 
    float charge = calculateCharge(unitsConsumed);
    float totalAmount = calculateTotalAmount(charge);
    
    cout << "Customer ID: " << customerId << endl;
    cout << "Customer Name: " << customerName << endl;
    cout << "Units Consumed: " << unitsConsumed << endl;
    cout << "Amount Charges (Rs.): " << charge << endl;

    if (charge > 18000) {
        cout << "Surcharge Amount (Rs.): " << (charge * 0.15) << endl;
    }
    cout << "Net Amount Paid by the Customer (Rs.): " << totalAmount << endl;
    return 0;
}
