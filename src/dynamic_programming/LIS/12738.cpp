#include <bits/stdc++.h>

using namespace std;

// Time Complexity : O(NlogN)
//
// 최장 길이만 구함
// 7
// 10 20 15 30 20 50 12
// 1 : 10 0 0 0 0 0 0 
// 2 : 10 20 0 0 0 0 0
// 2 : 10 15 0 0 0 0 0
// 3 : 10 15 30 0 0 0 0
// 3 : 10 15 20 0 0 0 0
// 4 : 10 15 20 50 0 0 0
// 4 : 10 12 20 50 0 0 0 <- 15가 12로 바뀜

constexpr int INIT_ELEM = -1'999'999'999;

int n;

int arr[1'000'004];
int lis[1'000'004];

int len;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    fill(lis, lis + 1'000'004, INIT_ELEM);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        int* lower = lower_bound(lis, lis + len, arr[i]);

        // 새로운 최장 길이를 찾으면
        if (INIT_ELEM == *lower)
        {
            len++;
        }

        *lower = arr[i];

        // cout << len << " : ";

        // for (int j = 0; j < n; j++)
        // {
        //     cout << lis[j] << ' ';
        // }

        // cout << '\n';
    }

    cout << len;

    return 0;
}