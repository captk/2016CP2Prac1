/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: k
 *
 * Created on 2 August 2016, 3:26 PM
 */

#include <cstdlib>
#include <climits>
#include <iostream>

using namespace std;

long sumOfFactors(long n);
long power (int, int);

long power(int base, int power) {
    long result = 1;
    while (power--) {
        result *= base;
    }
    return result;
}

int main(int argc, char* argv[]) {
    const long limit = argc > 1 ? atoi(argv[1]) : LONG_MAX;
    long candidate;
    for (int n = 2; (candidate = power(2, n - 1)*(power(2, n) - 1)) < limit; n++) {
        if (sumOfFactors(candidate) == candidate) {
            cout << candidate << endl;
        }
    }
    cout << "That's all!";
}

long sumOfFactors(long n) {
    long total = 1;
    for (long factor = 2; factor * factor < n; factor++) {
        if (n % factor == 0) {
            total += factor + n / factor;
        }
    }
    return total;
}

