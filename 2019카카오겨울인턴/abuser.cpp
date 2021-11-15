// 건들지도 못했다.... 뭘 어디서부터 어떻게 시작해야할지조차 감이 오지 않았다.
// 어떤 문제 상황에서 어떤 자료구조를 사용해야 하는지, 어떤 문제해결 전략을 사용해야하는지조차 모르는 상태다.
// DFS가 뭔지, 언제 사용되는지, BFS 는 어떠한지, 최단경로 찾기는 어떠한지
// 이런 것들이 전혀 머릿속에 정리가 돼있지 않으니 될 리가 있겠는가...
// set 이 중복없이 사용할 수 있는 자료구조라는 사실조차 모르는데 어떻게 이런 문제를 풀겠는가?
// b_id 의 size 만큼 targetBannedIndex 가 다 차고 나서 dfs 의 첫 if 문을 만나고 나면 그 다음 과정이 어떻게 되는지 그려지지 않는다 씨발

#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;
bool check[8];
int u_len, b_len;
set<string> s;

void dfs(int targetBannedIndex, string possibleCase, vector<string> u_id, vector<string> b_id){
    if(targetBannedIndex == b_len){
        sort(possibleCase.begin(), possibleCase.end());
        s.insert(possibleCase);
        return;
    }

    string targetBannedUser = b_id[targetBannedIndex];
    int targetBannedUserLength = targetBannedUser.size();

    for(int i=0; i<u_len; i++){
        string targetOriginalUser = u_id[i];

        if(targetOriginalUser.size() != targetBannedUserLength) continue;
        if(check[i]) continue;

        bool flag = true;
        for(int j=0; j<targetBannedUserLength; j++){
            if(targetBannedUser[j] == '*') continue;

            if(targetOriginalUser[j] != targetBannedUser[j]){
                flag = false;
                break;
            }
        }

        if(flag){
            check[i] = true;
            dfs(targetBannedIndex+1, possibleCase+to_string(i), u_id, b_id);

            check[i] = false;
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;

    u_len = user_id.size();
    b_len = banned_id.size();
    dfs(0, "", user_id, banned_id);

    answer = s.size();

    return answer;
}