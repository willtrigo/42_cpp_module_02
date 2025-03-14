/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FixedConstructors.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 16:27:51 by dande-je          #+#    #+#             */
/*   Updated: 2025/03/14 16:39:50 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/fixed/Fixed.hpp"
#include <cmath>

Fixed::Fixed() : m_value(VALUE_DEFAULT) {}

Fixed::Fixed(const int value) : m_value(value << m_fractionalBits) {}

Fixed::Fixed(const float value) : m_value(static_cast<int>(roundf(value * (BIT_SHIFT << m_fractionalBits)))) {}

Fixed::Fixed(Fixed const& other) : m_value(other.m_value) {}

Fixed::~Fixed() {}

Fixed& Fixed::operator=(const Fixed& other) {
  if (this != &other) {
    this->m_value = other.getRawBits();
  }
  return *this;
}
