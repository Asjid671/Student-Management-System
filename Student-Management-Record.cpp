#include <iostream>
#include <string>

using namespace std;

const int SIZE = 100;

int studentID[SIZE];
string studentName[SIZE];
string studentClass[SIZE];
string studentAddress[SIZE];
string attendance[SIZE];
string studentsection[SIZE];
float marks[SIZE];

int totalStudents = 0;

void addStudent() 
{
    if (totalStudents >= SIZE) 
    {
        cout << "Record is full!\n";
        return;
    }

    cout << "\nEnter Student ID: ";
    cin >> studentID[totalStudents];

    cout << "Enter Student Name: ";
    cin >> studentName[totalStudents];

    cout << "Enter Class: ";
    cin >> studentClass[totalStudents];
    
    cout << "Enter Section: ";
    cin >> studentsection[totalStudents];

    cout << "Enter Address: ";
    cin >> studentAddress[totalStudents];

    attendance[totalStudents] = "Absent";
    marks[totalStudents] = 0;

    totalStudents++;
    cout << "\nStudent added successfully!\n";
}

void updateStudent() 
{
    int id;
    cout << "\nEnter Student ID to update: ";
    cin >> id;

    bool found = false;
    for (int i = 0; i < totalStudents; i++) 
    {
        if (studentID[i] == id) 
        {
            cout << "Enter new name: ";
            cin >> studentName[i];

            cout << "Enter new address: ";
            cin >> studentAddress[i];

            cout << "\nRecord updated!\n";
            found = true;
            break;
        }
    }
    if (!found)
    {
        cout << "\nStudent not found!\n";
    }
}

void searchStudent() 
{
    int id;
    cout << "\nEnter Student ID to search: ";
    cin >> id;

    bool found = false;
    for (int i = 0; i < totalStudents; i++) 
    {
        if (studentID[i] == id) 
        {
            cout << "\n--- Student Found ---\n";
            cout << "ID: " << studentID[i] << endl;
            cout << "Name: " << studentName[i] << endl;
            cout << "Class: " << studentClass[i] << endl;
            cout << "Section: " << studentsection[i] << endl;
            cout << "Address: " << studentAddress[i] << endl;
            cout << "Marks: " << marks[i] << endl;
            cout << "Attendance: " << attendance[i] << endl;
            found = true;
            break;
        }
    }
    if (!found)
    {
        cout << "\nStudent not found!\n";
    }
}

void deleteStudent() 
{
    int id;
    cout << "\nEnter Student ID to delete: ";
    cin >> id;

    bool found = false;
    for (int i = 0; i < totalStudents; i++) 
    {
        if (studentID[i] == id) 
        {
            for (int j = i; j < totalStudents - 1; j++) 
            {
                studentID[j] = studentID[j + 1];
                studentName[j] = studentName[j + 1];
                studentClass[j] = studentClass[j + 1];
                studentsection[j] = studentsection[j + 1];
                studentAddress[j] = studentAddress[j + 1];
                attendance[j] = attendance[j + 1];
                marks[j] = marks[j + 1];
            }
            totalStudents--;
            cout << "\nRecord deleted!\n";
            found = true;
            break;
        }
    }
    if (!found)
    {
        cout << "\nStudent not found!\n";
    }
}

void recordAttendance() 
{
    int id;
    cout << "\nEnter Student ID for attendance: ";
    cin >> id;

    bool found = false;
    for (int i = 0; i < totalStudents; i++) 
    {
        if (studentID[i] == id) 
        {
            int c;
            cout << "Enter 1 for Present, 0 for Absent: ";
            cin >> c;
            attendance[i] = (c == 1) ? "Present" : "Absent";
            cout << "\nAttendance recorded!\n";
            found = true;
            break;
        }
    }
    if (!found)
    {
        cout << "\nStudent not found!\n";
    }
}

void enterMarks() 
{
    int id;
    cout << "\nEnter Student ID to enter marks: ";
    cin >> id;

    bool found = false;
    for (int i = 0; i < totalStudents; i++) 
    {
        if (studentID[i] == id) 
        {
            cout << "Enter marks: ";
            cin >> marks[i];
            cout << "\nMarks updated!\n";
            found = true;
            break;
        }
    }
    if (!found)
    {
        cout << "\nStudent not found!\n";
    }
}

void showAll() 
{
    if (totalStudents == 0)
    {
        cout << "\nNo student records found!\n";
        return;
    }

    cout << "\n==== All Student Management Records ====\n";
    for (int i = 0; i < totalStudents; i++) 
    {
        cout << "\nID: " << studentID[i];
        cout << "\nName: " << studentName[i];
        cout << "\nClass: " << studentClass[i];
        cout << "\nSection: " << studentsection[i];
        cout << "\nAddress: " << studentAddress[i];
        cout << "\nMarks: " << marks[i];
        cout << "\nAttendance: " << attendance[i];
        cout << "\n-------------------------\n";
    }
}

int main() 
{
    int choice;

    while (true) 
    {
        cout << "\n\n--- STUDENT RECORD SYSTEM ---\n";
        cout << "1. Add Student\n";
        cout << "2. Update Student\n";
        cout << "3. Search Student\n";
        cout << "4. Delete Student\n";
        cout << "5. Record Attendance\n";
        cout << "6. Enter Marks\n";
        cout << "7. Show All Records\n";
        cout << "8. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) 
        {
        case 1: 
            addStudent(); 
            break;
        case 2: 
            updateStudent(); 
            break;
        case 3: 
            searchStudent(); 
            break;
        case 4: 
            deleteStudent(); 
            break;
        case 5: 
            recordAttendance(); 
            break;
        case 6: 
            enterMarks(); 
            break;
        case 7: 
            showAll(); 
            break;
        case 8: 
            return 0;
        default: 
            cout << "Invalid choice!\n";
        }
    }
}