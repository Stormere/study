//
//  MultipleThreadSort.h
//  多线程排序
//
//  Created by 郜俊博 on 2017/5/21星期日.
//  Copyright © 2017年 郜俊博. All rights reserved.
//

#ifndef MultipleThreadSort_h
#define MultipleThreadSort_h

#include <stdio.h>
#include <pthread.h>
#include <ourheader.h>
#include <sys/time.h>
#include "pthread_barrier.h" // osx 没有实现pthread_barrier_t  手动实现





#ifdef SOLARIS
#define heapsort qsort
#else

extern int heapsort(void *,size_t,size_t,int(*)(const void *, const void *));


#endif

int complong(const void *arg1,const void *arg2);

void *thr_fn(void *arg);
void merge(void);

void TestMultipleThreadSort(void);

#endif /* MultipleThreadSort_h */
