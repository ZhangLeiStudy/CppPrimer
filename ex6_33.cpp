#include <iostream>
#include <vector>

using namespace std;

typedef vector<int>::iterator Iter;

void printVector(Iter begin, Iter end)
{
    if(begin != end) {
        cout << *begin << " ";
        printVector(++begin, end); //Notice here if using begin++ will couse overflow!
    }
    
}

int main(int argc, char *argv[])
{
    vector<int> vec{1, 2, 3, 4, 5, 6};
    printVector(vec.begin(), vec.end());
    
    return 0;
}
