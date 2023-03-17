#include <iostream>
#include <stack>

using namespace std;

class   Queue
{
private:

    stack<int> stack1, stack2;

public:

    void enqueue(int x)
    {
        stack1.push(x);

    }

    int dequeue()
    {
        if (stack1.empty() && stack2.empty())
        {
            cout << "Error, queue is empty" << endl;
            return -1;
        }

        if (stack2.empty())
        {
            while (!stack1.empty())
            {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }

        int n = stack2.top();
        stack2.pop();

        return n;
    }
};

int main()
{
    Queue q;

    int val[] = { 1,2,3,4,5 };

    for (int i = 0; i < size(val); i++)
    {
        q.enqueue(val[i]);
    }

    for (int i = 0; i < size(val); i++)
    {
        cout << q.dequeue() << endl;
    }

}
