#include <iostream>

using namespace std;

int compare(const int num, const int *ptr)
{
    return num >= *ptr ? num : *ptr;
}

int main(int argc, const char * argv[]) {
    int num1 = 100, num2 = 110;
    
    int larger = compare(num1, &num2);
    
    cout << larger << endl;
    
    return 0;
}
