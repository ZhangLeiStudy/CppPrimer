#include <iostream>

using namespace std;

void exchangePtr(int *& ptr1, int *& ptr2) // exchange the two pointer
{
    int *temp;
    temp = ptr1;
    ptr1 = ptr2;
    ptr2 = temp;
}

int main(int argc, const char * argv[]) {
    int num1 = 100, num2 = 110;
    int *ptr1 = &num1, *ptr2 = &num2;
    
    cout << "ptr1: " << ptr1 << " " << "ptr2: " << ptr2 << endl;
    
    exchangePtr(ptr1, ptr2);
    
    cout << "ptr1: " << ptr1 << " " << "ptr2: " << ptr2 << endl;
    
    return 0;
}
