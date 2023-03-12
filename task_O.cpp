#include <iostream>
#include <iostream>
#include <stack>
#include <deque>
#include <string>
#include <algorithm>
#include <sstream>


int main() {

    //  111253. Гистограмма. Выведите площадь самого большого прямоугольника в гистограмме.
    //  статус ОК

    // Ввод чисел
    long result = 0;
    std::deque<long> chart;
    std::stack<int> stack;

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

    // получение и удаление кол-ва колонок
    int n = chart[0];
    chart.pop_front();

    long column_idx;
    long area;
    long max_area =0;

    int i = 0;

    // проверка столбцов и заполнение стека
    while (i < n) {
        if (stack.empty() || chart[stack.top()]<=chart[i]) {
            stack.push(i);
            i++;
        }
        else {
            column_idx = stack.top();
            stack.pop();
            if (stack.empty())
                area  = chart[column_idx]*i;
            else
                area = chart[column_idx]*(i - stack.top() - 1);
            if (max_area<area)
                max_area = area;
        }
    }


    // проверка стека
    while (!stack.empty())
    {
        column_idx = stack.top();
        stack.pop();
        if(stack.empty())
            area = chart[column_idx]*i;
        else
            area = chart[column_idx]*(i - stack.top() - 1);

        if (max_area < area)
            max_area = area;
    }
    result = max_area;

    std::printf("%ld\n",result);


    return 0;
}


