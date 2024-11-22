#include<bits/stdc++.h>

using namespace std;

#define INF 0x3f3f3f

const int N = 100;

int n; // n表示点数
int g[N][N]; // 邻接矩阵
int dist[N]; // 存储其他点到当前最小生成树的距离
bool st[N]; // 存储每个节点时候已经加入最小生成树


// 如果图不连通，则返回INF(值是0x3f3f3f),否则返回最小生成树的权值和
int prim() {
    memset(dist, 0x3f, sizeof dist);

    int res = 0;
    for (int i = 0; i < n; i ++) {
        int t = -1;
        for (int j = 1; j <= n; j ++) {  // 找到未在最小生成树的点集中，到当前最小生成树的最小距离
            if (!st[j] && (t == -1 || dist[t] > dist[j]))
                t = j;
        }

        if (i != 0 && dist[t] == INF) return INF;

        if (i != 0) res += dist[t];
        st[t] = true;

        // 更新未在最小生成树的点集到当前最小生成树的距离
        for (int j = 1; j <= n; j ++) {
            dist[j] = min(dist[j], g[t][j]);
        }
    }

    return res;
}