class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        if(stack2.size())
        {
            auto result=stack2.top();
            stack2.pop();
            return result;
        }else
        {
            while(!stack1.empty())
            {
                stack2.push(stack1.top());
                stack1.pop();
            }
            if(stack2.size())
            {
                auto result=stack2.top();
                stack2.pop();
                return result;
            }
            return -99999;
        }
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};