/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_constructor.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 16:34:53 by dande-je          #+#    #+#             */
/*   Updated: 2025/03/14 16:35:01 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/fixed/test_fixture.hpp"
#include "gtest/gtest.h"

TEST_F(FixedTest, DefaultConstructor) {
  Fixed c;
  EXPECT_EQ(c.getRawBits(), 0);
}

TEST_F(FixedTest, IntConstructor) {
  EXPECT_EQ(big.getRawBits(), expecBig << 8);
}

TEST_F(FixedTest, FloatConstructor) {
  EXPECT_NEAR(bigf.toFloat(), expecBigf, absError);
}

TEST_F(FixedTest, CopyConstructor) {
  Fixed c(small);
  EXPECT_EQ(c.getRawBits(), small.getRawBits());
}

TEST_F(FixedTest, AssignmentOperator) {
  Fixed c;
  c = small;
  EXPECT_EQ(c.getRawBits(), small.getRawBits());
}
