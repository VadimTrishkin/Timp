#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <stdexcept> // For exception handling

class modAlphaCipher {
private:
    std::wstring numAlpha = L"АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ"; // Алфавит по порядку
    std::map<wchar_t, int> alphaNum; // Ассоциативный массив "номер по символу"
    std::vector<int> key; // Ключ

    std::vector<int> convert(const std::wstring& s); // Преобразование строка-вектор
    std::wstring convert(const std::vector<int>& v); // Преобразование вектор-строка

public:
    modAlphaCipher() = delete; // Запретим конструктор без параметров
    modAlphaCipher(const std::wstring& skey); // Конструктор для установки ключа

    std::wstring encrypt(const std::wstring& open_text); // Зашифрование
    std::wstring decrypt(const std::wstring& cipher_text); // Расшифрование
};