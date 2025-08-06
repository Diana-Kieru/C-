#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Student {
private:
    string name;
    int marks;
    char grade;

public:
    // Constructor
    Student() : name(""), marks(0), grade('F') {}
    
    Student(string studentName, int studentMarks) 
        : name(studentName), marks(studentMarks) {
        grade = calculateGrade(studentMarks);
    }

    // Getters
    string getName() const { return name; }
    int getMarks() const { return marks; }
    char getGrade() const { return grade; }

    // Setters
    void setName(const string& studentName) { name = studentName; }
    
    void setMarks(int studentMarks) { 
        marks = studentMarks; 
        grade = calculateGrade(studentMarks);
    }

    // Function to calculate grade based on marks
    static char calculateGrade(int marks) {
        if (marks >= 90) return 'A';
        else if (marks >= 80) return 'B';
        else if (marks >= 70) return 'C';
        else if (marks >= 60) return 'D';
        else return 'F';
    }

    // Display student information
    void displayInfo() const {
        cout << "Name: " << name
             << " | Marks: " << marks
             << " | Grade: " << grade << endl;
    }
};

class StudentManager {
private:
    vector<Student> students;

public:
    // Add a student to the collection
    void addStudent(const Student& student) {
        students.push_back(student);
    }

    // Input student data from user
    void inputStudentData() {
        int num;
        cout << "Enter number of students: ";
        cin >> num;

        for (int i = 0; i < num; ++i) {
            string name;
            int marks;

            cout << "\nEnter name of student " << i + 1 << ": ";
            cin >> ws; // to clear newline from previous input
            getline(cin, name);

            cout << "Enter marks (out of 100): ";
            cin >> marks;

            Student student(name, marks);
            addStudent(student);
        }
    }

    // Display all student data
    void displayAllStudents() const {
        cout << "\n--- Student Report ---\n";
        for (const auto& student : students) {
            student.displayInfo();
        }
    }

    // Get number of students
    int getStudentCount() const {
        return students.size();
    }

    // Get student by index
    const Student& getStudent(int index) const {
        return students[index];
    }
};

int main() {
    StudentManager manager;
    
    // Input student data
    manager.inputStudentData();
    
    // Display student report
    manager.displayAllStudents();

    return 0;
}
