//
// Created by Daniel Bulhosa Solorzano on 1/6/21.
//
#include <vector>
#include <algorithm>
#include "median.h"

double median(std::vector<double> v) {
    sort(v.begin(), v.end());
    std::vector<double>::size_type size = v.size(), mid = v.size() / 2;
    double med = (size % 2 == 0) ? (v[mid - 1] + v[mid]) / 2 : v[mid];
    return med;
}
