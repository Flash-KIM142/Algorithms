#include <string>
#include <vector>
#include <set>

using namespace std;
bool occupied[8];
vector<int> candidate[8];
set<string> s;

bool cmpStr(string a, string b){
    if(a.length()!=b.length())  return false;

    for(int i=0; i<a.length(); i++){
        if(b.at(i)=='*')    continue;
        if(a.at(i)!=b.at(i))    return false;
    }
    return true;
}

void dfs(int idx, int banned_size){
    if(idx==banned_size){
        string tmp = "";
        for(int i=0; i<8; i++)
            if(occupied[i]) tmp += to_string(i);
        s.insert(tmp);
        return;
    }

    for(int i=0; i<candidate[idx].size(); i++){
        int cur = candidate[idx][i];
        if(occupied[cur])   continue;

        occupied[cur] = true;
        dfs(idx+1, banned_size);
        occupied[cur] = false;
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;

    for(int i=0; i<banned_id.size(); i++){
        for(int j=0; j<user_id.size(); j++){
            if(cmpStr(user_id[j], banned_id[i])){
                candidate[i].push_back(j);
            }
        }
    }

    dfs(0, banned_id.size());
    answer = s.size();
    return answer;
}