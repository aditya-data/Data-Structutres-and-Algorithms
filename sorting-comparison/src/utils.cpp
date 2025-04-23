#include "utils.h"
#include <algorithm>
#include <iostream>
#include <random>
#include <functional>

using namespace std;

pair<vector<int>, string> random_vector_generator(int size, int min_val, int max_val, VectorType type) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(min_val, max_val);

    vector<int> v;
    string label;

    switch (type) {
        case VectorType::RANDOM:
            for (int i = 0; i < size; ++i) v.push_back(dist(gen));
            label = "Random";
            break;

        case VectorType::SORTED:
            for (int i = 0; i < size; ++i) v.push_back(dist(gen));
            sort(v.begin(), v.end());
            label = "Sorted";
            break;

        case VectorType::REVERSE_SORTED:
            for (int i = 0; i < size; ++i) v.push_back(dist(gen));
            sort(v.begin(), v.end(), greater<>());
            label = "Reverse Sorted";
            break;

        case VectorType::ALMOST_SORTED:
            for (int i = 0; i < size; ++i) v.push_back(dist(gen));
            sort(v.begin(), v.end());
            if (size >= 10) shuffle(v.begin(), v.begin() + size / 10, gen);
            label = "Almost Sorted";
            break;

        case VectorType::SEMI_SORTED:
            for (int i = 0; i < size; ++i) v.push_back(dist(gen));
            sort(v.begin(), v.begin() + size / 2);
            sort(v.begin() + size / 2, v.end(), greater<>());
            label = "Semi Sorted";
            break;

        case VectorType::CONSTANT:
            v = vector<int>(size, dist(gen));
            label = "Constant";
            break;

        case VectorType::INCREASING:
            for (int i = 0; i < size; ++i) v.push_back(min_val + i);
            label = "Increasing";
            break;

        case VectorType::DECREASING:
            for (int i = size - 1; i >= 0; --i) v.push_back(min_val + i);
            label = "Decreasing";
            break;

        case VectorType::ALTERNATING:
            for (int i = 0; i < size; ++i)
                v.push_back((i % 2 == 0) ? dist(gen) : dist(gen) / 2);
            label = "Alternating";
            break;

        case VectorType::FEW_UNIQUE:
            for (int i = 0; i < size; ++i)
                v.push_back(dist(gen) % 3); // 0, 1, 2
            label = "Few Unique";
            break;

        case VectorType::RANDOM_WITH_DUPLICATES:
            for (int i = 0; i < size; ++i) v.push_back(dist(gen));
            label = "Random with Duplicates";
            break;

        case VectorType::SORTED_WITH_DUPLICATES:
            for (int i = 0; i < size; ++i) v.push_back(dist(gen));
            sort(v.begin(), v.end());
            for (int i = size / 2; i < size; ++i)
                v[i] = v[i / 2]; // Introduce duplicates
            label = "Sorted with Duplicates";
            break;

        case VectorType::NEAR_DUPLICATES:
            {
                int base = dist(gen);
                uniform_int_distribution<> offset(-2, 2);
                for (int i = 0; i < size; ++i) v.push_back(base + offset(gen));
                label = "Near Duplicates";
            }
            break;

        case VectorType::ZIGZAG:
            for (int i = 0; i < size; ++i)
                v.push_back((i % 2 == 0) ? i * 2 : max_val - i * 2);
            label = "ZigZag";
            break;

        case VectorType::EMPTY:
            label = "Empty";
            break;

        case VectorType::SINGLE_ELEMENT:
            v.push_back(dist(gen));
            label = "Single Element";
            break;

        case VectorType::LARGE_GAPS:
            for (int i = 0; i < size; ++i)
                v.push_back(dist(gen) * 10);
            label = "Large Gaps";
            break;

        case VectorType::NEGATIVE_VALUES:
            for (int i = 0; i < size; ++i)
                v.push_back(-abs(dist(gen)));
            label = "Negative Values";
            break;

        case VectorType::MIXED_SIGN:
            for (int i = 0; i < size; ++i)
                v.push_back(dist(gen) - (max_val - min_val) / 2);
            label = "Mixed Sign";
            break;

        case VectorType::PEAK:
            for (int i = 0; i < size / 2; ++i)
                v.push_back(i);
            for (int i = size / 2; i < size; ++i)
                v.push_back(size - i);
            label = "Peak";
            break;

        case VectorType::VALLEY:
            for (int i = 0; i < size / 2; ++i)
                v.push_back(size - i);
            for (int i = size / 2; i < size; ++i)
                v.push_back(i);
            label = "Valley";
            break;

        case VectorType::UNIFORMLY_DISTRIBUTED:
            for (int i = 0; i < size; ++i)
                v.push_back(min_val + ((max_val - min_val) * i) / size);
            shuffle(v.begin(), v.end(), gen);
            label = "Uniformly Distributed";
            break;
        
        case VectorType::NARROW_RANGE:
            {
                uniform_int_distribution<> small_range(0, 10);
                for (int i = 0; i < size; ++i)
                    v.push_back(small_range(gen));
                label = "Narrow Range";
            }
            break;
        
        case VectorType::PHONE_NUMBER_LIKE:
            for (int i = 0; i < size; ++i)
                v.push_back(8000000 + dist(gen) % 9000000);  // 4-digit numbers
            label = "Radix Friendly(PHONE_NUMBER_LIKE)";
            break;

    }


    return make_pair(v, label);
}

void swap(vector<int>& v, int i, int j) {
    int temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

void print(vector<int>& v) {
    for (int i : v) cout << i << " ";
    cout << endl;
}
