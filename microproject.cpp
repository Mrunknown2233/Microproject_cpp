#include <iostream>
#include <string.h>
#include <iomanip>
using namespace std;
class emp {
private:
    long int dl;
    char project[200], message[200];
    int status;

public:
    emp() {
        strcpy(project, "not_available");
        strcpy(message, "not_available");
        status = 0;
        dl = 0;
    }

    void update() {
        cout << "\nEnter the status: ";
        cin >> status;
        cout << "\nThe status has been updated";
    }

    void display() {
        cout << "\nThe given project: " << project;
        cout << "\nThe status of the project: " << status << "%";
        cout << "\nThe deadline: " << dl;
        cout << "\nThe message given by boss: " << message;
    }

    friend void insertboss(emp &e);
    friend void displayboss(emp &e);
};

void insertboss(emp &e) {
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

void displayboss(emp &e) {
    cout << "\nThe project: " << e.project << endl;
    cout << "\nThe deadline: " << e.dl << endl;
    cout << "\nThe status: " << e.status << endl;
}

int main() {
    emp e[10];
    int term = 2, level, choice, n, pass;

    cout << "\nEnter the choice: " << endl;
    cout << "0. For exit" << endl;
    cout << "10. For boss" << endl;
    cout << "20. For employee" << endl;
    cout << "1. For insert as boss" << endl;
    cout << "2. For insert as employee" << endl;
    cout << "1. For update" << endl;
    cout << "0. For terminate" << endl;

    while (term) {
        cout << "\nEnter the level for boss and employee: ";
        cin >> level;

        switch (level) {
            case 10:
		cout << "\nEnter the password: ";
		cin >> pass;

		switch (pass) {
		    case 906472:
			cout << "\nHello master Yash" << endl;
			cout << "\nEnter the choice (1 for insert, 2 for display): ";
			cin >> choice;
			cout << "\nEnter the employee number: ";
			cin >> n;

			if (choice == 1)
			    insertboss(e[n]);
			else if (choice == 2)
			    displayboss(e[n]);
			break;

		    case 903456:
			cout << "\nHello master Phinehas" << endl;
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
