// Copyright 2026

#include "alg.h"

int countPairs1(int *arr, int len, int value) {
    int count = 0;

    for (int i = 0; i < len; ++i) {
        for (int j = i + 1; j < len; ++j) {
            if (arr[i] + arr[j] == value) {
                ++count;
            }
        }
    }

    return count;
}

int countPairs2(int *arr, int len, int value) {
    int count = 0;

    for (int i = 0; i < len; ++i) {
        for (int j = i + 1; j < len; ++j) {
            int sum = arr[i] + arr[j];

            if (sum > value) {
                break;
            }

            if (sum == value) {
                ++count;
            }
        }
    }

    return count;
}

int binarySearch(int *arr, int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid;
        }

        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}

int countPairs3(int *arr, int len, int value) {
    int count = 0;

    for (int i = 0; i < len - 1; ++i) {
        int target = value - arr[i];

        int pos = binarySearch(arr, i + 1, len - 1, target);

        if (pos == -1) {
            continue;
        }

        int left = pos;
        int right = pos;

        while (left > i + 1 && arr[left - 1] == target) {
            --left;
        }

        while (right < len - 1 && arr[right + 1] == target) {
            ++right;
        }

        count += right - left + 1;
    }

    return count;
}
