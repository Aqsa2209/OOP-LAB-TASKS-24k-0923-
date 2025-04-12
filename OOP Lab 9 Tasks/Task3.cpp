#include <iostream>
#include <string>

using namespace std;

class PatientRecord {
private:
    string name;
    string patientID;
    string dateOfBirth;
    string medicalHistory;
    string currentTreatments;

public:
    PatientRecord(const string& name, const string& id, const string& dob)
        : name(name), patientID(id), dateOfBirth(dob), medicalHistory(""), currentTreatments("") {}

    string getPublicData() const {
        return "Name: " + name + ", ID: " + patientID + ", Date of Birth: " + dateOfBirth;
    }

    void updateMedicalHistory(const string& history) {
        medicalHistory = history;
    }

    void setCurrentTreatments(const string& treatments) {
        currentTreatments = treatments;
    }

    string getMedicalData(const string& role) const {
        if (role == "Doctor" || role == "Billing") {
            return "Medical History: " + medicalHistory + ", Current Treatments: " + currentTreatments;
        }
        return "Unauthorized access to medical data.";
    }
};

class Doctor {
private:
    PatientRecord& record;

public:
    Doctor(PatientRecord& rec) : record(rec) {}

    void updateMedicalHistory(const string& history) {
        record.updateMedicalHistory(history);
    }

    void setCurrentTreatments(const string& treatments) {
        record.setCurrentTreatments(treatments);
    }

    void viewMedicalData() {
        cout << record.getMedicalData("Doctor") << endl;
    }
};

class Billing {
private:
    PatientRecord& record;

public:
    Billing(PatientRecord& rec) : record(rec) {}

    void addBillingDetails(const string& details) {
        // Placeholder for billing details logic
    }

    void viewMedicalData() {
        cout << record.getMedicalData("Billing") << endl;
    }
};

class Receptionist {
private:
    PatientRecord& record;

public:
    Receptionist(PatientRecord& rec) : record(rec) {}

    void viewPublicData() {
        cout << record.getPublicData() << endl;
    }

    void tryAccessMedicalData() {
        cout << record.getMedicalData("Receptionist") << endl;
    }
};

int main() {
    PatientRecord patient("Aqsa", "12345", "01/01/1980");

    Doctor doctor(patient);
    doctor.updateMedicalHistory("Allergic to Penicillin");
    doctor.setCurrentTreatments("Antihistamines");
    doctor.viewMedicalData();

    Billing billing(patient);
    billing.viewMedicalData();

    Receptionist receptionist(patient);
    receptionist.viewPublicData();
    receptionist.tryAccessMedicalData();

    return 0;
}
