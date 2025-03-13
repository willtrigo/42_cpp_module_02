/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_arithmetic.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 22:02:18 by dande-je          #+#    #+#             */
/*   Updated: 2025/03/13 00:56:44 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/fixed/test_fixture.hpp"
#include "gtest/gtest.h"

TEST_F(FixedTest, AdditionOperators) {
  EXPECT_EQ((small + big).toInt(), 52);
  EXPECT_EQ((small + bigf).toInt(), 52);
  EXPECT_NEAR((small + bigf).toFloat(), 52.4219F, 0.01F);
  EXPECT_EQ((small + big + small).toInt(), 62);
}

TEST_F(FixedTest, ArithmeticOperators) {
  EXPECT_EQ((big - small).toInt(), 32);
  EXPECT_EQ((small * big).toInt(), 420);
  EXPECT_EQ((big / small).toInt(), 4);
}

TEST_F(FixedTest, LessThanOperators) {
  EXPECT_TRUE(small < big);
  EXPECT_FALSE(big < small);
  EXPECT_FALSE(big < big);
}

TEST_F(FixedTest, GreaterThanOperators) {
  EXPECT_TRUE(big > small);
  EXPECT_FALSE(small > big);
  EXPECT_FALSE(big > big);
}

TEST_F(FixedTest, LessOrEqualOperators) {
  EXPECT_TRUE(small <= big);
  EXPECT_FALSE(big <= small);
  EXPECT_TRUE(big <= big);
}

TEST_F(FixedTest, GreaterOrEqualOperators) {
  EXPECT_TRUE(big >= small);
  EXPECT_FALSE(small >= big);
  EXPECT_TRUE(big >= big);
}

TEST_F(FixedTest, EqualityOperators) {
  EXPECT_TRUE(big == big);
  EXPECT_FALSE(small == big);
}

TEST_F(FixedTest, InequalityOperators) {
  EXPECT_TRUE(small != big);
  EXPECT_FALSE(big != big);
}

TEST_F(FixedTest, PreIncrementOperators) {
  EXPECT_EQ((++small).toInt(), 11);
  EXPECT_EQ(small.toInt(), 11);
}

TEST_F(FixedTest, PostIncrementOperators) {
  EXPECT_EQ((small++).toInt(), 10);
  EXPECT_EQ(small.toInt(), 11);
}

TEST_F(FixedTest, PreDecrementOperators) {
  EXPECT_EQ((--small).toInt(), 9);
  EXPECT_EQ(small.toInt(), 9);
}

TEST_F(FixedTest, PostDecrementOperators) {
  EXPECT_EQ((small--).toInt(), 10);
  EXPECT_EQ(small.toInt(), 9);
}
