#include <iostream>
#include <string>

bool flag = false;

string changeToLower(string &s) {
    string::size_type size = s.size();
    for(auto i = 0; i < size; ++i)
    {
        if(s[i] >= 'A' && s[i] <= 'Z')
        {
            flag = true;
            s[i] = s[i] - ('A' - 'a');
        }
    }
    
    return s;
}

int main() 
{
    string str("Hello World");
    string ss = chantToLower(str);
    
    cout  << ss << endl;
    
    return 0;
}
