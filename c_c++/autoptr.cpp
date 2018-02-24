#include <iostream>
#include <memory>

using namespace std;

class Double
{
    public:
        Double(double d = 0) : dValue(d) 
        { 
            cout << "constructor: " << dValue << endl; 
        } 
        
        ~Double() { 
            cout << "destructor: " << dValue << endl; 
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
    auto_ptr<Double> ptr(new Double(3.14));
    (*ptr).setDouble(6.28); 
    (*ptr).dispDouble(); 
    cout << *(ptr.get()) << endl;

    ptr->setDouble(10.10); 
    ptr->dispDouble(); 
    return 0;
}
