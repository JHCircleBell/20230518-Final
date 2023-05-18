#include <iostream>
#include <queue>
#include <utility> // pair 키워드를 사용하기 위해 추가한 헤더파일

using namespace std;


int main()
{
	// 이름과 점수를 같이 관리하는 우선순위 queue
	priority_queue<pair<string, int>> priQue;

	priQue.emplace("영희", 24);
	priQue.push(make_pair("영철", 89)); // 스택에 매게파라미터를 값 복사를 해야해서 메모리가 더 많이 사용됨


	while (!priQue.empty())
	{
		auto p = priQue.top();
		cout << p.first << "   " << p.second << endl;
		priQue.pop();
	}

	return 0;
}