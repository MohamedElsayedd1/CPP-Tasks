// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
#include <string>

using namespace std;

string longestCommonPrefix(vector<string> &strs);

int romanToInt(string s);

int main()
{
    vector<string> strs{"aca", "cba"};
    cout << longestCommonPrefix(strs);

    // vector<string> result = findAndReplacePattern(words, pattern);

    return 0;
}

string longestCommonPrefix(vector<string> &strs)
{
    int counter = strs.at(0).size();
    int max = strs.at(0).size();
    int max_index = 0;
    int maxx = counter - 1;
    string s{};
    for (int i = 0; i < strs.size(); i++)
    {
        if (max < strs.at(i).size())
        {
            max = strs.at(i).size();
            max_index = i;
        }
    }

    while (counter)
    {
        int flag = 1;
        s = strs.at(max_index).substr(0, counter);
        for (int i = 0; i < strs.size(); i++)
        {
            if(i == max_index){
                continue;
            }
            else if ((strs.at(i).find(s) != string::npos) && (strs.at(i).find(s) == strs.at(max_index).find(s)))
            {
                flag = 1;
            }
            else
            {
                flag = 0;
                break;
            }
        }
        if (flag == 1)
        {
            return s;
        }
        counter--;
    }
    return "";
}