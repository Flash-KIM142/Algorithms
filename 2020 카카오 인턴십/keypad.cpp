#include <string>
#include <utility>
#include <vector>
#include <cstdlib>

using namespace std;

string decideWhichHand(pair<int,int> left, pair<int,int> right, pair<int,int> target){
    int distanceFromRight = abs(target.first-right.first) + abs(target.second-right.second);
    int distanceFromLeft = abs(target.first-left.first) + abs(target.second-left.second);

    if(distanceFromLeft>distanceFromRight) return "R";
    else if(distanceFromLeft<distanceFromRight) return "L";
    else return "S";
}

string solution(vector<int> numbers, string hand) {
    string answer = "";

    int length = numbers.size(); // 주어진 수열의 길이 = 반복문의 횟수
    pair<int,int> leftWhere = make_pair(0, 0); // 왼손의 위치
    pair<int,int> rightWhere = make_pair(2, 0); // 오른손의 위치

    for(int i=0; i<length; i++){
        int target = numbers.at(i);
        int heightOfTarget = 0;
        pair<int,int> targetWhere;

        if(target==1 || target==4 || target==7){ // 무조건 왼손 쓸 경우 
            answer += "L";

            switch (target) {
            case 1:
                leftWhere = make_pair(0, 3);
                break;
            
            case 4:
                leftWhere = make_pair(0, 2);
                break;

            case 7:
                leftWhere = make_pair(0, 1);
                break;
            }

        }
        else if(target==3 || target==6 || target==9){ // 무조건 오른손 쓸 경우
            answer += "R";

            switch (target) {
            case 3:
                rightWhere = make_pair(2, 3);
                break;
            
            case 6:
                rightWhere = make_pair(2, 2);
                break;

            case 9:
                rightWhere = make_pair(2, 1);
                break;
            }

        }
        else{
            string whichHand = "";

            switch (target) {
            case 2:
                targetWhere = make_pair(1, 3);
                whichHand = decideWhichHand(leftWhere, rightWhere, targetWhere);

                if(whichHand == "L"){
                    leftWhere = targetWhere;
                    answer += whichHand;
                }
                else if(whichHand == "R"){
                    rightWhere = targetWhere;
                    answer += whichHand;
                }
                else{ // 양손으로부터 거리가 똑같을 때 
                    if(hand == "left"){ // 왼손잡이일 때 
                        leftWhere = targetWhere;
                        answer += "L";
                    }
                    else if(hand== "right"){ // 오른손잡이일 때 
                        rightWhere = targetWhere;
                        answer += "R";
                    }
                }

                break;

            case 5:
                targetWhere = make_pair(1, 2);
                whichHand = decideWhichHand(leftWhere, rightWhere, targetWhere);

                if(whichHand == "L"){
                    leftWhere = targetWhere;
                    answer += whichHand;
                }
                else if(whichHand == "R"){
                    rightWhere = targetWhere;
                    answer += whichHand;
                }
                else{ // 양손으로부터 거리가 똑같을 때 
                    if(hand == "left"){ // 왼손잡이일 때 
                        leftWhere = targetWhere;
                        answer += "L";
                    }
                    else if(hand== "right"){ // 오른손잡이일 때 
                        rightWhere = targetWhere;
                        answer += "R";
                    }
                }

                break;

            case 8: 
                targetWhere = make_pair(1, 1);
                whichHand = decideWhichHand(leftWhere, rightWhere, targetWhere);

                if(whichHand == "L"){
                    leftWhere = targetWhere;
                    answer += whichHand;
                }
                else if(whichHand == "R"){
                    rightWhere = targetWhere;
                    answer += whichHand;
                }
                else{ // 양손으로부터 거리가 똑같을 때 
                    if(hand == "left"){ // 왼손잡이일 때 
                        leftWhere = targetWhere;
                        answer += "L";
                    }
                    else if(hand== "right"){ // 오른손잡이일 때 
                        rightWhere = targetWhere;
                        answer += "R";
                    }
                }

                break;

            case 0:
                targetWhere = make_pair(1, 0);
                whichHand = decideWhichHand(leftWhere, rightWhere, targetWhere);

                if(whichHand == "L"){
                    leftWhere = targetWhere;
                    answer += whichHand;
                }
                else if(whichHand == "R"){
                    rightWhere = targetWhere;
                    answer += whichHand;
                }
                else{ // 양손으로부터 거리가 똑같을 때 
                    if(hand == "left"){ // 왼손잡이일 때 
                        leftWhere = targetWhere;
                        answer += "L";
                    }
                    else if(hand== "right"){ // 오른손잡이일 때 
                        rightWhere = targetWhere;
                        answer += "R";
                    }
                }

                break;
            }
        }
    }

    return answer;
}