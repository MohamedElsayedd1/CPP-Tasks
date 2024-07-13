#include <iostream>
#include <array>
#include <algorithm>
#include <numeric>

using namespace std;

/**
 * @brief Displays the elements of a std::array
 *
 * This template function takes a constant reference to a std::array and prints its elements.
 *
 * @tparam T The type of the elements in the array
 * @tparam N The number of elements in the array
 * @param obj The array to display
 */
template<typename T, size_t N>
void display(const array<T, N> &obj) {
    cout << "[ ";
    for (const auto &elem : obj) {
        cout << elem << " ";
    }
    cout << "]" << endl;
}

void test1(void){
    array<int, 5> arr1 {1, 2, 3, 4, 5};
    array<int, 5> arr2;

    display(arr1);
    display(arr2); // garbage value

    arr2 = {10, 20, 30, 40, 50}; 

    display(arr1);
    display(arr2); 

    cout << "size of arr1  : " << arr1.size() << endl;
    cout << "size of arr2 : " << arr2.size() << endl;

    arr1.at(0) = 2000; // .at() -> boundry checking, throw an exception 
    arr1[1] = 1000; // [] subscript -> no type checking
    display(arr1);

    cout << "Front of arr2 : " << arr2.front() << endl;
    cout << "Back of arr2 : " << arr2.back() << endl;

    cout << "============================\n";
}

void test2(void){
    array<int, 5> arr1 {1, 2, 3, 4, 5};
    array<int, 5> arr2 {10, 20, 30, 40, 50};

    display(arr1);
    display(arr2);

    arr2.fill(0);

    cout << "After filling 0 in arr2 : \n";
    display(arr1);
    display(arr2);

    cout << "Before swaping : \n";
    display(arr1);
    display(arr2);

    arr1.swap(arr2);
    
    cout << "After swaping : \n";
    display(arr1);
    display(arr2);
    cout << "============================\n";
}

void test3(void){
    array<char, 3> arr1 {'A', 'B', 'C'};
    array<char, 3> arr2 {'D', 'E', 'F'};

    cout << "Before swaping : \n";
    display(arr1);
    display(arr2);

    arr1.swap(arr2);
    
    cout << "After swaping : \n";
    display(arr1);
    display(arr2);
    cout << "============================\n";
}

void test4(void){
    array<string, 3> my_str {"Moe", "Larry", "Curly"};
    display(my_str);
    string *s_ptr = my_str.data();
    cout << "Address of 1st element : " << s_ptr << endl;
    cout << "Value of 1st element : " << *s_ptr << endl;
    cout << "============================\n";
}

void test5(void){
    array<int, 5> arr{11, 2, 4, 19, 1};
    cout << "Unsorted Array : ";
    display(arr);
    sort(arr.begin(), arr.end());
    cout << "Sorted Array : ";
    display(arr);
    cout << "============================\n";
}

void test6(){
    array<int, 5> arr{11, 2, 4, 19, 1};
    cout << "Array : ";
    display(arr);
    array<int, 5>::iterator min = min_element(arr.begin(), arr.end());
    auto max = max_element(arr.begin(), arr.end());
    cout << "Min : " << *min << " at " << min << endl;
    cout << "Min : " << *max << " at " << max << endl;
    cout << "============================\n";
}

void test7(){
    array<int, 5> arr{11, 2, 4, 4, 1};
    cout << "Array : ";
    display(arr);
    auto adjacent = adjacent_find(arr.begin(), arr.end());
    if(adjacent != arr.end())
        cout << "Adjacent elements found with value : " << *adjacent << endl;
    else
        cout << "No adjacent elements are found!" << endl;
    cout << "============================\n";
}

void test8(void){
    array<double, 5> arr{12.44, 35.44, 99.8, 11.2, 1.83};
    cout << "Array : ";
    display(arr);
    double sum = accumulate(arr.begin(), arr.end(), 0.0);
    cout << "Sum of array : " << sum << endl; 
    cout << "============================\n";
}

void test9(void){
    array<int, 8> arr {1, 2, 3, 4, 5, 3, 3, 3};
    cout << "Array : ";
    display(arr);
    int mycount = count(arr.begin(), arr.end(), 3); // 4
    cout << "Found 3 : " << mycount << " times" << endl;
    cout << "============================\n";
}

void test10(void){
    array<int, 10> arr {10, 2, 30, 50, 199, 90, 4004, 9, 44, 912};
    cout << "Array : ";
    display(arr);
    int mycount = count_if(arr.begin(), arr.end(), [](int x) { return ((x > 10) && (x < 200)) ;}); // 4
    cout << "Found " << mycount << " matches" << endl;
    cout << "============================\n";
}


int main() {
    // Create an array of integers with 3 elements
    array<int, 3> arr{1, 2, 3};
    
    // Display the contents of the array
    display(arr);

    // Create an array of integers with 3 elements
    array<string, 3> arr2; 
    arr2 = {"Khaled", "Mohamed", "Sally"};
    
    // Display the contents of the array
    display(arr2);

    cout << "============================\n";

    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    test8();
    test9();
    test10();
    return 0;
}

