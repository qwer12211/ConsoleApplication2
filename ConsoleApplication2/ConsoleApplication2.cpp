#include <iostream>
#include <algorithm>
#include <random>
#include <string>

std::string reverse(const std::string& word) {
    std::string reversed = word;
    std::reverse(reversed.begin(), reversed.end());
    return reversed;
}


std::string removeVowels(const std::string& word) {
    std::string withoutVowels = "";
    for (char c : word) {
        if (tolower(c) != 'a' && tolower(c) != 'e' && tolower(c) != 'i' && tolower(c) != 'o' && tolower(c) != 'u') {
            withoutVowels += c;
        }
    }
    return withoutVowels;
}

std::string removeConsonants(const std::string& word) {
    std::string withoutConsonants = "";
    for (char c : word) {
        if (tolower(c) != 'a' && tolower(c) != 'e' && tolower(c) != 'i' && tolower(c) != 'o' && tolower(c) != 'u') {
            withoutConsonants += c;
        }
    }
    return withoutConsonants;
}

std::string shuffle(const std::string& word) {
    std::string shuffled = word;
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(shuffled.begin(), shuffled.end(), g);
    return shuffled;
}

int main() {
    setlocale(LC_ALL, "Russian");
    std::cout << "Выберите действие:" << std::endl;
    std::cout << "1. Слово выводится задом наперед." << std::endl;
    std::cout << "2. Вывести слово без гласных." << std::endl;
    std::cout << "3. Вывести слово без согласных." << std::endl;
    std::cout << "4. Рандомно раскидывать буквы заданного слова." << std::endl;

    int choice;
    std::cin >> choice;

    std::string word;
    std::cout << "Введите слово: ";
    std::cin >> word;

    std::string result;

    switch (choice) {
    case 1:
        result = reverse(word);
        break;
    case 2:
        result = removeVowels(word);
        break;
    case 3:
        result = removeConsonants(word);
        break;
    case 4:
        result = shuffle(word);
        break;
    default:
        std::cout << "Некорректный выбор." << std::endl;
        return 0;
    }

    std::cout << "Результат: " << result << std::endl;

    return 0;
}
