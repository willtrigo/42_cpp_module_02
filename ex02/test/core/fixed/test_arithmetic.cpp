/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_arithmetic.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 22:02:18 by dande-je          #+#    #+#             */
/*   Updated: 2025/03/14 01:32:03 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/fixed/test_fixture.hpp"
#include "gtest/gtest.h"
#include <cmath>

TEST_F(FixedTest, AdditionIntOperators) {
  EXPECT_EQ((mid + big).toInt(), expecMid + expecBig);
  EXPECT_EQ((mid + bigf).toInt(), static_cast<int>(round(static_cast<float>(expecMid) + expecBigf)));
  EXPECT_EQ((midf + bigf).toInt(), static_cast<int>(round(expecMidf + expecBigf)));
  EXPECT_EQ((mid + big + mid).toInt(), expecMid + expecBig + expecMid);
  EXPECT_EQ((midf + bigf + midf).toInt(), static_cast<int>(round(expecMidf + expecBigf + expecMidf)));
}

TEST_F(FixedTest, AdditionFloatOperators) {
  EXPECT_NEAR((mid + big).toFloat(), static_cast<float>(expecMid + expecBig), absError);
  EXPECT_NEAR((mid + bigf).toFloat(), static_cast<float>(expecMid) + expecBigf, absError);
  EXPECT_NEAR((midf + bigf).toFloat(), expecMidf + expecBigf, absError);
  EXPECT_NEAR((mid + big + mid).toFloat(), static_cast<float>(expecMid + expecBig + expecMid), absError);
  EXPECT_NEAR((midf + bigf + midf).toFloat(), expecMidf + expecBigf + expecMidf, absError);
}

TEST_F(FixedTest, SubtractionIntOperators) {
  EXPECT_EQ((mid - big).toInt(), expecMid - expecBig);
  EXPECT_EQ((mid - bigf).toInt(), static_cast<int>(round(static_cast<float>(expecMid) - expecBigf)));
  EXPECT_EQ((midf - bigf).toInt(), static_cast<int>(round(expecMidf - expecBigf)));
  EXPECT_EQ((mid - big - mid).toInt(), expecMid - expecBig - expecMid);
  EXPECT_EQ((midf - bigf - midf).toInt(), static_cast<int>(round(expecMidf - expecBigf - expecMidf)));
}

TEST_F(FixedTest, SubractionFloatOperators) {
  EXPECT_NEAR((mid - big).toFloat(), static_cast<float>(expecMid - expecBig), absError);
  EXPECT_NEAR((mid - bigf).toFloat(), static_cast<float>(expecMid) - expecBigf, absError);
  EXPECT_NEAR((midf - bigf).toFloat(), expecMidf - expecBigf, absError);
  EXPECT_NEAR((mid - big - mid).toFloat(), static_cast<float>(expecMid - expecBig - expecMid), absError);
  EXPECT_NEAR((midf - bigf - midf).toFloat(), expecMidf - expecBigf - expecMidf, absError);
}

TEST_F(FixedTest, MultiplicationIntOperators) {
  EXPECT_EQ((mid * big).toInt(), expecMid * expecBig);
  EXPECT_EQ((mid * bigf).toInt(), static_cast<int>(round(static_cast<float>(expecMid) * expecBigf)));
  EXPECT_EQ((midf * bigf).toInt(), static_cast<int>(round(expecMidf * expecBigf)));
  EXPECT_EQ((mid * big * mid).toInt(), expecMid * expecBig * expecMid);
  EXPECT_EQ((midf * bigf * midf).toInt(), static_cast<int>(round(expecMidf * expecBigf * expecMidf)));
}

TEST_F(FixedTest, MultiplicationFloatOperators) {
  EXPECT_NEAR((mid * big).toFloat(), static_cast<float>(expecMid * expecBig), absError);
  EXPECT_NEAR((mid * bigf).toFloat(), static_cast<float>(expecMid) * expecBigf, absError);
  EXPECT_NEAR((midf * bigf).toFloat(), expecMidf * expecBigf, absError);
  EXPECT_NEAR((mid * big * mid).toFloat(), static_cast<float>(expecMid * expecBig * expecMid), absError);
  EXPECT_NEAR((midf * bigf * midf).toFloat(), expecMidf * expecBigf * expecMidf, absError);
}

TEST_F(FixedTest, DivisionIntOperators) {
  EXPECT_EQ((mid / big).toInt(), expecMid / expecBig);
  EXPECT_EQ((mid / bigf).toInt(), static_cast<int>(round(static_cast<float>(expecMid) / expecBigf)));
  EXPECT_EQ((midf / bigf).toInt(), static_cast<int>(round(expecMidf / expecBigf)));
  EXPECT_EQ((mid / big / mid).toInt(), expecMid / expecBig / expecMid);
  EXPECT_EQ((midf / bigf / midf).toInt(), static_cast<int>(round(expecMidf / expecBigf / expecMidf)));
}

TEST_F(FixedTest, DivisionFloatOperators) {
  EXPECT_NEAR((mid / big).toFloat(), static_cast<float>(expecMid) / expecBig, absError);
  EXPECT_NEAR((mid / bigf).toFloat(), static_cast<float>(expecMid) / expecBigf, absError);
  EXPECT_NEAR((midf / bigf).toFloat(), expecMidf / expecBigf, absError);
  EXPECT_NEAR((mid / big / mid).toFloat(), static_cast<float>(expecMid) / expecBig / expecMid, absError);
  EXPECT_NEAR((midf / bigf / midf).toFloat(), expecMidf / expecBigf / expecMidf, absError);
}

TEST_F(FixedTest, DivisionByZeroOperators) {
  EXPECT_EQ((big / zero).toInt(), expecZero);
  EXPECT_EQ((big / zero).toFloat(), expecZero);
}

TEST_F(FixedTest, LessThanOperators) {
  EXPECT_TRUE(mid < big);
  EXPECT_FALSE(big < mid);
  EXPECT_FALSE(big < big);
}

TEST_F(FixedTest, GreaterThanOperators) {
  EXPECT_TRUE(big > mid);
  EXPECT_FALSE(mid > big);
  EXPECT_FALSE(big > big);
}

TEST_F(FixedTest, LessOrEqualOperators) {
  EXPECT_TRUE(mid <= big);
  EXPECT_FALSE(big <= mid);
  EXPECT_TRUE(big <= big);
}

TEST_F(FixedTest, GreaterOrEqualOperators) {
  EXPECT_TRUE(big >= mid);
  EXPECT_FALSE(mid >= big);
  EXPECT_TRUE(big >= big);
}

TEST_F(FixedTest, EqualityOperators) {
  EXPECT_TRUE(big == big);
  EXPECT_FALSE(mid == big);
}

TEST_F(FixedTest, InequalityOperators) {
  EXPECT_TRUE(mid != big);
  EXPECT_FALSE(big != big);
}

TEST_F(FixedTest, PreIncrementOperators) {
  float expecValue = expecSmall;
  EXPECT_NEAR((++small).toFloat(), expecValue + epsilon, absError);
  EXPECT_NEAR(small.toFloat(), expecValue, absError);
  expecValue = expecMid;
  EXPECT_NEAR((++mid).toFloat(), expecValue + epsilon, absError);
  EXPECT_NEAR(mid.toFloat(), expecValue, absError);
}

TEST_F(FixedTest, PostIncrementOperators) {
  float expecValue = expecSmall;
  EXPECT_NEAR((small++).toFloat(), expecValue, absError);
  EXPECT_NEAR(small.toFloat(), expecValue + epsilon, absError);
  expecValue = expecMid;
  EXPECT_NEAR((mid++).toFloat(), expecValue, absError);
  EXPECT_NEAR(mid.toFloat(), expecValue + epsilon, absError);
}

TEST_F(FixedTest, PreDecrementOperators) {
  float expecValue = expecSmall;
  EXPECT_NEAR((small--).toFloat(), expecValue, absError);
  EXPECT_NEAR(small.toFloat(), expecValue - epsilon, absError);
  expecValue = expecMid;
  EXPECT_NEAR((mid--).toFloat(), expecValue, absError);
  EXPECT_NEAR(mid.toFloat(), expecValue - epsilon, absError);
}

TEST_F(FixedTest, PostDecrementOperators) {
  float expecValue = expecSmall;
  EXPECT_NEAR((--small).toFloat(), expecValue - epsilon, absError);
  EXPECT_NEAR(small.toFloat(), expecValue, absError);
  expecValue = expecMid;
  EXPECT_NEAR((--mid).toFloat(), expecValue - epsilon, absError);
  EXPECT_NEAR(mid.toFloat(), expecValue, absError);
}
