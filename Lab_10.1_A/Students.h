
#pragma once
#include <string>

enum Specialty
{
    COMPUTER_SCIENCE,
    MATH_ECONOMICS,
    PHYSICS_INFORMATICS,
    INFORMATICS,
    LABOR_TRAINING
};

struct Student
{
    std::string surname;
    int course;
    Specialty specialty;
    int physics;
    int math;
    int informatics;
};

void Create(Student* students, const int N);
void Print(const Student* students, const int N);

void CountSatisfactory(
    const Student* students, const int N,
    int& physics, int& math, int& informatics);

void PrintGoodStudents(const Student* students, const int N);
