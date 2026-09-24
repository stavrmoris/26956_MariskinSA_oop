#include <iostream>

#include "head.h"
#include "mod_head.h"

int main()
{
    int integer_a;
    int integer_b;
    std::cout << "Введите два целых числа: ";
    if (!(std::cin >> integer_a >> integer_b)) {
        std::cerr << "Некорректный ввод\n";
        return 1;
    }

    std::cout << "Обычное среднее: "
              << original::average<double>(integer_a, integer_b) << '\n';
    std::cout << "Среднее со случайной добавкой: "
              << modified::average<double>(integer_a, integer_b) << '\n';

    double double_a;
    double double_b;
    std::cout << "Введите два вещественных числа: ";
    if (!(std::cin >> double_a >> double_b)) {
        std::cerr << "Некорректный ввод\n";
        return 1;
    }

    std::cout << "Обычное среднее для double: "
              << original::average<double>(double_a, double_b) << '\n';
    std::cout << "Среднее со случайной добавкой для double: "
              << modified::average<double>(double_a, double_b) << '\n';

    double changed_a = double_a;
    by_reference::average(changed_a, double_b);
    std::cout << "Первый аргумент после вызова по ссылке: " << changed_a << '\n';
    return 0;
}
