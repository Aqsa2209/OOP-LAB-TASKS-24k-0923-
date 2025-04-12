#include <iostream>
#include <string>

using namespace std;

class Logger {
private:
    string logs[1000];
    size_t logCount;
    const size_t maxLogs;

public:
    Logger(size_t maxLogCount) : logCount(0), maxLogs(maxLogCount) {}

    void logInfo(const string& message) {
        storeLog("INFO: " + message);
    }

    void logWarning(const string& message) {
        storeLog("WARN: " + message);
    }

    void logError(const string& message) {
        storeLog("ERROR: " + message);
    }

    string getLogs(const string& authToken) const {
        if (authToken != "valid_token") {
            return "Unauthorized access.";
        }
        
        string allLogs;
        for (size_t i = 0; i < logCount; ++i) {
            allLogs += logs[i] + "\n";
        }
        return allLogs;
    }

private:
    void storeLog(const string& message) {
        if (logCount >= maxLogs) {
            for (size_t i = 1; i < maxLogs; ++i) {
                logs[i - 1] = logs[i];
            }
            logCount--;
        }
        logs[logCount++] = message;
    }
};

int main() {
    Logger logger(1000);
    logger.logInfo("Network module started.");
    logger.logWarning("Database module is slow.");
    logger.logError("Failed to connect to the server.");
    
    string authToken = "valid_token";
    string logEntries = logger.getLogs(authToken);
    
    cout << "Log Entries:\n" << logEntries;

    return 0;
}
