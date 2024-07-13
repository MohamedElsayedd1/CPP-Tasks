#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream in_file {"../poem.txt", ios::in};
    ofstream out_file {"../copied_poem.txt"};
    char ch{};

    if(!in_file){
        cout << "\nCan't open file.\n";
        return 0;
    }
    cout << "Input file is created successfully.\n";
    if(!out_file){
        cout << "\nFile can't be created.\n";
    }
    cout << "Output file is created successfully.\n";

    while(in_file.get(ch))
        out_file << ch; // out_file.put(ch);
    
    cout << "File is copied successfully.\n";


    return 0;
}