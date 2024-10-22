// Lab_7_1.cpp
// < Пушкаш Максим >
// Лабораторна робота № 7.1.
// Пошук заданих елементів та впорядкування рядків / стовпчиків матриці.
// Варіант 11

#include <iostream>
#include <iomanip>
#include <ctime> 
using namespace std;

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High);

void Print(int** a, const int rowCount, const int colCount); 

void Calc(int** a, const int rowCount, const int colCount, int& S, int& k); 

void Sort(int** a, const int rowCount, const int colCount); 


int main() 
{
    srand((unsigned)time(NULL)); 

    const int Low = 7;   
    const int High = 62; 
    const int rowCount = 7;
    const int colCount = 6;

    
    int** a = new int* [rowCount];
    for (int i = 0; i < rowCount; i++) 
    {
        a[i] = new int[colCount];
    }

    
    Create(a, rowCount, colCount, Low, High);
    Print(a, rowCount, colCount);

    
    Sort(a, rowCount, colCount);
    Print(a, rowCount, colCount);

    
    int S = 0, k = 0;
    Calc(a, rowCount, colCount, S, k);

    
    cout << "Сума парних елементів: " << S << endl;
    cout << "Кількість парних елементів: " << k << endl;

    
    Print(a, rowCount, colCount);

    
    for (int i = 0; i < rowCount; i++) 
    {
        delete[] a[i];
    }
    delete[] a;

    return 0;
}

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High) 
{
    for (int i = 0; i < rowCount; i++) 
    {
        for (int j = 0; j < colCount; j++) 
        {
            a[i][j] = Low + rand() % (High - Low + 1); 
        }
    }
}


void Print(int** a, const int rowCount, const int colCount) 
{
    cout << endl;
    for (int i = 0; i < rowCount; i++) 
    {
        for (int j = 0; j < colCount; j++) 
        {
            cout << setw(4) << a[i][j]; 
        }
        cout << endl;
    }
    cout << endl;
}


void Calc(int** a, const int rowCount, const int colCount, int& S, int& k) 
{
    S = 0;
    k = 0;
    for (int i = 0; i < rowCount; i++) 
    {
        for (int j = 0; j < colCount; j++) 
        {
            if (a[i][j] % 2 == 0 && ((i + j) % 8 != 0)) 
            { 
                S += a[i][j];
                k++;
                a[i][j] = 0; 
            }
        }
    }
}


void Sort(int** a, const int rowCount, const int colCount) 
{
    for (int j = 0; j < colCount; j++) 
    {
        for (int i0 = 0; i0 < rowCount - 1; i0++) 
        {
            for (int i1 = 0; i1 < rowCount - i0 - 1; i1++) 
            {
                
                if ((a[i1][j] < a[i1 + 1][j]) || (a[i1][j] == a[i1 + 1][j] && a[i1][1] < a[i1 + 1][1])) 
                {
                    
                    for (int k = 0; k < colCount; k++) 
                    {
                        swap(a[i1][k], a[i1 + 1][k]);
                    }
                }
            }
        }
    }
}