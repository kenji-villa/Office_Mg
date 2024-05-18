//Author: Eyosias Simon
//Date: 2024-05-18

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Employee {
    string name;
    int id;
    int age;
    int salary;
    string department;
    string position;
};

void updateEmployee(fstream& file) {
    string empName;
    cout << "Enter the name of the employee to update: ";
    cin >> empName;

    // Move the file pointer to the beginning of the file
    file.seekg(0, ios::beg);

    string line;
    bool found = false;
    fstream tempFile("temp.txt", ios::out);

    while (getline(file, line)) {
        size_t pos = line.find(',');
        string name = line.substr(0, pos);

        if (name == empName) {
            found = true;
            Employee record;
            record.name = empName;

            cout << "Current employee information:" << endl;
            cout << line << endl;

            cout << "Enter new employee information:" << endl;
            cout << "Name: ";
            cin >> record.name;
            cout << "ID: ";
            cin >> record.id;
            cout << "Age: ";
            cin >> record.age;
            cout << "Salary: ";
            cin >> record.salary;
            cout << "Department: ";
            cin >> record.department;
            cout << "Position: ";
            cin >> record.position;

            tempFile << record.name << "," << record.id << "," << record.age << "," << record.salary << "," << record.department << "," << record.position << endl;
        } else {
            tempFile << line << endl;
        }
    }

    file.close();
    tempFile.close();

    remove("employees.txt");
    rename("temp.txt", "employees.txt");

    if (found) {
        cout << "Employee record updated successfully." << endl;
    } else {
        cout << "Employee not found." << endl;
    }
}

int main() {
    fstream file("employee.txt", ios::in | ios::out);

    if (!file) {
        cout << "Could not open the file." << endl;
        return 1;
    }

    updateEmployee(file);

    file.close();
    return 0;
}
