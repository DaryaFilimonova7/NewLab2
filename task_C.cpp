#include <iostream>
#include <list>
#include <string>
#include <algorithm>


int main() {

    //  №50. Игра в пьяницу
    // статус ОК

    int moves = 0;

    // list тк нет необходимости обращаться по индексам
    std::list<int> player1;
    std::list<int> player2;
    int x;
    int n = 5;

    // заполнение колоды
    for (int i = 0; i < n; i++) {
        std::cin >> x;
        player1.push_back(x);
    }

    for (int i = 0; i< n; i++) {
        std::cin >> x;
        player2.push_back(x);
    }

    // текущие карты игроков
    int first = 0;
    int second = 0;
    int winner = 0;


    while (!player1.empty() && !player2.empty() && moves<1000000 ) {

        ++moves;

        first = player1.front();
        second = player2.front();

        if (first ==0 && second ==9)
        {
            player1.push_back(first);
            player1.push_back(second);
        }
        else if ((first>second) && !(first==9 && second==0))
        {
            player1.push_back(first);
            player1.push_back(second);
        }
        else if (first==9 && second==0) {
            player2.push_back(first);
            player2.push_back(second);
        }
        else if ((first<second) && !(first ==0 && second ==9)) {
            player2.push_back(first);
            player2.push_back(second);
        }
        player1.pop_front();
        player2.pop_front();

        if (player2.empty()) {
            winner = 1;
        }
        else if (player1.empty()) {
            winner = 2;
        }
    }

    if (moves == 1000000) {
        std::cout << "botva \n";
        std::exit(0);
    }

    if (winner == 1) {
        std::cout << "first " << moves << "\n";
    }
    else if (winner == 2) {
        std::cout << "second " << moves << "\n";
    }

    return 0;
}
