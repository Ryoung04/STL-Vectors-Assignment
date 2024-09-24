/*******************************************
*
* Author: Reise Young
* Student ID: 1239147
* Assignment: HW05
* Class: CS1C
* Section: 19710
* Last Modified: September 19, 2024
* 
* PRECONDITIONS: 
*  The `Lotto()` function requires two valid integer inputs: num_spots (the       *  total number of spots in the lottery) and 
*  num_selected (the number of winning numbers to be drawn). num_selected  
*  must be less than or equal to num_spots. 
*  The code assumes that the srand() function is called once to seed the random   *  number generator for consistent results.
* 
* POSTCONDITIONS:
*  The Lotto() function returns a vector of integers containing num_selected 
*  unique random numbers between 1 and num_spots, sorted in ascending order. The 
*  function does not modify any external variables or have any side effects 
*  other than returning the vector of winning numbers. 
*
*******************************************/

#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib> 
#include <random> // For std::shuffle

using namespace std;

// Class Declarations
vector<int> Lotto(int num_spots, int num_selected) {
  vector<int> all_numbers;
  vector<int> winners;

  // Generate the possible numbers
  for (int i = 1; i <= num_spots; ++i) {
    all_numbers.push_back(i);
  }

  // Shuffle the numbers randomly (std::shuffle)

  srand(time(0)); // Seed the random number generator  

  random_device rd; // Obtain a random number from the hardware

  mt19937 gen(rd()); // Seed the generator

  shuffle(all_numbers.begin(), all_numbers.end(), gen); // Shuffle the numbers

  // Get the selected numbers
  for (int i = 0; i < num_selected; ++i) {
    winners.push_back(all_numbers[i]);
  }

  // Sort the selected numbers
  sort(winners.begin(), winners.end());

  return winners;
}

// Main Function
int main() {
  vector<int> winners;
  winners = Lotto(51, 6);
  cout << "\033[2J\033[1;1H";
  cout << endl;
  cout << "-----------------------------" <<      endl;
  cout << "Num Spot: " << 51 << endl; // Print num_spots value
  cout << "Num Selected: " << 6 << endl; // Print num_selected value
  cout << "Winning numbers: ";
  for (int num : winners) {
    cout << num << " ";
  }
  cout << endl;
  cout << "-----------------------------" <<      endl;
  cout << endl;

  return 0;
}