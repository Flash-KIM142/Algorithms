#include <string>
#include <vector>
#include <algorithm>

using namespace std;
vector<string> numStr{"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

int solution(string s) {
    string result = "";
    string temp = "";
    
    for(int i=0; i<s.size(); i++){
        if(isdigit(s.at(i)))    result += s.at(i);
        else{
            temp += s.at(i);
            auto it = find(numStr.begin(), numStr.end(), temp);
            if(it==numStr.end())   continue;
            else{
                result += (char)(it - numStr.begin()+48);
                temp = "";
            }
        }
    }
    return stoi(result);
}