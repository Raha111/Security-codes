#include <iostream>
#include <string>
using namespace std;

// Function to encrypt the plaintext using Caesar Cipher
string encrypt(string text, int s) {
    string result = "";

    // Traverse the text
    for (int i = 0; i < text.length(); i++) {
        // Encrypt uppercase letters
        if (isupper(text[i]))
            result += char(int(text[i] + s - 65) % 26 + 65);
        // Encrypt lowercase letters
        else if (islower(text[i]))
            result += char(int(text[i] + s - 97) % 26 + 97);
        // Leave non-alphabetic characters unchanged
        else
            result += text[i];
    }

    return result;
}

// Function to decrypt the ciphertext using Caesar Cipher
string decrypt(string text, int s) {
    string result = "";

    // Traverse the text
    for (int i = 0; i < text.length(); i++) {
        // Decrypt uppercase letters
        if (isupper(text[i]))
            result += char(int(text[i] - s - 65 + 26) % 26 + 65);
        // Decrypt lowercase letters
        else if (islower(text[i]))
            result += char(int(text[i] - s - 97 + 26) % 26 + 97);
        // Leave non-alphabetic characters unchanged
        else
            result += text[i];
    }

    return result;
}

int main() {
    string text;
    int s;

    // Take plaintext and shift value as input
    cout << "Enter the text: ";
    getline(cin, text);
    cout << "Enter the shift value: ";
    cin >> s;

    // Encrypt the plaintext
    string encryptedText = encrypt(text, s);
    cout << "Encrypted Text: " << encryptedText << endl;

    // Decrypt the ciphertext
    string decryptedText = decrypt(encryptedText, s);
    cout << "Decrypted Text: " << decryptedText << endl;

    return 0;
}

