#include<bits/stdc++.h>
using namespace std;

const int N = 100;
int n;

// 拓扑排序
const int n = 100;
int d[n];
bool topsort() {
    int hh = 0, tt = -1;
    int q[n]; // 队列

    // d[i]存储i的入度
    for (int i = 1; i <= n; i ++) {
        if (!d[i]) {
            q[++ tt] = i;
        }
    }

    while (hh <= tt) {
        int t = q[hh ++ ];

        for (int i = h[t]; i != -1; i = ne[i]) { // 删除i节点相关的边
            int j = e[i];
            if (-- d[j] == 0) { // 如果与i相连的节点j删除一条边以后，入度为0，则加入队列
                q[ ++ tt] = j;
            }
        }
    }
}