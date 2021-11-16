#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<string> unitGems;
int unitGemsSize;
int firstPos;
int lastPos;
vector<string> firstAppearance;

vector<int> solution(vector<string> gems) {
    vector<int> answer;

    unitGems = gems;
    sort(unitGems.begin(), unitGems.end());
    unitGems.erase(unique(unitGems.begin(), unitGems.end())); // 보석 종류 간추린 것
    unitGemsSize = unitGems.size();

    for(int i=0; i<gems.size(); i++){
        if(find(firstAppearance.begin(), firstAppearance.end(), gems[i]) == firstAppearance.end()){ // 처음 나왔으면
            firstAppearance.push_back(gems[i]);
        }

        if(firstAppearance.size()==unitGemsSize){
            lastPos = i; 
            printf("몇 번째에서 끝나냐?: %d\n", lastPos);
            break;
        }
    }

    vector<string> reverse;
    reverse.assign(gems.begin(), gems.begin() + lastPos);
    std::reverse(reverse.begin(), reverse.end());


    printf("원래 거\n");
    for(string jewerly: gems)
        cout << jewerly << endl;

    printf("\n뒤집은 거\n");
    for(string jewerly: reverse)
        cout << jewerly << endl;

    return answer;
}

int main(){
    vector<string> example = { "DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA" };
    vector<int> name = solution(example);
    return 0;
}