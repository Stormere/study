//
//  pthread_barrier.h
//  多线程排序
//
//  Created by 郜俊博 on 2017/5/21星期日.
//  Copyright © 2017年 郜俊博. All rights reserved.
//


// osx 没有实现pthread_barrier_t  手动实现

//pthread_barrier_t 是协调多个线程并行工作的同步机制.允许每个线程等待,直到所有的合作线程都到达某一点,然后从该点执行.


#ifdef __APPLE__

#ifndef PTHREAD_BARRIER_H_
#define PTHREAD_BARRIER_H_

#include <pthread.h>
#include <errno.h>

typedef int pthread_barrierattr_t;
typedef struct
{
    pthread_mutex_t mutex;
    pthread_cond_t cond;
    int count;
    int tripCount;
} pthread_barrier_t;


int pthread_barrier_init(pthread_barrier_t *barrier, const pthread_barrierattr_t *attr, unsigned int count);

int pthread_barrier_destroy(pthread_barrier_t *barrier);


int pthread_barrier_wait(pthread_barrier_t *barrier);


#endif // PTHREAD_BARRIER_H_
#endif // __APPLE__
