#include<bits/stdc++.h>
#include "utils.h"
using namespace std;


void selection_sort(vector<int> &v){
    for(size_t i = 0; i< v.size(); ++i){
        int minimum = v[i];
        int min_index = i;
        for(size_t j=i+1; j<v.size(); ++j){
            if(v[j] < minimum){
                minimum = v[j];
                min_index = j;
            }
        }
        swap(v, i, min_index);
    }
}

int main(){
    // RANDOM, SORTED, REVERSE_SORTED, ALMOST_SORTED, SEMI_SORTED, CONSTANT, INCREASING, DECREASING
    // ALTERNATING, FEW_UNIQUE, RANDOM_WITH_DUPLICATES, SORTED_WITH_DUPLICATES, NEAR_DUPLICATES, ZIGZAG, EMPTY, SINGLE_ELEMENT
    // LARGE_GAPS, NEGATIVE_VALUES, MIXED_SIGN, PEAK, VALLEY, UNIFORMLY_DISTRIBUTED, NARROW_RANGE, PHONE_NUMBER_LIKE

    auto [v, type] = random_vector_generator(15, 1, 100, VectorType::PHONE_NUMBER_LIKE);
    cout << "Generated Vector (Type: " << type << "): " << endl;
    print(v);
    selection_sort(v);
    print(v);
}