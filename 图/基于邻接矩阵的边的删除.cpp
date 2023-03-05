#include <iostream>
using namespace std;

struct UGraph
{
    /* data */
    int pointCnt;
    int edgeCnt;
    int dot[100][100];
};

void createGraph(UGraph &g, int n, int m)
{
    int p1, p2;
    g.pointCnt = n;
    g.edgeCnt = m;
    // 初始化坐标系
    for (int i = 0; i <= g.pointCnt; i++)
    {
        g.dot[0][i] = g.dot[i][0] = i;
    }
    // 初始化值
    for (int i = 1; i <= g.pointCnt; i++)
    {
        for (int j = 1; j <= g.pointCnt; j++)
        {
            g.dot[i][j] = 0;
        }
    }
    // 添加边
    while (m--)
    {
        cin >> p1 >> p2;
        g.dot[p1][p2] = g.dot[p2][p1] = 1;
    }
}

void insertEdge(UGraph &g)
{
    int p1, p2;
    cin >> p1 >> p2;
    g.dot[p1][p2] = g.dot[p2][p1] = 1;
}
void deleteEdge(UGraph &g)
{
    int p1, p2;
    cin >> p1 >> p2;
    g.dot[p1][p2] = g.dot[p2][p1] = 0;
}

void showGraph(UGraph g)
{
    for (int i = 0; i <= g.pointCnt; i++)
    {
        for (int j = 0; j < g.pointCnt; j++)
        {
            cout << g.dot[i][j] << " ";
        }
        cout << g.dot[i][g.pointCnt] << endl;
    }
}

int main()
{
    int n, m;
    while (cin >> n >> m)
    {
        if (!n && !m)
            break;
        UGraph g;
        createGraph(g, n, m);
        deleteEdge(g);
        showGraph(g);
    }
    return 0;
}
