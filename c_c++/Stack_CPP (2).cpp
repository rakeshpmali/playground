#include <iostream>
 
using namespace std;
 
class Stack
{
private:
    int *piData;
    int iTop, iSize;
 
public:
    Stack(int = 0);
    ~Stack();
 
    void push(int);
    int pop();
    void display();
};
 
Stack::Stack(int aiSize)
{
    iTop = -1;
    iSize = aiSize;

    if(aiSize == 0)
        piData = 0;
    else
        piData = new int[iSize];
}
 
Stack::~Stack()
{
    if(piData != 0)
        delete [] piData;
}
 
void Stack::push(int iElement)
{
    if(piData == 0)                //If the stack size is zero, allow user to mention it at runtime
    {
        cout << "Stack not created ! Creating new Stack ..." << endl;
        cout<<"Enter a Size for Stack : ";
        cin >> iSize;
        piData = new int[iSize];
    }

    if( iTop == (iSize - 1) )     //If the top reaches to the maximum stack size
    {
        cout<<"\nCannot push "<< iElement <<", Stack Full !"<<endl;
        return;
    }
    else
    {
        piData[++iTop] = iElement;
    }
}

int Stack::pop()
{
    if(piData == 0 || iTop == -1)
    {
        cout << "Stack Empty!" << endl;
        return -1;
    }

    int iRet = piData[iTop--];
    --iSize;
 
    return iRet;
}
 
void Stack::display()
{
    for(int i = 0; i <= iTop; i++)
        cout << piData[i] << endl;
    cout << endl;
}
 
int main()
{

start:
    printf("\n********** STACK **********\n\n");
    printf("Operations:\n");
    printf("1. Create Stack\n");
    printf("2. Push\n");
    printf("3. Pop\n");
    printf("4. Display Stack\n");
    printf("0. Exit\n");
    printf("#Your Selection: ");
    scanf("%d", &iSelect);

    switch(iSelect)
    {   
        case 0:
        {
            printf("\nBye Bye ! See you again ...\n\n");
            exit(EXIT_SUCCESS);
        }
        break;
        case 1:
        {
            int iLen = 0;
            cout << 
            Stack s1;             
        }
    }

}
