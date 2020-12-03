#include <iostream>
#include <string>
#include <cassert>
using namespace std;

void KMPStrMatching(string S, string P, int *N, int &start, int &len)
{
	int j = 0;			   // ģʽ���±����
	int i = 0;			   // Ŀ����±����
	int pLen = P.length(); // ģʽ�ĳ���
	int tLen = S.length(); // Ŀ��ĳ���

	while (j < pLen && i < tLen)
	{ // �����Ƚϣ�����ƥ��
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
	int m = P.length();		// mΪģʽP�ĳ���
	assert(m > 0);			// ��m��0���˳�
	int *next = new int[m]; // ��̬�洢��������������
	assert(next != 0);		// �����ٴ洢����ʧ�ܣ��˳�
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
			k = next[k]; //��������� KMP �ݹ�����β�Ӵ�
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