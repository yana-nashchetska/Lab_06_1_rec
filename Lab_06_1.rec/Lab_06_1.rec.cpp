#include <iostream>  
#include <iomanip>  
#include <time.h>  
#include <windows.h>  

using namespace std;

void Generator(int* r, const int size, const int Low, const int High, int i)
{
    r[i] = Low + rand() % (High - Low + 1);
    if (i < size - 1)
        Generator(r, size, Low, High, i + 1);
}
void printGenerator(int* r, const int size, int i)
{
    cout << setw(4) << r[i];
    if (i < size - 1)
        printGenerator(r, size, i + 1);
    else
        cout << endl;
}

int Amount(int* r, const int size, int i, int A)
{
    if (i < size - 1)
    {
        if (r[i] % 4 != 0 && r[i] > 0)
        {
            A = A + 1;
            Amount(r, size, i + 1, A);
        }
        else {

            Amount(r, size, i + 1, A);
        }
    }
    else 
        return A;
}

int Sum(int* r, const int size, int i, int S)
{
    if (r[i] % 4 != 0 && r[i] > 0)
        S += r[i];
    if (i < size - 1)
        return Sum(r, size, i + 1, S);
    else
        return S;
    }

void Replace(int* r, const int size, int i)
{
    if (r[i] % 4 != 0 && r[i] > 0)
        r[i] = 0; 
    if (i < size - 1)
        Replace(r, size, i + 1);
}
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    srand((unsigned)time(NULL)); 
    const int n = 23;
    int r[n];
    int Low = -19;
    int High = 25;

    cout << "Масив з діапазону {-19, ..., 25}: " << endl;
    Generator(r, n, Low, High, 0);
    printGenerator(r, n, 0);
    cout << "--------------------------------------------------------------------------" << endl;
    cout << "Кількість елементів, які задовільняють умову = " << Amount(r, n, 0, 0);
    cout << "\n";
    cout << "Сума елементів, котрі задовільняють умову = " << Sum(r, n, 0, 0) << "\n";
    cout << endl;
    cout << "--------------------------------------------------------------------------" << endl;
    cout << "Масив, у якому числа, котрі задовільняють умову, замінені нулями: " << endl;
    Replace(r, n, 0);
    printGenerator(r, n, 0);
    cout << "--------------------------------------------------------------------------" << endl;
    return 0;
}

