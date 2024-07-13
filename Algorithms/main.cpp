#include <iostream>
#include <vector>
#include <set>
#include <list>
#include <algorithm>

using namespace std;

// Person class with overloaded operators for equality and comparison
class Person
{
private:
    string name;
    int age;

public:
    Person(string n = "None", int a = 0) : name{n}, age{a} {}

    bool operator==(const Person &rhs) const
    {
        return (this->name == rhs.name && this->age == rhs.age);
    }

    bool operator>(const Person &rhs) const
    {
        return (this->age > rhs.age);
    }

    friend ostream &operator<<(ostream &os, const Person &obj);

    ~Person() = default;
};

// Function to test the find algorithm
void find_test(void)
{
    // Finding an integer in a list
    list<int> my_list{1, 2, 3, 4, 5};
    list<int>::const_iterator it = find(my_list.begin(), my_list.end(), 2);
    if (it != my_list.end())
        cout << "Found number: " << *it << endl;
    else
        cout << "Couldn't find number.\n";
    cout << "===============================\n";

    // Finding a Person in a list
    list<Person> ppl{{"Larry", 20}, {"Moe", 15}, {"Curly", 15}};
    list<Person>::const_iterator it2 = find(ppl.begin(), ppl.end(), Person{"Larry", 20});
    if (it2 != ppl.end())
        cout << "Found object: " << *it2 << endl;
    else
        cout << "Couldn't find object.\n";
    cout << "===============================\n";

    Person p{"Curly", 90};
    it2 = find(ppl.begin(), ppl.end(), p);
    if (it2 != ppl.end())
        cout << "Found object: " << *it2 << endl;
    else
        cout << "Couldn't find object.\n";
    cout << "===============================\n";
}

// Function to test the count algorithm
void count_test(void)
{
    vector<int> vec{1, 2, 3, 1, 2, 1, 5, 10};
    int number_of_occur = count(vec.begin(), vec.end(), 1);
    cout << "Number of occurrences: " << number_of_occur << endl;
    number_of_occur = count(vec.begin(), vec.end(), -1);
    cout << "Number of occurrences: " << number_of_occur << endl;
    cout << "===============================\n";
}

// Function to test the count_if algorithm
void count_if_test(void)
{
    set<int> my_set{1, 2, 3, 4, 5, 6, 7, 8, 9};
    int num = count_if(my_set.begin(), my_set.end(), [](int x)
                       { return x % 2 == 0; });
    cout << "Count of even numbers: " << num << endl;
    num = count_if(my_set.begin(), my_set.end(), [](int x)
                   { return x % 2 != 0; });
    cout << "Count of odd numbers: " << num << endl;
    num = count_if(my_set.begin(), my_set.end(), [](int x)
                   { return x >= 5; });
    cout << "Count of numbers >= 5: " << num << endl;
    cout << "===============================\n";
}

// Function to test the for_each algorithm
void for_each_test(void)
{
    vector<char> chars{'A', 'B', 'C', 'D'};
    for_each(chars.begin(), chars.end(), [](char x)
             { cout << x << " "; });
    cout << endl;
    cout << "===============================\n";

    vector<Person> persons{{"Sally", 15}, {"Ibra", 13}, {"Messi", 37}};
    for_each(persons.begin(), persons.end(), [](const Person &p)
             { cout << p << endl; });
    cout << "===============================\n";

    vector<int> vec{1, 2, 3, 1, 5, 4};
    for_each(vec.begin(), vec.end(), [](int x)
             { cout << x * x << " "; });
    cout << "\n===============================\n";
}

// Function to test the replace algorithm
void replace_test()
{
    vector<int> vec{1, 2, 3, 1, 1, 4};
    cout << "Before replacing: ";
    for (const auto &x : vec)
    {
        cout << x << " ";
    }
    cout << endl;

    replace(vec.begin(), vec.end(), 1, 100);
    cout << "After replacing: ";
    for_each(vec.begin(), vec.end(), [](int x)
             { cout << x << " "; });
    cout << "\n===============================\n";
}

// Function to test the all_of algorithm
void all_of_test()
{
    vector<int> vec{1, 2, 4, 6, 5, 9, 7, 8, 11, 15};
    if (all_of(vec.begin(), vec.end(), [](int x)
               { return x > 10; }))
        cout << "All numbers are > 10.\n";
    else
        cout << "Not all numbers > 10.\n";

    if (all_of(vec.begin(), vec.end(), [](int x)
               { return x < 20; }))
        cout << "All numbers are < 20.\n";
    else
        cout << "Not all numbers < 20.\n";
}

// Function to test the any_of algorithm
void any_of_test()
{
    vector<int> vec{1, 2, 4, 6, 5, 9, 7, 8, 11, 15};
    if (any_of(vec.begin(), vec.end(), [](int x)
               { return x > 10; }))
        cout << "There is at least one number > 10.\n";
    else
        cout << "No number is > 10.\n";

    if (any_of(vec.begin(), vec.end(), [](int x)
               { return x < 0; }))
        cout << "There is at least one number < 0.\n";
    else
        cout << "No number is < 0.\n";
}

// Function to test the none_of algorithm
void none_of_test()
{
    vector<int> vec{1, 2, 4, 6, 5, 9, 7, 8, 11, 15};
    if (none_of(vec.begin(), vec.end(), [](int x)
                { return x > 20; }))
        cout << "No number is > 20.\n";
    else
        cout << "There is at least one number > 20.\n";

    if (none_of(vec.begin(), vec.end(), [](int x)
                { return x < 0; }))
        cout << "No number is < 0.\n";
    else
        cout << "There is at least one number < 0.\n";
}

int main()
{
    find_test();
    count_test();
    count_if_test();
    for_each_test();
    replace_test();
    all_of_test();
    any_of_test();
    none_of_test();
    return 0;
}

// Overloading the << operator for Person class to enable easy printing
ostream &operator<<(ostream &os, const Person &obj)
{
    os << obj.name << ", " << obj.age;
    return os;
}
