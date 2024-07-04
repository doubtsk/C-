#include <stdio.h>
void InsertionSort(int *arr, int size) // 插入排序
{
    int i, j, tmp; // 定义i、j、tmp变量
    for (i = 1; i < size; i++)
    {
        if (arr[i] < arr[i - 1]) // 如果当前元素小于前一个元素
        {
            tmp = arr[i];                                // 将当前元素赋值给tmp
            for (j = i - 1; j >= 0 && arr[j] > tmp; j--) // 从后往前遍历数组，找到比tmp小的元素
            {
                arr[j + 1] = arr[j]; // 将找到的元素后移一位
            }
            arr[j + 1] = tmp; // 将tmp插入到找到的元素后面
        }
    }
}

void BubbleSort(int *arr, int size) // 冒泡排序
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

void insertionSort(int *arr, int size) // 选择排序
{
    int i, j, tmp;
    for (i = 1; i < size; i++) // 简单的自增
    {
        tmp = arr[i];               // 把i号的变量赋值给临时变量
        j = i - 1;                  // 这就不需要注释了吧？？
        if (j >= 0 && arr[j] > tmp) // 当满足了j>0且这个元素比tmp大时
        {
            arr[j + 1] = arr[j]; // 简单的交换变量操作
            j = j - 1;           // j自减
        }
        arr[j + 1] = tmp; // 把tmp赋值给j+1号元素
    }
}

void ShellSort(int *arr, int size) // 希尔排序
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

void mergeSort(int *arr, int left, int right) // 最终调用的是这个函数，arr不用解释，left永远是0，right代表的是这个数组的长度，即"arr[9]"方括号里面的数字
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        // 递归地将数组分为两半进行排序
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // 合并两个已排序的子数组
        merge(arr, left, mid, right);
    }
}

void merge(int *arr, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // 创建临时数组
    int L[n1], R[n2];

    // 复制数据到临时数组
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // 合并临时数组回原数组
    int i = 0;    // 初始索引第一个子数组
    int j = 0;    // 初始索引第二个子数组
    int k = left; // 初始索引合并后的子数组

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

    // 拷贝L[]的剩余元素
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    // 拷贝R[]的剩余元素
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
