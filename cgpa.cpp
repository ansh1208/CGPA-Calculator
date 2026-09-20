#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Structure to store course details
struct Course {
    string name;
    char grade;
    float credit;
    float gradePoint;
};

// Function to convert grade into grade point
float getGradePoint(char grade) {

    switch (grade) {
        case 'A':
        case 'a':
            return 10.0;

        case 'B':
        case 'b':
            return 8.0;

        case 'C':
        case 'c':
            return 7.0;

        case 'D':
        case 'd':
            return 6.0;

        case 'E':
        case 'e':
            return 5.0;

        case 'F':
        case 'f':
            return 0.0;

        default:
            return -1;
    }
}

int main() {

    int n;

    cout << "====================================\n";
    cout << "        CGPA CALCULATOR\n";
    cout << "====================================\n";

    cout << "Enter number of Subjects: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid number of Subject!\n";
        return 0;
    }

    Course courses[n];

    float totalCredits = 0;
    float totalGradePoints = 0;

    // Input course details
    for (int i = 0; i < n; i++) {

        cout << "\nCourse " << i + 1 << endl;

        cout << "Enter Subject name: ";
        cin >> courses[i].name;

        cout << "Enter grade (A/B/C/D/E/F): ";
        cin >> courses[i].grade;

        // Validate grade
        courses[i].gradePoint =
            getGradePoint(courses[i].grade);

        if (courses[i].gradePoint == -1) {
            cout << "Invalid grade entered!\n";
            return 0;
        }

        cout << "Enter credit hours: ";
        cin >> courses[i].credit;

        if (courses[i].credit <= 0) {
            cout << "Invalid credit hours!\n";
            return 0;
        }

        // Calculate grade points
        totalCredits += courses[i].credit;

        totalGradePoints +=
            courses[i].gradePoint * courses[i].credit;
    }

    // Calculate GPA
    float GPA = totalGradePoints / totalCredits;

    // Display course details
    cout << "\n\n====================================\n";
    cout << "          Subject DETAILS\n";
    cout << "====================================\n";

    cout << left
         << setw(15) << "Subject"
         << setw(10) << "Grade"
         << setw(12) << "Credits"
         << setw(12) << "Grade Point"
         << endl;

    cout << "------------------------------------\n";

    for (int i = 0; i < n; i++) {

        cout << left
             << setw(15) << courses[i].name
             << setw(10) << courses[i].grade
             << setw(12) << courses[i].credit
             << setw(12) << courses[i].gradePoint
             << endl;
    }

    // Display results
    cout << "\n====================================\n";
    cout << "          SEMESTER RESULT\n";
    cout << "====================================\n";

    cout << "Total Credits      : " << totalCredits << endl;

    cout << "Total Grade Points : "
         << totalGradePoints << endl;

    cout << fixed << setprecision(2);

    cout << "Semester GPA       : "
         << GPA << endl;

    cout << "Overall CGPA       : "
         << GPA << endl;

    cout << "====================================\n";

    return 0;
}