#include <iostream>
#include <string>
using namespace std;

string caesarEncrypt(const string& text, int shift) {
    string encrypted = text;
    for (char& ch : encrypted) {
        if (isalpha(ch)) {
            char offset = isupper(ch) ? 'A' : 'a';
            ch = (ch - offset + shift) % 26 + offset;
        }
    }
    return encrypted;
}

string caesarDecrypt(const string& text, int shift) {
    return caesarEncrypt(text, 26 - shift);
}

string rleCompress(const string& text) {
    string compressed;
    for (size_t i = 0; i < text.length(); ++i) {
        int count = 1;
        while (i + 1 < text.length() && text[i] == text[i + 1]) {
            ++count;
            ++i;
        }
        compressed += text[i];
        compressed += (count + '0');
    }
    return compressed;
}

string rleDecompress(const string& text) {
    string decompressed;
    for (size_t i = 0; i < text.length(); ++i) {
        char ch = text[i];
        ++i;
        int count = text[i] - '0';
        decompressed.append(count, ch);
    }
    return decompressed;
}

int main() {
    string text;
    int shift;

    cout << "Enter text to encrypt: ";
    cin >> text;

    cout << "Enter Caesar cipher shift: ";
    cin >> shift;

    string caesarEncrypted = caesarEncrypt(text, shift);
    cout << "Caesar Encrypted: " << caesarEncrypted << endl;

    string rleEncrypted = rleCompress(caesarEncrypted);
    cout << "RLE Encrypted: " << rleEncrypted << endl;

    string rleDecrypted = rleDecompress(rleEncrypted);
    cout << "RLE Decrypted: " << rleDecrypted << endl;

    string caesarDecrypted = caesarDecrypt(rleDecrypted, shift);
    cout << "Caesar Decrypted: " << caesarDecrypted << endl;

    return 0;
}
