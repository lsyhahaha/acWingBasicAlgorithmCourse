#include<iostream>
#include<string.h>

using namespace std;

#define N 100
const int a = 100, b = 100;


// 邻接表
// 对于每一个k，开一个单链表，存储k所有可以走到的点。h[k]存储这个单链表的头节点
int h[N],  e[N], ne[N], idx = 0;

// 添加一条边a->b
void add(int a, int b) {
    // 存下b的值，b指向a的下一个节点，a的下一个结点指向b
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

// 初始化
void init(){
    idx = 0;
    memset(h, -1, sizeof h);
}



// 深度优先搜索
bool st[N];
int dfs(int u) {
    st[u] = true; // 表示u已经被访问过了

    for (int i = h[u]; i != -1; i = ne[i]) {
        int j = e[i];
        if (!st[j]) dfs(j);
    }
}