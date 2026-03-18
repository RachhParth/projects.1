#include <iostream>
#include <vector>
using namespace std;

class MemoryCalculate {
private:
    int id;
    string name;

public:
    MemoryCalculate(int i, string n) {
        id = i;
        name = n;
    }

    int getId() {
        return id;
    }

    void displayDetails() {
        cout << "ID: " << id << ", Name: " << name << endl;
    }
};

int main() {
    vector<MemoryCalculate> students;
    int choice;

    do {
        cout << "\n--- Student Management System ---\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Search Student by ID\n";
        cout << "4. Remove Student by ID\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            int id;
            string name;

            cout << "Enter ID: ";
            cin >> id;

            cin.ignore(); // 🔥 Fix for getline issue

            cout << "Enter Name: ";
            getline(cin, name); // 🔥 Now supports full name

            students.push_back(MemoryCalculate(id, name));
            cout << "Student Added Successfully!\n";
        }

        else if (choice == 2) {
            if (students.empty()) {
                cout << "No students found!\n";
            } else {
                cout << "\nStudent List:\n";
                for (auto &s : students) {
                    s.displayDetails();
                }
            }
        }

        else if (choice == 3) {
            int searchId;
            cout << "Enter ID to search: ";
            cin >> searchId;

            bool found = false;
            for (auto &s : students) {
                if (s.getId() == searchId) {
                    s.displayDetails();
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "Student not found!\n";
            }
        }

        else if (choice == 4) {
            int removeId;
            cout << "Enter ID to remove: ";
            cin >> removeId;

            bool found = false;
            for (auto it = students.begin(); it != students.end(); it++) {
                if (it->getId() == removeId) {
                    students.erase(it);
                    cout << "Student removed successfully!\n";
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "Student not found!\n";
            }
        }

    } while (choice != 5);

    return 0;
}