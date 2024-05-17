//Author: Dawit Moges
//Date: 05/17/2024
#include<iostream>
#include<fstream>
using namespace std;
void deleteEmployee(const string& empName, fstream& file) {
//The temporary file will be used to store the employee records except for the one to be deleted.  
    fstream tempFile("temp.txt", ios::out);
    string line;
//Found variable will be used to determine if the employee to be deleted is found in the file.
    bool found = false;
//The loop continues until there are no more lines to be read
    while (getline(file, line)) {
//It extracts the name of the employee from the line by using the substr function
        size_t pos = line.find(',');
//The extracted name is stored in the variable name
        string name = line.substr(0, pos);
//It checks if the extracted name (name) is not equal to the empName (the name of the employee to be deleted).
        if (name != empName) {
//If they are not equal, it means this line does not correspond to the employee to be deleted.
//so it writes the line to the tempFile using the << operator.
            tempFile << line << endl;
//In this case, it sets the found variable to true to indicate that the employee has been found but does not write this line to the tempFile.
        } else {
            found = true;
        }
    }
    file.close();
    tempFile.close();
//It uses the remove function to delete the original file "employees.txt"
    remove("employees.txt");
//It uses the rename function to rename the temporary file "temp.txt" to "employees.txt". 
    rename("temp.txt", "employees.txt");
    if (found) {
        cout << "Employee deleted successfully." << endl;
    } else {
        cout << "Employee not found." << endl;
    }
}