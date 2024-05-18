//Author: Eyosias Simon
//Date: 2024-05-18

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void displayEmployeeRecords(fstream& file) {
    string line;
    cout << "Employee Records:" << endl;

    // Move the file pointer to the beginning of the file
    file.seekg(0, ios::beg);

    // Read and display each line from the file
    while (getline(file, line)) {
        cout << line << endl;
    }
}

int main() {
    fstream file("employee.txt", ios::in);

    if (!file) {
        cout << "Could not open the file." << endl;
        return 1;
    }

    displayEmployeeRecords(file);

    file.close();
    return 0;
}
