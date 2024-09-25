//
//  main.cpp
//  Student Grade Management System
//
//  Created by Isaac Adeleke on 9/23/24.
//

#include <iostream>
#include <string>

using namespace std;

// Constants
const int MAX_STUDENTS = 100; // Maximum number of students
const int MAX_SUBJECTS = 5; // Number of subjects

// Student Structure
struct Student {
    string name;
    int id;
    float grades[MAX_SUBJECTS];
};

// Function Prototypes
void displayMenu();
void addStudent(Student students[], int &count);

int main() {
    Student students[MAX_STUDENTS];
    int count = 0; // Current number of students
    int choice;

    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent(students, count);
                break;
            // Other cases will be added in future commits
            case 6:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}

// Display the main menu
void displayMenu() {
    cout << "---------------------------\n";
    cout << "  Student Grade Management  \n";
    cout << "---------------------------\n";
    cout << "1. Add Student Record\n";
    cout << "2. View All Records\n";
    cout << "3. Modify Student Record\n";
    cout << "4. Delete Student Record\n";
    cout << "5. Calculate Statistics\n";
    cout << "6. Exit\n";
    cout << "Enter your choice: ";
}

// Add a new student record
void addStudent(Student students[], int &count) {
    if (count >= MAX_STUDENTS) {
        cout << "Maximum number of students reached. Cannot add more students.\n";
        return;
    }

    cout << "Enter Student Name: ";
    cin.ignore(); // Clear the input buffer
    getline(cin, students[count].name);

    cout << "Enter Student ID: ";
    cin >> students[count].id;

    for (int i = 0; i < MAX_SUBJECTS; ++i) {
        cout << "Enter grade for subject " << i + 1 << ": ";
        cin >> students[count].grades[i];
    }
    count++;
    cout << "Student added successfully.\n";
}
