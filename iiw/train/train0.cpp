#include <iostream>

class Single{
private:
    explicit Single(){}
    explicit Single(const Single& single){}
    Single& operator=(const Single &);
public:
    static Single& GetInstance()
    {
        static Single instance;
        return instance;
    }

    void DoSomething();

};

void Single::DoSomething()
{
    std::cout<<"2222222222222222222"<<std::endl;
}

int main()
{
    Single::GetInstance().DoSomething();
}

