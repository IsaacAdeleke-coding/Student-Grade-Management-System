//
//  main.cpp
//  Student Grade Management System
//
//  Created by Isaac Adeleke on 9/23/24.
//
#include <iostream>
#include <string>
#include <limits> // For numeric_limits

using namespace std;

// Constants
const int MAX_STUDENTS = 100; // Maximum number of students
const int MAX_SUBJECTS = 5;   // Number of subjects

// Subject names (you can modify these as needed)
const string SUBJECT_NAMES[MAX_SUBJECTS] = {"Math", "English", "Physics", "Chemistry", "Biology"};

// Student Structure
struct Student {
    string name;
    int id;
    float grades[MAX_SUBJECTS];
};

// Function Prototypes
void displayMenu();
void addStudent(Student students[], int &count);
void viewStudents(const Student students[], int count);
void viewSingleStudent(const Student students[], int count);
void modifyStudent(Student students[], int count);
void deleteStudent(Student students[], int &count);
void calculateStatistics(const Student students[], int count);

int main() {
    Student students[MAX_STUDENTS];
    int count = 0; // Current number of students
    int choice;

    do {
        displayMenu();
        cin >> choice;

        // Clear any remaining characters in the input buffer, e.g., newline
        if (cin.fail()) {
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore the rest of the input line
            choice = 0; // Set an invalid choice to display an error message
        }

        switch (choice) {
            case 1:
                addStudent(students, count);
                break;
            case 2:
                viewStudents(students, count);
                break;
            case 3:
                modifyStudent(students, count);
                break;
            case 4:
                deleteStudent(students, count);
                break;
            case 5:
                calculateStatistics(students, count);
                break;
            case 6:
                viewSingleStudent(students, count); // New option to search for a student
                break;
            case 7:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 7);

    return 0;
}

// Display the main menu
void displayMenu() {
    cout << "---------------------------\n";
    cout << " < Student Grade Management > \n";
    cout << "---------------------------\n";
    cout << "1. Add Student Record\n";
    cout << "2. View All Records\n";
    cout << "3. Modify Student Record\n";
    cout << "4. Delete Student Record\n";
    cout << "5. Calculate Statistics\n";
    cout << "6. Search and View Student Record\n"; // New option
    cout << "7. Exit\n";
    cout << "Enter your choice: ";
}

// Add a new student record
void addStudent(Student students[], int &count) {
    if (count >= MAX_STUDENTS) {
        cout << "Maximum number of students reached. Cannot add more students.\n";
        return;
    }

    cout << "Enter Student Name: ";
    cin.ignore(); // Clear the input buffer before getting the name
    getline(cin, students[count].name);

    cout << "Enter Student ID: ";
    while (!(cin >> students[count].id)) { // Validate student ID input
        cin.clear(); // Clear the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore incorrect input
        cout << "Invalid input. Please enter a valid numeric Student ID: ";
    }

    for (int i = 0; i < MAX_SUBJECTS; ++i) {
        cout << "Enter grade for " << SUBJECT_NAMES[i] << " (0-100): ";
        while (!(cin >> students[count].grades[i]) || students[count].grades[i] < 0 || students[count].grades[i] > 100) {
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore incorrect input
            cout << "Invalid input. Please enter a valid grade for " << SUBJECT_NAMES[i] << " (0-100): ";
        }
    }
    count++;
    cout << "Student added successfully.\n";
}

// View all student records
void viewStudents(const Student students[], int count) {
    if (count == 0) {
        cout << "No student records available.\n";
        return;
    }

    cout << "Student Records:\n";
    cout << "---------------------------\n";
    for (int i = 0; i < count; ++i) {
        cout << "Name: " << students[i].name << "\n";
        cout << "ID: " << students[i].id << "\n";
        cout << "Grades:\n";
        for (int j = 0; j < MAX_SUBJECTS; ++j) {
            cout << SUBJECT_NAMES[j] << ": " << students[i].grades[j] << "\n";
        }
        cout << "---------------------------\n";
    }
}

// View a single student record based on Student ID
void viewSingleStudent(const Student students[], int count) {
    if (count == 0) {
        cout << "No student records available to search.\n";
        return;
    }

    int id;
    cout << "Enter Student ID to search: ";
    while (!(cin >> id)) { // Validate student ID input
        cin.clear(); // Clear the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore incorrect input
        cout << "Invalid input. Please enter a valid numeric Student ID: ";
    }

    for (int i = 0; i < count; ++i) {
        if (students[i].id == id) {
            cout << "Student found:\n";
            cout << "Name: " << students[i].name << "\n";
            cout << "ID: " << students[i].id << "\n";
            cout << "Grades:\n";
            for (int j = 0; j < MAX_SUBJECTS; ++j) {
                cout << SUBJECT_NAMES[j] << ": " << students[i].grades[j] << "\n";
            }
            cout << "---------------------------\n";
            return;
        }
    }
    cout << "Student ID not found.\n";
}

// Modify an existing student record
void modifyStudent(Student students[], int count) {
    if (count == 0) {
        cout << "No student records available to modify.\n";
        return;
    }

    int id;
    cout << "Enter Student ID to modify: ";
    while (!(cin >> id)) { // Validate student ID input
        cin.clear(); // Clear the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore incorrect input
        cout << "Invalid input. Please enter a valid numeric Student ID: ";
    }

    for (int i = 0; i < count; ++i) {
        if (students[i].id == id) {
            cout << "Enter new name: ";
            cin.ignore(); // Clear the input buffer
            getline(cin, students[i].name);

            for (int j = 0; j < MAX_SUBJECTS; ++j) {
                cout << "Enter new grade for " << SUBJECT_NAMES[j] << " (0-100): ";
                while (!(cin >> students[i].grades[j]) || students[i].grades[j] < 0 || students[i].grades[j] > 100) {
                    cin.clear(); // Clear the error flag
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore incorrect input
                    cout << "Invalid input. Please enter a valid grade (0-100): ";
                }
            }
            cout << "Student record updated successfully.\n";
            return;
        }
    }
    cout << "Student ID not found.\n";
}

// Delete a student record
void deleteStudent(Student students[], int &count) {
    if (count == 0) {
        cout << "No student records available to delete.\n";
        return;
    }

    int id;
    cout << "Enter Student ID to delete: ";
    while (!(cin >> id)) { // Validate student ID input
        cin.clear(); // Clear the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore incorrect input
        cout << "Invalid input. Please enter a valid numeric Student ID: ";
    }

    for (int i = 0; i < count; ++i) {
        if (students[i].id == id) {
            for (int j = i; j < count - 1; ++j) {
                students[j] = students[j + 1];
            }
            count--;
            cout << "Student record deleted successfully.\n";
            return;
        }
    }
    cout << "Student ID not found.\n";
}

// Calculate and display statistics
void calculateStatistics(const Student students[], int count) {
    if (count == 0) {
        cout << "No student records available to calculate statistics.\n";
        return;
    }

    float totalGrades[MAX_SUBJECTS] = {0};
    float maxGrades[MAX_SUBJECTS] = {0};
    float minGrades[MAX_SUBJECTS] = {100};

    for (int i = 0; i < count; ++i) {
        for (int j = 0; j < MAX_SUBJECTS; ++j) {
            totalGrades[j] += students[i].grades[j];
            if (students[i].grades[j] > maxGrades[j]) maxGrades[j] = students[i].grades[j];
            if (students[i].grades[j] < minGrades[j]) minGrades[j] = students[i].grades[j];
        }
    }

    cout << "Statistics:\n";
    for (int i = 0; i < MAX_SUBJECTS; ++i) {
        cout << SUBJECT_NAMES[i] << ":\n";
        cout << "Average: " << totalGrades[i] / count << "\n";
        cout << "Highest: " << maxGrades[i] << "\n";
        cout << "Lowest: " << minGrades[i] << "\n";
    }
}
