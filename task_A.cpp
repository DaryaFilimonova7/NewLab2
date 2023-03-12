#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <set>


int main() {

    //  1418. Разное. Дано N чисел, требуется выяснить, сколько среди них различных.
    // статус ОК

    long answer = 0;

    int n;
    // Ввод кол-ва чисел
    std::cin >> n;
    // проверка 1 <= N <= 100000
    if (n<1 || n>100000) {
        std::printf("%ld\n",answer);
        std::exit(0);
    }

    // Ввод чисел
    std::string numbers;
    std::cin.ignore();
    std::getline(std::cin, numbers);
    // использование set, чтобы отсеять дублирование
    std::set<int> vars; 
    std::string x;
    std::istringstream stream(numbers);

    // Преобразование строки в число и обработка исключения
    try {
        while (std::getline(stream, x, ' ')) {
            vars.insert(std::stoi(x));
        }
    }
    catch (const std::out_of_range& e) {
        std::printf("%ld\n",answer);
        std::exit(0);
    }
    catch (const std::invalid_argument& e) {
        std::printf("%ld\n",answer);
        std::exit(0);
    }

    answer = vars.size();

    std::printf("%ld\n",answer);

    return 0;
}

