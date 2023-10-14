#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Student {
private:
    string name;
    int rollNumber;
    double marks;

public:
    Student(); // Constructor
    void setData(string studentName, int studentRollNumber, double studentMarks);
    void displayData() const; // Make displayData a const member function
    int getRollNumber() const; // Also make getRollNumber a const member function
};

Student::Student() {
    // Constructor initializes data members with default values
    name = "N/A";
    rollNumber = 0;
    marks = 0.0;
}

void Student::setData(string studentName, int studentRollNumber, double studentMarks) {
    // Set student information
    name = studentName;
    rollNumber = studentRollNumber;
    marks = studentMarks;
}

void Student::displayData() const {
    cout << "Name: " << name << endl;
    cout << "Roll Number: " << rollNumber << endl;
    cout << "Marks: " << marks << endl;
}

int Student::getRollNumber() const {
    return rollNumber;
}


int main() {
    vector<Student> students; // A vector to store student records

    char continueOperation;
    do {
        cout << "Student Information System" << endl;
        cout << "1. Add Student" << endl;
        cout << "2. Update Student Information" << endl;
        cout << "3. Display Students" << endl;
        cout << "Enter your choice (1/2/3): ";

        int choice;
        cin >> choice;

        if (choice == 1) {
            // Adding a new student
            Student student;
            string name;
            int rollNumber;
            double marks;

            cout << "Enter Student Name: ";
            cin.ignore(); // Clear the input buffer
            getline(cin, name);

            cout << "Enter Roll Number: ";
            cin >> rollNumber;

            cout << "Enter Marks: ";
            cin >> marks;

            student.setData(name, rollNumber, marks);
            students.push_back(student);
            cout << "Student added successfully!" << endl;
        }
        else if (choice == 2) {
            // Updating student information
            int rollNumber;
            cout << "Enter Roll Number of the student to update: ";
            cin >> rollNumber;

            bool found = false;
            for (Student& student : students) {
                if (student.getRollNumber() == rollNumber) {
                    string name;
                    double marks;

                    cout << "Enter Updated Name: ";
                    cin.ignore();
                    getline(cin, name);

                    cout << "Enter Updated Marks: ";
                    cin >> marks;

                    student.setData(name, rollNumber, marks);
                    cout << "Student information updated!" << endl;
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "Student with Roll Number " << rollNumber << " not found." << endl;
            }
        }
        else if (choice == 3) {
            // Displaying the list of students
            cout << "Student List:" << endl;
            for (const Student& student : students) {
                student.displayData();
                cout << "-------------------" << endl;
            }
        }
        else {
            cout << "Invalid choice." << endl;
        }

        cout << "Do you want to perform another operation? (y/n): ";
        cin >> continueOperation;
    } while (continueOperation == 'y' || continueOperation == 'Y');

    return 0;
}
