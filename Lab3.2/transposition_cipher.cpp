#include "transposition_cipher.h"

TranspositionCipher::TranspositionCipher(int columns) : columns_(columns) {
    if (columns <= 0) {
        throw std::invalid_argument("Number of columns must be positive");
    }
}

// Шифрование
std::string TranspositionCipher::encrypt(const std::string& plaintext) {
    if (plaintext.empty()) {
        throw std::invalid_argument("Input text is empty");
    }

    // Проверка на невалидные символы
    for (char c : plaintext) {
        if (!isalnum(c) && !isspace(c)) {
            throw std::invalid_argument("Input text contains invalid characters");
        }
    }

    int rows = (plaintext.size() + columns_ - 1) / columns_; // Количество строк
    std::vector<std::string> table(rows, std::string(columns_, ' ')); // Заполняем таблицу пробелами
    int index = 0;

    // Заполнение таблицы
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns_; ++j) {
            if (index < plaintext.size()) {
                table[i][j] = plaintext[index++];
            }
        }
    }

    // Считывание текста по столбцам
    std::string ciphertext;
    for (int j = 0; j < columns_; ++j) {
        for (int i = 0; i < rows; ++i) {
            ciphertext += table[i][j];
        }
    }

    return ciphertext;
}

// Дешифрование
std::string TranspositionCipher::decrypt(const std::string& ciphertext) {
    if (ciphertext.empty()) {
        throw std::invalid_argument("Input text is empty");
    }

    // Проверка на невалидные символы
    for (char c : ciphertext) {
        if (!isalnum(c) && !isspace(c)) {
            throw std::invalid_argument("Input text contains invalid characters");
        }
    }

    int rows = (ciphertext.size() + columns_ - 1) / columns_; // Количество строк
    std::vector<std::string> table(rows, std::string(columns_, ' ')); // Создаем пустую таблицу

    int index = 0;

    // Заполнение таблицы столбцами
    for (int j = 0; j < columns_; ++j) {
        for (int i = 0; i < rows; ++i) {
            if (index < ciphertext.size()) {
                table[i][j] = ciphertext[index++];
            }
        }
    }

    // Чтение текста по строкам
    std::string plaintext;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns_; ++j) {
            plaintext += table[i][j];
        }
    }

    return plaintext;
}

