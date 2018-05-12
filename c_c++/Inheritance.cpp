#include<iostream>
using namespace std;

class Base
{
    int iVarBase;

public:
    Base()
    {
        iVarBase = 1;
    }
    int getiVarBase()
    {
        return iVarBase;
    }
};

class Derived1: public Base
{
public:
    void displayiVarBase()
    {
        //cout << iVarBase; error: iVarBase is private in Base class 
        cout << getiVarBase();
    }
};

int main()
{
    Derived1 objDer1;
    objDer1.displayiVarBase();

    return 0;
}