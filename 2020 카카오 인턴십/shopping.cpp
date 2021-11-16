#include <string>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

int unitGemsSize;
int startPoint; int tmp_start = 0;
int endPoint; int tmp_end = 0;
int currentGemsSize = 0;
int length;

vector<int> solution(vector<string> gems) {
    vector<int> answer;

    length = gems.size()+1;
    set<string> unitGems(gems.begin(), gems.end());
    unitGemsSize = unitGems.size();

    map<string, int> jewerlyAppearance;
    for(auto jewerly: gems)
        jewerlyAppearance[jewerly] = 0;

    while(1){
        if(currentGemsSize==unitGemsSize){
            if(tmp_end-tmp_start < length){
                startPoint = tmp_start;
                endPoint = tmp_end;
                length = endPoint - startPoint;
            }

            if(jewerlyAppearance[gems[tmp_start]]>1){
                jewerlyAppearance[gems[tmp_start]]--;
                tmp_start++;
            }
            else{
                jewerlyAppearance[gems[tmp_start]]--;
                tmp_start++;
                currentGemsSize--;
            }
        }
        else{
            if(tmp_end==gems.size())    break;
            if(!jewerlyAppearance[gems[tmp_end]])   currentGemsSize++;
            
            jewerlyAppearance[gems[tmp_end]]++;
            tmp_end++;
        }
    }
    answer.push_back(startPoint+1);
    answer.push_back(endPoint);

    return answer;
}

int main(){
    vector<string> example = { "DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA" };
    vector<int> name = solution(example);
    for(int i: name)
        cout << i << " ";
    return 0;
}