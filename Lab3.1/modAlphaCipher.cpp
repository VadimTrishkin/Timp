#include "modAlphaCipher.h"

// Инициализация ключа
modAlphaCipher::modAlphaCipher(const std::wstring& skey) {
    for (unsigned i = 0; i < numAlpha.size(); i++) {
        alphaNum[numAlpha[i]] = i;
    }
    key = convert(skey);
}

// Преобразование строки в числовой вектор
std::vector<int> modAlphaCipher::convert(const std::wstring& s) {
    std::vector<int> result;
    for (auto c : s) {
        if (alphaNum.find(c) == alphaNum.end()) {
            throw std::invalid_argument("Недопустимый символ в тексте.");
        }
        result.push_back(alphaNum[c]);
    }
    return result;
}

// Преобразование числового вектора в строку
std::wstring modAlphaCipher::convert(const std::vector<int>& v) {
    std::wstring result;
    for (size_t i = 0; i < v.size(); ++i) {
        if (static_cast<size_t>(v[i]) >= numAlpha.size()) {
            throw std::invalid_argument("Индекс вышел за границу");
        }
        result += numAlpha[v[i]];
    }
    return result;
}


// Шифрование 
std::wstring modAlphaCipher::encrypt(const std::wstring& open_text) {
    try {
        std::vector<int> work = convert(open_text);
        for (unsigned i = 0; i < work.size(); i++) {
            work[i] = (work[i] + key[i % key.size()]) % numAlpha.size();
        }
        return convert(work);
    } catch (const std::exception& e) {
        std::wcerr << L"Ошибка шифрования: " << e.what() << std::endl;
        throw;
    }
}

// Расшифрование 
std::wstring modAlphaCipher::decrypt(const std::wstring& cipher_text) {
    try {
        std::vector<int> work = convert(cipher_text);
        for (unsigned i = 0; i < work.size(); i++) {
            work[i] = (work[i] + numAlpha.size() - key[i % key.size()]) % numAlpha.size();
        }
        return convert(work);
    } catch (const std::exception& e) {
        std::wcerr << L"Ошибка дешифрования: " << e.what() << std::endl;
        throw;
    }
}
