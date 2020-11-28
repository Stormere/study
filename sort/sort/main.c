//
//  main.c
//  sort
//
//  Created by steveluccy on 11/28/20.
//

#include <stdio.h>
#include "MultipleThreadSort.h"

/*
 
 In-place sort（不占用额外内存或占用常数的内存）：插入排序、选择排序、冒泡排序、堆排序、快速排序。
 Out-place sort：归并排序、计数排序、基数排序、桶排序。
 
 stable sort：插入排序、冒泡排序、归并排序、计数排序、基数排序、桶排序。
 unstable sort：选择排序(5 8 5 2 9)、快速排序、堆排序。
 
 */

/**
 交换数据
 */
void DataSwap(int* data1, int* data2)
{
    int temp = *data1;
    *data1 = *data2;
    *data2 = temp;
}
void func(int *low,int*high) {
    while (low < high ) {
        while (*low==0) {
            low++;
        }
        while (*high==1) {
            high--;
        }
        if (low>high) {
            break;
        }
        DataSwap(low, high);
        low++;high--;
    }
}


// 插入排序
/*
 
 特点：stable sort、In-place sort
 最优复杂度：当输入数组就是排好序的时候，复杂度为O(n)，而快速排序在这种情况下会产生O(n^2)的复杂度。
 最差复杂度：当输入数组为倒序时，复杂度为O(n^2)
 插入排序比较适合用于“少量元素的数组”。
 
 其实插入排序的复杂度和逆序对的个数一样，当数组倒序时，逆序对的个数为n(n-1)/2，因此插入排序复杂度为O(n^2)。
 **/
void insert_sort(int a[],int n) {
    for (int i=0; i<n; i++) {
        if (a[i] < a[i-1]) {
            int num = a[i];// 保存最小的值
            int j=i;
            while (j>=1&&a[j-1]>num) {
                a[j]=a[j-1];
                j--;
            }
            a[j] = num;
        }
    }
}

//选择排序
/**
 特性：In-place sort，unstable sort。
 思想：每次找一个最小值。
 最好情况时间：O(n^2)。
 最坏情况时间：O(n^2)。
 */
void chose_sort(int a[],int num) {
    for (int i=0; i<num-1; i++) {
        for (int j=1+i; j<num; j++) {
            if (a[i]>a[j]) {
                DataSwap(&a[i], &a[j]);
                
                
            }
        }
    }
}

// 冒泡排序

/**
 特点：stable sort、In-place sort
 思想：通过两两交换，像水中的泡泡一样，小的先冒出来，大的后冒出来。
 最坏运行时间：O(n^2)
 最佳运行时间：O(n^2)（当然，也可以进行改进使得最佳运行时间为O(n)）
 */

void bubble_sort(int a[],int num) {
    for (int i=0; i<num-1; i++) {
        for (int j=0; j<num-i-1; j++) {
            if (a[j]>a[j+1]) {
                DataSwap(&a[j], &a[j+1]);

            }
        }
    }
}

// 快速排序
void quick_sort(int *a, int left, int right)
{
    if(left >= right)/*如果左边索引大于或者等于右边的索引就代表已经整理完成一个组了*/
    {
        return ;
    }
    int i = left;
    int j = right;
    int key = a[left];
    
    while(i < j)                               /*控制在当组内寻找一遍*/
    {
        while(i < j && key <= a[j])
        /*而寻找结束的条件就是，1，找到一个小于或者大于key的数（大于或小于取决于你想升
         序还是降序）2，没有符合条件1的，并且i与j的大小没有反转*/
        {
            j--;/*向前寻找*/
        }
        
        a[i] = a[j];
        /*找到一个这样的数后就把它赋给前面的被拿走的i的值（如果第一次循环且key是
         a[left]，那么就是给key）*/
        
        while(i < j && key >= a[i])
        /*这是i在当组内向前寻找，同上，不过注意与key的大小关系停止循环和上面相反，
         因为排序思想是把数往两边扔，所以左右两边的数大小与key的关系相反*/
        {
            i++;
        }
        
        a[j] = a[i];
    }
    
    a[i] = key;/*当在当组内找完一遍以后就把中间数key回归*/
    quick_sort(a, left, i - 1);/*最后用同样的方式对分出来的左边的小组进行同上的做法*/
    quick_sort(a, i + 1, right);/*用同样的方式对分出来的右边的小组进行同上的做法*/
    /*当然最后可能会出现很多分左右，直到每一组的i = j 为止*/
}


int main(int argc,char *argv[]) {
    
    TestMultipleThreadSort();
    
    int a[] = {49,38,65,9007,76,13,27,59};
    int b[90]={0,1,0,1,0,1,1,0,1,0,0,0,0,0,0,1,1,1,0,1,0,1,0,1,1,0,1,0,0,0,0,0,0,1,1,1,0,1,0,1,0,1,1,0,1,0,0,0,0,0,0,1,
                1,1,0,1,0,1,0,1,1,0,1,0,0,0,0,0,0,1,1,1,0,1,0,1,0,1,1,0,1,0,0,0,0,0,0,1,1,1};
    insert_sort(a,8);
    
    for(int i=0;i<8;i++) {
        printf("%d\n",a[i]);
    }
    
    func(b, b+89);
    for (int i=0; i<89; i++) {
       printf("%d\n",b[i]);
    }
    return 0;
}

