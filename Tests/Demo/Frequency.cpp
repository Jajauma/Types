#include "Demo/Frequency.hpp"

#include <gtest/gtest.h>

TEST(Frequency, UsingCxx11Auto)
{
    auto f = 1_Hz;
    EXPECT_EQ(sizeof(f), sizeof(unsigned long long int));
    EXPECT_EQ(f.Count(), 1);
    auto g = 1.0_Hz;
    EXPECT_EQ(sizeof(g), sizeof(long double));
    EXPECT_FLOAT_EQ(g.Count(), 1.0);
}

TEST(Frequency, Hz)
{
    SI::Frequency<int> f = 144_Hz;
    EXPECT_EQ(f.Count(), 144);
    SI::Frequency<double> g = 300000.0_Hz;
    EXPECT_FLOAT_EQ(g.Count(), 300000.0);
}

TEST(Frequency, kHz)
{
    SI::Frequency<int, std::kilo> f = 125_kHz;
    EXPECT_EQ(f.Count(), 125);
    SI::Frequency<double, std::kilo> g = 300.0_kHz;
    EXPECT_FLOAT_EQ(g.Count(), 300.0);
}

TEST(Frequency, MHz)
{
    SI::Frequency<int, std::mega> f = -1_MHz;
    EXPECT_EQ(f.Count(), -1);
    SI::Frequency<double, std::mega> g = 27.5_MHz;
    EXPECT_FLOAT_EQ(g.Count(), 27.5);
}

TEST(Frequency, GHz)
{
    SI::Frequency<int, std::giga> f = 0_GHz;
    EXPECT_EQ(f.Count(), 0);
    SI::Frequency<double, std::giga> g = 3.3_GHz;
    EXPECT_FLOAT_EQ(g.Count(), 3.3);
}

TEST(Frequency, THz)
{
    SI::Frequency<int, std::tera> f = 430_THz;
    EXPECT_EQ(f.Count(), 430);
    SI::Frequency<double, std::tera> g = .11_THz;
    EXPECT_FLOAT_EQ(g.Count(), 0.11);
}
