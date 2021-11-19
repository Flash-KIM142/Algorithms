#include <string>
#include <vector>
#include <stack>

using namespace std;
stack<int> basket;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    int size = board.size();

    for(int i=0; i<moves.size(); i++){
        int whichColumn = moves[i]-1;
        int target;

        for(int j=0; j<size; j++){
            target = board[j][whichColumn];

            if(target!=0){
                board[j][whichColumn] = 0;
                break;
            }
        }
        
        if(target==0)   continue;
        else if(basket.empty())  basket.push(target);
        else if(!basket.empty() && basket.top()!=target)   basket.push(target);
        else if(!basket.empty() && basket.top()==target){
            basket.pop();
            answer +=2 ;
        }
    }
    return answer;
}