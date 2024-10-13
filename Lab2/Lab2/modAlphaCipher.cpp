#include "modAlphaCipher.h"
#include <stdexcept>

modAlphaCipher::modAlphaCipher(const std::wstring& skey) {
    if (skey.empty()) {
        throw std::invalid_argument("Key is empty");
    }

    for (unsigned i = 0; i < numAlpha.size(); i++) {
        alphaNum[numAlpha[i]] = i;
    }
    key = convert(skey);
}

std::vector<int> modAlphaCipher::convert(const std::wstring& s) {
    if (s.empty()) {
        throw std::invalid_argument("Input text is empty");
    }

    std::vector<int> result;
    for (auto c : s) {
        if (alphaNum.find(c) == alphaNum.end()) {
            throw std::invalid_argument("Invalid character in input");
        }
        result.push_back(alphaNum[c]);
    }
    return result;
}

std::wstring modAlphaCipher::convert(const std::vector<int>& v) {
    if (v.empty()) {
        throw std::invalid_argument("Input vector is empty");
    }

    std::wstring result;
    for (auto i : v) {
        if (i < 0 || i >= numAlpha.size()) {
            throw std::out_of_range("Index out of range");
        }
        result.push_back(numAlpha[i]);
    }
    return result;
}

std::wstring modAlphaCipher::encrypt(const std::wstring& open_text) {
    if (key.empty()) {
        throw std::invalid_argument("Key is empty");
    }
    if (open_text.empty()) {
        throw std::invalid_argument("Input text is empty");
    }

    std::vector<int> work = convert(open_text);
    for (unsigned i = 0; i < work.size(); i++) {
        work[i] = (work[i] + key[i % key.size()]) % numAlpha.size();
    }
    return convert(work);
}

std::wstring modAlphaCipher::decrypt(const std::wstring& cipher_text) {
    if (key.empty()) {
        throw std::invalid_argument("Key is empty");
    }
    if (cipher_text.empty()) {
        throw std::invalid_argument("Input text is empty");
    }

    std::vector<int> work = convert(cipher_text);
    for (unsigned i = 0; i < work.size(); i++) {
        work[i] = (work[i] + numAlpha.size() - key[i % key.size()]) % numAlpha.size();
    }
    return convert(work);
}