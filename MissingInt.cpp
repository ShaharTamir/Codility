#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Compare
{
   public:
    bool operator() (int a, int b)
    {
        return a >= b;
    } 
};

int solution(vector<int> &A) {
    priority_queue<int, vector<int>, Compare> q;

    for(auto i : A)
        if(i > 0)
        {
            q.push(i);
        }
    
    if(q.empty())
        return 1;

    int j = 0;
    int offset = 1;
    int prev = 0;
    unsigned int startSize = q.size();

    for(j = 0; (unsigned)j < startSize; ++j)
    {
        if(prev == q.top())
            --offset;
        else if(j + offset != q.top())
        {
            return j + offset;
        }
        
        prev = q.top();
        q.pop();
    }

    return j + offset;
}
