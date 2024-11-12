#include <UnitTest++/UnitTest++.h>
#include "modAlphaCipher.h"

// шифрование пустого текста
TEST(TestEncryptEmptyText) {
    modAlphaCipher cipher(L"БКД");
    std::wstring encrypted = cipher.encrypt(L"");
    CHECK(encrypted == L""); 
}

// дешифрование пустого текста
TEST(TestDecryptEmptyText) {
    modAlphaCipher cipher(L"БКД");
    std::wstring decrypted = cipher.decrypt(L"");
    CHECK(decrypted == L""); 
}

// шифрование текста с недопустимыми символами
TEST(TestLowerCaseCharacterInText) {
    modAlphaCipher cipher(L"БКД");
    CHECK_THROW(cipher.encrypt(L"бгеж"), std::invalid_argument); 
}

// дешифрование текста с недопустимыми символами
TEST(TestLowerCaseCharacterInKey) {
    modAlphaCipher cipher(L"БКД");
    CHECK_THROW(cipher.decrypt(L"бгеж"), std::invalid_argument); 
}

// шифрование текста с невалидными символами
TEST(TestForeignCharacterInText) {
    modAlphaCipher cipher(L"БКД");
    CHECK_THROW(cipher.encrypt(L"Hello"), std::invalid_argument); 
}

// шифрование минимального ключа
TEST(TestMinimalKey) {
    modAlphaCipher cipher(L"БКД");
    std::wstring encrypted = cipher.encrypt(L"БГЕЖ"); 
    CHECK(encrypted != L""); 
}

// шифрование длинного ключа
TEST(TestLongKey) {
    modAlphaCipher cipher(L"БКДБКДБКДБКДБКД");
    std::wstring encrypted = cipher.encrypt(L"БГЕЖ"); 
    CHECK(encrypted != L""); 
}

// Тест на правильность шифрования
TEST(TestEncryptionCorrectness) {
    modAlphaCipher cipher(L"БКД");
    std::wstring encrypted = cipher.encrypt(L"БГЕЖ");
    CHECK(encrypted == L"ВНИЗ"); 
}

// Тест на правильность дешифрования
TEST(TestDecryptionCorrectness) {
    modAlphaCipher cipher(L"БКД");
    std::wstring decrypted = cipher.decrypt(L"ВНИЗ");
    CHECK(decrypted == L"БГЕЖ"); 
}

int main() {
    return UnitTest::RunAllTests();
}

