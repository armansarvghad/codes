#include <iostream>
#include <string>

// Function to compress a string using Run-Length Encoding (RLE)
std::string compressRLE(const std::string& input) {
    std::string compressed;

    int count = 1;
    char prev = input[0];

    for (int i = 1; i < input.length(); i++) {
        if (input[i] == prev) {
            count++;
        } else {
            compressed += std::to_string(count) + prev;
            count = 1;
            prev = input[i];
        }
    }

    // Append the last character and its count
    compressed += std::to_string(count) + prev;

    return compressed;
}

// Function to decompress a string using Run-Length Encoding (RLE)
std::string decompressRLE(const std::string& input) {
    std::string decompressed;

    for (int i = 0; i < input.length(); i += 2) {
        int count = input[i] - '0';
        char ch = input[i + 1];

        for (int j = 0; j < count; j++) {
            decompressed += ch;
        }
    }

    return decompressed;
}

int main() {
    std::string original = "AAAABBBCCDAA";
    std::cout << "Original string: " << original << std::endl;

    std::string compressed = compressRLE(original);
    std::cout << "Compressed string: " << compressed << std::endl;

    std::string decompressed = decompressRLE(compressed);
    std::cout << "Decompressed string: " << decompressed << std::endl;

    return 0;
}
