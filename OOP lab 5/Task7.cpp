#include <iostream>
#include <string>

using namespace std;

class Student {
private:
    const string roll_no; 

public:
    Student() : roll_no("") {} 
    void setRollNo(const string& number) {
        const_cast<string&>(roll_no) = number; 
    }
    string getRollNo() const {
        return roll_no;
    }
};

int main() {
    Student student;
    string rollNumber;

    cout << "Enter roll number: ";
    cin >> rollNumber;
    student.setRollNo(rollNumber);
    cout << "Student Roll No: " << student.getRollNo() << endl;

    return 0;
}
