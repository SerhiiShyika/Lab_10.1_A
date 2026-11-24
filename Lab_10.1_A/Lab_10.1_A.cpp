
// Lab_10.1_A.cpp
// Шийка Сергій Іванович
// Лабораторна робота № 10.1 А
// Варіант 31

#include <iostream>
#include <limits>
#include "Students.h"

using namespace std;

int main()
{
    int N;

    cout << "Enter number of students (1-100): ";

    while (!(cin >> N) || N < 1 || N > 100)
    {
        cout << "Incorrect number. Enter N (1-100): ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    Student* students = new Student[N];

    Create(students, N);
    Print(students, N);

    int physics, math, informatics;

    CountSatisfactory(students, N,
        physics, math, informatics);

    cout << "\nNumber of satisfactory grades (3):\n";
    cout << "Physics: " << physics << endl;
    cout << "Math: " << math << endl;
    cout << "Informatics: " << informatics << endl;

    PrintGoodStudents(students, N);

    delete[] students;

    return 0;
}
