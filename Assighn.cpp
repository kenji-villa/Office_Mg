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


void accept(Employee& record) {
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

void search(Employee& record){
    
}

void deleteEmp(Employee& record) {


}

void saveEmp(const Employee& record, fstream& outFile) {
    
}


void readRecords(fstream& inFile) {

}


void display(const Employee& record) {
    
}


long getFileSize(fstream& file) {
    
}
int main() {
    cout<<"what do u wana do?";
    cout<<"";
}