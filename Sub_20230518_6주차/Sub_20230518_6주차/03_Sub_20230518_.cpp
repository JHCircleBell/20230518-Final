#include <iostream>
#include <queue>
#include <utility> // pair Ű���带 ����ϱ� ���� �߰��� �������
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
		// �������� ����
		//return a.kor > b.kor;

		// �������� ����
		//return a.kor > b.kor;

		// kor, math, sci �� ���� ����
		return a.kor + a.math + a.sci < b.kor + b.math + b.sci;
	}
};


int main()
{
	// priority_queue<"�ڷ���" , "����ü", "�񱳿�����"> ��ü��;
	priority_queue<myStudent, vector<myStudent>, cmp> PQ;

	PQ.emplace("����", 55, 77, 90);
	PQ.emplace("��ö", 49, 75, 32);
	PQ.emplace("����", 35, 67, 49);
	PQ.emplace("��ȣ", 98, 7, 50);
	// �켱������ ���� ���� ��Ȯ�� �ϱⰡ �����

	// struct(����ü)���� �켱������ ������ ����
	// >> ����ü���� �켱������ �����ϴ� ���

	while (!PQ.empty())
	{
		auto k = PQ.top();
		cout << k.name << "  " << k.kor + k.math + k.sci << endl;
		PQ.pop();
	}

	return 0;
}