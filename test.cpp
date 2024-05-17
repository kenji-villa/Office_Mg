#include <iostream>
#include <fstream>
using namespace std;

struct items {
    int ID;
    string name;
    string desc;
    string price;
    string pcs;
};

int main() {

    string namefile, line;
    int counter = 0;

    cout << "Name of the file:" << endl;
    namefile="TXT.txt";

    ifstream file;

    file.open(namefile);

    if( !file.is_open()) {

        cout << "File "<< namefile <<" not found." << endl;
        exit(-1);

    }

    while ( getline( file, line) ) { // To get the number of lines in the file
        counter++;
    }

    items* item = new items[counter]; // Add number to structured array

    for (int i = 0; i < counter; i++) {

        file >> item[i].ID >> item[i].name >> item[i].desc >> item[i].price >> item[i].pcs;

    }

    cout << item[1].name << endl;

    file.close();
    return 0;
}
