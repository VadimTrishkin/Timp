#include <UnitTest++/UnitTest++.h>
#include "transposition_cipher.h"

// Тест шифрования текста "HELLOWORLD" с 4 столбцами
TEST(TestEncryptBasic) {
    TranspositionCipher cipher(4);
    std::string encrypted = cipher.encrypt("HELLOWORLD");
    CHECK_EQUAL("LHDLOEORWL", encrypted); // Ожидаемый зашифрованный текст
}

// Тест дешифрования текста "LHDLOEORWL" с 4 столбцами
TEST(TestDecryptBasic) {
    TranspositionCipher cipher(4);
    std::string decrypted = cipher.decrypt("LHDLOEORWL");
    CHECK_EQUAL("HELLOWORLD", decrypted); // Ожидаемый расшифрованный текст
}

// Тест на шифрование пустого текста
TEST(TestEncryptEmptyText) {
    TranspositionCipher cipher(4);
    CHECK_THROW(cipher.encrypt(""), std::invalid_argument); // Ожидаем исключение
}

// Тест на дешифрование пустого текста
TEST(TestDecryptEmptyText) {
    TranspositionCipher cipher(4);
    CHECK_THROW(cipher.decrypt(""), std::invalid_argument); // Ожидаем исключение
}

// Тест на шифрование текста с невалидными символами
TEST(TestEncryptInvalidCharacters) {
    TranspositionCipher cipher(4);
    CHECK_THROW(cipher.encrypt("HELL@WORLD"), std::invalid_argument); // Ожидаем исключение
}

// Тест на дешифрование текста с невалидными символами
TEST(TestDecryptInvalidCharacters) {
    TranspositionCipher cipher(4);
    CHECK_THROW(cipher.decrypt("HELLO@WORLD"), std::invalid_argument); // Ожидаем исключение
}

// Тест с неверным количеством столбцов (0)
TEST(TestInvalidColumns) {
    CHECK_THROW(TranspositionCipher(0), std::invalid_argument); // Ожидаем исключение
}

// Тест на шифрование с большим количеством столбцов, чем символов
TEST(TestEncryptMoreColumnsThanText) {
    TranspositionCipher cipher(20);
    std::string encrypted = cipher.encrypt("HELLO");
    CHECK(encrypted.size() == 20); // Проверка на корректный размер
}

// Тест на дешифрование с большим количеством столбцов, чем символов
TEST(TestDecryptMoreColumnsThanText) {
    TranspositionCipher cipher(20);
    std::string decrypted = cipher.decrypt("H    E    L    L    O");
    CHECK_EQUAL("HELLO", decrypted); // Ожидаем, что пробелы убраны и текст корректный
}

int main() {
    return UnitTest::RunAllTests();
}
