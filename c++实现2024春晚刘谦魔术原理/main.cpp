#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
//Author:PrintX
using namespace std;  // 引入整个std命名空间

int main() {
    // 初始化牌组
    system("clear");
    vector<int> cards = {1, 2, 3, 4};
    cards.insert(cards.end(), cards.begin(), cards.end()); // 复制一份牌组

    // 名字长度 2-7 的自然数
    int name_length = 3;
    // 南方1 北方2 分不清3
    int north_south = 2;
    // 男1 女2
    int gender = 1;

    // 打印初始牌组
    cout << "初始牌组：" << endl;
    for (int card : cards) {
        cout << card << " ";
    }
    cout << endl;

    // 将队头的name_length张插入队尾
    for (int i = 0; i < name_length; ++i) {
        cards.push_back(cards.front());
        cards.erase(cards.begin());
    }

    // 打印移动牌组元素后的牌组
    cout << "移动牌组元素后：" << endl;
    for (int card : cards) {
        cout << card << " ";
    }
    cout << endl;

    // 将队头的三个元素插入中间
    vector<int> top_three(cards.begin(), cards.begin() + 3);
    vector<int> last_five(cards.begin() + 3, cards.end());
    int location = rand() % 4 + 1;
    last_five.insert(last_five.begin() + location, top_three.begin(), top_three.end());
    cards = last_five;

    // 打印移动牌组元素后的牌组
    cout << "移动牌组元素后：" << endl;
    for (int card : cards) {
        cout << card << " ";
    }
    cout << endl;

    // 记录屁股下的牌
    int under_butt = cards.front();
    cout << "屁股下的牌：" << under_butt << endl;

    // 移动牌组元素，将队头的一张牌插入到队尾
    vector<int> top_cards(cards.begin(), cards.begin() + north_south);
    vector<int> last_cards(cards.begin() + north_south, cards.end());
    location = rand() % (7 - north_south - 1) + 1;
    last_cards.insert(last_cards.begin() + location, top_cards.begin(), top_cards.end());
    cards = last_cards;

    // 打印移动牌组元素后的牌组
    cout << "移动牌组元素后：" << endl;
    for (int card : cards) {
        cout << card << " ";
    }
    cout << endl;

    // 根据性别，将对应数量的牌组队头的牌取出
    for (int i = 0; i < gender; ++i) {
        cards.erase(cards.begin());
    }

    // 打印“见证奇迹的时刻”
    cout << "见证奇迹的时刻" << endl;
    for (int i = 0; i < 7; ++i) {
        cards.push_back(cards.front());
        cards.erase(cards.begin());
        for (int card : cards) {
            cout << card << " ";
        }
        cout << endl;
    }

    // 循环移动牌组元素，直到剩下一张牌
    while (cards.size() > 1) {
        cards.push_back(cards.front());
        cards.erase(cards.begin());
        cards.erase(cards.begin());
        for (int card : cards) {
            cout << card << " ";
        }
        cout << endl;
    }

    // 检查最终牌组队头的牌是否等于之前输出的“屁股下的牌”
    if (cards.front() == under_butt) {
        cout << "魔术通过！" << endl;
    } else {
        cout << "魔术失败！" << endl;
    }

    return 0;
}
