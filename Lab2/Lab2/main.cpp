#include <iostream>
#include "modAlphaCipher.h"
using namespace std;

void check(const wstring& Text, const wstring& key) {
    try {
        wstring cipherText;
        wstring decryptedText;
        modAlphaCipher cipher(key);
        cipherText = cipher.encrypt(Text);
        decryptedText = cipher.decrypt(cipherText);
        wcout << L"key=" << key << endl;
        wcout << Text << endl;
        wcout << cipherText << endl;
        wcout << decryptedText << endl;
        if (Text == decryptedText)
            wcout << L"Ok\n";
        else
            wcout << L"Err\n";
    } catch (const std::exception& e) {
        wcout << L"Error: " << e.what() << endl;
    }
}

int main() {
    check(L"БЫСТРАЯКОРИЧНЕВАЯЛИСАПЕРЕПРЫГНУЛАЧЕРЕЗЛЕНИВУЮСОБАКУ",
          L"ПРОСТОЙ");
    check(L"БЫСТРАЯКОРИЧНЕВАЯЛИСАПЕРЕПРЫГНУЛАЧЕРЕЗЛЕНИВУЮСОБАКУ",
          L"ПРИМЕР");
    check(L"БЫСТРАЯКОРИЧНЕВАЯЛИСАПЕРЕПРЫГНУЛАЧЕРЕЗЛЕНИВУЮСОБАКУ",
          L"АБВГ");
          check(L"",
          L"АБВГ");
          check(L"БЫСТРАЯКОРИЧНЕВАЯЛИСАПЕРЕПРЫГНУЛАЧЕРЕЗЛЕНИВУЮСОБАКУ",
          L"");
          check(L"БЫСТРАЯКОРИфЧНЕВАЯЛИСАПЕРЕПРЫГНУЛАЧЕРЕЗЛЕНИВУЮСОБАКУ",
          L"АБВГ");
          check(L"БЫСТРАЯКОРИЧНЕВАЯЛИСАПЕРЕПРЫГНУЛАЧЕРЕЗЛЕНИВУЮСОБАКУ",
          L"АБфВГ");
    return 0;
}