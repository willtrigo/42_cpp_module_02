/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_utility.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 23:26:37 by dande-je          #+#    #+#             */
/*   Updated: 2025/03/13 00:05:10 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/fixed/test_fixture.hpp"
#include "gtest/gtest.h"

TEST_F(FixedTest, MaxFunction) {
  EXPECT_EQ(Fixed::max(small, big).toInt(), 42);
  EXPECT_EQ(Fixed::max(big, big).toInt(), 42);
}

TEST_F(FixedTest, MinFunction) {
  EXPECT_EQ(Fixed::min(small, big).toInt(), 10);
  EXPECT_EQ(Fixed::min(small, small).toInt(), 10);
}
