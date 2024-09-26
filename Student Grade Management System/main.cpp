//
//  main.cpp
//  Student Grade Management System
//
//  Created by Isaac Adeleke on 9/23/24.
//

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
    cout << " < Student Grade Management > \n";
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
    cin.ignore(); // Clear the input buffer before getting the name
    getline(cin, students[count].name);
    
    cout << "Enter Student ID: ";
    cin >> students[count].id;
    
    // Validate student ID input
   while (cin.fail()) {
       cin.clear(); // Clear the error flag
       cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore incorrect input
       cout << "Invalid input. Please enter a valid numeric Student ID: ";
       cin >> students[count].id;
   }

   for (int i = 0; i < MAX_SUBJECTS; ++i) {
       cout << "Enter grade for subject " << i + 1 << " (0-100): ";
       cin >> students[count].grades[i];

       // Validate grade input
       while (cin.fail() || students[count].grades[i] < 0 || students[count].grades[i] > 100) {
           cin.clear(); // Clear the error flag
           cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore incorrect input
           cout << "Invalid input. Please enter a valid grade (0-100): ";
           cin >> students[count].grades[i];
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
       cout << "Grades: ";
       for (int j = 0; j < MAX_SUBJECTS; ++j) {
           cout << students[i].grades[j] << " ";
       }
       cout << "\n---------------------------\n";
   }
}
