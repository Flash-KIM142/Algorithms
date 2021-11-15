#include <string>
#include <vector>

using namespace std;
vector< vector<int> > Board;
vector<int> Moves;

int solution(vector< vector<int> > board, vector<int> moves) {
    int answer = 0;
    vector<int> basket;

    int N = board.size();

    for(int i=0; i<moves.size(); i++){
        int empty=0;
        int target;

        for(int j=0; j<N; j++){ // moves 의  원소에 따라서 해당 col의 0이 아닌 원소를 target 으로 삼아 basket 으로 옮겨야 한다.
            target = board[j][moves[i]-1];

            if(target==0) empty++;
            else{
                board[j][moves[i]-1] = 0; // 뽑힌 녀석들은 0으로 바꿔줘야 하는데 이 작업을 잊었다...!
                break;
            }
        }

        if(basket.size()==0){
            basket.push_back(target);
        }
        else if(basket.size()>0 && basket.at(basket.size()-1)!=target){
            basket.push_back(target);
        }  
        else if(target==0){ // 해당 col 이 결국 다 0일 경우에는 그냥 건너뛰는 작업을 해줘야 한다!!!
            empty++;
        }
        else if(basket.size()>0 && basket.at(basket.size()-1)==target){
            basket.pop_back();
            answer += 2;
        } 

    }

    return answer;
}