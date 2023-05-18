#include <iostream>
#include <queue>
#include <utility> // pair Ű���带 ����ϱ� ���� �߰��� �������

using namespace std;


int main()
{
	// �̸��� ������ ���� �����ϴ� �켱���� queue
	priority_queue<pair<string, int>> priQue;

	priQue.emplace("����", 24);
	priQue.push(make_pair("��ö", 89)); // ���ÿ� �Ű��Ķ���͸� �� ���縦 �ؾ��ؼ� �޸𸮰� �� ���� ����


	while (!priQue.empty())
	{
		auto p = priQue.top();
		cout << p.first << "   " << p.second << endl;
		priQue.pop();
	}

	return 0;
}