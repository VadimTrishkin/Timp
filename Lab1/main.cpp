#include "modAlphaCipher.h"

#include <iostream>
using namespace std;
void check(const wstring& Text, const wstring& key)
{
    wstring cipherText;
    wstring decryptedText;
    modAlphaCipher cipher(key);
    cipherText = cipher.encrypt(Text);
    decryptedText = cipher.decrypt(cipherText);
    wcout << L"key=" << key << endl;
    wcout << Text << endl;
    wcout << cipherText << endl;
    wcout << decryptedText << endl;
    if(Text == decryptedText)
        wcout << L"Ok\n";
    else
        wcout << L"Err\n";
}
int main()
{
    check(L"БЫСТРАЯКОРИЧНЕВАЯЛИСАПЕРЕПРЫГНУЛАЧЕРЕЗЛЕНИВУЮСОБАКУ", L"ПРОСТОЙ");
    check(L"БЫСТРАЯКОРИЧНЕВАЯЛИСАПЕРЕПРЫГНУЛАЧЕРЕЗЛЕНИВУЮСОБАКУ", L"ПРИМЕР");
    check(L"БЫСТРАЯКОРИЧНЕВАЯЛИСАПЕРЕПРЫГНУЛАЧЕРЕЗЛЕНИВУЮСОБАКУ", L"АБВГ");
    return 0;
}
