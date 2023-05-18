#include <iostream>
#include <queue>
#include <utility> // pair 키워드를 사용하기 위해 추가한 헤더파일
#include <string>

using namespace std;

struct myStudent
{
	string name;
	int kor;
	int math;
	int sci;

public:
	myStudent(string _name, int _kor,int _math, int _sci)
	{
		name = _name;
		kor = _kor;
		math = _math;
		sci = _sci;
	}
};

struct cmp
{
	bool operator()(myStudent a, myStudent b)
	{
		// 오름차순 정렬
		//return a.kor > b.kor;

		// 내림차순 정렬
		//return a.kor > b.kor;

		// kor, math, sci 의 총점 리턴
		return a.kor + a.math + a.sci < b.kor + b.math + b.sci;
	}
};


int main()
{
	// priority_queue<"자료형" , "구현체", "비교연산자"> 객체명;
	priority_queue<myStudent, vector<myStudent>, cmp> PQ;

	PQ.emplace("영수", 55, 77, 90);
	PQ.emplace("영철", 49, 75, 32);
	PQ.emplace("영식", 35, 67, 49);
	PQ.emplace("영호", 98, 7, 50);
	// 우선순위가 높은 것을 명확히 하기가 어려움

	// struct(구조체)에서 우선순위를 정하지 않음
	// >> 구조체에서 우선순위를 설정하는 방법

	while (!PQ.empty())
	{
		auto k = PQ.top();
		cout << k.name << "  " << k.kor + k.math + k.sci << endl;
		PQ.pop();
	}

	return 0;
}