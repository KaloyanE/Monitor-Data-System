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
        cout << endl << "1. �������� �� ���� ��� �������." << endl
            << "2. �������� �� ������� ��������." << endl
            << "3. ������ �� ������ ��������." << endl
            << "4. ������ �� �������� � ���- ������ ������������ ����������." << endl
            << "5. ������ �� �������� ����� ��������." << endl
            << "6. �������� �� ������� �� ����� � �����." << endl
            << "7. �������� �� ����� �� ������/�� ������." << endl
            << "8. �������� �� ����� ��� ���������� ������." << endl
            << "9. �������� �� ������� �� ����� � �����." << endl
            << "10. ����������." << endl
            << "11. ���� �� ���������� � ��������� � ��� ����." << endl
            << "0. �����" << endl
            << "�������� �����: ";
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
                cout << endl << "1. ��������� �� ������ �������� ��������� �� ������ �����." << endl
                    << "2. ��������� �� �������� �� �������� �����, ��������� �� ����." << endl
                    << "3. ��������� �� �������� � �������� � �������� ���" << endl
                    << "4. ��������� �� �������� �� �������� ��������, ��������� � �����, ��������� �� �����." << endl
                    << "0. ������� ��� �������� ����" << endl
                    << "�������� �����: ";
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
    while (continuation != "��")
    {
        cout << "������� �: " << current + 1 << "/100" << endl << "������ �����: ";
        cin >> ar[current].serial_number;
        cout << "�����: ";
        cin >> ar[current].brand;
        cout << "�����: ";
        cin >> ar[current].model;
        cout << "����: ";
        cin >> ar[current].color;
        cout << "����: ";
        cin >> ar[current].price;
        cout << "�������� �� ������: ";
        cin >> ar[current].diagonal;
        cout << "������������ ����������: ";
        cin >> ar[current].resolution;
        cout << "������� TV ����� (��/��): ";
        cin >> ar[current].tuner;
        cin.ignore();
        cout << "���(���/����� ��������): ";
        getline(cin, ar[current].type);
        cout << "������(� ��������, ���������, ��������, � ��������):";
        getline(cin, ar[current].status);       
        if (ar[current].status == "� ��������")
        {
            cout << "������� % �� ��������: ";
            cin >> ar[current].discount;
            if (ar[current].discount == 0)
            {
                cout << "��������� �� � � ��������.";
                ar[current].status = "� ��������";
            }
        }
        current++;
        cout << "������ �� �� ���������� �� �������� ��������(��/��)?\n";
        cin >> continuation;
    }
}
void add_many(monitor ar[], int& current)
{
    int n;
    string continuation;
    cout << "����� �������� �� ��������?" << endl;
    cin >> n;    
    for (n += current; current < n; current++)
    {
        cout << "������� �: " << current + 1 << "/100" << endl << "������ �����: ";
        cin >> ar[current].serial_number;
        cout << "�����: ";
        cin >> ar[current].brand;
        cout << "�����: ";
        cin >> ar[current].model;
        cout << "����: ";
        cin >> ar[current].color;
        cout << "����: ";
        cin >> ar[current].price;
        cout << "�������� �� ������: ";
        cin >> ar[current].diagonal;
        cout << "������������ ����������: ";
        cin >> ar[current].resolution;
        cout << "������� TV ����� (��/��): ";
        cin >> ar[current].tuner;
        cout << "���(���/����� ��������): ";
        cin.ignore();
        getline(cin, ar[current].type);        
        cout << "������(� ��������, ���������, ��������, � ��������):";
        getline(cin, ar[current].status);
        if (ar[current].status == "� ��������")
        {
            cout << "������� % �� ��������: ";
            cin >> ar[current].discount;
            if (ar[current].discount == 0)
            {
                cout << "��������� �� � � ��������.";
                ar[current].status = "� ��������";
            }
        }
        cout << "������ �� �� ���������� �� �������� ��������(��/��)?\n";
        cin >> continuation;
        if (continuation == "��")
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
        cout << endl << "������ �����: "<< ar[i].serial_number
             << ", �����: " << ar[i].brand
             << ", �����: " << ar[i].model
             << ", ����: " << ar[i].color
             << ", ����: " << fixed << setprecision(2) << ar[i].price
             << ", �������� �� ������: " << ar[i].diagonal
             << ", ������������ ����������: " << ar[i].resolution
             << ", ������� TV �����: " << ar[i].tuner
             << ", ���: " << ar[i].type
             << ", ������:" << ar[i].status;
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
            cout << endl << "������ �����: " << ar[i].serial_number
                << ", �����: " << ar[i].brand
                << ", �����: " << ar[i].model
                << ", ����: " << ar[i].color
                << ", ����: " << ar[i].price
                << ", �������� �� ������: " << ar[i].diagonal
                << ", ������������ ����������: " << ar[i].resolution
                << ", ������� TV �����: " << ar[i].tuner
                << ", ���: " << ar[i].type
                << ", ������:" << ar[i].status;
        }
    }
}
void print_by_type(monitor ar[], int& current)
{
    for (int i = 0; i < current; i++)
    {
        if (ar[i].type == "����� ��������")
        {
            cout << endl << "������ �����: " << ar[i].serial_number
                << ", �����: " << ar[i].brand
                << ", �����: " << ar[i].model
                << ", ����: " << ar[i].color
                << ", ����: " << ar[i].price
                << ", �������� �� ������: " << ar[i].diagonal
                << ", ������������ ����������: " << ar[i].resolution
                << ", ������� TV �����: " << ar[i].tuner
                << ", ���: " << ar[i].type
                << ", ������:" << ar[i].status;
        }
    }
}
void correction_by_brand(monitor ar[], int& current)
{
    string brand, model;
    cout << "�������� �����: ";
    cin >> brand;
    cout << "�������� �����: ";
    cin >> model;
    for (int i = 0; i < current; i++)
    {
        if (ar[i].status == "��������")
        {
            continue;
        }
            if (ar[i].brand == brand && ar[i].model == model)
            {
                cout << endl << "����������� ������� �� ������� ��� ������ �����: " << ar[i].serial_number << endl;
                cout << "������ �����: ";
                cin >> ar[i].serial_number;
                cout << "����: ";
                cin >> ar[i].color;
                cout << "����: ";
                cin >> ar[i].price;
                cout << "�������� �� ������: ";
                cin >> ar[i].diagonal;
                cout << "������������ ����������: ";
                cin >> ar[i].resolution;
                cout << "������� TV ����� (��/��): ";
                cin >> ar[i].tuner;
                cin.ignore();
                cout << "���(���/����� ��������): ";
                getline(cin, ar[i].type);
                cout << "������(� ��������, ���������, ��������, � ��������):";
                getline(cin, ar[i].status);
                if (ar[i].status == "� ��������")
                {
                    cout << "������� % �� ��������: ";
                    cin >> ar[i].discount;
                    if (ar[i].discount == 0)
                    {
                        cout << "��������� �� � � ��������.";
                        ar[i].status = "� ��������";
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
        cout << "�������� ������ �����(��� 0 �� ����������): ";
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
                cout << endl << "����������� ������� �� ������� ��� ������ �����: " << ar[z].serial_number << endl;
                cout << "�����: ";
                cin >> ar[z].brand;
                cout << "�����: ";
                cin >> ar[z].model;
                cout << "����: ";
                cin >> ar[z].color;
                cout << "����: ";
                cin >> ar[z].price;
                cout << "�������� �� ������: ";
                cin >> ar[z].diagonal;
                cout << "������������ ����������: ";
                cin >> ar[z].resolution;
                cout << "������� TV ����� (��/��): ";
                cin >> ar[z].tuner;
                cin.ignore();
                cout << "���(���/����� ��������): ";
                getline(cin, ar[z].type);
                cout << "������(� ��������, ���������, ��������, � ��������):";
                getline(cin, ar[z].status);
                if (ar[z].status == "� ��������")
                {
                    cout << "������� % �� ��������: ";
                    cin >> ar[z].discount;
                    if (ar[z].discount == 0)
                    {
                        cout << "��������� �� � � ��������.";
                        ar[z].status = "� ��������";
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
    cout << "�� ����� ��� �� ������ �����?" << endl;    
    getline(cin,choice);   
    if (choice == "�����")
    {
        cout << "�������� �����: ";
        cin >> model;
        cout << "������� �� �� �������� � �� ������ �����(��/��)?";
        cin >> yesno;
        if (yesno == "��")
        {
            cout << "� ����� % ������� �� �������� ������ �� ���� ��������: ";
            cin >> promo;
            for (int z = 0; z < current; z++)
            {
                if (ar[z].status == "��������")
                {
                    continue;
                }
                    if (ar[z].model == model)
                    {
                        ar[z].price -= (ar[z].price * promo / 100);
                    }
                
            }
        }
        else if (yesno == "��")
        {
            int count = 0;
            for (int i = 0; i < current; i++)
            {
                cout << "�������� ������ �����(��� 0 �� ����������): ";
                cin >> sn[i];
                count++;
                if (sn[i] == 0)
                {
                    count--;
                    break;
                }
            }
            cout << "� ����� % ������� �� �������� ������ �� ���� ��������: ";
            cin >> promo;
            for (int z = 0; z < current; z++)
            {
                if (ar[z].status == "��������")
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
    else if (choice == "������ �����")
    {
        int count=0;
        for (int i = 0; i < current; i++)
        {
            cout << "�������� ������ �����(��� 0 �� ����������): ";
            cin >> sn[i];
            count++;
            if (sn[i] == 0)
            {
                count--;
                break;
            }
        }
        cout << "� ����� % ������� �� �������� ������ �� ���� ��������: ";
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
    cout << "�������� �����: ";
    cin >> brand;
    cout << "�������� �����: ";
    cin >> model;
    for (int i = 0; i < current; i++)
    {
        if (ar[i].model == model && ar[i].brand == brand)
        {
            count++;
            cout << endl << "������ �����: " << ar[i].serial_number
                << ", �����: " << ar[i].brand
                << ", �����: " << ar[i].model
                << ", ����: " << ar[i].color
                << ", ����: " << fixed << setprecision(2) << ar[i].price
                << ", �������� �� ������: " << ar[i].diagonal
                << ", ������������ ����������: " << ar[i].resolution
                << ", ������� TV �����: " << ar[i].tuner
                << ", ���: " << ar[i].type
                << ", ������:" << ar[i].status;            
        }
    }
    if (count == 0)
    {
        cout << "��������� �����" << endl;
        return;
    }
    cout << endl <<"�������� ������ �����:";
    cin >> sn;
    for (int i = 0; i < current; i++)
    {
        if (ar[i].serial_number == sn)
        {            
            ar[i].status = "��������";
        }
    }
    
}
void handsel(monitor ar[], int& current) 
{
    int sn;
    double part;
    cout << "���������� �� �������." << endl << "�������� ������ �����: ";
    cin >> sn;
    cout << "� ����� �� �� ����������: ";
    cin >> part;
    for (int i = 0; i < current; i++)
    {
        if (ar[i].serial_number == sn)
        {
            ar[i].price -= part;
            ar[i].status = "���������";
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
        if (ar[z].status == "��������" || ar[z].status == "���������")
        {
            continue;
        }
            cout << endl << "������ �����: " << ar[z].serial_number
                << ", �����: " << ar[z].brand
                << ", �����: " << ar[z].model
                << ", ����: " << ar[z].color
                << ", ����: " << fixed << setprecision(2) << ar[z].price
                << ", �������� �� ������: " << ar[z].diagonal
                << ", ������������ ����������: " << ar[z].resolution
                << ", ������� TV �����: " << ar[z].tuner
                << ", ���: " << ar[z].type
                << ", ������:" << ar[z].status;
        
    }
}
void sort_by_price(monitor ar[], int& current)
{
    string brand;
    monitor buf;
    int count = 0;
    cout << "�������� �����: ";
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
        if (brand == ar[y].brand && ar[y].status != "��������" && ar[y].status != "���������")
        {                     
            cout << endl << "������ �����: " << ar[y].serial_number
                << ", �����: " << ar[y].brand
                << ", �����: " << ar[y].model
                << ", ����: " << ar[y].color
                << ", ����: " << fixed << setprecision(2) << ar[y].price
                << ", �������� �� ������: " << ar[y].diagonal
                << ", ������������ ����������: " << ar[y].resolution
                << ", ������� TV �����: " << ar[y].tuner
                << ", ���: " << ar[y].type
                << ", ������:" << ar[y].status;
            count++;
        }
    }
    if (count == 0)
    {
        cout << "���� �������� � ������ �����.";
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
        if (ar[y].status == "� ��������")
        {
            cout << endl << "������ �����: " << ar[y].serial_number << endl
                << "����: " << fixed << setprecision(2) << ar[y].price << endl
                << "���� ���� ����������: " << fixed << setprecision(2) << (ar[y].price - (ar[y].discount*ar[y].price /100));
            count++;
        }
    }
    if (count == 0)
    {
        cout << "���� �������� � ��������.";
    }

}
void sort_by_brand(monitor ar[], int& current)
{
    monitor buf;
    string min_resolution; 
    int min_diagonal, count = 0;
    cout << "�������� ��������� ������������ ����������: ";
    cin >> min_resolution;
    cout << "�������� ��������� ��������: ";
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
        if (ar[y].tuner == "��" && min_diagonal <= ar[y].diagonal && ar[y].status != "��������" && ar[y].status != "���������")
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
                        cout << endl << "������ �����: " << ar[y].serial_number
                            << ", �����: " << ar[y].brand
                            << ", �����: " << ar[y].model
                            << ", ����: " << ar[y].color
                            << ", ����: " << fixed << setprecision(2) << ar[y].price
                            << ", �������� �� ������: " << ar[y].diagonal
                            << ", ������������ ����������: " << ar[y].resolution
                            << ", ������� TV �����: " << ar[y].tuner
                            << ", ���: " << ar[y].type
                            << ", ������:" << ar[y].status;
                        count++;
                        break;
                    }
                }
            }            
        }
    }
    if (count == 0)
    {
        cout << "���� ������ ��������.";
    }
}
void save(monitor ar[], int& current)
{
    string answer;
    fstream file;
    cout << "�� �� ������� �� ������� ��� ����?(��/��)\n";
    cin >> answer;
    if (answer == "��")
    {
        file.open("monitors.dat", ios::out);
        for (int i = 0; i < current; i++)
        {
            file << endl << "������ �����: " << ar[i].serial_number
                << ", �����: " << ar[i].brand
                << ", �����: " << ar[i].model
                << ", ����: " << ar[i].color
                << ", ����: " << fixed << setprecision(2) << ar[i].price
                << ", �������� �� ������: " << ar[i].diagonal
                << ", ������������ ����������: " << ar[i].resolution
                << ", ������� TV �����: " << ar[i].tuner
                << ", ���: " << ar[i].type
                << ", ������:" << ar[i].status;
        }
        file.close();
    }
}