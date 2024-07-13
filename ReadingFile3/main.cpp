#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream in_file;
    string path;
    cout << "Enter path of the file : ";
    cin >> path;
    in_file.open(path);

    if(!in_file){
        cout << "Error !!" << endl;
        return 0;
    }
    cout << "File opened successfully.\n\n";

    string line{};
    while(getline(in_file, line)){
        cout << line << endl;
    }

    // char ch;
    // while(in_file.get(ch)){
    //     cout << ch;
    // }
    
    return 0;
}