#include <iostream>
#include <map>

using namespace std;

#define ENUM_PUSH 0
#define ENUM_POP 1
#define ENUM_SIZE 2
#define ENUM_EMPTY 3
#define ENUM_TOP 4

static map< string, int > m;

void Init()
{
    m["push"] = ENUM_PUSH;
    m["pop"] = ENUM_POP;
    m["size"] = ENUM_SIZE;
    m["empty"] = ENUM_EMPTY;
    m["top"] = ENUM_TOP;
}

struct Stack
{
    int data;
    Stack* next = NULL;
};

int main()
{
    int n;
    cin >> n;

    Stack stack;

    for (int i = 0; i < n; i++)
    {
        string command;
        cin >> command;

        switch (m[command])
        {
            case ENUM_PUSH:
                // asd
                break;
            case ENUM_POP:
                // asd
                break;
            case ENUM_SIZE:
                // asd
                break;
            case ENUM_EMPTY:
                // asd
                break;
            case ENUM_TOP:
                // asd
                break;
            default:
                break;
        }
    }

    std::cout << "Hello World!\n";
}