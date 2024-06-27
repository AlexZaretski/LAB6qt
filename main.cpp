#include <QCoreApplication>
#include <iostream>
#include <Qlist>
#include <algorithm>
#include <QtAlgorithms>
#include <Qlist>
#include <clocale>
#include <Windows.h>

using namespace std;

void show(const list<int>& a) {
    if (a.empty()) {
        cout << "Список пуст" << endl;
    } else {
        copy(a.begin(), a.end(), ostream_iterator<int>(cout, " "));
        cout << endl;
    }
}

bool comp(int l, int r) {
    if (abs(l % 2) < abs(r % 2)) return true;
    if (abs(l % 2) > abs(r % 2)) return false;
    if (abs(l % 2) == 0 && abs(r % 2) == 0) return l > r;
    if (abs(l % 2) == 1  && abs(r % 2) == 1) return l > r;
    return false;
}

int mul(int x, int y) {
    return (x * y);
}

void erN(list<int>&a, int n){
    auto r_begin = a.begin();
    auto r_end = a.begin();
    int pos=0;
    for(auto it=a.begin();it!=a.end();it++){
        if(*it==n){
            break;
        }else{
            pos++;
        }
    }
    if(pos==a.size()){
        cout<<"Такого числа нет в списке!"<<endl;
    }else{
        advance(r_begin, pos);
        advance(r_end, pos + 1);
        a.erase(r_begin, r_end);
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    setlocale(LC_ALL, "PL_pl.UTF-8");
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    cout << "1.Просмотреть состояние списка" << "\n"
         << "2.Добавить элемент" << "\n"
         << "3.Добавить несколько элементов" << "\n"
         << "4.Удалить элемент" << "\n"
         << "5.Разделить элементы на две группы, использовать (Sort)" << "\n"
         << "6.Перемножить поэлементно два списка, использовать алгоритм (transform)" << "\n"
         << "7.Выход из программы" << "\n";

    QList<int> qList = { 46, 81, -3, 98, 0, 71, 231, 882, -111 };
    QList<int> qList2 = { 7, 38, 0, -22, 77, 1, 28, 999, 12 };
    list<int> qlistA(qList.begin(), qList.end());
    list<int> qlistA2(qList2.begin(), qList2.end());

    char ch;
    auto r_begin = qlistA.begin();
    auto r_end = qlistA.begin();
    auto r_begin2 = qlistA2.begin();
    auto r_end2 = qlistA2.begin();

    while (true) {
        cout << "Выберите операцию:" << endl;
        cin >> ch;

        switch (ch) {
        case '1':
            cout << "Лист:" << endl;
            show(qlistA); // Изменено имя переменной
            break;
        case '2': {
            cout << "Введите число:" << endl;
            int el;
            cin >> el;
            qlistA.push_back(el);
            break;
        }
        case '3': {
            cout << "Введите количество:" << endl;
            int kol;
            cin >> kol;
            while (kol) {
                cout << "Введите число:" << endl;
                int el2;
                cin >> el2;
                qlistA.push_back(el2);
                kol--;
            }
            break;
        }
        case '4': {
            // cout << "Введите позицию:" << endl;
            // int pos;
            // cin >> pos;
            // advance(r_begin, pos);
            // advance(r_end, pos + 1);
            // qlistA.erase(r_begin, r_end);
            int numb;
            cout<<"Введите число: "<<endl;
            cin>>numb;
            erN(qlistA,numb);
            break;
        }
        case '5':
            qlistA.sort(comp);
            break;
        case '6':
            transform(qlistA.begin(), qlistA.end(), qlistA2.begin(), qlistA.begin(), mul);
            break;
        case '7':
            cout << "Конец программы." << endl;
            exit(EXIT_SUCCESS);
            break;
        default:
            cout << "Ошибка" << endl;
        }
    }

    return a.exec();
}
