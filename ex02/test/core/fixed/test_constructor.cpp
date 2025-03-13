/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_constructor.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 00:06:43 by dande-je          #+#    #+#             */
/*   Updated: 2025/03/13 00:05:05 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/fixed/test_fixture.hpp"
#include "gtest/gtest.h"

TEST_F(FixedTest, DefaultConstructor) {
  Fixed c;
  EXPECT_EQ(c.getRawBits(), 0);
}

TEST_F(FixedTest, IntConstructor) {
  Fixed c(42);
  EXPECT_EQ(c.getRawBits(), 42 << 8);
}

TEST_F(FixedTest, FloatConstructor) {
  Fixed c(3.14f);
  EXPECT_NEAR(c.toFloat(), 3.14f, 0.01f);
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
