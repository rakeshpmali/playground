#include<iostream>

using namespace std;

int main()
{
    int a = 5;
    int c = a++ + ++a + a++;
    
    cout << "c = " << c << endl;
}