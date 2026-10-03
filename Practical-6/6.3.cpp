#include <iostream>
#include <string>
using namespace std;

bool isOperator(char ch)
{
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

int priority(char ch)
{
    if (ch == '+' || ch == '-')
        return 1;

    if (ch == '*' || ch == '/')
        return 2;

    return 0;
}

string infixToPostfix(string infix)
{
    char stack[100];
    int top = -1;

    string postfix = "";

    for (int i = 0; i < infix.length(); i++)
    {
        char ch = infix[i];

        if (ch == ' ')
            continue;

        if ((ch >= '0' && ch <= '9') ||
            (ch >= 'A' && ch <= 'Z') ||
            (ch >= 'a' && ch <= 'z'))
        {
            postfix += ch;
            postfix += ' ';
        }

        else if (ch == '(')
        {
            top++;
            stack[top] = ch;
        }

        else if (ch == ')')
        {

            while (top != -1 && stack[top] != '(')
            {
                postfix += stack[top];
                postfix += ' ';
                top--;
            }

            if (top != -1)
                top--;
        }

        else if (isOperator(ch))
        {

            while (top != -1 &&
                   stack[top] != '(' &&
                   priority(stack[top]) >= priority(ch))
            {
                postfix += stack[top];
                postfix += ' ';
                top--;
            }

            top++;
            stack[top] = ch;
        }
    }

    while (top != -1)
    {
        postfix += stack[top];
        postfix += ' ';
        top--;
    }

    return postfix;
}

int main()
{
    string infix;

    cout << "Enter infix expression: ";
    getline(cin, infix);

    string postfix = infixToPostfix(infix);

    cout << "Postfix expression: " << postfix << endl;

    return 0;
}

