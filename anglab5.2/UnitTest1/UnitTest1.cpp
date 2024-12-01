#include "pch.h"
#include "CppUnitTest.h"
#include "../5.2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(TestCalculateTerm)
        {
            double x = 2.5;
            int n = 0;
            double term = 1.0 / (x * (2 * n + 1));

            calculateTerm(x, n, term);

            double expected_term = -1.0 / (x * x * x); 
            Assert::AreEqual(term, expected_term, 0.0001);
        }

        TEST_METHOD(TestCalculateSeries)
        {
            double x = 2.5;
            double eps = 1e-5;
            int n = 0;
            double s = 0.0;

            calculateSeries(x, eps, n, s);

            double expected_value = log((x + 1) / (x - 1));

            Assert::AreEqual(s, expected_value, 0.0001);
        }
    };
}