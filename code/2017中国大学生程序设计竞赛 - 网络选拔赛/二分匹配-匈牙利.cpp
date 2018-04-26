/*
#include<iostream>
#include<algorithm>
#include<cmath>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
using namespace std;
#pragma warning(disable:4996)
bool map[3005][3005];
int num[3005][3005];
int cnt[3005];
bool yes[3005];

int main()
{
		freopen("input.txt","r",stdin);
	freopen("w.txt","w",stdout);
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n;
		int a;
		scanf("%d", &n);
		memset(num, 0, sizeof(num));
		memset(yes, 0, sizeof(yes));
		memset(num, 0, sizeof(num));
		memset(cnt, 0, sizeof(cnt));
		int tot=0;
		for (int i = 1;i < n;i++)
		{
			for (int j = i + 1;j <= n;j++)
			{
				scanf("%d", &a);
				map[j][i] = map[i][j] = a;
				if (map[i][j] == 0)
				{
					if (yes[i] == 0)
					{
						num[i][cnt[i]] = j;
						cnt[i]++;
					}
					if (cnt[i] >= 3)
						yes[i] = 1;
					if (yes[j] == 0)
					{
						num[j][cnt[j]] = i;
						cnt[j]++;
					}
					if (cnt[j] >= 3)
						yes[j] = 1;
				}
				else
					tot++;
			}
		}
		int f = 1;
		for (int i = 1;i <= n;i++)
		{
			if (yes[i] == 1)
				f = 0;
			else if (cnt[i] == 2)
			{
				if (map[num[i][0]][num[i][1]] == 0)
					f = 0;
			}
			else if (3 * tot >= 2 * n*(n - 1))
				f = 0;
		}
		if (f == 0)
			printf("Bad Team!\n");
		else
			printf("Great Team!\n");
	}
}*/
#include<iostream>
#include<algorithm>
#include<cmath>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
using namespace std;
#pragma warning(disable:4996)
bool map[3005][3005];
int num[3005][3];
int cnt[3005];
int num2[3005][3005];
int cnt2[3005];
bool yes[3005];
int main()
{
	int T;
		freopen("input.txt","r",stdin);
	freopen("w.txt","w",stdout);
	scanf("%d", &T);
	while (T--)
	{
		int n;
		int a;
		scanf("%d", &n);
		memset(num, 0, sizeof(num));
		memset(yes, 0, sizeof(yes));
		memset(num, 0, sizeof(num));
		memset(cnt, 0, sizeof(cnt));
		int tot = 0;
		for (int i = 1;i < n;i++)
		{
			for (int j = i + 1;j <= n;j++)
			{
				scanf("%d", &a);
				map[j][i] = map[i][j] = a;
				if (map[i][j] == 0)
				{
					if (yes[i] == 0)
					{
						num[i][cnt[i]] = j;
						cnt[i]++;
					}
					if (cnt[i] >= 3)
						yes[i] = 1;
					if (yes[j] == 0)
					{
						num[j][cnt[j]] = i;
						cnt[j]++;
					}
					if (cnt[j] >= 3)
						yes[j] = 1;
				}
				else
				{
					tot++;
					num2[i][cnt[i]] = j;
					cnt2[i]++;
					num2[j][cnt[j]] = i;
					cnt2[j]++;
				}
			}
		}
		int f = 1;
		for (int i = 1;i <= n;i++)
		{
			if (yes[i] == 1)
				f = 0;
			else if (cnt[i] == 2)
			{
				if (map[num[i][0]][num[i][1]] == 0)
					f = 0;
			}
			else
			{
				for (int j = i + 1;j <= n;j++)
				{
					for (int k = 0;k < cnt2[j];k++)
					{
						if (map[i][num2[j][k]] == 1)
						{
							f = 0;
							break;
						}
					}
				}
			}
		}
		if (f == 0)
			printf("Bad Team!\n");
		else
			printf("Great Team!\n");
	}
}
