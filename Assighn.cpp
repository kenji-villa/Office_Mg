#include<iostream>
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


void addEmp(Employee& record) {
    cout<<"pleas enter employee name: ";
    cin>>record.name;
    cout<<"pleas enter employee id: ";
    cin>>record.id;
    cout<<"pleas enter employee age: ";
    cin>>record.age;
    cout<<"pleas enter employee salary: ";
    cin>>record.salary;
    cout<<"pleas enter employee department: ";
    cin>>record.department;
    cout<<"pleas enter employee position: ";
    cin>>record.position;
}

    bool searchEmp(fstream& file) {
    string empName;
    cout<<"pleas enter employee name";
    cin>> empName;
string line;

//a while loop is used to read each line from the file using the getline function. The loop continues until there are no more lines to read from the file.
while (getline(file, line)) {
//the code finds the position of the comma (',') using the find function of the string class. The position of the comma indicates the end of the employee name.  
size_t pos = line.find(',');
//The substr function is then used to extract the portion of the line from the beginning (index 0) up to the position of the comma.
string name = line.substr(0, pos);
//The extracted name is compared with the empName parameter to check if it matches. If a match is found, the code displays a message indicating that the employee is found
if (name == empName) {
cout << "Employee found!" << endl;
cout << line << endl;
return true;
}
}
cout << "Employee not found." << endl;
return false;
}


void deleteEmp(fstream& file) {
    string empName;
    cout<<"pleas enter employee name";
    cin>> empName;
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

void saveEmp(const Employee& record, fstream& outFile) {
    outFile.open("employee.txt", ios::app);
    outFile << record.name << ' '<< record.id << ' '<< record.age <<' '<< record.salary <<' '<< record.department <<' '<< record.position << endl;
    outFile.close();
}

void editEmp(fstream& file){

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


void readRecords(fstream& file) {
    string line;
    cout << "Employee Records:" << endl;
    while (getline(file, line)) {
        cout << line << endl;
    
}

}




void display(fstream &file) {
    file.open("employee.txt", ios::in);
    string line;
    cout << "Employee Records:" << endl;

    // Move the file pointer to the beginning of the file
    file.seekg(0, ios::beg);

    // Read and display each line from the file
    while (getline(file, line)) {
        cout << line << endl;
    }
    file.close();
}


long getFileSize(fstream& file) {
    //unused function for some reason...
}
int main() {
    int num;
    fstream file;
    if (!file) {
        cout << "File could not be opened" << endl;
        return 1;
        }
    Employee record;
    
    cout<<"what do u wana do? "<<endl;
    cout<<"1, add Employee "<<endl;
    cout<<"2, edit employee info "<<endl;
    cout<<"3, delete employee "<<endl;
    cout<<"4, search employee "<<endl;
    cout<<"5, desplay employeies "<<endl;
    cout<<"6, exit "<<endl;
    int choice;
    cin>>choice;
    switch(choice){
        case 1:
        addEmp(record);
        saveEmp(record, file);
        break;
        case 2:
        editEmp(file);
        break;
        case 3:
        deleteEmp(file);
        break;
        case 4:
        searchEmp(file);
        break;
        case 5:
        display(file);
        break;
        case 6:
        exit(0);
        break;
        default:
        cout<<"invalid choice";
        break;
    }
    return 0;
}