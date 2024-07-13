#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    fstream in_file;
    in_file.open("../myfile.txt");
    if(!in_file){
        cout << "Can't open file.\n";
        return 0;
    }
    cout << "File opened successfully.\n";

    string str;
    int num;
    double total;

    in_file >> str >> num >> total;
    cout << str << endl;
    cout << num << endl;
    cout << total << endl;

    in_file.close();

    return 0;
}