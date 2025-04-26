#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class StringEncryptor {
public:
    // Method to encrypt the input string
    string encrypt(const string& input) {
        string encrypted;
        for (size_t i = 0; i < input.length(); ++i) {
            char encryptedChar = input[i] + (i + 1); // i + 1 is the position (1-based)
            encrypted += encryptedChar;
        }
        return encrypted;
    }

    // Method to decrypt the encrypted string
    string decrypt(const string& encrypted) {
        string decrypted;
        for (size_t i = 0; i < encrypted.length(); ++i) {
            char decryptedChar = encrypted[i] - (i + 1); // i + 1 is the position (1-based)
            decrypted += decryptedChar;
        }
        return decrypted;
    }

    // Method to write encrypted text to a file
    void writeToFile(const string& filename, const string& encryptedText) {
        ofstream outFile(filename);
        if (outFile.is_open()) {
            outFile << encryptedText;
            outFile.close();
            cout << "Encrypted text inserted into file\n";
        } else {
            cerr << "Unable to open file for writing\n";
        }
    }

    // Method to read text from a file
    string readFromFile(const string& filename) {
        string content;
        ifstream inFile(filename);
        if (inFile.is_open()) {
            getline(inFile, content);
            inFile.close();
        } else {
            cerr << "Unable to open file for reading\n";
        }
        return content;
    }
};

int main() {
    StringEncryptor encryptor;
    string input;

    // User input
    cout << "Enter String: ";
    getline(cin, input);

    // Encrypt the string
    string encryptedText = encryptor.encrypt(input);
    cout << "Normal Text: " << input << "\n";
    
    // Write encrypted text to file
    const string filename = "encrypted.txt";
    encryptor.writeToFile(filename, encryptedText);

    // Read the encrypted text from file
    string readEncryptedText = encryptor.readFromFile(filename);

    // Decrypt the text
    string decryptedText = encryptor.decrypt(readEncryptedText);
    cout << "Decrypted text read from file:\n";
    cout << decryptedText << "\n";

    return 0;
}
