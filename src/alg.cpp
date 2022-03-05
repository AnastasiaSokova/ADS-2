// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
    if (n == 0) {
        return 1;
    } else if (n == 1) {
        return value;
    } else {
        return value * pown(value, n - 1);
    }
}


uint64_t fact(uint16_t n) {
    if (n <= 1) {
        return 1;
    } else {
        return fact(n - 1) * n;
    }
}

double calcItem(double x, uint16_t n) {
    return pown(x, n) / fact(n);
}

double expn(double x, uint16_t count) {
    if (count < 1) {
        return 1;
    } else {
        return calcItem(x, count) + expn(x, count - 1);
    }
}

double sinn(double x, uint16_t count) {
    double s;
    if (count == 1) {
        return x;
    } else {
        s = (pown(-1, count - 1) * calcItem(x, 2 * count - 1));
        return s + sinn(x, count - 1);
    }
}

double cosn(double x, uint16_t count) {
    double s;
    if (count == 1) {
        return 1;
    } else {
        s = (pown(-1, count - 1) * calcItem(x, 2 * count - 2));
        return s + cosn(x, count - 1);
    }
}
