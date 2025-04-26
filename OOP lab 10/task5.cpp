#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int MAX_TASKS = 100; // Maximum number of tasks

class TodoList {
private:
    const string todoFile = "todo.txt";
    string tasks[MAX_TASKS]; // Array to store tasks
    int taskCount = 0; // Current number of tasks

public:
    TodoList() {
        // Load existing tasks from the file
        ifstream inFile(todoFile);
        string line;
        while (getline(inFile, line) && taskCount < MAX_TASKS) {
            tasks[taskCount++] = line; // Load tasks into the array
        }
    }

    void addTask(const string& task) {
        if (taskCount < MAX_TASKS) {
            tasks[taskCount++] = task; // Add new task
            ofstream outFile(todoFile, ios::app);
            outFile << task << endl; // Append to file
        } else {
            cout << "Task list is full!" << endl;
        }
    }

    void viewTasks() {
        cout << "To-Do List:\n";
        for (int i = 0; i < taskCount; ++i) {
            cout << (i + 1) << ". " << tasks[i] << endl;
        }
    }

    void markTaskAsDone(int taskNumber) {
        if (taskNumber > 0 && taskNumber <= taskCount) {
            // Shift tasks to remove the done task
            for (int i = taskNumber - 1; i < taskCount - 1; ++i) {
                tasks[i] = tasks[i + 1];
            }
            taskCount--; // Decrease the count of tasks

            // Rewrite remaining tasks to the file
            ofstream outFile(todoFile);
            for (int i = 0; i < taskCount; ++i) {
                outFile << tasks[i] << endl; // Write remaining tasks
            }
        } else {
            cout << "Invalid task number!" << endl;
        }
    }
};

int main() {
    TodoList todo;

    // Example usage
    todo.addTask("Buy groceries");
    todo.addTask("Finish homework");
    todo.addTask("Call the doctor");

    todo.viewTasks();

    // Mark the first task as done
    todo.markTaskAsDone(1);
    
    cout << "\nUpdated To-Do List:\n";
    todo.viewTasks();

    return 0;
}
