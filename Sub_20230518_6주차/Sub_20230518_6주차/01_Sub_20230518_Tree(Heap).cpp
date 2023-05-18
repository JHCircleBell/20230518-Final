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

    // ���� �����͸� ��������Ʈ���� ��Ĵ�� ���� �� MaxHeap���Ǵ�� �θ�� �ڽ��� �����͸� �ٲ۴�!

    void swap(int* a, int* b)
    {
        int temp = *a;
        *a = *b;
        *b = temp;
    }

    void push(int data) // �ְ� �θ𺸴� Ŭ ��� �ڸ����� �������ִ� �Լ�
    {
        arr[++heap_count] = data; // 1�� �ε����� ��Ʈ�� �����߱� ������ 1�� �ε����� �����Ͱ� �� �� ����

        int child = heap_count;
        int parent = child / 2;   // �θ� �ε��� ���

        while (child > 1 && arr[parent] < arr[child]) // child > 1 : �ڱ��ڽ��� ��Ʈ�� �ƴϰ� ,, arr[parent] < arr[child] : �ڱ� �ڽ��� �����Ͱ� �θ𺸴� ���� ��
        {
            swap(&arr[parent], &arr[child]);
            child = parent;
            parent = child / 2;
        }
    }
    // 
    int pop() // ���� ���� ����
    {
        int result = arr[1];

        swap(&arr[1], &arr[heap_count]);
        --heap_count;

        // �ڸ� ã��
        int parent = 1;
        int child = parent * 2;
        if (child + 1 <= heap_count) // ������ �ڽĵ� �����Ѵٴ� �ǹ�
        {
            child = (arr[child] > arr[child + 1]) ? child : child + 1;
        }

        while (child <= heap_count && arr[parent] < arr[child])
        {
            swap(&arr[parent], &arr[child]);

            parent = child;
            child = child * 2;

            if (child + 1 <= heap_count) // ������ �ڽĵ� �����Ѵٴ� �ǹ�
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