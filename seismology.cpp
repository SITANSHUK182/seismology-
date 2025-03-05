#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iomanip>

int main() {
    int N;
    std::cout << "Enter number of days: ";
    std::cin >> N;

    std::vector<double> magnitudes(N);
    for (int i = 0; i < N; ++i) {
        std::cout << "Enter magnitude for day " << i + 1 << ": ";
        std::cin >> magnitudes[i];
    }

    double highest = *std::max_element(magnitudes.begin(), magnitudes.end());

    double average = std::accumulate(magnitudes.begin(), magnitudes.end(), 0.0) / N;

    
    std::vector<int> highRiskDays;
    for (int i = 0; i < N; ++i) {
        if (magnitudes[i] > average) {
            highRiskDays.push_back(i + 1);
        }
    }

    std::cout << "Highest Magnitude: " << highest << std::endl;
    std::cout << "Average Magnitude: " << std::fixed << std::setprecision(2) << average << std::endl;
    std::cout << "High-Risk Days: ";
    for (int day : highRiskDays) {
        std::cout << day << " ";
    }
    std::cout << std::endl;

    return 0;
}
