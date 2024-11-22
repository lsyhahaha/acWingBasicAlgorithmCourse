#include<bits/stdc++.h>

using namespace std;

#define INF 0x3f3f3f

const int N = 100, M = 100;
int n,m; // n是点数，m是边数
int p[N];


// bool operator < (const Edge &W) const：这个成员函数重载了 < 运算符，使得可
// 以直接通过边的权重进行排序。当对 Edge 数组（如 edges[]）进行排序时，会自动根
// 据权重 w 排序，确保权重较小的边排在前面。const 表示此操作不会修改对象的状态。
struct Edge { // 存储边
    int a, b , w;

    bool operator < (const Edge &W) const {
        // 当对 Edge 数组（如 edges[]）进行排序时，会自动根据权重 w 排序
        return w < W.w;
    }
}edges[M]; 


// p[] 是一个一维数组，用来存储每个元素的父节点。初始时，p[i] 指向元素 i 本身，
// 表示每个元素都自成一个集合。后续的并操作（Union）将会将某些元素连接起来，修改 p[] 数组，使得它们指向一个共同的父节点。
int find(int x) {
    // 并查集核心操作
    if (p[x] != x) 
        p[x] = find(p[x]);
    
    return p[x];
}

int kruskal() {
    sort(edges, edges + m);

    for (int i = 1; i <= n; i ++) p[i] = i; // 初始化并查集

    int res = 0, cnt = 0;
    for (int i = 0; i < m; i ++) {
        int a = edges[i].a, b = edges[i].b, w = edges[i].w;

        a = find(a), b = find(b);
        if (a != b) {
            // 如果两个连通块不连通，则将这两个连通块合并
            p[a] = b;
            res += w;
            cnt ++;
        }
    }

    if (cnt < n - 1) 
        return INF;
    
    return res;
}