#include <iostream>
#include <stack>

#define SIZE (10)

using namespace std;

int main()
{
    stack <int> iStack;
    int i = 0;

    for (i = 0; i < SIZE; i++)
        iStack.push(i+10);

    cout << "Size of Stack: "<< iStack.size() << endl;
    cout << "Stack Top: " << iStack.top() << endl;
    cout << "Poped Stack Elements: " << endl;
    while (!iStack.empty())
    {
        cout << iStack.top() << endl;
        iStack.pop();
    }
    
}
