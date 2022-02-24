#include <map>
#include <string>

using namespace std;

string solution(string &S) {
    map<char, char> lowerCase;
    map<char, char> upperCase;
    unsigned int size = S.length();

    for(unsigned int i = 0; i < size; ++i)
    {
        if(islower(S[i]))
            lowerCase.insert(make_pair(S[i], S[i]));
        else if(isupper(S[i]))
            upperCase.insert(make_pair(S[i], S[i]));
    }

    if(lowerCase.empty() || upperCase.empty())
        return "NO";

    char res = 0;

    for(char j = 'a'; j <= 'z'; ++j)
    {
        if(lowerCase.find(j) != lowerCase.end() && 
            upperCase.find(toupper(j)) != upperCase.end())
        {
            res = res < j ? j : res;
        }
    }
    
    if(!res)
        return "NO";

    return string(1, toupper(res));
}
