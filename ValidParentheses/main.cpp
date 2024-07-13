// Online C++ compiler to run C++ program online
#include <iostream>

using namespace std;
bool isValid(string s);

int main() {
    // Write C++ code here
    std::cout << isValid("{[()]") ;

    return 0;
}

bool isValid(string s) {
    bool flag = false;
    for(int i = 0; i < s.size()-1; i ++){
        for(int j = i+1; j < s.size(); j++){
            if((s[i] == '(' && s[j] == ')') || (s[i] == '0')){
                flag = true;
                s[i] = '0';
                s[j] = '0';
                break;
            }
            else if((s[i] == '[' && s[j] == ']') || (s[i] == '0')){
                flag = true;
                s[i] = '0';
                s[j] = '0';
                break;
            }
            else if((s[i] == '{' && s[j] == '}') || (s[i] == '0')){
                flag = true;
                s[i] = '0';
                s[j] = '0';
                break;
            }
            else{
                flag = false;
            }
        }
        if(flag == false){
            break;
        }
    }
    return flag;
}