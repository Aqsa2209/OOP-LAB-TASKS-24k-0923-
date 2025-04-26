#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>

using namespace std;

class Logger {
private:
    const string logFileBase = "log";
    const string logFileExt = ".txt";
    const size_t maxSize = 1024 * 1024; // 1MB

    void rotateLogs() {
        for (int i = 5; i >= 1; --i) {
            string oldFile = logFileBase + to_string(i) + logFileExt;
            string newFile = logFileBase + to_string(i + 1) + logFileExt;
            if (FILE *file = fopen(oldFile.c_str(), "r")) {
                fclose(file);
                rename(oldFile.c_str(), newFile.c_str());
            }
        }
        rename((logFileBase + logFileExt).c_str(), (logFileBase + "1" + logFileExt).c_str());
    }

public:
    void log(const string& message) {
        ofstream logFile(logFileBase + logFileExt, ios::app | ios::binary);
        logFile << message << endl;

        // Check file size
        logFile.seekp(0, ios::end);
        if (logFile.tellp() >= maxSize) {
            logFile.close();
            rotateLogs();
        }
    }
};

int main() {
    Logger logger;

    // Sample logging
    for (int i = 0; i < 1000; ++i) {
        logger.log("This is log entry number " + to_string(i));
    }

    cout << "Logs have been written." << endl;
    return 0;
}
