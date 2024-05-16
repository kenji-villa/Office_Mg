//Author: Dawit Moges
//Date: 05/15/2024
#include<iostream>
#include<fstream>
using namespace std;

//Takes two parameter which is a constant reference to a string representing the name of the employee and a file
bool searchEmployee(const string& empName, fstream& file) {
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