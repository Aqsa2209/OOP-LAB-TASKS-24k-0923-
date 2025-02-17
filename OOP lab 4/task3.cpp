#include <iostream>
#include <string>

using namespace std;

class Invoice {
private:
    string partNumber;
    string partDescription;
    int quantity;
    double pricePerItem;

public:
    Invoice(const string& number, const string& description, int qty, double price) 
        : partNumber(number), partDescription(description), 
          quantity(qty > 0 ? qty : 0), pricePerItem(price > 0.0 ? price : 0.0) {}

    double getInvoiceAmount() const {
        return quantity * pricePerItem;
    }
};

int main() {
    string partNumber;
    string partDescription;
    int quantity;
    double pricePerItem;

    cout << "Enter part number: ";
    cin >> partNumber;
    cout << "Enter part description: ";
    cin.ignore(); 
    getline(cin, partDescription);
    cout << "Enter quantity: ";
    cin >> quantity;
    cout << "Enter price per item: ";
    cin >> pricePerItem;

    Invoice invoice(partNumber, partDescription, quantity, pricePerItem);
    double totalAmount = invoice.getInvoiceAmount();
    
    cout << "Invoice Amount: " << totalAmount << endl;

    return 0;
}
