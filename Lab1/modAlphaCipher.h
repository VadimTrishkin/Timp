#pragma once
#include <iostream>
#include <map>
#include <string>
#include <vector>
class modAlphaCipher
{
private:
    std::wstring numAlpha = L"АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ"; //Алфавит по порядку
    std::map<wchar_t, int> alphaNum; // Ассоциативный массив "номер посимволу"
    std::vector<int> key;            // Ключ
    std::vector<int> convert(const std::wstring& s); // Преобразованиестрока-вектор
    std::wstring convert(const std::vector<int>& v); // Преобразованиевектор-строка
public:
    modAlphaCipher() = delete;                // Запретим конструктор без параметров
    modAlphaCipher(const std::wstring& skey); // Конструктор дляустановки ключа
    std::wstring encrypt(const std::wstring& open_text);   // Зашифрование
    std::wstring decrypt(const std::wstring& cipher_text); // Расшифрование
};