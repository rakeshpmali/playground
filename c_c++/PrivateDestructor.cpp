#include<iostream>

using namespace std;

class Test
{
    public:
        
        Test()
        {
            cout << "Test()" << endl;
        }
        
        void deleteObject()
        {
            delete this;
        }
    
    private:
        
        ~Test()
        {
            cout << "~Test()" << endl;
        }
};


int main()
{
    //Test obj;     /* compile-time error: ~Test() is private */
    /*  making destructor private restricts direct object creation (statically),
        object creation allowed only via new operator (dynamically)
    */
    Test *pObj = new Test();    //Test()
    pObj->deleteObject();       //~Test()

}