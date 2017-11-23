#include "qs.h"

static const size_t QS_THRESHOLD = 5;

static void qs_ins(int* src, size_t c);
static void qs_rec(int* src, size_t lower, size_t upper);

void quicksort(int* src, size_t c) {
    qs_rec(src, 0, c - 1);
}

static void qs_swap(int* src, size_t i, size_t j) {
    int t = src[i];
    src[i] = src[j];
    src[j] = t;
}

static size_t qs_partition(int* src, size_t lower, size_t upper) {
    size_t size = upper - lower + 1;
    if (size <= 1) return lower;

    size_t pivot; // select pivot
    pivot = (lower + upper) / 2;

    qs_swap(src, pivot, upper); // move pivot to far right
    pivot = upper;

    size_t left = lower;
    for (size_t i = lower; i < upper; i++) {
        if (src[i] <= src[pivot]) {
            if (left != i) qs_swap(src, left, i);
            left++;
        }
    }
    qs_swap(src, left, pivot);
    
    return left;
}

static void qs_rec(int* src, size_t lower, size_t upper) {
    size_t m = qs_partition(src, lower, upper);
    size_t leftsize = m - lower,
        rightsize = upper - m;

    if (leftsize >= QS_THRESHOLD) qs_rec(src, lower, m - 1);
    else qs_ins(src + lower, leftsize);
    if (rightsize >= QS_THRESHOLD) qs_rec(src, m + 1, upper);
    else qs_ins(src + m + 1, rightsize);
}

void qs_ins(int* src, size_t c) {
    for (size_t i = 1; i < c; i++) {
        for (size_t j = i; j > 0; j--) {
            if (src[j - 1] > src[j]) {
                qs_swap(src, j - 1, j);
            } else break;
        }
    }
}