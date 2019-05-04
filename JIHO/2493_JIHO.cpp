#include <iostream>
#include <stack>

using namespace std;

/* 비어있다면 건물의 높이를 넣어줌, 0출력 비어있지 않다면 비교 그때의 top값과 비교를 해야함
만약 top이 더 크다면 그때 top의 번호 출력, break. 만약 더 크지 않다면 s.pop해줘서 비움 
비우고 비운 상태이므로 자신의 건물 번호를 푸쉬 어차피 자기가 더 크기 때문에 자신의 뒤에 있는 건물들은
자신의앞에 있는 애들을 거치기 전에 자신을 무조건 거치게 될 것이기 때문*/
struct building
{
	int height;
	int x;
};

int main()
{
	int n, a;
	stack <building> s; // 구조체 building 을 받음

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
		} // 비어있다면 푸쉬

	}
	return 0;
}