#include <iostream>
#include "transposition_cipher.h"

void checkTranspositionCipher(const std::string& text, int columns) {
    try {
        TranspositionCipher cipher(columns);
        std::string ciphertext = cipher.encrypt(text);
        std::string decryptedText = cipher.decrypt(ciphertext);
        std::cout << "Columns: " << columns << std::endl;
        std::cout << text << std::endl;
        std::cout << ciphertext << std::endl;
        std::cout << decryptedText << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}

int main() {
    checkTranspositionCipher("HELLOWORLD", 4);
    checkTranspositionCipher("", 4); // Test with empty text
    checkTranspositionCipher("HELLOWORLD", 0); // Test with invalid columns
    checkTranspositionCipher("HELL@WORLD", 4); // Test with invalid characters
    return 0;
}