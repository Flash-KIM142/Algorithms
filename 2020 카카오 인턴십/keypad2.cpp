#include <string>
#include <vector>

using namespace std;

typedef struct pos {
    int x;
    int y;
} pos;

pos leftPos, rightPos, targetPos;
vector<pos> pad = { {3,1}, {0,0}, {0,1}, {0,2}, {1,0}, {1,1}, {1,2}, {2,0}, {2,1}, {2,2} };

int howFar(pos a, pos b){
    return ( abs(a.x-b.x) + abs(a.y-b.y) );
}

string whichHand(pos target, pos left, pos right, string hand){
    int whichLine = target.y;

    switch(whichLine){
        case 0: // 왼쪽 숫자들일 때
            leftPos = target;
            return "L";

        case 2: // 오른쪽 숫자들일 때 
            rightPos = target;
            return "R";

        case 1: // 중간 숫자들일 때 
            int leftDistance = howFar(target, left);
            int rightDistance = howFar(target, right);
            if(leftDistance>rightDistance) {
                rightPos = target;
                return "R";
            }
            else if(leftDistance<rightDistance){
                leftPos = target;
                return "L";
            }
            else{
                if(hand=="right"){
                    rightPos = target;
                    return "R";
                }
                else {
                    leftPos = target;
                    return "L";
                }
            }
    }
    return "ERROR";
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    leftPos.x = 3; leftPos.y = 0;
    rightPos.x = 3; rightPos.y = 2;

    for(int i=0; i<numbers.size(); i++){
        targetPos = pad.at(numbers.at(i));
        answer.append(whichHand(targetPos, leftPos, rightPos, hand));
    }

    return answer;
}