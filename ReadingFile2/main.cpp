#include <iostream>
#include <iomanip>
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

    // while(!in_file.eof()){
    //     in_file >> str >> num >> total;
    //     cout << setw(10) << left << str 
    //     << setw(10) << left << num
    //     << setw(10) << left << total <<endl;
    // }

    while(in_file >> str >> num >> total){
        cout << setw(10) << left << str 
        << setw(10) << left << num
        << setw(10) << left << total <<endl;
    }

    // string line{};

    // while(getline(in_file, line)){
    //     cout << line <<endl;
    // }

    in_file.close();

    return 0;
}