#include <iostream>
#include <stack>

using namespace std;

/* ����ִٸ� �ǹ��� ���̸� �־���, 0��� ������� �ʴٸ� �� �׶��� top���� �񱳸� �ؾ���
���� top�� �� ũ�ٸ� �׶� top�� ��ȣ ���, break. ���� �� ũ�� �ʴٸ� s.pop���༭ ��� 
���� ��� �����̹Ƿ� �ڽ��� �ǹ� ��ȣ�� Ǫ�� ������ �ڱⰡ �� ũ�� ������ �ڽ��� �ڿ� �ִ� �ǹ�����
�ڽ��Ǿտ� �ִ� �ֵ��� ��ġ�� ���� �ڽ��� ������ ��ġ�� �� ���̱� ����*/
struct building
{
	int height;
	int x;
};

int main()
{
	int n, a;
	stack <building> s; // ����ü building �� ����

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> a;
		while (!s.empty())
		{
			if (s.top().height >= a)
			{
				cout << s.top().x << " ";
				s.push({ a,i });
				break;
			}
			s.pop();
		}
		if (s.empty())
		{
			cout << "0 ";
			s.push({ a,i });
		} // ����ִٸ� Ǫ��

	}
	return 0;
}