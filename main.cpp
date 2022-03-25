/*
    project name: Vignere Cipher
    By Fady Hany
    project university
    */

#include <iostream>
#include <string>
#include <algorithm>
int main() {
    std::cout<<"Vignere Cipher"<<std::endl;
    int x , choose;
    std::string key, encrypted_mess, decrypted_mess;
    // the user will choose between encryption or decryption
    std::cout << "1 to encrypted "<<std::endl<<"2 to decrypted"<<std::endl;
    std::cin >> choose;
    std::cin.ignore();

//in encryption we add the ascii value of the message's character with the key's character
    if (choose == 1) {
        std::cout << "Enter the message to encrypted: " << std::endl;
        getline(std::cin, encrypted_mess);
        std::transform(encrypted_mess.begin(), encrypted_mess.end(), encrypted_mess.begin(), toupper);
        std::cout << "Enter the key:";
        std::cin >> key;
        std::transform(key.begin(), key.end(), key.begin(), toupper);
       //this function to repeat the key until the length of message = the length of key
        for (int j = 0; j < encrypted_mess.length(); j++) {
            key += key[j];
            if (key.length() == encrypted_mess.length())
                break;
        }

        for (int i = 0; i < encrypted_mess.length(); i++) {
            if (encrypted_mess[i] == (char) 32) //this function to ignore the space
                std::cout << " ";
        //after adding the two values,take the mod of 26(the numbers of characters in english)
        // add the finally value to 65(the ascii of A)
            else if ((encrypted_mess[i] > 64) && (encrypted_mess[i] < 123)) {
                x = (int) key[i] + (int) encrypted_mess[i];
                x = x % 26;
                x += 65;
                std::cout << (char) x;

            }
            else
                std::cout << encrypted_mess[i];
        }
    }


    if (choose == 2) {
        char alphabet[27] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R',
                             'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

        std::cout << "Enter the message to decrypted: " << std::endl;
        getline(std::cin, decrypted_mess);
        std::transform(decrypted_mess.begin(), decrypted_mess.end(), decrypted_mess.begin(), toupper);
        std::cout << "Enter the key";
        std::cin >> key;
        std::transform(key.begin(), key.end(), key.begin(), toupper);

        for (int j = 0; j < decrypted_mess.length(); j++) {
            key += key[j];
            if (key.length() == decrypted_mess.length())
                break;
        }

        for (int i = 0; i < decrypted_mess.length(); i++) {
            if (decrypted_mess[i] == (char) 32)
                std::cout << " ";
            //this function take only the alphabet characters
            else if ((decrypted_mess[i] > 64) && (decrypted_mess[i] < 123)) {
                x = (int) decrypted_mess[i] - (int) key[i];
                //if the x value = -ve number
                //add 26 to get the number +ve and compare between it and the alphabet array
                if (x < 0)
                    x += 26;
                std::cout << alphabet[x];
            }
            else
                std::cout << decrypted_mess[i];
        }

    }

}