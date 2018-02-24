#include<iostream>
using namespace std;

// A generic smart pointer class
template <class T>
class SmartPtr
{
    T *ptr;  // Actual pointer
    public:
    // Constructor
    explicit SmartPtr(T *p = NULL) 
    { 
        ptr = p; 
        cout << "Constructor: SmartPtr()" << endl;
    }

    // Destructor
    ~SmartPtr() 
    { 
        delete(ptr); 
        cout << "Destructor: ~SmartPtr()" << endl;
    }

    // Overloading dereferncing operator
    T & operator * () 
    {  
        cout << "Operator *()" << endl;
        return *ptr; 
    }

    // Overloding arrow operator so that members of T can be accessed
    // like a pointer (useful if T represents a class or struct or 
    // union type)
    T * operator -> () 
    { 
        cout << "Operator ->()" << endl;
        return ptr; 
    }
};

int main()
{
    SmartPtr<int> ptr(new int());
    *ptr = 20;
    cout << *ptr << endl;
    return 0;
}
