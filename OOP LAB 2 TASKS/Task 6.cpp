#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Subject {
    string subject_name;
};

struct Student {
    int id;
    vector<Subject> subjects; 
};

int main() {
    vector<Student> students = {
        {1, {{"Math"}, {"Physics"}}},
        {2, {{"Biology"}, {"Chemistry"}, {"Math"}}},
        {3, {{"History"}}}
    };
    for (Student student : students) {   
        cout << "Student ID: " << student.id << endl;
        cout << "Subjects: ";
        for (Subject subject : student.subjects) { 
            cout << subject.subject_name << " ";
        }
        cout << endl;
    }

    return 0;
}
