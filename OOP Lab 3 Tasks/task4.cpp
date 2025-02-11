#include <iostream>
#include <string>

using namespace std;

class Employee {
private:
    string firstName;
    string lastName;
    double monthlySalary;

public:
    Employee(string fName, string lName, double salary) 
        : firstName(fName), lastName(lName) {
        monthlySalary = (salary > 0) ? salary : 0.0;
    }
    void setFirstName(string fName) {
        firstName = fName;
    }

    void setLastName(string lName) {
        lastName = lName;
    }

    void setMonthlySalary(double salary) {
        monthlySalary = (salary > 0) ? salary : 0.0;
    }
    string getFirstName() {
        return firstName;
    }

    string getLastName() {
        return lastName;
    }

    double getMonthlySalary() {
        return monthlySalary;
    }

    double getYearlySalary() {
        return monthlySalary * 12;
    }

    void giveRaise(double percentage) {
        monthlySalary += monthlySalary * percentage / 100;
    }
};

int main(int argc, char* argv[]) {
    if (argc < 7) {
        cout << "Usage: " << argv[0] << " <FirstName1> <LastName1> <MonthlySalary1> "
             << "<FirstName2> <LastName2> <MonthlySalary2>" << endl;
        return 1;
    }
    string firstName1 = argv[1];
    string lastName1 = argv[2];
    double monthlySalary1 = atof(argv[3]); 

    string firstName2 = argv[4];
    string lastName2 = argv[5];
    double monthlySalary2 = atof(argv[6]); 
    Employee emp1(firstName1, lastName1, monthlySalary1);
    Employee emp2(firstName2, lastName2, monthlySalary2); 

    cout << emp1.getFirstName() << " " << emp1.getLastName() 
         << "'s yearly salary: " << emp1.getYearlySalary() << endl;
    cout << emp2.getFirstName() << " " << emp2.getLastName() 
         << "'s yearly salary: " << emp2.getYearlySalary() << endl;

    emp1.giveRaise(10);
    emp2.giveRaise(10);

    cout << emp1.getFirstName() << " " << emp1.getLastName() 
         << "'s yearly salary after raise: " << emp1.getYearlySalary() << endl;
    cout << emp2.getFirstName() << " " << emp2.getLastName() 
         << "'s yearly salary after raise: " << emp2.getYearlySalary() << endl;

    return 0;
}
