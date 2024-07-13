#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

double circle_area(double r);
void cylinder_volume(void);
double cylinder_volume_calc(double rad, double height);

int main()
{
    double cradius;
    cout << "Enter radius of a circle : ";
    cin >> cradius;
    cout << "Area of circle : " << circle_area(cradius) << endl;
    cylinder_volume();
}

double circle_area(double r)
{
    return 3.14159265 * r * r;
}

void cylinder_volume(void)
{
    double r, h;
    cout << "Enter radius of a cylinder : ";
    cin >> r;
    cout << "Enter height of a circle : ";
    cin >> h;
    cout << "volume of cylnder : " << cylinder_volume_calc(r, h) << endl;
}

double cylinder_volume_calc(double rad, double height)
{
    return 3.14159265 * rad * rad * height;
}