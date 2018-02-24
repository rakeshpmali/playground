#include <iostream>
#include <deque>

#define SIZE (10)

using namespace std;

int main()
{
    deque <int> iDeque;
    int i = 0;

    for (i = 0; i < SIZE; i++)
        iDeque.push_back(i+10);
    
    cout << "Size of Deque: "<< iDeque.size() << endl;
    cout << "Queue Front: " << iDeque.front() << endl;
    cout << "Queue Back: " << iDeque.back() << endl;
    cout << "Poped Queue Elements: " << endl;
    while (!iDeque.empty())
    {
        cout << iDeque.front() << endl;
        iDeque.pop_front();
    }
    
    for (i = 0; i < SIZE; i++)
        iDeque.push_front(i+10);
    
    cout << "Size of Deque: "<< iDeque.size() << endl;
    cout << "Queue Front: " << iDeque.front() << endl;
    cout << "Queue Back: " << iDeque.back() << endl;
    cout << "Poped Queue Elements: " << endl;
    while (!iDeque.empty())
    {
        cout << iDeque.front() << endl;
        iDeque.pop_front();
    }

    
}
