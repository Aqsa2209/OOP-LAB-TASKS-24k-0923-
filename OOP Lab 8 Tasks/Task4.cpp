#include <iostream>
#include <string>

using namespace std;

// Base class
class Person {
protected:
    string name;
    string id;
    string phoneNumber;
    string email;

public:
    Person(string n, string id, string phone, string email)
        : name(n), id(id), phoneNumber(phone), email(email) {}

    virtual void displayInfo() {
        cout << "Name: " << name << "\nID: " << id << "\nPhone: " << phoneNumber
             << "\nEmail: " << email << endl;
    }

    void updateInfo(string n, string id, string phone, string email) {
        name = n;
        this->id = id;
        phoneNumber = phone;
        this->email = email;
    }

    // Getter for name
    string getName() const {
        return name;
    }

    virtual ~Person() {}
};

// Derived class: Student
class Student : public Person {
private:
    static const int MAX_COURSES = 5; // Maximum number of courses
    string coursesEnrolled[MAX_COURSES];
    int courseCount;
    float GPA;
    int enrollmentYear;

public:
    Student(string n, string id, string phone, string email, float gpa, int year)
        : Person(n, id, phone, email), GPA(gpa), enrollmentYear(year), courseCount(0) {}

    void enrollCourse(string course) {
        if (courseCount < MAX_COURSES) {
            coursesEnrolled[courseCount++] = course;
        } else {
            cout << "Maximum course limit reached!" << endl;
        }
    }

    void displayInfo() override {
        Person::displayInfo();
        cout << "Enrollment Year: " << enrollmentYear 
             << "\nGPA: " << GPA << "\nCourses Enrolled: ";
        for (int i = 0; i < courseCount; ++i) {
            cout << coursesEnrolled[i] << " ";
        }
        cout << endl;
    }
};

// Derived class: Professor
class Professor : public Person {
private:
    static const int MAX_COURSES = 5; // Maximum number of courses
    string coursesTaught[MAX_COURSES];
    int courseCount;
    string department;
    float salary;

public:
    Professor(string n, string id, string phone, string email, string dept, float sal)
        : Person(n, id, phone, email), department(dept), salary(sal), courseCount(0) {}

    void addCourse(string course) {
        if (courseCount < MAX_COURSES) {
            coursesTaught[courseCount++] = course;
        } else {
            cout << "Maximum course limit reached!" << endl;
        }
    }

    void displayInfo() override {
        Person::displayInfo();
        cout << "Department: " << department << "\nSalary: " << salary 
             << "\nCourses Taught: ";
        for (int i = 0; i < courseCount; ++i) {
            cout << coursesTaught[i] << " ";
        }
        cout << endl;
    }
};

// Derived class: Staff
class Staff : public Person {
private:
    string position;
    float salary;

public:
    Staff(string n, string id, string phone, string email, string pos, float sal)
        : Person(n, id, phone, email), position(pos), salary(sal) {}

    void displayInfo() override {
        Person::displayInfo();
        cout << "Position: " << position << "\nSalary: " << salary << endl;
    }
};

// Additional class: Course
class Course {
private:
    string courseName;
    int credits;
    string instructor;
    string schedule;
    Student* enrolledStudents[10]; // Maximum of 10 students
    int studentCount;

public:
    Course(string name, int creds, string instructor, string schedule)
        : courseName(name), credits(creds), instructor(instructor), schedule(schedule), studentCount(0) {}

    void registerStudent(Student* student) {
        if (studentCount < 10) {
            enrolledStudents[studentCount++] = student;
            student->enrollCourse(courseName);
            cout << "Student " << student->getName() << " has been registered for " << courseName << "." << endl;
        } else {
            cout << "Maximum student limit reached!" << endl;
        }
    }

    void calculateGrades() {
        // Placeholder for grade calculation logic
        cout << "Calculating grades for " << courseName << endl;
    }

    void displayCourseInfo() {
        cout << "Course Name: " << courseName 
             << "\nCredits: " << credits 
             << "\nInstructor: " << instructor 
             << "\nSchedule: " << schedule << endl;
    }
};

int main() {
    Student student("Aqsa", "k240923", "123-456-7890", "k240923@nu.edu.pk", 3.8, 2024);
    Professor professor("Sir Mohammad Monis", "P001", "987-654-3210", "mohammad.monis@nu.edu.pk", "Computer Science", 75000);
    Staff staff("Mr. Ahsan", "ST001", "555-123-4567", "ahsan2nu.edu.pk", "Administrator", 50000);

    Course course("Object-Oriented-Programming", 3, "Sir Mohammad Monis", "Tue/Fri 8-11 AM");
    course.registerStudent(&student);
    professor.addCourse("Object-Oriented-Programming"); 

    cout << "\nStudent Info:\n";
    student.displayInfo();
    
    cout << "\nProfessor Info:\n";
    professor.displayInfo();
    
    cout << "\nStaff Info:\n";
    staff.displayInfo();

    cout << "\nCourse Info:\n";
    course.displayCourseInfo();
    
    course.calculateGrades(); 

    return 0;
}
