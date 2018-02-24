#include <iostream>
#include <queue>

#define SIZE (10)

using namespace std;

int main()
{
    queue <int> iQueue;
    int i = 0;

    for (i = 0; i < SIZE; i++)
        iQueue.push(i+10);

    cout << "Size of Queue: "<< iQueue.size() << endl;
    cout << "Queue Front: " << iQueue.front() << endl;
    cout << "Queue Back: " << iQueue.back() << endl;
    cout << "Poped Queue Elements: " << endl;
    while (!iQueue.empty())
    {
        cout << iQueue.front() << endl;
        iQueue.pop();
    }
    
}
