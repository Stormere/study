//
//  main.cpp
//  interview
//
//  Created by steveluccy on 11/28/20.
//


#include <iostream>
#include <cmath>
#define MAX(a,b) ((a>b)?a:b)
#define MIN(a,b) ((a>b)?b:a)

using namespace std;

// 假设c 最大
void resolve() {
   int c = 1;// 假设最大是1岁
   int a = 1;
   int b = 1;
   for (c = 1; c < 37; c++) {
       if (36 % c != 0) continue;

       int ab = 36 / c; // ab为 a和b年龄的积
       int tmp = (int)sqrt(ab);//ab 开方后的数
       if (tmp > c) continue;
       else {
           // 对ab 分解为两个数的积,最大的因数不能超过 c
           for (int i = 1; i <= (int)sqrt(ab); i++) {
               if (ab%i != 0) continue;
               a = ab / i;
               b = ab / a;
               if (MAX(a, b) >= c) continue;
               else {
                   printf("%d %d %d\n", c, MAX(a, b), MIN(a, b));
               }
           }
       }
   }
}


int main()
{
   resolve();
    
   return 0;
}

