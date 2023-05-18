#include <iostream>
#include <queue>

using namespace std;

#define MAXSIZE 256

class myHeap
{
    int* arr; 
    int heap_count;
public:
    myHeap()
    {
        arr = new int[MAXSIZE];
        heap_count = 0;
    }
    ~myHeap()
    {
        delete[] arr;
    }

    int size()
    {
        return heap_count;
    }

    // 먼저 데이터를 완전이진트리에 방식대로 넣은 후 MaxHeap정의대로 부모와 자식의 데이터를 바꾼다!

    void swap(int* a, int* b)
    {
        int temp = *a;
        *a = *b;
        *b = temp;
    }

    void push(int data) // 넣고 부모보다 클 경우 자리까지 변경해주는 함수
    {
        arr[++heap_count] = data; // 1번 인덱스가 루트로 지정했기 때문에 1번 인덱스에 데이터가 들어갈 수 있음

        int child = heap_count;
        int parent = child / 2;   // 부모 인덱스 계산

        while (child > 1 && arr[parent] < arr[child]) // child > 1 : 자기자신이 루트가 아니고 ,, arr[parent] < arr[child] : 자기 자신의 데이터가 부모보다 작을 때
        {
            swap(&arr[parent], &arr[child]);
            child = parent;
            parent = child / 2;
        }
    }
    // 
    int pop() // 가장 높은 값을
    {
        int result = arr[1];

        swap(&arr[1], &arr[heap_count]);
        --heap_count;

        // 자리 찾기
        int parent = 1;
        int child = parent * 2;
        if (child + 1 <= heap_count) // 오른쪽 자식도 존재한다는 의미
        {
            child = (arr[child] > arr[child + 1]) ? child : child + 1;
        }

        while (child <= heap_count && arr[parent] < arr[child])
        {
            swap(&arr[parent], &arr[child]);

            parent = child;
            child = child * 2;

            if (child + 1 <= heap_count) // 오른쪽 자식도 존재한다는 의미
            {
                child = (arr[child] > arr[child + 1]) ? child : child + 1;
            }
        }

        return result;
    }
};

int main()
{
    myHeap myheap;
    myheap.push(5);
    myheap.push(6);
    myheap.push(1);
    myheap.push(9);
    myheap.push(2);
    myheap.push(4);

    int heapSize = myheap.size();

    for (int i = 0; i < heapSize; ++i)
    {
        cout << myheap.pop() << endl;
    }

    


    return 0;
}