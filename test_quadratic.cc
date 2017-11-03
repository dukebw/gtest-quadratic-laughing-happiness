#include "gtest/gtest.h"
#include <cmath>

constexpr double EPS = 0.00001;

static std::tuple<double, double>
solve_quadratic(double a, double b, double c)
{
        if ((std::abs(a) < EPS) && (std::abs(b) < EPS))
                throw std::runtime_error{"a or b must be non-zero"};

        if (std::abs(a) < EPS)
                return std::make_tuple(-c/b, -c/b);

        double under_sqrt = b*b - 4*a*c;
        if (under_sqrt < 0.0)
                throw std::runtime_error{"complex numbers not supported."};

        double sqrt_term = std::sqrt(under_sqrt);
        double left = (-b + sqrt_term)/(2*a);
        double right = (-b - sqrt_term)/(2*a);

        return std::make_tuple(left, right);
}

TEST(QuadraticTest, QuadraticTest_ab)
{
        EXPECT_THROW(solve_quadratic(0.0, 0.0, 0.0), std::runtime_error);
}

TEST(QuadraticTest, QuadraticTest_one_intercept)
{
        EXPECT_LE(std::get<0>(solve_quadratic(0.0, 2.0, 4.0)) - (-2.0), EPS);
}

int main(int argc, char **argv)
{
        ::testing::InitGoogleTest(&argc, argv);

        return RUN_ALL_TESTS();
}
