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

//sample user-defined class 
class Double
{
    public:
        Double(double d = 0) : dValue(d) 
        { 
            cout << "Constructor: Double(): " << dValue << endl; 
        } 
        
        ~Double() { 
            cout << "Destructor: ~Double(): " << dValue << endl; 
        }
        
        void setDouble(double d) 
        { 
            dValue = d; 
        }
        
        void dispDouble()
        {
            cout << "dispDouble:" << dValue << endl;
        }
    
    private:
        double dValue;
}; 

int main()
{
    //with integral data type
    SmartPtr<int> ptr1(new int());
    *ptr1 = 20;
    cout << *ptr1 << endl;

    //with user-defined data type
    SmartPtr<Double> ptr2(new Double(3.14));
    ptr2->setDouble(10.10); 
    ptr2->dispDouble(); 

    return 0;
}
