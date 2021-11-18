#include <string>
#include <vector>
#include <queue>
#include <cctype>
#include <iostream>
#include <algorithm>

using namespace std;
vector< vector<int> > partialSet;
vector<int> partialSetVector;

bool cmpVec(vector<int> a, vector<int> b){
    return (a.size() < b.size());
}

vector<int> solution(string s) {
    vector<int> answer;

    int sLength = s.length();
    int i=0; // 문자열 index
    string tempNum;

    for(int n=0; n<sLength-1; n++){
        if(s.at(n)=='{')    continue;
        
        if(s.at(n)=='}'){
            partialSetVector.push_back(stoi(tempNum));
            tempNum = "";

            partialSet.push_back(partialSetVector);
            partialSetVector.clear();
        }
        else if(s.at(n)==','){
            if(s.at(n-1)=='}')  continue;

            partialSetVector.push_back(stoi(tempNum));
            tempNum = "";
        }
        else{
            tempNum += s.at(n);
        }
    }

    sort(partialSet.begin(), partialSet.end(), cmpVec);
    answer.push_back(partialSet.at(0).at(0));

    for(i=0; i<partialSet.size(); i++){
        for(int j=0; j<partialSet.at(i).size(); j++){
            auto it = find(answer.begin(), answer.end(), partialSet.at(i).at(j));
            if(it==answer.end())
                answer.push_back(partialSet.at(i).at(j));
        }
    }
    return answer;
}

int main(){
    string s = "{{1,2,3},{2,1},{1,2,4,3},{2}}";
    vector<int> a = solution(s);

    // for(int i=0; i<partialSet.size(); i++){
    //     for(int j=0; j<partialSet.at(i).size(); j++)
    //         cout << partialSet.at(i).at(j) << " ";
    //     printf("\n");
    // }
    
    for(int num: a)
        cout << num << " ";
    return 0;
}