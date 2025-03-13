/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_fixture.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 22:41:04 by dande-je          #+#    #+#             */
/*   Updated: 2025/03/13 00:37:10 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_FIXTURE_HPP
#define TEST_FIXTURE_HPP

#include "core/Fixed.hpp"
#include "gtest/gtest.h"

class FixedTest : public ::testing::Test {
 protected:
  FixedTest() : small(10), big(42), smallf(10.10f), bigf(42.42f) {}

  Fixed small;
  Fixed big;
  Fixed smallf;
  Fixed bigf;
};
#endif // TEST_FIXTURE_HPP
