
#include <iostream>
#include <chrono>

using namespace std;

// Using long double for high precision and fast arithmetic
typedef long double ld;

ld calculate(ld iterations, ld param1, ld param2) {
    ld result = 0.0;
    for (ld i = 1.0; i <= iterations; i++) {
        ld j = i * param1 - param2;
        result -= 1.0 / j;
        j = i * param1 + param2;
        result += 1.0 / j;
    }
    return result * param1 * 4.0;
}

int main() {
    // Initialize timer
    auto start_time = chrono::high_resolution_clock::now();

    // Calculate and print result
    ld result = calculate(100000000, 4.0, 1.0);
    cout << setprecision(12) << "Result: " << result << endl;
    cout << setprecision(6) << "Execution Time: "
         << chrono::duration_cast<chrono::microseconds>(chrono::high_resolution_clock::now() - start_time).count()
         << " microseconds" << endl;

    return 0;
}
