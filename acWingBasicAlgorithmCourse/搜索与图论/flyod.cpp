#include<bits/stdc++.h>
using namespace std;

const int N = 100;
int n;

// flyod算法
#include<math.h>
int d[N][N]; // 算法结束后，d[a][b]表示a到b的最短距离

void init(){
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= n; j ++) {
            if (i == j) 
                d[i][j] = 0;
            else 
                d[i][j] = INT_MAX;
        }
    }
}

void flyod() {
    for (int k = 0; k <= n; k ++) {
        // 以每一个节点为中间节点，更新矩阵中任意两点的距离
        for (int i = 1; i <= n; i ++) {
            for (int j = 1; j <= n; j ++) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}