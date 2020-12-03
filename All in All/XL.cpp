#include <iostream>
#include <string>
#include <cassert>
using namespace std;

void KMPStrMatching(string S, string P, int *N, int &start, int &len)
{
	int j = 0;			   // 模式的下标变量
	int i = 0;			   // 目标的下标变量
	int pLen = P.length(); // 模式的长度
	int tLen = S.length(); // 目标的长度

	while (j < pLen && i < tLen)
	{ // 反复比较，进行匹配
		if (j == -1 || S[i] == P[j])
			i++, j++;
		else
		{

			j = N[j];
		}
		if (j > len)
		{
			len = j;
			start = i - j;
		}
	}
}

int *findNext(string P)
{
	int j, k;
	int m = P.length();		// m为模式P的长度
	assert(m > 0);			// 若m＝0，退出
	int *next = new int[m]; // 动态存储区开辟整数数组
	assert(next != 0);		// 若开辟存储区域失败，退出
	next[0] = -1;
	j = 0;
	k = -1;
	while (j < m - 1)
	{
		if (k == -1 || P[k] == P[j])
		{
			j++;
			k++;
			next[j] = k;
		}
		else
			k = next[k]; //不等则采用 KMP 递归找首尾子串
	}
	return next;
}

int main()
{
	string s1;
	string s2;
	cin >> s1 >> s2;
	int istart = 0, ilen = 0;
	for (int i = 0; i < s2.length(); ++i)
	{
		int start = 0, len = 0;
		KMPStrMatching(s1, s2.substr(i), findNext(s2.substr(i)), start, len);
		if (ilen < len)
		{
			ilen = len;
			istart = start;
		}
	}

	cout << s1.substr(istart, ilen) << endl;
	system("pause");
	return 0;
}