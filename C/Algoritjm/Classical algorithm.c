#include <stdio.h>
void InsertionSort(int *arr, int size) // ��������
{
    int i, j, tmp; // ����i��j��tmp����
    for (i = 1; i < size; i++)
    {
        if (arr[i] < arr[i - 1]) // �����ǰԪ��С��ǰһ��Ԫ��
        {
            tmp = arr[i];                                // ����ǰԪ�ظ�ֵ��tmp
            for (j = i - 1; j >= 0 && arr[j] > tmp; j--) // �Ӻ���ǰ�������飬�ҵ���tmpС��Ԫ��
            {
                arr[j + 1] = arr[j]; // ���ҵ���Ԫ�غ���һλ
            }
            arr[j + 1] = tmp; // ��tmp���뵽�ҵ���Ԫ�غ���
        }
    }
}

void BubbleSort(int *arr, int size) // ð������
{
    int i, j, tmp;
    for (i = 0; i < size; i++)
    {
        for (j = i - 1; j >= 0; j--)
        {
            if (arr[i] < arr[j])
            {
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
}

void insertionSort(int *arr, int size) // ѡ������
{
    int i, j, tmp;
    for (i = 1; i < size; i++) // �򵥵�����
    {
        tmp = arr[i];               // ��i�ŵı�����ֵ����ʱ����
        j = i - 1;                  // ��Ͳ���Ҫע���˰ɣ���
        if (j >= 0 && arr[j] > tmp) // ��������j>0�����Ԫ�ر�tmp��ʱ
        {
            arr[j + 1] = arr[j]; // �򵥵Ľ�����������
            j = j - 1;           // j�Լ�
        }
        arr[j + 1] = tmp; // ��tmp��ֵ��j+1��Ԫ��
    }
}

void ShellSort(int *arr, int size) // ϣ������
{
    int i, j, tmp, increment;
    for (increment = size / 2; increment > 0; increment /= 2)
    {
        for (i = increment; i < size; i++)
        {
            tmp = arr[i];
            for (j = i - increment; j >= 0 && tmp < arr[j]; j -= increment)
            {
                arr[j + increment] = arr[j];
            }
            arr[j + increment] = tmp;
        }
    }
}

void mergeSort(int *arr, int left, int right) // ���յ��õ������������arr���ý��ͣ�left��Զ��0��right��������������ĳ��ȣ���"arr[9]"���������������
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        // �ݹ�ؽ������Ϊ�����������
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // �ϲ������������������
        merge(arr, left, mid, right);
    }
}

void merge(int *arr, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // ������ʱ����
    int L[n1], R[n2];

    // �������ݵ���ʱ����
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // �ϲ���ʱ�����ԭ����
    int i = 0;    // ��ʼ������һ��������
    int j = 0;    // ��ʼ�����ڶ���������
    int k = left; // ��ʼ�����ϲ����������

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // ����L[]��ʣ��Ԫ��
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    // ����R[]��ʣ��Ԫ��
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
