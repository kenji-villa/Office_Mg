//Author: Dawit Moges
//Date: 05/15/2024
#include<iostream>
#include<fstream>
using namespace std;
void readFromFile(fstream& file) {
    string line;
    cout << "Employee Records:" << endl;
    while (getline(file, line)) {
        cout << line << endl;
    }
}