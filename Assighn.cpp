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
    cout<<"pleas enter employee name";
    cin>>record.name;
    cout<<"pleas enter employee id";
    cin>>record.id;
    cout<<"pleas enter employee age";
    cin>>record.age;
    cout<<"pleas enter employee salary";
    cin>>record.salary;
    cout<<"pleas enter employee department";
    cin>>record.department;
    cout<<"pleas enter employee position";
    cin>>record.position;
}

void searchEmp(Employee& record, fstream& file){
    
}

void deleteEmp(Employee& record, fstream& file) {


}

void saveEmp(const Employee& record, fstream& outFile) {
    outFile.open("employee.txt", ios::app);
    outFile << record.name << ' '<< record.id << ' '<< record.age <<' '<< record.salary <<' '<< record.department <<' '<< record.position << endl;
    outFile.close();
}

void editEmp(Employee& record, fstream& file){


}


void readRecords(fstream& inFile) {

}


void display(fstream &record) {
    
}


long getFileSize(fstream& file) {
    
}
int main() {
    int num;
    fstream file;
    if (!file) {
        cout << "File could not be opened" << endl;
        return 1;
        }
    Employee* record= new Employee[num];
    
    cout<<"what do u wana do?";
    cout<<"1, add Employee";
    cout<<"2, edit employee info";
    cout<<"3, delete employee";
    cout<<"4, search employee";
    cout<<"5, desplay employeies";
    cout<<"6, exit";
    int choice;
    cin>>choice;
    switch(choice){
        case 1:
        addEmp(*record);
        saveEmp(*record, file);
        break;
        case 2:
        editEmp(*record, file);
        break;
        case 3:
        deleteEmp(*record, file);
        break;
        case 4:
        searchEmp(*record, file);
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
}