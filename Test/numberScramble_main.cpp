#include <iostream>
#include <random>
#include <string>

// Function to scramble the number
std::string scrambleNumber(const std::string &number, unsigned int seed) {
    std::string scrambled = number;
    std::mt19937 rng(seed); // Mersenne Twister PRNG seeded for reproducibility
    std::uniform_int_distribution<int> dist(0, 9);

    for (char &digit : scrambled) {
        int randomDigit = dist(rng);
        digit = '0' + ((digit - '0' + randomDigit) % 10); // Scramble digit with random offset
    }

    return scrambled;
}

// Function to unscramble the number
std::string unscrambleNumber(const std::string &scrambled, unsigned int seed) {
    std::string original = scrambled;
    std::mt19937 rng(seed);
    std::uniform_int_distribution<int> dist(0, 9);

    for (char &digit : original) {
        int randomDigit = dist(rng);
        digit = '0' + ((digit - '0' - randomDigit + 10) % 10); // Reverse scramble by subtracting
    }

    return original;
}

int main() {
    std::string number = "53"; // Example input number
    unsigned int seed = 135622;        // Example seed for scrambling and unscrambling

    std::string scrambled = scrambleNumber(number, seed);
    std::cout << "Original Number: " << number << std::endl;
    std::cout << "Scrambled Number: " << scrambled << std::endl;

    std::string recovered = unscrambleNumber(scrambled, seed);
    std::cout << "Recovered Number: " << recovered << std::endl;

    return 0;
}