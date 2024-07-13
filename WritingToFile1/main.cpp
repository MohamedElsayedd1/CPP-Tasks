#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ofstream out_file{"../output.txt", ios::app};
    string line{};
    if (!out_file)
    {
        cout << "Can't create file.\n";
        return 0;
    }
    cout << "\nFile is created successfully.\n\n";
    cout << "Enter a string to put in file : ";
    getline(cin, line);
    out_file << line << endl;
    ;

    cout << "\nString added to file successfully.\n";

    out_file.close();
    
    return 0;
}