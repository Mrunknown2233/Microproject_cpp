#include <iostream>
#include <string>
#include <cstdlib>  // for atoi
#include <cstring>  // for c_str()
#include <fstream>
#define MAX 100

using namespace std;

class Employee {
protected:
    string dl; // Change to string for date
    char project[200], message[200];
    int status;

public:
    Employee() {
        strcpy(project, "not_available");
        strcpy(message, "not_available");
        status = 0;
        dl = "not_available";
    }

    virtual void update() {
        cout << "\nEnter the status: ";
        cin >> status;
        cout << "\nThe status has been updated";
    }

    virtual void display() {
        cout << "\nThe given project: " << project;
        cout << "\nThe status of the project: " << status << "%";
        cout << "\nThe deadline: " << dl; // Display the string date
        cout << "\nThe message given by boss: " << message;
    }

    void assignProject(const char* projName, const string& deadline, const char* msg) {
        strcpy(project, projName);
        dl = deadline; // Store date as string
        strcpy(message, msg);
    }

    friend void insertboss(Employee &e, int employeeIndex);
    friend void displayboss(Employee &e);
    friend void assignGroupProject(Employee e[], int employeeCount);
};

class Boss : public Employee {
public:
    void assignGroupProject(Employee e[], int employeeCount);
};

void saveToCSV(const char* projectName, const string& deadline, const char* message, int employeeIndex) {
    ofstream file;
    file.open("tasks.csv", ios::app); // Open file in append mode
    if (file.is_open()) {
        file << employeeIndex << "," << projectName << "," << deadline << "," << message << endl;
        cout << "\nInserted";
        file.close();
    } else {
        cout << "Error opening file." << endl;
    }
}

// Simple date validation function (using atoi instead of stoi)
bool isValidDate(const string& date) {
    if (date.size() != 10) return false; // Length check for YYYY-MM-DD

    // Check the format YYYY-MM-DD
    if (date[4] != '-' || date[7] != '-') return false;

    // Check if the year, month, and day parts are digits
    for (int i = 0; i < 10; i++) {
        if (i != 4 && i != 7 && !isdigit(date[i])) {
            return false;
        }
    }

    // Use atoi instead of stoi
    int year = atoi(date.substr(0, 4).c_str());  // Convert year to int
    int month = atoi(date.substr(5, 2).c_str()); // Convert month to int
    int day = atoi(date.substr(8, 2).c_str());   // Convert day to int

    // Basic checks for month and day
    if (month < 1 || month > 12) return false;
    if (day < 1 || day > 31) return false;

    // Handle months with less than 31 days
    if (month == 4 || month == 6 || month == 9 || month == 11) {
        if (day > 30) return false;
    }

    // Handle February
    if (month == 2) {
        bool leapYear = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
        if (day > (leapYear ? 29 : 28)) return false;
    }

    return true;
}

void insertboss(Employee &e, int employeeIndex) {
    cin.ignore();
    cout << "\nEnter the project for the employee: ";
    cin.getline(e.project, 200);
    cout << "\nProject inserted";
    
    string deadline;
    while (true) {
        cout << "\nEnter the deadline (YYYY-MM-DD): ";
        cin >> deadline;
        if (isValidDate(deadline)) {
            e.dl = deadline; // Set the deadline
            cout << "\nThe deadline inserted" << endl;
            break;
        } else {
            cout << "Invalid date format. Please use YYYY-MM-DD." << endl;
        }
    }
    
    cin.ignore(); // Clear input buffer
    cout << "\nEnter the message: ";
    cin.getline(e.message, 200);

    // Save to CSV
    saveToCSV(e.project, e.dl, e.message, employeeIndex);
}

void displayboss(Employee &e) {
    cout << "\nThe project: " << e.project << endl;
    cout << "\nThe deadline: " << e.dl << endl; // Display the string date
    cout << "\nThe status: " << e.status << endl;
}

void Boss::assignGroupProject(Employee e[], int employeeCount) {
    char projectName[200], message[200];
    string deadline;
    int noOfEmployees[MAX], actualCount = 0;

    cin.ignore();
    cout << "\nEnter the employee numbers (type 'done' to finish): ";
    
    while (true) {
        char input[10];
        cin >> input;

        if (strcmp(input, "done") == 0) {
            break; // Exit the loop if "done" is entered
        }

        int empIndex = atoi(input); // Convert input to integer
        if (empIndex >= 0 && empIndex < employeeCount) {
            noOfEmployees[actualCount++] = empIndex; // Store valid employee numbers
        } else {
            cout << "\nInvalid employee number: " << empIndex;
        }
    }

    cout << "\nEnter the project name: ";
    cin.ignore(); // To clear the buffer
    cin.getline(projectName, 200);
    
    // Get and validate the deadline
    while (true) {
        cout << "\nEnter the deadline (YYYY-MM-DD): ";
        cin >> deadline;
        if (isValidDate(deadline)) {
            break;
        } else {
            cout << "Invalid date format. Please use YYYY-MM-DD." << endl;
        }
    }
    
    cout << "\nEnter the message: ";
    cin.ignore(); // To clear the buffer
    cin.getline(message, 200);

    for (int i = 0; i < actualCount; i++) {
        int empIndex = noOfEmployees[i];
        e[empIndex].assignProject(projectName, deadline, message);
        cout << "\nProject assigned to employee " << empIndex << ": " << projectName;
        saveToCSV(projectName, deadline, message, empIndex); // Save to CSV
    }
}

int main() {
    Employee e[10];
    Boss boss;
    int term = 2, level, choice, n, pass;

    while (term) {
        cout << "\nEnter the choice: " << endl;
        cout << "0. For exit" << endl;
        cout << "10. For boss" << endl;
        cout << "20. For employee" << endl;
        cout << "1. For insert as boss" << endl;
        cout << "2. For insert as employee" << endl;
        cout << "1. For update" << endl;
        cout << "3. For assigning group task" << endl;
        cout << "0. For terminate" << endl;
        cout << "\nEnter the level for boss and employee: ";
        cin >> level;

        switch (level) {
            case 10:
                cout << "Enter the password: ";
                cin >> pass;

                switch (pass) {
                    case 906472:
                        cout << "\nHello master Yash" << endl;
                        cout << "Enter the choice (1 for insert, 2 for display, 3 for assigning group task): ";
                        cin >> choice;
                        cout << "Enter the employee number: ";
                        cin >> n;

                        if (choice == 1)
                            insertboss(e[n], n);
                        else if (choice == 2)
                            displayboss(e[n]);
                        else if (choice == 3)
                            boss.assignGroupProject(e, 10); // Assign project to group
                        break;

                    case 2411:
                        cout << "\nHello master Soumya " << endl;
                        cout << "\nEnter the choice (1 for insert, 2 for display): ";
                        cin >> choice;
                        cout << "\nEnter the employee number: ";
                        cin >> n;

                        if (choice == 1)
                            insertboss(e[n], n);
                        else if (choice == 2)
                            displayboss(e[n]);
                        break;

                    default:
                        cout << "\nInvalid number";
                        break;
                }
                break;

            case 20:
                cout << "\nEnter the number (1 for update, 2 for display): ";
                cin >> choice;
                cout << "\nEnter your employee number: ";
                cin >> n;

                if (choice == 1)
                    e[n].update();
                else if (choice == 2)
                    e[n].display();
                break;

            default:
                cout << "\nInvalid input" << endl;
                break;
        }
        cout << "\nRepeat or not (1 for yes, 0 for no): ";
        cin >> term;
        cout << endl;
    }

    return 0;
}
