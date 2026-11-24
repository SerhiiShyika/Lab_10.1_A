
#include "pch.h"
#include "CppUnitTest.h"

#include <sstream>
#include <iostream>
#include <string>
#include "Students.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace Lab10_1_A_Tests
{
    TEST_CLASS(StudentTests)
    {
    public:

        // 1. Трійка з фізики
        TEST_METHOD(TestPhysics3)
        {
            Student s[1] = {};
            s[0].physics = 3;
            s[0].math = 5;
            s[0].informatics = 4;

            int p, m, inf;
            CountSatisfactory(s, 1, p, m, inf);

            Assert::AreEqual(1, p);
            Assert::AreEqual(0, m);
            Assert::AreEqual(0, inf);
        }

        // 2. Трійка з математики
        TEST_METHOD(TestMath3)
        {
            Student s[1] = {};
            s[0].physics = 4;
            s[0].math = 3;
            s[0].informatics = 5;

            int p, m, inf;
            CountSatisfactory(s, 1, p, m, inf);

            Assert::AreEqual(0, p);
            Assert::AreEqual(1, m);
            Assert::AreEqual(0, inf);
        }

        // 3. Трійка з інформатики
        TEST_METHOD(TestInformatics3)
        {
            Student s[1] = {};
            s[0].physics = 5;
            s[0].math = 4;
            s[0].informatics = 3;

            int p, m, inf;
            CountSatisfactory(s, 1, p, m, inf);

            Assert::AreEqual(0, p);
            Assert::AreEqual(0, m);
            Assert::AreEqual(1, inf);
        }

        // 4. Немає жодної трійки
        TEST_METHOD(TestNoThrees)
        {
            Student s[1] = {};
            s[0].physics = 5;
            s[0].math = 4;
            s[0].informatics = 5;

            int p, m, inf;
            CountSatisfactory(s, 1, p, m, inf);

            Assert::AreEqual(0, p);
            Assert::AreEqual(0, m);
            Assert::AreEqual(0, inf);
        }

        // 5. Трійки з усіх трьох предметів
        TEST_METHOD(TestAllThrees)
        {
            Student s[1] = {};
            s[0].physics = 3;
            s[0].math = 3;
            s[0].informatics = 3;

            int p, m, inf;
            CountSatisfactory(s, 1, p, m, inf);

            Assert::AreEqual(1, p);
            Assert::AreEqual(1, m);
            Assert::AreEqual(1, inf);
        }

        // 6. Підрахунок для кількох студентів
        TEST_METHOD(TestMultipleStudents)
        {
            Student s[3] = {};

            s[0].physics = 3;
            s[0].math = 5;
            s[0].informatics = 3;

            s[1].physics = 3;
            s[1].math = 3;
            s[1].informatics = 5;

            s[2].physics = 4;
            s[2].math = 3;
            s[2].informatics = 3;

            int p, m, inf;
            CountSatisfactory(s, 3, p, m, inf);

            Assert::AreEqual(2, p);
            Assert::AreEqual(2, m);
            Assert::AreEqual(2, inf);
        }

        // 7. Порожній масив
        TEST_METHOD(TestEmptyArray)
        {
            int p, m, inf;

            CountSatisfactory(nullptr, 0, p, m, inf);

            Assert::AreEqual(0, p);
            Assert::AreEqual(0, m);
            Assert::AreEqual(0, inf);
        }

        // 8. Студент має оцінки 4 і 5
        TEST_METHOD(TestGoodStudent)
        {
            Student s[1] = {};
            s[0].surname = "Ivanenko";
            s[0].physics = 4;
            s[0].math = 5;

            ostringstream output;
            streambuf* oldBuffer = cout.rdbuf(output.rdbuf());

            PrintGoodStudents(s, 1);

            cout.rdbuf(oldBuffer);

            Assert::IsTrue(
                output.str().find("Ivanenko") != string::npos
            );
        }

        // 9. Студент має оцінку 3 з фізики
        TEST_METHOD(TestBadStudent)
        {
            Student s[1] = {};
            s[0].surname = "Petrenko";
            s[0].physics = 3;
            s[0].math = 5;

            ostringstream output;
            streambuf* oldBuffer = cout.rdbuf(output.rdbuf());

            PrintGoodStudents(s, 1);

            cout.rdbuf(oldBuffer);

            Assert::IsTrue(
                output.str().find("No students found") != string::npos
            );

            Assert::IsTrue(
                output.str().find("Petrenko") == string::npos
            );
        }

        // 10. Із двох студентів підходить лише один
        TEST_METHOD(TestOnlyOneGoodStudent)
        {
            Student s[2] = {};

            s[0].surname = "Ivanenko";
            s[0].physics = 5;
            s[0].math = 4;

            s[1].surname = "Petrenko";
            s[1].physics = 4;
            s[1].math = 3;

            ostringstream output;
            streambuf* oldBuffer = cout.rdbuf(output.rdbuf());

            PrintGoodStudents(s, 2);

            cout.rdbuf(oldBuffer);

            Assert::IsTrue(
                output.str().find("Ivanenko") != string::npos
            );

            Assert::IsTrue(
                output.str().find("Petrenko") == string::npos
            );
        }
    };
}
