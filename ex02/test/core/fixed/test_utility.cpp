/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_utility.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 23:26:37 by dande-je          #+#    #+#             */
/*   Updated: 2025/03/14 00:37:23 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/fixed/test_fixture.hpp"
#include "gtest/gtest.h"

TEST_F(FixedTest, MaxFunction) {
  EXPECT_EQ(Fixed::max(small, big).toInt(), expecBig);
  EXPECT_EQ(Fixed::max(big, big).toInt(), expecBig);
}

TEST_F(FixedTest, MinFunction) {
  EXPECT_EQ(Fixed::min(small, big).toInt(), expecSmall);
  EXPECT_EQ(Fixed::min(small, small).toInt(), expecSmall);
}
