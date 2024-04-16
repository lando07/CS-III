#include "util.h"
#include <algorithm>
#include <cmath>
#include <vector>

void calculate(vector<double> &nums, double *mean, double *min, double *max) {

  // Enter your code here
  double sum = 0;
  for (double i : nums) {
    *max = std::max(i, *max);
    sum += i;
    *min = std::min(i, *min);
  }
  *mean = sum / nums.size();
}

int main() {
  // Enter your code here
  vector<double> nums;

  while (true) {
    double n = readDouble("Please enter a positive number(-1 to quit): ");
    if (n == -1) {
      break;
    } else {
      nums.push_back(n);
    }
  }
  double *mean = new double(0);
  double *min = new double(nums[0]);
  double *max = new double(nums[0]);
  calculate(nums, mean, min, max);
  cout << "Min: " << *min << "\nMax: " << *max << "\nMean: " << *mean << endl;
  return 0;
}
