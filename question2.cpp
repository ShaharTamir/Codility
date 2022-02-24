#include "answer.h"
#include <iostream>

using namespace std;


vector<int> solution(int N) {
    vector<int> res(N);
    int numbers = 1;
    
    if(N % 2)
    {
        --N;
        res[N - 1] = 0;
    }

    for(int i = 0; i < N; i += 2)
    {
        res[i] = numbers;
        res[i + 1] = -1 * numbers;
        ++numbers;
    }

    int tester = 0;
    for(auto j : res)
    {
        cout << j;
        tester += j;
    }

    cout << endl << tester << endl;

    return res;
}
