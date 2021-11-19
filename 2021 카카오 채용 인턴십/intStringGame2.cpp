#include <string>
#include <vector>
#include <regex>

using namespace std;

vector<string> numStr{"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

int solution(string s) {
    for(int i=0; i<10; i++)
        s = regex_replace(s, regex(numStr[i]), to_string(i));
    return stoi(s);
}