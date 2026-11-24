
#include "Students.h"
#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;

static int ReadInt(const string& prompt, int minValue, int maxValue)
{
    int value;

    while (true)
    {
        cout << prompt;

        if (cin >> value && value >= minValue && value <= maxValue)
            return value;

        cout << "Incorrect value. Try again." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

static string SpecialtyToString(Specialty specialty)
{
    switch (specialty)
    {
    case COMPUTER_SCIENCE: return "Computer Science";
    case MATH_ECONOMICS: return "Math and Economics";
    case PHYSICS_INFORMATICS: return "Physics and Informatics";
    case INFORMATICS: return "Informatics";
    case LABOR_TRAINING: return "Labor Training";
    default: return "Unknown";
    }
}

void Create(Student* students, const int N)
{
    for (int i = 0; i < N; i++)
    {
        cout << "\nStudent #" << i + 1 << endl;

        cout << "Surname: ";
        cin >> students[i].surname;

        students[i].course = ReadInt("Course (1-6): ", 1, 6);

        cout << "0 - Computer Science\n";
        cout << "1 - Math and Economics\n";
        cout << "2 - Physics and Informatics\n";
        cout << "3 - Informatics\n";
        cout << "4 - Labor Training\n";

        int specialty = ReadInt("Specialty (0-4): ", 0, 4);
        students[i].specialty = static_cast<Specialty>(specialty);

        students[i].physics = ReadInt("Physics grade (1-5): ", 1, 5);
        students[i].math = ReadInt("Math grade (1-5): ", 1, 5);
        students[i].informatics = ReadInt("Informatics grade (1-5): ", 1, 5);
    }
}

void Print(const Student* students, const int N)
{
    const int W = 91;

    cout << "\nSTUDENTS TABLE\n";
    cout << string(W, '-') << endl;

    cout << "| " << setw(3) << right << "No"
        << " | " << setw(15) << left << "Surname"
        << " | " << setw(6) << right << "Course"
        << " | " << setw(23) << left << "Specialty"
        << " | " << setw(7) << right << "Physics"
        << " | " << setw(4) << right << "Math"
        << " | " << setw(11) << right << "Informatics"
        << " |" << endl;

    cout << string(W, '-') << endl;

    for (int i = 0; i < N; i++)
    {
        cout << "| " << setw(3) << right << i + 1
            << " | " << setw(15) << left << students[i].surname
            << " | " << setw(6) << right << students[i].course
            << " | " << setw(23) << left
            << SpecialtyToString(students[i].specialty)
            << " | " << setw(7) << right << students[i].physics
            << " | " << setw(4) << right << students[i].math
            << " | " << setw(11) << right << students[i].informatics
            << " |" << endl;
    }

    cout << string(W, '-') << endl;
}

void CountSatisfactory(
    const Student* students, const int N,
    int& physics, int& math, int& informatics)
{
    physics = 0;
    math = 0;
    informatics = 0;

    for (int i = 0; i < N; i++)
    {
        if (students[i].physics == 3)
            physics++;

        if (students[i].math == 3)
            math++;

        if (students[i].informatics == 3)
            informatics++;
    }
}

void PrintGoodStudents(const Student* students, const int N)
{
    bool found = false;

    cout << "\nStudents with Physics and Math grades 4 or 5:\n";

    for (int i = 0; i < N; i++)
    {
        if (students[i].physics >= 4 &&
            students[i].math >= 4)
        {
            cout << students[i].surname << endl;
            found = true;
        }
    }

    if (!found)
        cout << "No students found." << endl;
}
