#include <iostream>
#include <string>
#include <cctype>
#include <cstring>
#include <vector>

using namespace std;

void print_array(const int arr[], size_t size);
void zero_array(int arr[], size_t size);
void set_array(int arr[], size_t size, int value);
void print_vector(const vector<int> &nums);
void print_vector(const vector<string> &names);
void pass_string_by_ref(string &name);
void pass_vector_by_ref(vector<int> &numbers);
void pass_vector_by_ref(vector<string> &names);

int main()
{
    int arr[] {1, 2, 3, 4, 5};
    string name {"Khaled"};

    vector<int> numbers {11, 22, 33, 44};
    vector<string> names {"monuier", "john", "brad"};

    print_array(arr, 5);
    zero_array(arr, 5);
    print_array(arr, 5);

    set_array(arr, 5, 100);
    print_array(arr, 5);

    print_vector(numbers);
    pass_vector_by_ref(numbers);
    print_vector(numbers);

    cout << name << endl;
    pass_string_by_ref(name);
    cout << name << endl;


    print_vector(names);
    pass_vector_by_ref(names);
    print_vector(names);

}

void print_array(const int arr[], size_t size){
    for(size_t i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void zero_array(int arr[], size_t size){
    for(size_t i = 0; i < size; i++){
        arr[i] = 0;
    }
}

void set_array(int arr[], size_t size, int value){
    for(size_t i = 0; i < size; i++){
        arr[i] = value;
    }
}

void print_vector( const vector<int> &nums){
    for(auto x : nums){
        cout << x << " ";
    }
    cout << endl;
}

void print_vector( const vector<string> &names){
    for(auto x : names){
        cout << x << " ";
    }
    cout << endl;
}

void pass_string_by_ref(string &name){
    name = "Changed";
}

void pass_vector_by_ref(vector<int> &numbers){
    numbers.clear();
}
void pass_vector_by_ref(vector<string> &names){
    names.at(0) = "salma";
}