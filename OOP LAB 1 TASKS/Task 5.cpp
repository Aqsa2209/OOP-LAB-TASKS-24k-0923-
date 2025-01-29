#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void calculateAndDisplayResults(const string& movieName, float adultTicketPrice, float childTicketPrice,
                                 int numAdultTickets, int numChildTickets, float donationPercentage) {
    // Calculate total tickets sold and gross amount
    int totalTicketsSold = numAdultTickets + numChildTickets;
    float grossAmount = (adultTicketPrice * numAdultTickets) + (childTicketPrice * numChildTickets);
    float amountDonated = (donationPercentage / 100) * grossAmount;
    float netSale = grossAmount - amountDonated;

    // Output results with formatting
    cout << fixed << setprecision(2);
    cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
    cout << left << setw(50) << "Movie Name:" << right << setw(10) << movieName << endl;
    cout << left << setw(50) << "Number of Tickets Sold:" << right << setw(10) << totalTicketsSold << endl;
    cout << left << setw(50) << "Gross Amount:" << right << setw(10) << "$ " << grossAmount << endl;
    cout << left << setw(50) << "Percentage of Gross Amount Donated:" << right << setw(10) << donationPercentage << "%" << endl;
    cout << left << setw(50) << "Amount Donated:" << right << setw(10) << "$ " << amountDonated << endl;
    cout << left << setw(50) << "Net Sale:" << right << setw(10) << "$ " << netSale << endl;
}

int main(int argc, char* argv[]) {
    // Check if the correct number of arguments is provided
    if (argc != 7) {
        cout << "Usage: " << argv[0] << " <Movie Name> <Adult Ticket Price> <Child Ticket Price> <Number of Adult Tickets Sold> <Number of Child Tickets Sold> <Donation Percentage>" << endl;
        return 1; // Exit if incorrect parameters
    }

    // Retrieve input from command line arguments
    string movieName = argv[1];
    float adultTicketPrice = stof(argv[2]);
    float childTicketPrice = stof(argv[3]);
    int numAdultTickets = stoi(argv[4]);
    int numChildTickets = stoi(argv[5]);
    float donationPercentage = stof(argv[6]);

    // Call the function to calculate and display results
    calculateAndDisplayResults(movieName, adultTicketPrice, childTicketPrice, numAdultTickets, numChildTickets, donationPercentage);

    return 0;
}
