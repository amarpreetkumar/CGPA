#include <bits/stdc++.h>
using namespace std;

// Function to calculate GPA and grade
pair<int, string> calculateGPAandGrade(int marks) {
    string grade;
    int gpa;

    if (marks >= 90 && marks <= 100) {
        grade = "A+";
        gpa = 10;
    } else if (marks >= 80 && marks < 90) {
        grade = "A";
        gpa = 9;
    } else if (marks >= 70 && marks < 80) {
        grade = "B+";
        gpa = 8;
    } else if (marks >= 60 && marks < 70) {
        grade = "B";
        gpa = 7;
    } else if (marks >= 50 && marks < 60) {
        grade = "C+";
        gpa = 6;
    } else if (marks >= 40 && marks < 50) {
        grade = "C";
        gpa = 5;
    } else {
        grade = "F";
        gpa = 0;
    }
    return {gpa, grade};
}

// Function to get student details and marks
void details_Of_students(string &name, int &course_count, vector<int> &marks, vector<int> &gpas, vector<string> &grades) {
    cout << "Enter your name: ";
    cin >> name;

    cout << "Enter number of courses: ";
    cin >> course_count;

    marks.resize(course_count);  // Resize the vector to store marks for each course
    gpas.resize(course_count);   // Resize the vector to store GPA for each course
    grades.resize(course_count); // Resize the vector to store grades for each course

    for (int i = 0; i < course_count; i++) {
        cout << "Enter marks for course " << i + 1 << ": ";
        cin >> marks[i];

        // Calculate GPA and Grade
        pair<int, string> result = calculateGPAandGrade(marks[i]);
        gpas[i] = result.first;
        grades[i] = result.second;
    }
}

// Function to calculate CGPA
float calculateCGPA(const vector<int> &gpas) {
    int totalGPA = 0;
    for (int gpa : gpas) {
        totalGPA += gpa;
    }
    return static_cast<float>(totalGPA) / gpas.size();
}

int main() {
    cout << ".............................................." << endl;
    cout << "...........  CGPA CALCULATOR  ................" << endl;
    cout << ".............................................." << endl;

    string name;
    int course_count;
    vector<int> marks, gpas;
    vector<string> grades;

    details_Of_students(name, course_count, marks, gpas, grades);

    cout << "\nStudent Name: " << name << endl;
    cout << "Courses and their corresponding marks, GPA, and grades: " << endl;

    for (int i = 0; i < course_count; i++) {
        cout << "Course " << i + 1 << ": Marks = " << marks[i] 
             << ", GPA = " << gpas[i] 
             << ", Grade = " << grades[i] << endl;
    }

    // Calculate CGPA
    float cgpa = calculateCGPA(gpas);
    cout << "\nYour CGPA is: " << cgpa << endl;

    return 0;
}
