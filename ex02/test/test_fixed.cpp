/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_fixed.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 00:06:43 by dande-je          #+#    #+#             */
/*   Updated: 2025/03/12 04:23:20 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/Fixed.hpp"
#include "gtest/gtest.h"

// Test default constructor
TEST(FixedTest, DefaultConstructor) {
    Fixed a;
    EXPECT_EQ(a.getRawBits(), 0);
}

// Test int constructor
TEST(FixedTest, IntConstructor) {
    Fixed a(42);
    EXPECT_EQ(a.getRawBits(), 42 << 8);
}

// Test float constructor
TEST(FixedTest, FloatConstructor) {
    Fixed a(3.14f);
    EXPECT_NEAR(a.toFloat(), 3.14f, 0.01f);
}

// Test copy constructor
TEST(FixedTest, CopyConstructor) {
    Fixed a(10);
    Fixed b(a);
    EXPECT_EQ(b.getRawBits(), a.getRawBits());
}

// Test assignment operator
TEST(FixedTest, AssignmentOperator) {
    Fixed a(10);
    Fixed b;
    b = a;
    EXPECT_EQ(b.getRawBits(), a.getRawBits());
}

// Test arithmetic operators
TEST(FixedTest, ArithmeticOperators) {
    Fixed a(10);
    Fixed b(20);
    EXPECT_EQ((a + b).toInt(), 30);
    EXPECT_EQ((b - a).toInt(), 10);
    EXPECT_EQ((a * b).toInt(), 200);
    EXPECT_EQ((b / a).toInt(), 2);
}

// Test comparison operators
TEST(FixedTest, ComparisonOperators) {
    Fixed a(10);
    Fixed b(20);
    EXPECT_TRUE(a < b);
    EXPECT_FALSE(a > b);
    EXPECT_TRUE(a != b);
    EXPECT_FALSE(a == b);
}

// Test increment/decrement operators
TEST(FixedTest, IncrementDecrementOperators) {
    Fixed a(10);
    EXPECT_EQ((++a).toInt(), 11);
    EXPECT_EQ((a++).toInt(), 11);
    EXPECT_EQ(a.toInt(), 12);
    EXPECT_EQ((--a).toInt(), 11);
    EXPECT_EQ((a--).toInt(), 11);
    EXPECT_EQ(a.toInt(), 10);
}

// Test utility functions
TEST(FixedTest, UtilityFunctions) {
    Fixed a(10);
    Fixed b(20);
    EXPECT_EQ(Fixed::max(a, b).toInt(), 20);
    EXPECT_EQ(Fixed::min(a, b).toInt(), 10);
}
