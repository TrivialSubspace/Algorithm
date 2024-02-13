#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 1e6 + 10;

int n, q[N];

void quick_sort(int l, int r){
    if(l >= r) return ;
    int i = l - 1;
    int j = r + 1;
    int mid = q[(l+r)/2];
    while(i < j){
        do i++;while(q[i] < mid);
        do j--;while(q[j] > mid);
        if(i < j) swap(q[i], q[j]);
    }
    quick_sort(l, j);
    quick_sort(j+1, r);
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> q[i];
    }
    quick_sort(0, n-1);
    for(int i = 0; i < n; i++){
        cout << q[i] << " ";
    }
    return 0;
}
