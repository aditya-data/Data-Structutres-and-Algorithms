#include <bits/stdc++.h>
#include "utils.h"
using namespace std;

void insertion_sort(vector<int> &v)
{
    for (size_t j = 1; j < v.size(); ++j)
    {
        int key = v[j];
        size_t k = j;
        while (k > 0 && v[k - 1] > key)
        {
            v[k] = v[k - 1];
            --k;
        }
        v[k] = key;
    }
}

int main()
{
    // RANDOM, SOTED, REVERSE_SORTED, ALMOST_SORTED, SEMI_SORTED, CONSTANT, INCREASING, DECREASING
    // ALTERNATING, FEW_UNIQUE, RANDOM_WITH_DUPLICATES, SORTED_WITH_DUPLICATES, NEAR_DUPLICATES, ZIGZAG, EMPTY, SINGLE_ELEMENT
    // LARGE_GAPS, NEGATIVE_VALUES, MIXED_SIGN, PEAK, VALLEY, UNIFORMLY_DISTRIBUTED, NARROW_RANGE, PHONE_NUMBER_LIKE

    auto [v, type] = random_vector_generator(15, 1, 100, VectorType::NARROW_RANGE);
    cout << "Generated Vector (Type: " << type << "): " << endl;
    print(v);
    insertion_sort(v);
    print(v);
}