#include <iostream>
using namespace std;


class DivideByZero{
public : 
    friend ostream &operator<<(ostream &os, const DivideByZero &obj);
};

class NegativeOperand {
public : 
    friend ostream &operator<<(ostream &os, const NegativeOperand &obj);
};

double calc_avg(int mile, int gallon){
    if(gallon == 0)
        throw DivideByZero();
    if(gallon < 0 || mile < 0)
        throw NegativeOperand();
    return (double)mile/gallon;
}

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
        miles_per_gallons = calc_avg(miles, gallons);
        cout << "Miles per gallons : " << miles_per_gallons << endl;
    }
    catch(const DivideByZero &ex){
        cout << ex << endl;
    }
    catch(const NegativeOperand &ex){
        cout << ex << endl;
    }
    return 0;
}

ostream &operator<<(ostream &os, const DivideByZero &obj){
    os << "Can't divide by zero";
    return os;
}

ostream &operator<<(ostream &os, const NegativeOperand &obj){
    os << "Negative operand error !";
    return os;
}


