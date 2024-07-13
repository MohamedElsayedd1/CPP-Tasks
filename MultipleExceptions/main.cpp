#include <iostream>
using namespace std;

double calc_avg(int sum, int total);

int main()
{
    int miles; 
    int gallons;
    double miles_per_gallons;
    cout << "--------- miles per gallons ------\n";
    cout << "Enter number of miles : ";
    cin >> miles;
    cout << "Enter number of gallons : ";
    cin >> gallons;
    // miles_per_gallons = miles/gallons; // program craches if gallons = 0
    try{
        miles_per_gallons = calc_avg(miles, gallons); // results +-inf if gallons = 0
        cout << "Miles per gallons : " << miles_per_gallons << endl;
    }
    catch(int &ex){
        cout << "can't divide by zero.\n";
    }
    catch(string &ex){
        cout << ex << endl;
    }
    return 0;
}

double calc_avg(int sum, int total){
    if(total == 0)
        throw 0;
    if(sum <= 0 || total < 0)
        throw string{"Negative operand error.\n"};
    return (double)sum/total;
}