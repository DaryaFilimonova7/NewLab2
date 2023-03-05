#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>
#include <cstdlib>


int main() {

    //  1418. Дано N чисел, требуется выяснить, сколько среди них различных.

    int n;
    // Ввод кол-ва чисел
    std::cin >> n;
    // проверка 1 <= N <= 100000
    if (n<1 || n>100000) {
        std::exit(0);
    }

    // Ввод чисел
    std::string numbers;
    std::cin.ignore();
    std::getline(std::cin, numbers);

    std::vector<int> vars;
    std::string s;
    std::istringstream stream(numbers);

     // Преобразование строки в число и обработка исключения
     try {
         while (std::getline(stream, s, ' ')) {
             vars.push_back(std::stoi(s));
         }
     }
     catch (const std::out_of_range& e) {
         std::exit(0);
     }

    // проверка, что каждое не превышает 2*10^9
    for (int i = 0; i<n; i++) {
        if (abs(vars[i]) > 2*exp(9)) {
            std::cout << "Error";
            std::exit(0);
        }
    }


    int answer = 0;
    bool not_unique;

    //  Поиск различных чисел среди данных.
    for (int i = 0; i<n; i++) {       // выбор числа для сравнения
        for (int j=i+1;j<n; j++) {       // сравнение с остальными
            if (vars[i]==vars[j]) {
                not_unique = true;
            }
        }
        if (!not_unique) answer++;
        not_unique = false;
    }

    std::cout << answer;

    return 0;
}
