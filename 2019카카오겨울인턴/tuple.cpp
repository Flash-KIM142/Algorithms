#include <cstdlib>
#include <utility>
#include <algorithm>
#include <set>
#include <vector>
#include <string>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;

    vector<int> tmp;
    vector<pair<int, vector<int>>> tupleTotal;

    int tmpNum = 0;


    for(int i=1; i<s.size()-1; i++){
        if(s[i] == '{') continue; // 얘는 그냥 넘기고

        if(s[i] == '}'){ // 하나의 부분집합이 끝났으니까 정리해주자
            tmp.push_back(tmpNum);

            tupleTotal.push_back(make_pair(tmp.size(), tmp));

            tmpNum = 0;
            tmp.clear();
        }
        else if(s[i] == ','){ // 다음 숫자를 받아보자
            if(s[i-1] == '}') continue; // 다음 부분집합과 구분하기 위한 쉼표라면 넘어가자 

            tmp.push_back(tmpNum);
            tmpNum = 0; // 숫자 하나 완성해서 넣었으니까 0으로 초기화
        }
        else{ // 숫자를 만났을 때
            tmpNum *= 10;
            tmpNum += (s[i]-'0');
        }
    }

    sort(tupleTotal.begin(), tupleTotal.end()); // 이로써 부분집합의 크기순으로 정렬까지 완료했다

    set<int> result;
    for(pair<int, vector<int>> p: tupleTotal){ // size 순으로 정렬된 부분집합을 하나씩 돌려보자
        for(int num: p.second){ // 각 부분집합의 원소들 하나씩 돌려보자
            if(result.find(num) == result.end()){ // find 함수 이용해서 없는 원소 하나씩 추가해나가자 
                result.insert(num);
                answer.push_back(num);
            }
        }
    }

    return answer;
}