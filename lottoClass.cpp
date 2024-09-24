#include "lottoClass.h"
#include <algorithm>
#include <ctime> 
#include <cstdlib> 

LottoNum::LottoNum(int num_spots) {
    for (int i = 1; i <= num_spots; ++i) {
        numbers.push_back(i);
    }
}

std::vector<int> LottoNum::drawWinningNumbers(int num_selected) {
    std::vector<int> winners;

    // Shuffle the numbers randomly (std::shuffle)
    std::random_device rd; // obtain a random number from the hardware
    std::mt19937 gen(rd()); // seed the generator
    std::shuffle(numbers.begin(), numbers.end(), gen); // Shuffle the numbers

    // Get the selected numbers
    for (int i = 0; i < num_selected; ++i) {
        winners.push_back(numbers[i]);
    }

    // Sort the selected numbers
    std::sort(winners.begin(), winners.end());

    return winners;
}