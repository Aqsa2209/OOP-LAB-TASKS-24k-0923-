#include <iostream>
#include <string>
#include <iomanip>

using namespace std;
void calculateAverage(const string& studentName, float scores[]) {
    float sum = 0.0;
    for (int i = 0; i < 5; ++i) {
        sum += scores[i];
    }
    float average = sum / 5;
    cout << "Student name: " << studentName << endl;
    cout << "Test scores: ";
    for (int i = 0; i < 5; ++i) {
        cout << fixed << setprecision(2) << scores[i]; 
	    if (i < 4) {
            cout << " "; 
        }
    }
    cout << endl;
    cout << "Average test score: " << fixed << setprecision(2) << average << endl;
}

int main(int argc, char* argv[]) {
    if (argc != 7) {
        cout << "Usage: " << argv[0] << " <Student Name> <Score1> <Score2> <Score3> <Score4> <Score5>" << endl;
        return 1; 
    }
    string studentName = argv[1];
    float scores[5]; 

    for (int i = 0; i < 5; ++i) {
        scores[i] = stof(argv[i + 2]); 
    }
    calculateAverage(studentName, scores);

    return 0;
}
