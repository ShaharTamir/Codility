#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void swap(char& a, char& b)
{
    char tmp = a;
    a = b;
    b = tmp;
}

string solution(int A, int B, int C)
{
    string res;
    int max;
    bool oneLeft = false;

    while(A > 0 || B > 0 || C > 0 && oneLeft == false)
    {
        oneLeft = (A && !B && !C) || (!A && B && !C) || (!A && !B && C);

        max = std::max(C , std::max(A, B));
        if(max == A)
        {
            if(A-- > 0)
                res.push_back('a');
            if(A-- > 0)
                res.push_back('a');

            if(B >= C) {
                if(B-- > 0)
                    res.push_back('b');
            }
            else {
                if(C-- > 0)
                    res.push_back('c');
            }
        }

        else if(max == B)
        {
            if(B-- > 0)
                res.push_back('b');
            if(B-- > 0)
                res.push_back('b');

            if(A >= C)
            {
                if(A-- > 0)
                    res.push_back('a');
            }
            else
            {
                if(C-- > 0)
                    res.push_back('c');
            }
        }

        else if(max == C)
        {
            if(C-- > 0)
                res.push_back('c');
            if(C-- > 0)
                res.push_back('c');

            if(A >= B)
            {
                if(A-- > 0)
                    res.push_back('a');
            }
            else
            {
                if(B-- > 0)
                    res.push_back('b');
            }
        }
        else
        {
            if(A-- > 0)
                res.push_back('a');
            if(B-- > 0)
                res.push_back('b');
            if(C-- > 0)
                res.push_back('c');
        }
    }

    for(int i = 2; i < res.length(); ++i)
    {
        if(res[i] == res[i - 1] && res[i] == res[i - 2])
        {
            if(i + 1 == res.length())
                res[i] = '\0';
            else 
                swap(res[i], res[i + 1]);
        }
    }

    return res;
}

int main()
{
    int A = 1;
    int B = 2;
    int C = 8;

    cout << solution(A, B, C) << endl;

    A = 6;
    cout << solution(A, B, C) << endl;

    B = 6;
    cout << solution(A, B, C) << endl;

    A = 0;
    C = 3;
    cout << solution(A, B, C) << endl;

    C = 8;
    B = 1;
    cout << solution(A, B, C) << endl;

    return 0;
}