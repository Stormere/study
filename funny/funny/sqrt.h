/*************************************************************************
  > File Name   : mySqrt.cpp
  > Author      : junbo
  > Mail        : djssunday@gmail.com
  > Created Time: 六  9/23 13:56:56 2017
 ************************************************************************/

#include <stdio.h>
#include <assert.h>

/**
 计算平方根
 */
double mySqrt(double number) {
    assert(number>=0);
    double left = 0;
    double right = number>1?number:1;
    double result = 0;
    while(1) {
        result = (left+right)/2;
        if(result*result>number) {
            right=result;
            continue;
        }
        if(result*result < number) {
            if(number-result*result<0.000001){
                break;
            }
            else {
                left = result;
                continue;
            }
        }

        if(result*result==number) {
            break;
        }
    }
    return result;
}


double sqrtR(double left,double right,double number,double t) {
    double result = (left+right)/2;
    if(result*result > number) return sqrtR(left, result, number, t);
    if (result*result<=number) {
        if (number-result*result<t) {
            return result;
        } else {
            return sqrtR(result, right, number, t);
        }
    }
    return result;
}

double mySqrtR(double number) {

    return sqrtR(0, number>1?number:1, number, 0.000001);
}




