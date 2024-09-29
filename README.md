# Student Grade Management System
[Uploading Screen-2024-09-29-122747(1)(1)(1).mp4.zip…]()

## Overview
The Student Grade Management System is a C++ console application designed to manage student records efficiently. This system allows users to add, view, modify, and delete student records. It also provides a statistical analysis of student grades across multiple subjects. This project is aimed at helping educators and administrators streamline the management of student data.

## Features
- **Add Student Records:** Add new student information, including their name, ID, and grades for multiple subjects.
- **View All Records:** Display all stored student records in a formatted manner.
- **Modify Student Records:** Update existing student details such as name and grades.
- **Delete Student Records:** Remove a student record based on the student ID.
- **Calculate Statistics:** Compute and display the average, highest, and lowest grades for each subject.
- **Input Validation:** Robust input validation to ensure that the data entered is correct and within acceptable ranges.

## Project Structure
The project is organized into several functions to ensure clarity and modularity:

- **Student Struct:** Stores student information including name, ID, and grades.
- **`displayMenu()`:** Displays the main menu of the application.
- **`addStudent()`:** Adds a new student record and validates input.
- **`viewStudents()`:** Displays all student records.
- **`modifyStudent()`:** Allows modification of a student's information.
- **`deleteStudent()`:** Deletes a student record based on ID.
- **`calculateStatistics()`:** Calculates and displays statistics such as average, maximum, and minimum grades.

## How It Works
1. **Input Validation:**
   - The program uses loops and conditionals to ensure that all input data is correctly formatted and within expected ranges. For example, student IDs must be numeric, and grades must be between 0 and 100.

2. **Functions and Modularity:**
   - Each operation, like adding or modifying a student record, is encapsulated in its own function. This structure makes the code more maintainable and easier to extend.

3. **Statistical Analysis:**
   - The system calculates statistical metrics such as the average, highest, and lowest grades for each subject using loops to iterate over the stored records.

## Getting Started
### Prerequisites
- Xcode (for macOS users)
- A code editor or IDE (e.g., Visual Studio Code) for other platforms.

### Installation and Running with Xcode
1. Clone the repository:
   ```bash
   git clone https://github.com/IsaacAdeleke-coding/Student-Grade-Management-System.git
