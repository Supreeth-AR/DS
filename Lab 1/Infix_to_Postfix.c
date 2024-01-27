// WAP to convert a given valid parenthesized infix arithmetic expression to postfix expression. The expression consists of single character operands and the binary operators + (plus), - (minus), * (multiply) and /(divide)

#include <stdio.h>
#include <string.h>

int index1 = 0, pos = 0, top = -1, length;
char symbol, temp, infix[20], postfix[20], stack[20];
void infixtopostfix();
void push(char symbol);
char pop();
int pred(char symb);

void main()
{
    printf("\n Enter Infix Expression: \n");
    scanf("%s", infix);
    infixtopostfix();
    printf("\n \n Infix Expression: \n%s", infix);
    printf("\n \n Postfix Expression: \n%s", postfix);
}

void infixtopostfix()
{
    length = strlen(infix);
    push('#');
    while (index1 < length)
    {
        symbol = infix[index1];
        switch (symbol)
        {
        case '(':
            push(symbol);
            break;

        case ')':
            temp = pop();

            while (temp != '(')
            {
                postfix[pos] = temp;
                pos++;
                temp = pop();
            }
            break;

        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
            while (pred(stack[top]) >= pred(symbol))
            {
                temp = pop();
                postfix[pos++] = temp;
            }
            push(symbol);
            break;

        default:
            postfix[pos++] = symbol;
        }
        index1++;
    }
    while (top > 0)
    {
        temp = pop();
        postfix[pos++] = temp;
    }
}

void push(char symbol)
{
    top = top + 1;
    stack[top] = symbol;
}

char pop()
{
    char symb;
    symb = stack[top];
    top = top - 1;
    return (symb);
}

int pred(char symbol)
{
    int p;
    switch (symbol)
    {
    case '^':
        p = 3;
        break;

    case '*':

    case '/':
        p = 2;
        break;

    case '+':
    case '-':
        p = 1;
        break;

    case '(':
        p = 0;
        break;

    case '#':
        p = -1;
        break;
    }
    return (p);
}
