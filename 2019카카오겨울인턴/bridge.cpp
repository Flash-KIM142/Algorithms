#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool binarySearch(int mid, int k, vector<int> a){
    int cnt = 0;
    for(int i=0; i<a.size(); i++){
        if(a[i]-mid<=0) cnt++;
        else    cnt = 0;

        if(cnt>=k)  return true;
    }
    return false;
}

int solution(vector<int> stones, int k) {
    int left = 1, right = *max_element(stones.begin(), stones.end());

    while(left<=right){
        int mid = (left+right)/2;

        if(binarySearch(mid, k, stones))    right = mid-1;
        else    left = mid+1;
    }

    return left;
}