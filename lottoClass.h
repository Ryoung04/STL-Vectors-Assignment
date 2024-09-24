#ifndef LOTTOCLASS_H
#define LOTTOCLASS_H

#include <vector>
#include <random>

class LottoNum {
public:
    // Constructor
    LottoNum(int num_spots);

    // Methods
    std::vector<int> drawWinningNumbers(int num_selected);

private:
    std::vector<int> numbers;
};

#endif 