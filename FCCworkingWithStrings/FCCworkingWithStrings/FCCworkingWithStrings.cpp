// FCCworkingWithStrings.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
    std::string phrase = "Lets crush this interview!";
    
    std::cout << phrase << std::endl;
    std::cout << phrase.length() << std::endl;
    std::cout << phrase[25] << std::endl;
    phrase[0] = 'P';
    std::cout << phrase << std::endl;
    std::cout << phrase.find("crush", 0) << std::endl;
        // finds the index position, the 0 checks where to start the index  
    std::cout << phrase.substr(16, 25) << std::endl;
        // first parameter is starting index, second parameter is length
    
    std::string phrasesub;
    phrasesub = phrase.substr(16, 25);
    std::cout << phrasesub << std::endl;

    return 0;
}

