#include <iostream>
#include <string>
#include <Windows.h>
#include <iomanip>
#include <stdlib.h>
#include <fstream>
using namespace std;
struct monitor {
    int serial_number, diagonal, discount;
    string brand, model, color, tuner, type, status, resolution;
    double price;
};
void add_one(monitor ar[], int& current);
void add_many(monitor ar[], int& current);
void print_all(monitor ar[], int& current);
void print_by_resolution(monitor ar[], int& current);
void print_by_type(monitor ar[], int &current);
void correction_by_brand(monitor ar[], int& current);
void correction_by_serial_number(monitor ar[], int& current);
void discount(monitor ar[], int& current);
void sell(monitor ar[], int& current);
void handsel(monitor ar[], int& current);
void sort_by_serial_number(monitor ar[], int& current);
void sort_by_price(monitor ar[], int& current);
void sort_by_discount(monitor ar[], int& current);
void sort_by_brand(monitor ar[], int& current);
void save(monitor ar[], int& current);
int main()
{
    setlocale(LC_ALL, "BG");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    monitor product[100];
    int choice, current = 0, option;
    do {
        cout << endl << "1. Добавяне на един нов монитор." << endl
            << "2. Добавяне на няколко монитора." << endl
            << "3. Списък на всички монитори." << endl
            << "4. Списък на монитори с най- голяма разделителна способност." << endl
            << "5. Списък на монитори втора употреба." << endl
            << "6. Корекция на данните по марка и модел." << endl
            << "7. Корекция на данни по сериен/ни номера." << endl
            << "8. Промоция за модел или определени бройки." << endl
            << "9. Продажба на монитор по модел и марка." << endl
            << "10. Капариране." << endl
            << "11. Одит на мониторите в наличност в под меню." << endl
            << "0. Изход" << endl
            << "Изберете опция: ";
        cin >> choice;
        cin.ignore();
        switch (choice)
        {
        case 0:
        {
            save(product, current);
            exit(1);
        }
        case 1:
        {
            cout << endl;
            add_one(product, current);
            break;
        }
        case 2:
        {
            cout << endl;
            add_many(product, current);
            break;
        }
        case 3:
        {
            cout << endl;
            print_all(product, current);
            break;
        }
        case 4:
        {
            cout << endl;
            print_by_resolution(product, current);
            break;
        }
        case 5:
        {
            cout << endl;
            print_by_type(product, current);
            break;
        }
        case 6:
        {
            cout << endl;
            correction_by_brand(product, current);
            break;
        }
        case 7:
        {
            cout << endl;
            correction_by_serial_number(product, current);
            break;
        }
        case 8:
        {
            cout << endl;
            discount(product, current);
            break;
        }
        case 9:
        {
            cout << endl;
            sell(product, current);
            break;
        }
        case 10:
        {
            cout << endl;
            handsel(product, current);
            break;
        }
        case 11:
        {
            system("cls");
            do {
                cout << endl << "1. Извеждане на всички монитори подредени по сериен номер." << endl
                    << "2. Извеждане на монитори по критерии марка, сортирани по цена." << endl
                    << "3. Извеждане на монитори в промоция в низходящ ред" << endl
                    << "4. Извеждане на монитори по критерии диагонал, резолюция и тунер, сортирани по марка." << endl
                    << "0. Връщане към главното меню" << endl
                    << "Изберете опция: ";
                    cin >> option;
                    switch (option)
                    {
                    case 0:
                        break;
                    case 1:
                    {
                        cout << endl;
                        sort_by_serial_number(product, current);
                        break;
                    }
                    case 2:
                    {
                        cout << endl;
                        sort_by_price(product, current);
                        break;
                    }
                    case 3:
                    {
                        cout << endl;
                        sort_by_discount(product, current);
                        break;
                    }
                    case 4:
                    {
                        cout << endl;
                        sort_by_brand(product, current);
                        break;
                    }
                    }
            } while (option != 0);
            break;
        }
        }
    } while (true);
}
void add_one(monitor ar[], int &current)
{ 
    string continuation;
    while (continuation != "не")
    {
        cout << "Монитор №: " << current + 1 << "/100" << endl << "Сериен номер: ";
        cin >> ar[current].serial_number;
        cout << "Марка: ";
        cin >> ar[current].brand;
        cout << "Модел: ";
        cin >> ar[current].model;
        cout << "Цвят: ";
        cin >> ar[current].color;
        cout << "Цена: ";
        cin >> ar[current].price;
        cout << "Диагонал на екрана: ";
        cin >> ar[current].diagonal;
        cout << "Разделителна способност: ";
        cin >> ar[current].resolution;
        cout << "Вграден TV тунер (да/не): ";
        cin >> ar[current].tuner;
        cin.ignore();
        cout << "Тип(нов/втора употреба): ";
        getline(cin, ar[current].type);
        cout << "Статус(в продажба, капариран, продаден, в промоция):";
        getline(cin, ar[current].status);       
        if (ar[current].status == "в промоция")
        {
            cout << "Укажете % на отстъпка: ";
            cin >> ar[current].discount;
            if (ar[current].discount == 0)
            {
                cout << "Продуктът не е в промоция.";
                ar[current].status = "в продажба";
            }
        }
        current++;
        cout << "Искате ли да продължите да добавяте монитори(да/не)?\n";
        cin >> continuation;
    }
}
void add_many(monitor ar[], int& current)
{
    int n;
    string continuation;
    cout << "Колко монитора ще добавите?" << endl;
    cin >> n;    
    for (n += current; current < n; current++)
    {
        cout << "Монитор №: " << current + 1 << "/100" << endl << "Сериен номер: ";
        cin >> ar[current].serial_number;
        cout << "Марка: ";
        cin >> ar[current].brand;
        cout << "Модел: ";
        cin >> ar[current].model;
        cout << "Цвят: ";
        cin >> ar[current].color;
        cout << "Цена: ";
        cin >> ar[current].price;
        cout << "Диагонал на екрана: ";
        cin >> ar[current].diagonal;
        cout << "Разделителна способност: ";
        cin >> ar[current].resolution;
        cout << "Вграден TV тунер (да/не): ";
        cin >> ar[current].tuner;
        cout << "Тип(нов/втора употреба): ";
        cin.ignore();
        getline(cin, ar[current].type);        
        cout << "Статус(в продажба, капариран, продаден, в промоция):";
        getline(cin, ar[current].status);
        if (ar[current].status == "в промоция")
        {
            cout << "Укажете % на отстъпка: ";
            cin >> ar[current].discount;
            if (ar[current].discount == 0)
            {
                cout << "Продуктът не е в промоция.";
                ar[current].status = "в продажба";
            }
        }
        cout << "Искате ли да продължите да добавяте монитори(да/не)?\n";
        cin >> continuation;
        if (continuation == "не")
        {
            current++;
            break;
        }
    }
}
void print_all(monitor ar[], int &current)
{
    for (int i = 0; i < current;i++)
    {
        cout << endl << "Сериен номер: "<< ar[i].serial_number
             << ", Марка: " << ar[i].brand
             << ", Модел: " << ar[i].model
             << ", Цвят: " << ar[i].color
             << ", Цена: " << fixed << setprecision(2) << ar[i].price
             << ", Диагонал на екрана: " << ar[i].diagonal
             << ", Разделителна способност: " << ar[i].resolution
             << ", Вграден TV тунер: " << ar[i].tuner
             << ", Тип: " << ar[i].type
             << ", Статус:" << ar[i].status;
    }
}
void print_by_resolution(monitor ar[], int &current)
{
    string max_resolution = ar[0].resolution;
    for (int i = 1; i < current; i++)
    {   
        if (max_resolution.length() > ar[i].resolution.length())
        {
            continue;
        }
        else
        {
            for (int y = 0; y < ar[i].resolution.length(); y++)
            {
                if (max_resolution[y] < ar[i].resolution[y])
                {
                    max_resolution = ar[i].resolution;
                    break;
                }
            }
        }        
    }
    for (int i = 0; i < current; i++)
    {
        if (max_resolution == ar[i].resolution)
        {
            cout << endl << "Сериен номер: " << ar[i].serial_number
                << ", Марка: " << ar[i].brand
                << ", Модел: " << ar[i].model
                << ", Цвят: " << ar[i].color
                << ", Цена: " << ar[i].price
                << ", Диагонал на екрана: " << ar[i].diagonal
                << ", Разделителна способност: " << ar[i].resolution
                << ", Вграден TV тунер: " << ar[i].tuner
                << ", Тип: " << ar[i].type
                << ", Статус:" << ar[i].status;
        }
    }
}
void print_by_type(monitor ar[], int& current)
{
    for (int i = 0; i < current; i++)
    {
        if (ar[i].type == "втора употреба")
        {
            cout << endl << "Сериен номер: " << ar[i].serial_number
                << ", Марка: " << ar[i].brand
                << ", Модел: " << ar[i].model
                << ", Цвят: " << ar[i].color
                << ", Цена: " << ar[i].price
                << ", Диагонал на екрана: " << ar[i].diagonal
                << ", Разделителна способност: " << ar[i].resolution
                << ", Вграден TV тунер: " << ar[i].tuner
                << ", Тип: " << ar[i].type
                << ", Статус:" << ar[i].status;
        }
    }
}
void correction_by_brand(monitor ar[], int& current)
{
    string brand, model;
    cout << "Въведете марка: ";
    cin >> brand;
    cout << "Въведете модел: ";
    cin >> model;
    for (int i = 0; i < current; i++)
    {
        if (ar[i].status == "продаден")
        {
            continue;
        }
            if (ar[i].brand == brand && ar[i].model == model)
            {
                cout << endl << "Коригирайте данните на монитор със сериен номер: " << ar[i].serial_number << endl;
                cout << "Сериен номер: ";
                cin >> ar[i].serial_number;
                cout << "Цвят: ";
                cin >> ar[i].color;
                cout << "Цена: ";
                cin >> ar[i].price;
                cout << "Диагонал на екрана: ";
                cin >> ar[i].diagonal;
                cout << "Разделителна способност: ";
                cin >> ar[i].resolution;
                cout << "Вграден TV тунер (да/не): ";
                cin >> ar[i].tuner;
                cin.ignore();
                cout << "Тип(нов/втора употреба): ";
                getline(cin, ar[i].type);
                cout << "Статус(в продажба, капариран, продаден, в промоция):";
                getline(cin, ar[i].status);
                if (ar[i].status == "в промоция")
                {
                    cout << "Укажете % на отстъпка: ";
                    cin >> ar[i].discount;
                    if (ar[i].discount == 0)
                    {
                        cout << "Продуктът не е в промоция.";
                        ar[i].status = "в продажба";
                    }
                }
            }
    }
}
void correction_by_serial_number(monitor ar[], int& current)
{
    int sn[100], count = 0;    
    for (int i = 0; i < current; i++)
    {
        cout << "Въведете сериен номер(или 0 за прекъсване): ";
        cin >> sn[i];
        count++;
        if (sn[i] == 0)
        {
            count--;
            break;
        }                         
    }
    for (int z = 0; z < current; z++)
    {
        for (int y = 0; y < count; y++)
        {
            if (sn[y] == ar[z].serial_number)
            {
                cout << endl << "Коригирайте данните на монитор със сериен номер: " << ar[z].serial_number << endl;
                cout << "Марка: ";
                cin >> ar[z].brand;
                cout << "Модел: ";
                cin >> ar[z].model;
                cout << "Цвят: ";
                cin >> ar[z].color;
                cout << "Цена: ";
                cin >> ar[z].price;
                cout << "Диагонал на екрана: ";
                cin >> ar[z].diagonal;
                cout << "Разделителна способност: ";
                cin >> ar[z].resolution;
                cout << "Вграден TV тунер (да/не): ";
                cin >> ar[z].tuner;
                cin.ignore();
                cout << "Тип(нов/втора употреба): ";
                getline(cin, ar[z].type);
                cout << "Статус(в продажба, капариран, продаден, в промоция):";
                getline(cin, ar[z].status);
                if (ar[z].status == "в промоция")
                {
                    cout << "Укажете % на отстъпка: ";
                    cin >> ar[z].discount;
                    if (ar[z].discount == 0)
                    {
                        cout << "Продуктът не е в промоция.";
                        ar[z].status = "в продажба";
                    }
                }
            }
        }
    }
}
void discount(monitor ar[], int& current)
{
    int sn[100], promo;
    string model, choice, yesno;    
    cout << "По модел или по сериен номер?" << endl;    
    getline(cin,choice);   
    if (choice == "модел")
    {
        cout << "Въведете модел: ";
        cin >> model;
        cout << "Желаете ли да изберете и по сериен номер(да/не)?";
        cin >> yesno;
        if (yesno == "не")
        {
            cout << "С колко % желаете да намалите цената на тези монитори: ";
            cin >> promo;
            for (int z = 0; z < current; z++)
            {
                if (ar[z].status == "продаден")
                {
                    continue;
                }
                    if (ar[z].model == model)
                    {
                        ar[z].price -= (ar[z].price * promo / 100);
                    }
                
            }
        }
        else if (yesno == "да")
        {
            int count = 0;
            for (int i = 0; i < current; i++)
            {
                cout << "Въведете сериен номер(или 0 за прекъсване): ";
                cin >> sn[i];
                count++;
                if (sn[i] == 0)
                {
                    count--;
                    break;
                }
            }
            cout << "С колко % желаете да намалите цената на тези монитори: ";
            cin >> promo;
            for (int z = 0; z < current; z++)
            {
                if (ar[z].status == "продаден")
                {
                    continue;
                }
                    if (ar[z].model == model)
                    {
                        ar[z].price -= (ar[z].price * promo / 100);
                    }
                    for (int y = 0; y < count; y++)
                    {
                        if (ar[z].serial_number == sn[y])
                        {
                            ar[z].price -= (ar[z].price * promo / 100);
                        }
                    }
            }
        }
    }
    else if (choice == "сериен номер")
    {
        int count=0;
        for (int i = 0; i < current; i++)
        {
            cout << "Въведете сериен номер(или 0 за прекъсване): ";
            cin >> sn[i];
            count++;
            if (sn[i] == 0)
            {
                count--;
                break;
            }
        }
        cout << "С колко % желаете да намалите цената на тези монитори: ";
        cin >> promo;
        for (int z = 0; z < current; z++)
        {            
            for (int y = 0; y < count; y++)
            {
                if (ar[z].serial_number == sn[y])
                {
                    ar[z].price -= (ar[z].price * promo / 100);
                }
            }
        }
    }
} 
void sell(monitor ar[], int& current)
{
    int count = 0, sn;
    string brand, model;
    cout << "Въведете марка: ";
    cin >> brand;
    cout << "Въведете модел: ";
    cin >> model;
    for (int i = 0; i < current; i++)
    {
        if (ar[i].model == model && ar[i].brand == brand)
        {
            count++;
            cout << endl << "Сериен номер: " << ar[i].serial_number
                << ", Марка: " << ar[i].brand
                << ", Модел: " << ar[i].model
                << ", Цвят: " << ar[i].color
                << ", Цена: " << fixed << setprecision(2) << ar[i].price
                << ", Диагонал на екрана: " << ar[i].diagonal
                << ", Разделителна способност: " << ar[i].resolution
                << ", Вграден TV тунер: " << ar[i].tuner
                << ", Тип: " << ar[i].type
                << ", Статус:" << ar[i].status;            
        }
    }
    if (count == 0)
    {
        cout << "Невалидни данни" << endl;
        return;
    }
    cout << endl <<"Изберете сериен номер:";
    cin >> sn;
    for (int i = 0; i < current; i++)
    {
        if (ar[i].serial_number == sn)
        {            
            ar[i].status = "продаден";
        }
    }
    
}
void handsel(monitor ar[], int& current) 
{
    int sn;
    double part;
    cout << "Капариране на монитор." << endl << "Изберете сериен номер: ";
    cin >> sn;
    cout << "С колко ще го капарирате: ";
    cin >> part;
    for (int i = 0; i < current; i++)
    {
        if (ar[i].serial_number == sn)
        {
            ar[i].price -= part;
            ar[i].status = "капариран";
            break;
        }
    }   
}
void sort_by_serial_number(monitor ar[], int& current)
{
    monitor buf;
    for (int i = 0; i < current - 1; i++)
    {
            for (int k = 0; k < current - i - 1; k++)
            {
                if (ar[k].serial_number < ar[k + 1].serial_number)
                {
                    buf = ar[k];
                    ar[k] = ar[k + 1];
                    ar[k + 1] = buf;
                }
            }
    }    
    for (int z = 0; z < current; z++)
    {
        if (ar[z].status == "продаден" || ar[z].status == "капариран")
        {
            continue;
        }
            cout << endl << "Сериен номер: " << ar[z].serial_number
                << ", Марка: " << ar[z].brand
                << ", Модел: " << ar[z].model
                << ", Цвят: " << ar[z].color
                << ", Цена: " << fixed << setprecision(2) << ar[z].price
                << ", Диагонал на екрана: " << ar[z].diagonal
                << ", Разделителна способност: " << ar[z].resolution
                << ", Вграден TV тунер: " << ar[z].tuner
                << ", Тип: " << ar[z].type
                << ", Статус:" << ar[z].status;
        
    }
}
void sort_by_price(monitor ar[], int& current)
{
    string brand;
    monitor buf;
    int count = 0;
    cout << "Изберете марка: ";
    cin >> brand;    
    for (int i = 0; i < current - 1; i++)
    {
        for (int k = 0; k < current - i - 1; k++)
        {
            if (ar[k].price > ar[k + 1].price)
            {
                buf = ar[k];
                ar[k] = ar[k + 1];
                ar[k + 1] = buf;
            }
        }
    }
    for (int y = 0; y < current; y++)
    {
        if (brand == ar[y].brand && ar[y].status != "продаден" && ar[y].status != "капариран")
        {                     
            cout << endl << "Сериен номер: " << ar[y].serial_number
                << ", Марка: " << ar[y].brand
                << ", Модел: " << ar[y].model
                << ", Цвят: " << ar[y].color
                << ", Цена: " << fixed << setprecision(2) << ar[y].price
                << ", Диагонал на екрана: " << ar[y].diagonal
                << ", Разделителна способност: " << ar[y].resolution
                << ", Вграден TV тунер: " << ar[y].tuner
                << ", Тип: " << ar[y].type
                << ", Статус:" << ar[y].status;
            count++;
        }
    }
    if (count == 0)
    {
        cout << "Няма монитори с такава марка.";
    }
}
void sort_by_discount(monitor ar[], int& current)
{
    monitor buf;
    int count = 0;
    for (int i = 0; i < current - 1; i++)
    {
        for (int k = 0; k < current - i - 1; k++)
        {
            if (ar[k].price < ar[k + 1].price)
            {
                buf = ar[k];
                ar[k] = ar[k + 1];
                ar[k + 1] = buf;
            }
        }
    }
    for (int y = 0; y < current; y++)
    {
        if (ar[y].status == "в промоция")
        {
            cout << endl << "Сериен номер: " << ar[y].serial_number << endl
                << "Цена: " << fixed << setprecision(2) << ar[y].price << endl
                << "Цена след отстъпката: " << fixed << setprecision(2) << (ar[y].price - (ar[y].discount*ar[y].price /100));
            count++;
        }
    }
    if (count == 0)
    {
        cout << "Няма монитори в промоция.";
    }

}
void sort_by_brand(monitor ar[], int& current)
{
    monitor buf;
    string min_resolution; 
    int min_diagonal, count = 0;
    cout << "Въведете минимална разделителна способност: ";
    cin >> min_resolution;
    cout << "Въведете минимален диагонал: ";
    cin >> min_diagonal;
    for (int z = 0; z < current - 1; z++)
    {
        for (int k = 0; k < current - z - 1; k++)
        {
            if (ar[k].brand.length() < ar[k + 1].brand.length())
            {
                buf = ar[k];
                ar[k] = ar[k + 1];
                ar[k + 1] = buf;
            }
        }
    }
    for (int y = 0; y < current; y++)
    {
        if (ar[y].tuner == "да" && min_diagonal <= ar[y].diagonal && ar[y].status != "продаден" && ar[y].status != "капариран")
        {
            if (min_resolution.length() > ar[y].resolution.length())
            {
                continue;
            }
            else
            {
                for (int i = 0; i < min_resolution.length(); i++)
                {
                    if (min_resolution[i] < ar[y].resolution[i] || min_resolution == ar[y].resolution)
                    {
                        cout << endl << "Сериен номер: " << ar[y].serial_number
                            << ", Марка: " << ar[y].brand
                            << ", Модел: " << ar[y].model
                            << ", Цвят: " << ar[y].color
                            << ", Цена: " << fixed << setprecision(2) << ar[y].price
                            << ", Диагонал на екрана: " << ar[y].diagonal
                            << ", Разделителна способност: " << ar[y].resolution
                            << ", Вграден TV тунер: " << ar[y].tuner
                            << ", Тип: " << ar[y].type
                            << ", Статус:" << ar[y].status;
                        count++;
                        break;
                    }
                }
            }            
        }
    }
    if (count == 0)
    {
        cout << "Няма такива монитори.";
    }
}
void save(monitor ar[], int& current)
{
    string answer;
    fstream file;
    cout << "Да се запишат ли данните във файл?(да/не)\n";
    cin >> answer;
    if (answer == "да")
    {
        file.open("monitors.dat", ios::out);
        for (int i = 0; i < current; i++)
        {
            file << endl << "Сериен номер: " << ar[i].serial_number
                << ", Марка: " << ar[i].brand
                << ", Модел: " << ar[i].model
                << ", Цвят: " << ar[i].color
                << ", Цена: " << fixed << setprecision(2) << ar[i].price
                << ", Диагонал на екрана: " << ar[i].diagonal
                << ", Разделителна способност: " << ar[i].resolution
                << ", Вграден TV тунер: " << ar[i].tuner
                << ", Тип: " << ar[i].type
                << ", Статус:" << ar[i].status;
        }
        file.close();
    }
}