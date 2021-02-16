#include<bits/stdc++.h>
using namespace std;

vector<int> digs = {1, 1, 2, 6, 4, 2, 2,4, 2, 8};

int lastNonZero(int n){
    if(n<10){
        return digs[n];
    }

    int lastDigit = n%10;
    int lastSecDig = (n/10)%10;
    if(lastSecDig&1){
        return 6*lastNonZero(floor(n/5))*lastNonZero(lastDigit) %10;
    } else {
        return 4 * lastNonZero(floor(n/5)) * lastNonZero(lastDigit)%10;
    }
}

int main(){
    cout<<lastNonZero(99);
    return 0;
}