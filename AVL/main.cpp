#include "Tree.h"

void menu(int command, int i, Tree &t);

enum Command {
    INSERT = 1,
    REMOVE = 2,
    DISPLAY = 3,
    DELETE = 4,
    EXIT = 0,
};

int main() {
    setlocale(LC_ALL, "rus");

    Tree t;
    int command = 0;
    int i = 0;

    while (true) {
        menu(command, i, t);
    }

    return 0;
}

void menu(int command, int i, Tree &t) {
    std::cout << "\t\t\tМеню" << std::endl;
    std::cout << "1. Добавить вершину." << std::endl;
    std::cout << "2. Удалить вершину." << std::endl;
    std::cout << "3. Вывести вершины." << std::endl;
    std::cout << "4. Очистить дерево." << std::endl;
    std::cout << "5. Закрыть программу." << std::endl;
    std::cout << std::endl;
    std::cout << "Команды: ";
    std::cout << "INSERT=1; ";
    std::cout << "REMOVE=2; ";
    std::cout << "DISPLAY=3; ";
    std::cout << "DELETE=4; ";
    std::cout << "EXIT=0" << std::endl;
    std::cout << std::endl;

    std::cout << "Введите команду: ";
    std::cin >> command;
    switch (command) {
    case INSERT:
        std::cout << "Введите значения узла: ";
        std::cin >> i;
        t.insert(i);
        std::cout << std::endl;
        break;
    case REMOVE:
        std::cout << "Введите значения узла: ";
        std::cin >> i;
        t.remove(i);
        std::cout << std::endl;
        break;
    case DISPLAY:
        std::cout << "Упорядоченные узлы: ";
        t.display();
        std::cout << std::endl;
        break;
    case DELETE:
        t.del();
        std::cout << std::endl;
        break;
    case EXIT:
        exit(0);
    default:
        std::cout << "Не правильное значение!!!" << std::endl;
    }
}
