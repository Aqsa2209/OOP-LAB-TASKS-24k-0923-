#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

const int MAX_EMPLOYEES = 100;

struct Employee {
    int id;
    string name;
    string designation;
    int yearsOfService;

    string toCSV() const {
        return to_string(id) + "," + name + "," + designation + "," + to_string(yearsOfService);
    }
};

class EmployeeManager {
private:
    const string filename = "employees.csv";
    Employee employees[MAX_EMPLOYEES];
    int employeeCount;

    void loadEmployees() {
        ifstream inFile(filename);
        string line;

        employeeCount = 0;
        while (getline(inFile, line) && employeeCount < MAX_EMPLOYEES) {
            stringstream ss(line);
            Employee emp;

            string token;
            getline(ss, token, ',');
            emp.id = stoi(token);
            getline(ss, emp.name, ',');
            getline(ss, emp.designation, ',');
            getline(ss, token, ',');
            emp.yearsOfService = stoi(token);

            employees[employeeCount++] = emp;
        }
    }

    void saveEmployees() {
        ofstream outFile(filename);
        for (int i = 0; i < employeeCount; ++i) {
            outFile << employees[i].toCSV() << endl;
        }
    }

public:
    EmployeeManager() {
        loadEmployees();
    }

    void initializeDummyData() {
        employees[0] = {1, "Aqsa", "Manager", 3};
        employees[1] = {2, "Rafia", "Developer", 1};
        employees[2] = {3, "Ahsan", "Manager", 2};
        employees[3] = {4, "Urooj", "Tester", 4};
        employeeCount = 4; 
        saveEmployees();
    }

    void queryAndRetainManagers() {
        Employee retained[MAX_EMPLOYEES];
        int retainedCount = 0;

        for (int i = 0; i < employeeCount; ++i) {
            if (employees[i].designation == "Manager" && employees[i].yearsOfService >= 2) {
                retained[retainedCount++] = employees[i];
            }
        }

        employeeCount = retainedCount;
        for (int i = 0; i < employeeCount; ++i) {
            employees[i] = retained[i];
        }
        saveEmployees();
    }

    void deleteAllExceptManagers() {
        queryAndRetainManagers(); // Reuse the method to retain managers
    }

    void incrementAndWriteData() {
        for (int i = 0; i < employeeCount; ++i) {
            employees[i].id += 1;
            employees[i].yearsOfService += 1;
        }
        saveEmployees();
    }

    void displayEmployees() const {
        for (int i = 0; i < employeeCount; ++i) {
            cout << employees[i].id << ", " << employees[i].name << ", "
                 << employees[i].designation << ", " << employees[i].yearsOfService << endl;
        }
    }
};

int main() {
    EmployeeManager manager;

    // Initialize dummy data if the file is empty
    manager.initializeDummyData();

    cout << "Original Employees:\n";
    manager.displayEmployees();

    // Query to retain managers with at least 2 years
    manager.queryAndRetainManagers();
    cout << "\nAfter Query and Retain Managers:\n";
    manager.displayEmployees();

    // Delete all except managers
    manager.deleteAllExceptManagers();
    cout << "\nAfter Deleting All Except Managers:\n";
    manager.displayEmployees();

    // Increment IDs and years of service and write to file
    manager.incrementAndWriteData();
    cout << "\nAfter Incrementing IDs and Years of Service:\n";
    manager.displayEmployees();

    return 0;
}
