#include<iostream>
#include <fstream>
#include <string>
using namespace std;

struct StudentRecord {
    string name;
    char gender;
    int age;
    int rollNumber;
    double marks;
};


void accept(StudentRecord& record) {
    cout << "Enter student name: ";
    cin >> record.name;
    cout << "Enter roll number: ";
    cin >> record.rollNumber;
    cout << "Enter gender: ";
    cin >> record.gender;
    cout << "Enter age: ";
    cin >> record.age;
    cout << "Enter marks: ";
    cin >> record.marks;
}


void save(const StudentRecord& record, fstream& outFile) {
    outFile << record.name << "," << record.rollNumber << "," <<record.gender<<","<<record.age<<","<< record.marks << "\n";
}


void readRecords(fstream& inFile) {
    StudentRecord record;
    while (inFile >> record.name >> record.rollNumber >> record.gender >> record.age >> record.marks) {
        cout << "Name: " << record.name << ", Roll Number: " << record.rollNumber << ", Gender: " << record.gender << ", Age: " << record.age
                  << ", Marks: " << record.marks << "\n";
    }
}


void display(const StudentRecord& record) {
    cout << "Name: " << record.name << ", Roll Number: " << record.rollNumber << ", Gender: " << record.gender << ", Age: " << record.age
              << ", Marks: " << record.marks << "\n";
}


long getFileSize(fstream& file) {
    long number_of_lines;
    string line;
    while (getline(file, line))
        ++number_of_lines;
        return number_of_lines;
}
int main() {
    const string fileName = "student_records.csv";
    fstream File(fileName, ios::app|ios::in);  

    if (File.fail()) {
        cerr << "Error opening file: " << fileName << "\n";
        return 1;
    }
    long number_of_lines = getFileSize(File);

    StudentRecord = new students[100]; 


    int numStudents;
    cout << "Enter the number of students: ";
    cin >> numStudents;
    for (int i = 0; i < numStudents; ++i) {
        accept(students[i]);
        save(students[i], File);
    }


    cout << "\nStudent records from file:\n";
    readRecords(File);

    cout << "\nFile size: " << getFileSize(File) << " bytes\n";

    return 0;
}