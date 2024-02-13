#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 1e6 + 10;

int n, q[N], tmp[N];

void merge_sort(int l, int r){
    if(l >= r) return ;
    int mid = (l + r) / 2;
    merge_sort(l, mid), merge_sort(mid + 1, r);
    int i = l;
    int j = mid + 1;
    int k = 0;
    while(i <= mid && j <= r){
        if(q[i] <= q[j]) tmp[k++] = q[i++];
        else tmp[k++] = q[j++];
    }
    while(i <= mid) tmp[k++] = q[i++];
    while(j <= r) tmp[k++] = q[j++];
    for(int i = l, j = 0; i <= r; i++, j++){
        q[i] = tmp[j];
    }
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> q[i];
    }
    merge_sort(0, n-1);
    for(int i = 0; i < n; i++){
        cout << q[i] << " ";
    }
    return 0;
}
