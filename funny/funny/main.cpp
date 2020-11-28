//
//  main.cpp
//  funny
//
//  Created by steveluccy on 11/28/20.
//

#include <stdio.h>
#include <iostream>
using namespace std;
#include "sqrt.h"

#include "compress.h"


void testsqrt() {
    double result;
    std::cout << "enter numer" <<endl;
    cin >> result;
    cout << mySqrt(result)<<endl;
}

void testCompress() {
    const char *src="aaewbbbbbbbbFccdd";
    char *result= (char *)malloc(sizeof(strlen(src)));
    printf("%s\n",compress(src,result));
}

int main() {
//    testsqrt();
    testCompress();
    return 0;
}
