#include <vector>

using namespace std;

struct CounterVector
{
    CounterVector(int length) : c(length)
    {}

    void Add(int index)
    {
        if(c[index] < lastMaxCounter)
            c[index] = lastMaxCounter;

        ++c[index];
        maxCounter = c[index] > maxCounter ? c[index] : maxCounter;
    }

    void SaveLastMaxCounter()
    {
        lastMaxCounter = maxCounter;
    }

    void AddToAll()
    {
        for(auto& i : c)
        {
            if(i < lastMaxCounter)
                i = lastMaxCounter;
        }
    }

    int lastMaxCounter = 0;
    int maxCounter = 0;
    vector<int> c;
};

vector<int> solution(int N, vector<int> &A) {
    CounterVector vec(N);

    for(auto i : A)
    {
        if(i == N + 1)
            vec.SaveLastMaxCounter();
        else
            vec.Add(i - 1);   
    }
    
    vec.AddToAll();

    return vec.c;
}

