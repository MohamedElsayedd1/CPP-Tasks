#include <iostream>
#include <vector>

using namespace std;

void DisplayMenu(char &c);
void PrintVector(const vector<int> &x);
void AddElement(vector<int> &x);
void DisplayMeanOfList(const vector<int> &x);
void DisplayLargestNumber(const vector<int> &x);
void SearchForNumber(const vector<int> &x);
void ClearList(vector<int> &x);

int main()
{
    char choice{};
    int search_number {};
    vector<int> elements{};

    while (1)
    {
        DisplayMenu(choice);
        if ((choice == 'q') || (choice == 'Q'))
        {
            cout << "Goodbye .." << endl;
            break;
        }
        else if ((choice == 'p') || (choice == 'P'))
        {
            PrintVector(elements);
        }
        else if ((choice == 'a') || (choice == 'A'))
        {
            AddElement(elements);
        }
        else if ((choice == 'm') || (choice == 'M'))
        {
            DisplayMeanOfList(elements);
        }
        else if ((choice == 'l') || (choice == 'L'))
        {
            DisplayLargestNumber(elements);
        }
        else if ((choice == 'S') || (choice == 's'))
        {
            SearchForNumber(elements);
        }
        else if ((choice == 'C') || (choice == 'c'))
        {
            ClearList(elements);
        }
        else
        {
            cout << "Unknown selection, please try again.";
        }
    }

    return 0;
}

void DisplayMenu(char &c)
{
    cout << "P - Print numbers \n";
    cout << "A - Add a number \n";
    cout << "M - Display mean of the numbers \n";
    cout << "S - Display the smallest number \n";
    cout << "L - Display the largest number \n";
    cout << "S - Search for number in the list\n";
    cout << "C - Clear the entire list\n";
    cout << "Q - Quit \n";
    cout << "\nEnter choice : ";
    cin >> c;
}

void PrintVector(const vector<int> &x)
{
    cout << "[ ";
    for (auto i : x)
    {
        cout << i << " ";
    }
    cout << " ]";
    if(x.size() == 0){
        cout << " - list is empty";
    }
    else{}
    cout << endl << endl;
}

void AddElement(vector<int> &x){
    int temp {0};
    cout << "Enter integer to add to the list : ";
    cin >> temp;
    x.push_back(temp);
    cout << temp <<" is added to the list.\n" << endl;
}

void DisplayMeanOfList(const vector<int> &x){
    int mean {0}, sum{0};
    if(x.size() == 0){
        cout << "Unable to calculate mean - the list is empty.\n\n";
    }
    else{
        for(size_t i = 0; i < x.size(); i++){
        sum += x.at(i);
        }
        cout << "The mean value = " << ((double)sum/x.size()) << endl << endl;
    }
    
}

void DisplayLargestNumber(const vector<int> &x){
    int max = x.at(0);
    for(size_t i = 0; i < x.size(); i++){
        if(x.at(i) > max){
            max = x.at(i);
        }
        else{

        }
    }
    cout << "The largest numbber in the list = " << max << endl << endl;
}

void SearchForNumber(const vector<int> &x){
    int counter = 0, num {};
    cout << "Enter number to search in the list : ";
    cin >> num;
    for(auto i:x){
        if(i == num){
            counter++;
        }
    }
    cout << "Number " << num << " ocurred " << counter << " times in the list."<< endl << endl;
}

void ClearList(vector<int> &x){
    x.clear();
    cout << "the entire list has been deleted.\n";
    PrintVector(x);
}