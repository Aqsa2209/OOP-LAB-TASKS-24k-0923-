#include <iostream>
#include <string>

using namespace std;

class Student {
public:
    virtual double getTuition(const string& status, int creditHours) = 0; // Pure virtual function
};

class GraduateStudent : public Student {
private:
    string researchTopic;

public:
    void setResearchTopic(const string& topic) {
        researchTopic = topic;
    }

    string getResearchTopic() const {
        return researchTopic;
    }

    double getTuition(const string& status, int creditHours) override {
        double rate = 0;
        if (status == "undergraduate") {
            rate = 200;
        } else if (status == "graduate") {
            rate = 300;
        } else if (status == "doctoral") {
            rate = 400;
        }
        return rate * creditHours;
    }
};

int main() {
    GraduateStudent gradStudent;
    gradStudent.setResearchTopic("AI in Healthcare");

    string status = "graduate";
    int creditHours = 15;
    double tuition = gradStudent.getTuition(status, creditHours);

    cout << "Research Topic: " << gradStudent.getResearchTopic() << endl;
    cout << "Tuition for " << status << " student: $" << tuition << endl;

    return 0;
}
