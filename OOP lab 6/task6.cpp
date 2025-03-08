#include <iostream>
using namespace std;
class Student {
protected:
    string id;
    string name;
public:
    void getStudentDetails() {
        cout << "Enter Student ID: ";
        getline(cin, id);
        cout << "Enter Student Name: ";
        getline(cin, name);
    }
    
    void displayStudentDetails() {
        cout << "Student ID: " << id << endl;
        cout << "Student Name: " << name << endl;
    }
};
class Marks : public Student {
protected:
    int marks_oop, marks_pf, marks_ds, marks_db;
public:
    void getMarks() {
        cout << "Enter marks for Object Oriented Programming: ";
        cin >> marks_oop;
        cout << "Enter marks for Programming Fundamentals: ";
        cin >> marks_pf;
        cout << "Enter marks for Data Structures: ";
        cin >> marks_ds;
        cout << "Enter marks for Databases: ";
        cin >> marks_db;
    }
    
    void displayMarks() {
        cout << "Marks in OOP: " << marks_oop << endl;
        cout << "Marks in PF: " << marks_pf << endl;
        cout << "Marks in DS: " << marks_ds << endl;
        cout << "Marks in DB: " << marks_db << endl;
    }
};
class Result : public Marks {
private:
    int total_marks;
    double avg_marks;
public:
    void calculateResult() {
        total_marks = marks_oop + marks_pf + marks_ds + marks_db;
        avg_marks = total_marks / 4.0;
    }

    void display() {
        displayStudentDetails();
        displayMarks();
        cout << "Total Marks: " << total_marks << endl;
        cout << "Average Marks: " << avg_marks << endl;
    }
};

int main() {
    Result studentResult;

    // Get input from user
    studentResult.getStudentDetails();
    studentResult.getMarks();
    studentResult.calculateResult();
    cout << "\n----- Student Report -----\n";
    studentResult.display();

    return 0;
}

