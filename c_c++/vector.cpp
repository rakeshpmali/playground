#include <iostream>
#include <vector>

#define SIZE (10)

using namespace std;

int main()
{
    vector <int> iVec;
    int i = 0;

    cout << "Size Before: " << iVec.size() << endl;
    cout << "Capacity Before: " << iVec.capacity() << endl;

    cout << "Creating Vector ..." << endl;

    for (i = 0; i < SIZE; i++)
        iVec.push_back(i+10);

    cout << "Size After: " << iVec.size() << endl;
    cout << "Capacity After: " << iVec.capacity() << endl;
    cout << endl;

    cout << "Display Elements of Vector using Counter: " << endl;
    for (i = 0; i < SIZE; i++)
        cout << "iVec["<<i<<"] = " << iVec[i] << endl;

    iVec.pop_back();
    cout << endl;
    cout << "Display Elements of Vector using Iterator: " << endl;
    vector<int>::iterator it = iVec.begin();

    while(it != iVec.end())
    {
        cout << *it << endl;
        it++;
    }
    
    //iVec.clear();
    cout << "Display Elements of Vector after erase() " << endl;
    it-=5;;
    iVec.erase(--it);
    it = iVec.begin();
    while(it != iVec.end())
    {
        cout << *it << endl;
        it++;
    }
    
    return 0;
}
