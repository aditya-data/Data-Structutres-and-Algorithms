#ifndef UTILS_H
#define UTILS_H

#include <vector>
#include <string>
#include <utility>  // For std::pair

enum class VectorType {
    RANDOM,
    SORTED,
    REVERSE_SORTED,
    ALMOST_SORTED,
    SEMI_SORTED,
    CONSTANT,
    INCREASING,
    DECREASING,
    ALTERNATING,
    FEW_UNIQUE,
    RANDOM_WITH_DUPLICATES,
    SORTED_WITH_DUPLICATES,
    NEAR_DUPLICATES,
    ZIGZAG,
    EMPTY,
    SINGLE_ELEMENT,
    LARGE_GAPS,
    NEGATIVE_VALUES,
    MIXED_SIGN,
    PEAK,
    VALLEY,
    UNIFORMLY_DISTRIBUTED,
    NARROW_RANGE,
    PHONE_NUMBER_LIKE
};

std::pair<std::vector<int>, std::string> random_vector_generator(int size = 10, int min_val = 0, int max_val = 100, VectorType type = VectorType::RANDOM);

void swap(std::vector<int>& v, int i, int j);
void print(std::vector<int>& v);

#endif  // UTILS_H
