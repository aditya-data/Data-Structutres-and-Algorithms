#include<bits/stdc++.h>
#include "utils.h"
using namespace std;


void bubble_sort(vector<int> &v){
    for(size_t i= 0; i < v.size(); ++i){
        bool no_swap = true; // flag variable
        for(size_t j=i+1; j < v.size(); ++j){
            if (v[i] > v[j]){
                swap(v, i, j);
                no_swap = false;
            }
        }
        if (no_swap == true) {
            break;
        }   
    }
}

int main(){
    // RANDOM, SOTED, REVERSE_SORTED, ALMOST_SORTED, SEMI_SORTED, CONSTANT, INCREASING, DECREASING
    // ALTERNATING, FEW_UNIQUE, RANDOM_WITH_DUPLICATES, SORTED_WITH_DUPLICATES, NEAR_DUPLICATES, ZIGZAG, EMPTY, SINGLE_ELEMENT
    // LARGE_GAPS, NEGATIVE_VALUES, MIXED_SIGN, PEAK, VALLEY, UNIFORMLY_DISTRIBUTED, NARROW_RANGE, PHONE_NUMBER_LIKE

    auto [v, type] = random_vector_generator(15, 1, 100, VectorType::RANDOM);
    cout << "Generated Vector (Type: " << type << "): " << endl;
    print(v);
    bubble_sort(v);
    print(v);
}