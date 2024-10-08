#include <iostream>
#include <string.h>
#include <iomanip>
#include <cstdlib>
#include <cctype>
#define MAX 100

using namespace std;

class Employee {
protected:
    long int dl;
    char project[200], message[200];
    int status;

public:
    Employee() {
        strcpy(project, "not_available");
        strcpy(message, "not_available");
        status = 0;
        dl = 0;
    }

    virtual void update() {
        cout << "\nEnter the status: ";
        cin >> status;
        cout << "\nThe status has been updated";
    }

    virtual void display() {
        cout << "\nThe given project: " << project;
        cout << "\nThe status of the project: " << status << "%";
        cout << "\nThe deadline: " << dl;
        cout << "\nThe message given by boss: " << message;
    }

    void assignProject(const char* projName, long int deadline, const char* msg) {
        strcpy(project, projName);
        dl = deadline;
        strcpy(message, msg);
    }

    friend void insertboss(Employee &e);
    friend void displayboss(Employee &e);
    friend void assignGroupProject(Employee e[], int employeeCount);
};

class Boss : public Employee {
public:
    void assignGroupProject(Employee e[], int employeeCount);
};

void insertboss(Employee &e) {
    cin.ignore();
    cout << "\nEnter the project for the employee: ";
    cin.getline(e.project, 200);
    cout << "\nProject inserted";
    cout << "\nEnter the deadline: ";
    cin >> e.dl;
    cin.ignore();
    cout << "\nThe deadline inserted" << endl;
    cout << "\nEnter the message: ";
    cin.getline(e.message, 200);
}

void displayboss(Employee &e) {
    cout << "\nThe project: " << e.project << endl;
    cout << "\nThe deadline: " << e.dl << endl;
    cout << "\nThe status: " << e.status << endl;
}

void Boss::assignGroupProject(Employee e[], int employeeCount) {
    char projectName[200], message[200];
    long int deadline;
    int noOfEmployees[MAX], actualCount = 0;

    cin.ignore();
    cout << "\nEnter the employee numbers (type 'done' to finish): ";
    
    // Using a while loop to collect employee numbers
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

    // Get project details
    cout << "\nEnter the project name: ";
    cin.ignore(); // To clear the buffer
    cin.getline(projectName, 200);
    cout << "\nEnter the deadline: ";
    cin >> deadline;
    cin.ignore(); // To ignore the newline character
    cout << "\nEnter the message: ";
    cin.getline(message, 200);

    // Assign the project to each employee
    for (int i = 0; i < actualCount; i++) {
        int empIndex = noOfEmployees[i];
        e[empIndex].assignProject(projectName, deadline, message);
        cout << "\nProject assigned to employee " << empIndex << ": " << projectName;
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
        cout << "3. For assigning group task" << endl; // Added option
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
                            insertboss(e[n]);
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
                            insertboss(e[n]);
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
