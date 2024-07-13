// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

vector<int> parseInts(string str) {
	// Complete this function
    int i = 0;
    int last = 0;
    vector<int> num;
    size_t found = str.find(',');
    while(found != string::npos){
        num.push_back(stoi(str.substr(i, found))); // 
        i = found+1; // 3
        found = str.find(',', found+1);
        if(found != string::npos)
            last = found;
    }
    num.push_back(stoi(str.substr(last+1, str.size()-last-1))); // 
    return num;
}

int main() {
    string str;
    cin >> str;
    vector<int> integers {};
    integers = parseInts(str);
    
    for(int i = 0; i < integers.size(); i++) {
         cout << integers[i] << "\n";
    }
    
    return 0;
}