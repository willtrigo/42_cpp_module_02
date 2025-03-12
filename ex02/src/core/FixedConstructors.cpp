/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FixedConstructors.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 15:21:53 by dande-je          #+#    #+#             */
/*   Updated: 2025/03/11 12:26:33 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/Fixed.hpp"
#include <cmath>

Fixed::Fixed() : m_value(VALUE_DEFAULT) {}

Fixed::Fixed(const int value) : m_value(value << m_fractionalBits) {}

Fixed::Fixed(const float value) : m_value(roundf(value * (BIT_SHIFT << m_fractionalBits))) {}

Fixed::Fixed(Fixed const& other) : m_value(other.getRawBits()) {}

Fixed::~Fixed() {}

Fixed& Fixed::operator=(const Fixed& other) {
  if (this != &other) {
    this->m_value = other.getRawBits();
  }
  return *this;
}
