//
//  MultipleThreadSort.c
//  sort
//
//  Created by steveluccy on 11/28/20.
//

#include "MultipleThreadSort.h"

#define NTHR 8
#define NUMNUM 8000L
#define THUM (NUMNUM/NTHR)

long nums[NUMNUM];
long snums[NUMNUM];

pthread_barrier_t b;

int complong(const void *arg1,const void *arg2) {
    
    long l1 = *(long *)arg1;
    long l2 = *(long *)arg2;
    
    if (l1==l2) {
        return 0;
    } else if (l1 < l2) {
        return -1;
    } else {
        return 1;
    }
}

void *thr_fn(void *arg) {
    
    long idx = (long)arg;
    heapsort(&nums[idx], THUM, sizeof(long), complong);
    pthread_barrier_wait(&b);//执行到这里,如果其他线程没有执行完毕,该线程进入休眠.
    return (void *)0;
}
void merge() {
    long idx[NTHR];//保存排序好的数组的起始位置
    long i,minidx = 0,sidx,num;
    for (i=0; i<NTHR; i++) {
        idx[i] = i*THUM;
    }
    for (sidx=0; sidx<NUMNUM; sidx++) {
        num = 1<<31;
        // 找出8个排序好的数组中的最小的一个数,将其index
        for (i=0; i<NTHR; i++) {
            // idx[i]< (i+1)*THUM 保证是同一个分组中的数据 避免不同分组的数相互比较
            if ((idx[i]<(i+1)*THUM) && nums[idx[i]] < num) {
                num = nums[idx[i]];
                minidx = i;
                
            }
        }
        snums[sidx] = nums[idx[minidx]];
        idx[minidx]++;//这个地方的++操作会导致最后一个数据和其他数组的数据比较
        
    }
}

void TestMultipleThreadSort() {
    unsigned long i;
    struct timeval start,end;
    long long startusec,endusec;
    double elapsed;
    int err;
    pthread_t tid;
    
    
    srandom(1);
    for (i=0; i<NUMNUM; i++) {
        nums[i]=random();
    }
    gettimeofday(&start, NULL);
    pthread_barrier_init(&b, NULL, NTHR+1);
    for (i =0; i<NTHR; i++) {
        err = pthread_create(&tid, NULL, thr_fn, (void *)(i*THUM));
        if (err != 0) {
            printf("cant create pthread");
        }
    }
    pthread_barrier_wait(&b);
    merge();
    gettimeofday(&end, NULL);
    
    
    startusec = start.tv_sec * 1000000+start.tv_usec;
    endusec = end.tv_sec * 1000000+end.tv_usec;
    elapsed = (double)(endusec-startusec)/1000000.0;
    printf("sort took %.4f seconds\n",elapsed);
    for (i=0; i<NUMNUM; i++) {
        printf("%ld ",snums[i]);
        
    }
    
}
