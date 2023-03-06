#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>


int main() {

    //  111253. Гистограмма. Выведите площадь самого большого прямоугольника в гистограмме.
    // 65 тестов из 66 из-за превышении максимального времени работы программы (1.095)

    // Ввод чисел
    long result = 0;
    std::vector<long> chart;

    std::string numbers;
    std::getline(std::cin, numbers);

    std::string s;
    std::istringstream stream(numbers);

    // Преобразование строки в число
    try {
        while (std::getline(stream, s, ' ')) {
            chart.push_back(std::stoi(s));
        }
    }
    catch (const std::out_of_range& e) {
        std::printf("%ld\n",result);
        std::exit(0);
    }
    catch (const std::invalid_argument& e) {
        std::printf("%ld\n",result);
        std::exit(0);
    }

    int n = chart[0];
    long area;
    int left_idx, right_idx;

    int i =1;
    while (i <= n) {
        left_idx = right_idx = i;
        // поиск границ прямоугольников
        while(left_idx > 1 && chart[left_idx-1] >= chart[i]) left_idx--;    // сканирование столбцов слева
        while(right_idx < n && chart[right_idx+1] >= chart[i]) right_idx++; // сканирование столбцов справа

        area = (right_idx - left_idx + 1) * chart[i];
        if (area > result) result = area;
        i++;
    }

    std::printf("%ld\n",result);


    return 0;
}


