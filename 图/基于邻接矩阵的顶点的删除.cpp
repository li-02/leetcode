#include <iostream>
using namespace std;

struct UGraph
{
    /* data */
    int pointCnt;
    int edgeCnt;
    int point[1000][1000];
};
/**
 * @brief Create a Graph object
 * 由于输出中还要带上横纵坐标,所以要多出来第0行和第0列充当坐标
 *
 * @param g
 * @param n
 * @param m
 */
void createGraph(UGraph &g, int n, int m)
{
    int a, b;
    g.pointCnt = n;
    g.edgeCnt = m;
    // 充当横纵坐标
    for (int i = 0; i <= g.pointCnt; i++)
        g.point[0][i] = g.point[i][0] = i;
    // 所有值初始化
    for (int i = 1; i <= g.pointCnt; i++)
        for (int j = 1; j <= g.pointCnt; j++)
            g.point[i][j] = 0;
    while (m--)
    {
        cin >> a >> b;
        g.point[a][b] = g.point[b][a] = 1;
    }
}

void InsertPoint(UGraph &g)
{
    int n;
    cin >> n;
    g.pointCnt++;
    g.point[0][g.pointCnt] = g.point[g.pointCnt][0] = n;
    for (int i = 1; i <= g.pointCnt; i++)
        g.point[i][g.pointCnt] = g.point[g.pointCnt][i] = 0;
}

/**
 * @brief 删两次,要删除点开始,后面的列前移,后面的行前移
 *
 * @param g
 */
void deletePoint(UGraph &g)
{
    int n;
    cin >> n;
    // n点开始,所有列前移
    for (int i = 0; i <= g.pointCnt; i++)
    {
        for (int j = n; j <= g.pointCnt; j++)
        {
            g.point[i][j] = g.point[i][j + 1];
        }
    }
    for (int i = n; i <= g.pointCnt; i++)
    {
        for (int j = 0; j <= g.pointCnt; j++)
            g.point[i][j] = g.point[i + 1][j];
    }
    g.pointCnt--;
}

void printGraph(UGraph g)
{
    for (int i = 0; i <= g.pointCnt; i++)
    {
        for (int j = 0; j < g.pointCnt; j++)
            cout << g.point[i][j] << " ";
        cout << g.point[i][g.pointCnt] << endl;
    }
}

int main()
{
    int n, m;
    while (cin >> n >> m)
    {
        if (n == 0 && m == 0)
            break;
        UGraph g;
        createGraph(g, n, m);
        deletePoint(g);
        printGraph(g);
    }
}
