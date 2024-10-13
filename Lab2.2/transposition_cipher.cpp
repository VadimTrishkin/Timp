#include "transposition_cipher.h"
#include <stdexcept>
#include <iostream>

TranspositionCipher::TranspositionCipher(int columns) : columns_(columns) {
    if (columns <= 0) {
        throw std::invalid_argument("Number of columns must be positive");
    }
}

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

    int rows = (plaintext.size() + columns_ - 1) / columns_;
    // Определение кол-ва строк
    std::vector<std::string> table(rows, std::string(columns_, ' ')); // Создание таблицы, заполненной пробелами
    int index = 0; // Запись текста в таблицу по строкам
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns_; ++j) {
            if (index < plaintext.size()) {
                table[i][j] = plaintext[index++];
            }
        }
    }
    std::string ciphertext; // Чтение зашифрованного текста по столбцам в обратном порядке
    for (int j = columns_ - 1; j >= 0; --j) {
        for (int i = 0; i < rows; ++i) {
            ciphertext += table[i][j];
        }
    }
    return ciphertext;
}

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

    int rows = (ciphertext.size() + columns_ - 1) / columns_;
    // Определение кол-ва строк для таблицы
    std::vector<std::string> table(rows, std::string(columns_, ' ')); // Создание таблицы, заполненной пробелами
    int index = 0;
    for (int j = columns_ - 1; j >= 0; --j) { // Вписывание зашифрованного в таблицу в обратном порядке
        for (int i = 0; i < rows; ++i) {
            if (index < ciphertext.size()) {
                table[i][j] = ciphertext[index++];
            }
        }
    }
    std::string plaintext;
    for (int i = 0; i < rows; ++i) { // Чтение расшифрованного по строкам
        for (int j = 0; j < columns_; ++j) {
            plaintext += table[i][j];
        }
    }
    return plaintext;
}