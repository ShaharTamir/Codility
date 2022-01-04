#include <vector>

using namespace std;

int solution(vector<int> &A) {
    int sum = 0;
    int east = 0;

    for(auto i : A)
    {
        if(i)
            sum += east;
        else
            ++east;
    }

    if(sum < 0 || sum > 1000000000)
        return -1;

    return sum;
}