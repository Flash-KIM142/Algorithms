#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <utility>

using namespace std;
vector<long long> operand;
vector<char> op;

void Parser(string expression){ 
    string temp = "";
    for(int i=0; i<expression.length(); i++){
        char targetChar = expression.at(i);
        if(targetChar!='+' && targetChar!='-' && targetChar!='*'){ // 숫자 들어오면
            temp.push_back(targetChar);
        }
        else{ // 연산자 들어오면
            operand.push_back(stoll(temp));
            temp = "";

            op.push_back(targetChar);
        }
    }
    operand.push_back(stoll(temp));
}

long long Calculator(long long a, long long b, char op){
    if(op=='+')
        return a+b;
    else if(op=='-')
        return a-b;
    else if(op=='*')
        return a*b;
}

long long solution(string expression) {
    long long answer = 0;

    Parser(expression);
    vector<char> operatorList;
    operatorList.push_back('*');    operatorList.push_back('+');    operatorList.push_back('-');

    do{
        vector<long long> tempOperand = operand;
        vector<char> tempOp = op;
        for(int i=0; i<3; i++){ // 연산자 개수 따라서
            for(int j=0; j<tempOp.size(); j++){ // 수식의 total 연산자 개수에 따라서
                if(tempOp.at(j) == operatorList.at(i)){ // 연산자 우선순위 따라서
                    tempOperand[j] = Calculator(tempOperand[j], tempOperand[j+1], operatorList.at(i));
                    tempOperand.erase(tempOperand.begin()+ j+1);
                    tempOp.erase(tempOp.begin() + j);
                    j--;
                }
            }
        }
        if(answer<abs(tempOperand[0]))
            answer = abs(tempOperand[0]);
    } while(next_permutation(operatorList.begin(), operatorList.end()));
    return answer;
}

// 문제에서 주어진 type 에 맞게 작성해야 할 것 아냐... 이것 때문에 대체 몇 분을 날린 거니...