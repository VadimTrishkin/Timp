/**
 * @file main.cpp
 * @brief Основная программа для работы программы шифра маршрутной перестановки.
 * 
 * @author 
 * Тришкин В. Д.
 * 
 * @date 
 * 9 декабря 2024 г.
 */

#include <iostream>
#include <stdexcept>
#include <string>
#include "transposition_cipher.h"

/**
 * @brief Главная функция программы.
 * 
 * Реализует консольный интерфейс для шифрования и дешифрования текста методом перестановок.
 * Пользователь вводит количество столбцов, выбирает действие (шифрование или дешифрование) и предоставляет текст.
 * 
 * @return Код завершения программы (0 при успешном выполнении).
 */
int main() {
    try {
        int columns; // Количество столбцов для таблицы перестановок
        std::cout << "Введите количество столбцов для шифрования/дешифрования: ";
        std::cin >> columns; // Считываем количество столбцов
        std::cin.ignore(); // Очистка буфера ввода

        // Создаем объект шифра с указанным количеством столбцов
        TranspositionCipher cipher(columns);

        int choice; // Выбор действия (1 - шифрование, 2 - дешифрование)
        std::cout << "Выберите действие:\n1. Зашифровать текст\n2. Расшифровать текст\n";
        std::cout << "Ваш выбор: ";
        std::cin >> choice; // Считываем выбор пользователя
        std::cin.ignore(); // Очистка буфера ввода

        std::string text; // Текст для обработки
        if (choice == 1) {
            // Шифрование текста
            std::cout << "Введите текст для шифрования: ";
            std::getline(std::cin, text); // Считываем текст для шифрования

            std::string encryptedText = cipher.encrypt(text); // Шифруем текст
            std::cout << "Зашифрованный текст: " << encryptedText << std::endl;
        } else if (choice == 2) {
            // Дешифрование текста
            std::cout << "Введите зашифрованный текст для расшифровки: ";
            std::getline(std::cin, text); // Считываем текст для дешифрования

            std::string decryptedText = cipher.decrypt(text); // Расшифровываем текст
            std::cout << "Расшифрованный текст: " << decryptedText << std::endl;
        } else {
            // Обработка неверного выбора
            std::cout << "Неверный выбор!" << std::endl;
        }

    } catch (const std::exception& e) {
        // Обработка исключений
        std::cout << "Ошибка: " << e.what() << std::endl;
    }

    return 0; // Успешное завершение программы
}