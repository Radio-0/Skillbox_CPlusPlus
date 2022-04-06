/*Задание 1. Реализация деревни эльфов
Лесные эльфы расположили свою деревню в лесу, прямо на деревьях.Нужно расселить эльфов по веткам деревьев, а затем подсчитать общее количество соседей определённого эльфа.
Всего в лесу пять деревьев, на каждом из деревьев 3–5 основных больших ветвей.На каждой из них расположены ещё по 2 - 3 средние ветки.Дома эльфов построены только на больших и средних ветках.
В начале программы пользователь размещает в каждом доме по одному эльфу.Делается это с помощью последовательного перебора всех имеющихся домов и запроса имени заселяемого эльфа через стандартный ввод.Если было введено None в качестве имени, то дом пропускается и не заселяется вообще никем.
После этого требуется найти определённого эльфа по имени.Имя искомого эльфа вводится через стандартный ввод.Для данного эльфа, если таковой был найден, требуется вывести общее количество эльфов, живущих вместе с ним на одной большой ветви.
Советы и рекомендации
Реализуйте генерацию деревьев с помощью кода, используя случайные числа.Для организации структуры деревьев используйте указатель this.*/

#include <iostream>
#include <string>
#include <ctime>
#include <vector>

#define NONE_NAME   "None"
constexpr int NUMB_TREE = 5;

class MiddleBranch {
    std::string elfName = NONE_NAME;
public:
    MiddleBranch(std::string inName): elfName(inName){
        elfName = inName;
    }
    std::string getName() {
        return elfName;
    }
};

class BigBranch {
    int numbMiddle = 0;
    MiddleBranch** middle = nullptr;
public:
    MiddleBranch* getMiddle(int index) {
        return this->middle[index];
    }
    int getMiddleSize() {
        return numbMiddle;
    }
    BigBranch(int inNumbMiddle) : numbMiddle(inNumbMiddle) {
        middle = new MiddleBranch * [inNumbMiddle];
        std::string inName;
        for (int i = 0; i < numbMiddle; i++) {
            std::cout << "middle branch " << i << ": ";
            std::cin >> inName;
            middle[i] = new MiddleBranch(inName);
        }
    }
};

class Tree {
    int nubmBig = 0;
    BigBranch** big = nullptr;
public:
    BigBranch* getBig(int index) {
        return this->big[index];
    }
    int getBigSize() {
        return nubmBig;
    }
    Tree(int inNumbBig) : nubmBig(inNumbBig){
        big = new BigBranch * [inNumbBig];
        int numb = rand() % 3 + 2;
        for (int i = 0; i < nubmBig; i++) {
            std::cout << "big branch " << i << " ";
            big[i] = new BigBranch(numb);
        }
    }
};

void addElf(Tree** tree) {
    for (int i = 0; i < NUMB_TREE; i++) {
        int numbBigBranch = rand() % 5 + 3;
        std::cout << "Enter name for tree " << i << " ";
        tree[i] = new Tree(2);
    }
}

void findElf(Tree** tree){
    int numbNeighbor = 0;
    std::cout << "Enter a search name elf: ";
    std::string findElf;
    std::cin >> findElf;
    for(int t = 0; t < NUMB_TREE; t++){
        for(int b = 0; b < tree[t]->getBigSize(); b++){
            for(int m = 0; m < tree[t]->getBig(b)->getMiddleSize(); m++){
                if (findElf == tree[t]->getBig(b)->getMiddle(m)->getName()) {
                    std::cout << "Elf found: " << tree[t]->getBig(b)->getMiddle(m)->getName() << "\n";
                    for (int i = 0; i < tree[t]->getBig(b)->getMiddleSize(); i++) {
                        if (tree[t]->getBig(b)->getMiddle(i)->getName() != NONE_NAME) numbNeighbor++;
                    }
                }
            }
        }
    }
    std::cout << "Elf " << findElf << " has " << numbNeighbor - 1 << " neighbors.\n";
}

int main(){
    Tree** tree = nullptr;
    tree = new Tree*[NUMB_TREE];
    addElf(tree);
    findElf(tree);
    delete[] tree;
    tree = nullptr;
}