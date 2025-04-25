
#include <iostream>
#include <iomanip>
#include <chrono>

double calculate(long long iterations, int param1, int param2) {
    double result = 1.0;
    for (long long i = 1; i <= iterations; ++i) {
        double j = static_cast<double>(i * param1 - param2);
        result -= (1/j);
        j = static_cast<double>(i * param1 + param2);
        result += (1/j);
    }
    return result;
}

int main() {
    using namespace std::chrono;
    
    auto start_time = high_resolution_clock::now();
    double result = calculate(100000000LL, 4, 1) * 4;
    auto end_time = high_resolution_clock::now();
    
    duration<double> exec_time = end_time - start_time;
    
    std::cout << std::fixed << std::setprecision(12);
    std::cout << "Result: " << result << "\n";
    std::cout << "Execution Time: " << exec_time.count() << " seconds\n";
    
    return 0;
}
