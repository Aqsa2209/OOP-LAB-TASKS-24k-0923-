#include <iostream>
#include <string>

using namespace std;

const int MAX_PASSENGERS = 10;

class Flight {
private:
    string flightNumber;
    string departure;
    string arrival;
    int capacity;
    int bookedSeats;
    string passengerList[MAX_PASSENGERS];

public:
    Flight(const string& flightNum, const string& dep, const string& arr, int cap)
        : flightNumber(flightNum), departure(dep), arrival(arr), capacity(cap), bookedSeats(0) {}

    string getFlightDetails() const {
        return "Flight Number: " + flightNumber + ", Departure: " + departure + 
               ", Arrival: " + arrival + ", Available Seats: " + to_string(capacity - bookedSeats);
    }

    bool bookSeat(const string& passengerID) {
        if (bookedSeats >= capacity) {
            cout << "No available seats to book." << endl;
            return false;
        }
        passengerList[bookedSeats] = passengerID;
        bookedSeats++;
        return true;
    }

    bool cancelSeat(const string& passengerID) {
        for (int i = 0; i < bookedSeats; ++i) {
            if (passengerList[i] == passengerID) {
                passengerList[i] = passengerList[bookedSeats - 1]; // Move last booked to the current position
                bookedSeats--;
                return true;
            }
        }
        cout << "Seat not booked for this passenger." << endl;
        return false;
    }

    bool upgradeSeat(const string& passengerID) {
        for (int i = 0; i < bookedSeats; ++i) {
            if (passengerList[i] == passengerID) {
                cout << "Upgrading seat for passenger: " << passengerID << endl;
                return true;
            }
        }
        cout << "Seat not booked for this passenger." << endl;
        return false;
    }
};

class Passenger {
private:
    string id;
    string name;

public:
    Passenger(const string& id, const string& name) : id(id), name(name) {}

    void requestBooking(Flight& flight) {
        if (flight.bookSeat(id)) {
            cout << name << " successfully booked a seat on flight " << flight.getFlightDetails() << endl;
        }
    }

    void requestCancellation(Flight& flight) {
        if (flight.cancelSeat(id)) {
            cout << name << " successfully canceled their seat on flight " << flight.getFlightDetails() << endl;
        }
    }

    void requestUpgrade(Flight& flight) {
        if (flight.upgradeSeat(id)) {
            cout << name << " successfully upgraded their seat on flight " << flight.getFlightDetails() << endl;
        }
    }
};

int main() {
    Flight flight1("AA101", "New York", "Los Angeles", 3);
    Flight flight2("BA202", "Chicago", "Miami", 2);

    Passenger passenger1("P001", "Aqsa");
    Passenger passenger2("P002", "Ayesha");
    Passenger passenger3("P003", "Urooj");
    Passenger passenger4("P004", "Rafia");

    passenger1.requestBooking(flight1);
    passenger2.requestBooking(flight1);
    passenger3.requestBooking(flight1);
    passenger4.requestBooking(flight1); // Should fail

    passenger1.requestCancellation(flight1);
    passenger4.requestBooking(flight1); // Should succeed now

    passenger2.requestUpgrade(flight1);
    passenger3.requestCancellation(flight1); // Should fail

    cout << flight1.getFlightDetails() << endl;

    return 0;
}
