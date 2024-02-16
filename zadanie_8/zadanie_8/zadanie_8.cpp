// zadanie_8.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;

//enum class Color { Красный, Оранжевый, Желтый, Зеленый, Голубой, Синий, Фиолетовый };

typedef struct
{
    double S;
    int type;
   // Color color;
    union
    {
        
        double r;//для круга
        double ab[2];//для прямоугольника
        double abc[3];//для треугольника
    }Figure;
}fig;
fig f;

int main()
{
    setlocale(LC_ALL, "ru");
    while(true)
    {
        double P = M_PI;
        int otv;
        const int ξ = 15;
        double R;
        double a, b;
        bool def = true;
        double a1, b1, c;
        //Color cv;
        int numb;
        string cc = " ";
        cout << "\nВыберите цвет фигуры:\n1.Красный\n2.Оранжевый\n3.Желтый" << endl
            << "4.Зеленый\n5.Голубой\n6.Синий\n7.Фиолетовый" << endl;
        cin >> numb;
            switch (numb)
            {
            case 1:
                cc = "Красный";
                break;
            case 2:
                cc = "Оранжевый";
                break;
            case 3:
                cc = "Желтый";
                break;
            case 4:
                cc = "Зеленый";
                break;
            case 5:
                cc = "Голубой";
                break;
            case 6:
                cc = "Синий";
                break;
            case 7:
                cc = "Фиолетовый";
                break;
            default:
                cout << "такого цвета нет" << endl;
                break;
            }
        cout << "выберите тип фигуры:\n1.Круг\n2.Прямоугольник\n3.Треугольник" << endl;
        cin >> otv;
        f.type = otv;
        switch (f.type)
        {
        case 1:
           
            cout << "R= ";
            cin >> R;
            if (R <= 0) cout << "Ошибка,радиус не может быть отрицательным или равен 0" << endl;
            else
            {
                f.Figure.r = R;
                f.S = P * pow(f.Figure.r, 2);
                cout << "S circle= " << f.S;
                if (f.S < ξ)
                {
                    cout << "\nзамена на стандартную фигуру!" << endl;
                    cout << "Цвет - " << cc << endl;
                }
            }
            break;

        case 2:
          
            cout << "введите 1-ую сторону прямоугольника: " << endl;
            cin >> a;
            cout << "введите 2-ую сторону прямоугольника: " << endl;
            cin >> b;
            if (a <= 0 || b <= 0) cout << "Ошибка,сторона прямоугольника не может быть отрицательной или равна 0" << endl;
            else
            {
                f.Figure.ab[0] = a;  f.Figure.ab[1] = b;
                f.S = f.Figure.ab[0] * f.Figure.ab[1];
                cout << "S rectangle= " << f.S;

                if (f.S < ξ)
                {
                    cout << "\nзамена на стандартную фигуру!" << endl;
                    cout << "Цвет - " << cc << endl;
                }
            }
            break;

        case 3:
           
            cout << "введите 1-ую сторону треугольника: " << endl;
            cin >> a1;
            cout << "введите 2-ую сторону треугольника: " << endl;
            cin >> b1;
            cout << "введите 3-ую сторону треугольника: " << endl;
            cin >> c;
            if (a1 + b1 > c && b1 + c > a1 && a1 + c > b1)
            {
                f.Figure.abc[0] = a1; f.Figure.abc[1] = b1; f.Figure.abc[2] = c;
                double p = (f.Figure.abc[0] + f.Figure.abc[1] + f.Figure.abc[2]) / 2;//полупериметр
                f.S = sqrt(p * (p - f.Figure.abc[0]) * (p - f.Figure.abc[1]) * (p - f.Figure.abc[2]));
                cout << "S triangle= " << f.S;

                if (f.S < ξ)
                {
                    cout << "\nзамена на стандартную фигуру!" << endl;
                    cout << "Цвет - " << cc << endl;
                }
            }
            else cout << "такого треугольника не существует" << endl;
            break;

          default:
            cout << "такой фигуры нет" << endl;
            break;
        }
        
    }
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
