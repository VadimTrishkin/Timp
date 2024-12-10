/**
 * @file modAlphaCipher.h
 * @brief Заголовочный файл для шифрования Гронсвельда.
 *
 * @author 
 * Тришкин В.Д.
 * 
 * @date 
 * 9 декабря 2024 г.
 */

#pragma once
#include <string>
#include <map>
#include <vector>
#include <stdexcept>
#include <iostream>

/**
 * @class modAlphaCipher
 * @brief Предоставляет методы шифрования и дешифрования шифра Гронсвельда.
 */
class modAlphaCipher {
private:
    std::wstring numAlpha = L"АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ"; ///< Алфавит, используемый для шифра.
    std::map<wchar_t, int> alphaNum; ///< Сопоставление символов с их числовыми позициями в алфавите.
    std::vector<int> key; ///< Числовое представление ключа шифрования.

    /**
     * @brief Преобразует строку в числовой вектор на основе алфавита.
     * @param s Входная строка для преобразования.
     * @return Вектор чисел, представляющий строку.
     * @throw std::invalid_argument Если строка содержит символы, отсутствующие в алфавите.
     */
    std::vector<int> convert(const std::wstring& s);

    /**
     * @brief Преобразует числовой вектор обратно в строку на основе алфавита.
     * @param v Входной вектор для преобразования.
     * @return Строка, соответствующая вектору.
     * @throw std::invalid_argument Если индекс в векторе выходит за пределы алфавита.
     */
    std::wstring convert(const std::vector<int>& v);

public:
    /**
     * @brief Конструктор по умолчанию удалён, чтобы всегда требовался ключ.
     */
    modAlphaCipher() = delete;

    /**
     * @brief Конструктор для инициализации шифра с ключом.
     * @param skey Строка-ключ, используемая для шифрования и дешифрования.
     */
    modAlphaCipher(const std::wstring& skey);

    /**
     * @brief Шифрует открытую строку.
     * @param open_text Входная строка для шифрования.
     * @return Зашифрованная строка.
     * @throw std::exception В случае возникновения ошибки при шифровании.
     */
    std::wstring encrypt(const std::wstring& open_text);

    /**
     * @brief Дешифрует зашифрованную строку.
     * @param cipher_text Входная строка для дешифрования.
     * @return Расшифрованная строка.
     * @throw std::exception В случае возникновения ошибки при дешифровании.
     */
    std::wstring decrypt(const std::wstring& cipher_text);
};
