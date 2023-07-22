#include <bits/stdc++.h>

using namespace std;

struct Shark
{
    int y;
    int x;

    int speed;
    int dir;
    int weight;
};

const int dy[4] = { -1, 0, 1, 0 };
const int dx[4] = { 0, 1, 0, -1 };

int r;
int c;
int m;

int s; // 속력
int d; // 방향 (1 : 위, 2 : 아래, 3 : 오른쪽, 4 : 왼쪽)
int z; // 크기

vector<Shark> sharkMap[104][104];
vector<Shark> sharkVec;

int pos;

int res;

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(nullptr);
    // cout.tie(nullptr);

    cin >> r >> c >> m;

    for (int i = 0; i < m; i++)
    {
        Shark shark;

        cin >> shark.y >> shark.x >> shark.speed >> shark.dir >> shark.weight;

        shark.y--;
        shark.x--;

        if (1 == shark.dir)
        {
            shark.dir = 0;

            shark.speed %= (r - 1) * 2;
        }
        else if (2 == shark.dir)
        {
            shark.dir = 2;
            
            shark.speed %= (r - 1) * 2;
        }
        else if (3 == shark.dir)
        {
            shark.dir = 1;
            
            shark.speed %= (c - 1) * 2;
        }
        else
        {
            shark.dir = 3;
            
            shark.speed %= (c - 1) * 2;
        }

        sharkMap[shark.y][shark.x].push_back(shark);
    }

    while (pos < c)
    {
        // 가장 가까운 상어 있으면 잡기
        for (int y = 0; y < r; y++)
        {
            if (sharkMap[y][pos].size())
            {
                res += sharkMap[y][pos][0].weight;

                sharkMap[y][pos].clear();

                break;
            }
        }

        // 움직일 수 있는 상어 모으기
        for (int y = 0; y < r; y++)
        {
            for (int x = 0; x < c; x++)
            {
                for (Shark& shark : sharkMap[y][x])
                {
                    sharkVec.push_back(shark);
                }

                sharkMap[y][x].clear();
            }
        }

        // 상어 갱신
        for (Shark& shark : sharkVec)
        {
            // 상어 움직이기
            int amount = shark.speed;

            if (0 == shark.dir || 2 == shark.dir)
            {
                // y 방향
                while (amount)
                {
                    if ((0 == shark.dir && 0 == shark.y) || (2 == shark.dir && r - 1 == shark.y))
                    {
                        shark.dir = (shark.dir + 2) % 4;
                    }

                    shark.y += dy[shark.dir];

                    amount--;
                }
            }
            else if (1 == shark.dir || 3 == shark.dir)
            {
                // x 방향
                while (amount)
                {
                    if ((3 == shark.dir && 0 == shark.x) || (1 == shark.dir && c - 1 == shark.x))
                    {
                        shark.dir = (shark.dir + 2) % 4;
                    }

                    shark.x += dx[shark.dir];

                    amount--;
                }
            }

            // 상어를 맵에 추가하기
            if (sharkMap[shark.y][shark.x].size())
            {
                if (shark.weight > sharkMap[shark.y][shark.x][0].weight)
                {
                    sharkMap[shark.y][shark.x][0] = shark; // 잡아 먹기
                }
            }
            else
            {
                sharkMap[shark.y][shark.x].push_back(shark);
            }
        }

        // cout << '\n';

        // for (int y = 0; y < r; y++)
        // {
        //     for (int x = 0; x < c; x++)
        //     {
        //         if (sharkMap[y][x].size())
        //         {
        //             cout << sharkMap[y][x][0].weight << ' ';
        //         }
        //         else
        //         {
        //             cout << "- ";
        //         }
        //     }

        //     cout << '\n';
        // }

        sharkVec.clear();

        pos++;   
    }

    cout << res;

    return 0;
}