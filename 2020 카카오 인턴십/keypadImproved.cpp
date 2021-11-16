#include <string>
#include <utility>
#include <vector>
#include <cstdlib>
#define pii pair<int,int>

using namespace std;
vector<pii> keypad = {
    {1,0}, {0,3}, {1,3}, {2,3}, {0,2}, {1,2}, {2,2}, {0,1}, {1,1}, {2,1},
};

string decideWhichHand(pii left, pii right, pii target, string hand){
    int distanceFromLeft = abs(left.first - target.first) + abs(left.second - target.second);
    int distanceFromRight = abs(right.first - target.first) + abs(right.second - target.second);

    if(distanceFromLeft>distanceFromRight) return "R";
    else if(distanceFromLeft<distanceFromRight) return "L";
    else{
        if(hand=="left") return "L";
        else return "R";
    }
}

string solution(vector<int> numbers, string hand) {
    string answer = "";

    int length = numbers.size();
    pii leftWhere = make_pair(0,0);
    pii rightWhere = make_pair(2,0);

    for(int i=0; i<length; i++){
        int target = numbers.at(i);

        if(target == 1 || target == 4 || target == 7){
            answer += "L";
            leftWhere = keypad[target];
        }
        else if(target == 3 || target == 6 || target == 9){
            answer += "R";
            rightWhere = keypad[target];
        }
        else{
            pii targetWhere = keypad[target];
            string whichHand = decideWhichHand(leftWhere, rightWhere, targetWhere, hand);

            if(whichHand=="L"){
                answer += whichHand;
                leftWhere = targetWhere;
            }
            else{
                answer += whichHand;
                rightWhere = targetWhere;
            }
        }
    }

    return answer;
}

// 좌표를 사용해야 한다는 아이디어를 바로 떠올릴 수 있었어야 한다.
// 애초에 처리해야할 data 의 수가 keypad 의 12개 뿐이니까 처음부터 직접 각 data 의 좌표값을 초기화해줘서 다루면 됐다.
// 처음에는 매번 일일이 각 data 의 값을 case 마다 초기화해서 코드가 훨씬 길어졌다.
// 절대 바뀌지 않을 값인 keypad 의 좌표값은 처음부터 전역변수로 초기화해서 제공하면 훨씬 보기 쉬운 코드가 된다. 