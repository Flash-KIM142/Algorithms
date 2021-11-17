#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
int moveX[4] = { 0, 0, -1, 1}; // 상하좌우
int moveY[4] = { -1, 1, 0, 0};
int costBoard[25][25][4];

typedef struct pos{
    int x;
    int y;
    int direction;
} pos;

bool isInside(pos a, int size){
    return (a.x>=0 && a.x<size && a.y>=0 && a.y<size);
}

void bfs(vector< vector<int> > board){
    int size = board.size();
    queue<pos> q;

    fill_n(&costBoard[0][0][0], 25*25*4, 999999999);
    for(int i=0; i<4; i++)
        costBoard[0][0][i] = 0;

    q.push({0,0,-1});

    while(!q.empty()){
        pos current = q.front();
        q.pop();

        for(int i=0; i<4; i++){
            int movedX = current.x + moveX[i];
            int movedY = current.y + moveY[i];
            pos moved; moved.x = movedX; moved.y = movedY;  moved.direction = i;

            if(!isInside(moved, size) || board[moved.x][moved.y]==1)   
                continue;
            
            if(current.direction==moved.direction){
                if(costBoard[moved.x][moved.y][moved.direction]>costBoard[current.x][current.y][current.direction] + 100){
                    costBoard[moved.x][moved.y][moved.direction] = costBoard[current.x][current.y][current.direction] +100;
                    q.push(moved);
                }
            }
            else{
                if(costBoard[moved.x][moved.y][moved.direction]>costBoard[current.x][current.y][current.direction] + 600){
                    costBoard[moved.x][moved.y][moved.direction] = costBoard[current.x][current.y][current.direction] +600;
                    q.push(moved);
                }
            }
        }
    }
}

int solution(vector< vector<int> > board) {
    int answer = 999999999;
    int n = board.size();
    bfs(board);

    for(int i=0; i<4; i++){
        answer = min(answer, costBoard[n-1][n-1][i]);
    }
    return answer-500;
}