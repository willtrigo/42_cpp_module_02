/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_fixture.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 16:35:17 by dande-je          #+#    #+#             */
/*   Updated: 2025/03/14 16:40:23 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_FIXTURE_HPP
#define TEST_FIXTURE_HPP

#include "core/fixed/Fixed.hpp"
#include "gtest/gtest.h"

class FixedTest : public ::testing::Test {
 protected:
  FixedTest() 
    : small(-10),
      mid(9),
      big(42),
      zero(0),
      smallf(-10.f),
      midf(9.f),
      bigf(42.f),
      zerof(0.f),
      expecSmall(-10),
      expecMid(9),
      expecBig(42),
      expecSmallf(-10.f),
      expecMidf(9.f),
      expecBigf(42.f),
      expecZero(0),
      epsilon(0.00390625f),
      absError(0.01f) {}

  int expecSmall;
  int expecMid;
  int expecBig;
  int expecZero;
  float expecSmallf;
  float expecMidf;
  float expecBigf;
  float epsilon;
  float absError;

  Fixed small;
  Fixed mid;
  Fixed big;
  Fixed zero;
  Fixed smallf;
  Fixed midf;
  Fixed bigf;
  Fixed zerof;
};
#endif // TEST_FIXTURE_HPP
