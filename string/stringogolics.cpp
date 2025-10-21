#include <iostream>
#include <vector>
#include <string>
#include <numeric> // Required for std::gcd in C++17
#include <map>
#include <fstream>
#include <sstream>

class Stringoholics {
private:
    const int MOD = 1000000007;

    // Modular Exponentiation: calculates (base^exp) % mod
    long long power(long long base, long long exp) {
        long long res = 1;
        base %= MOD;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp /= 2;
        }
        return res;
    }

    // Rotates the string based on the cumulative rotation formula
    std::string rotateString(const std::string& A, int k) {
        std::string result = "";
        int length = A.length();
        if (length == 0) return "";
        
        long long total_rotation = (static_cast<long long>(k) * (k + 1)) / 2;
        
        for (int i = 0; i < length; i++) {
            result += A[(i + total_rotation) % length];
        }
        return result;
    }

public:
    int solve(const std::vector<std::string>& A) {
        int n = A.size();
        std::vector<long long> arr(n);

        // Find cycle length for each string by simulation
        for (int i = 0; i < n; i++) {
            const std::string& temp = A[i];
            int length = temp.length();
            for (int j = 1; j <= length * 2; j++) {
                if (temp == rotateString(temp, j)) {
                    arr[i] = j;
                    break;
                }
            }
        }

        // Use prime factorization to find the LCM of all cycle lengths
        // This map is local to the function to avoid state issues across test cases.
        std::map<long long, long long> maxPrimePowers;

        for (int i = 0; i < n; i++) {
            long long cycle = arr[i];
            for (long long j = 2; j * j <= cycle; j++) {
                if (cycle % j == 0) {
                    long long count = 0;
                    while (cycle % j == 0) {
                        cycle /= j;
                        count++;
                    }
                    if (maxPrimePowers.find(j) == maxPrimePowers.end() || count > maxPrimePowers[j]) {
                        maxPrimePowers[j] = count;
                    }
                }
            }
            if (cycle > 1) {
                 if (maxPrimePowers.find(cycle) == maxPrimePowers.end() || 1 > maxPrimePowers[cycle]) {
                    maxPrimePowers[cycle] = 1;
                }
            }
        }

        // Build the final LCM from its prime factorization, under modulo.
        long long finalLcmMod = 1;
        for (auto const& [prime, maxPower] : maxPrimePowers) {
            long long term = power(prime, maxPower);
            finalLcmMod = (finalLcmMod * term) % MOD;
        }

        return static_cast<int>(finalLcmMod);
    }
};

int main() {
    std::vector<std::string> A;
    std::ifstream inputFile("/home/shreyash/VSCode/placementPractice/string/input.txt");

    if (inputFile.is_open()) {
        std::string line;
        if (std::getline(inputFile, line)) {
            std::stringstream ss(line);
            int n;
            ss >> n;
            std::string temp_str;
            for (int i = 0; i < n && ss >> temp_str; ++i) {
                A.push_back(temp_str);
            }
        }
        inputFile.close();
    } else {
        std::cerr << "Unable to open input file." << std::endl;
        return 1;
    }

    Stringoholics obj;
    std::cout << obj.solve(A) << std::endl;

    return 0;
}