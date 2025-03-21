/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FixedArithmetic.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 16:27:22 by dande-je          #+#    #+#             */
/*   Updated: 2025/03/14 16:39:43 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/fixed/Fixed.hpp"

bool Fixed::operator>(const Fixed& other) const {
  return this->m_value > other.m_value;
}

bool Fixed::operator<(const Fixed& other) const {
  return this->m_value < other.m_value;
}

bool Fixed::operator>=(const Fixed& other) const {
  return this->m_value >= other.m_value;
}

bool Fixed::operator<=(const Fixed& other) const {
  return this->m_value <= other.m_value;
}

bool Fixed::operator==(const Fixed& other) const {
  return this->m_value == other.m_value;
}

bool Fixed::operator!=(const Fixed& other) const {
  return this->m_value != other.m_value;
}

Fixed Fixed::operator+(const Fixed& other) const {
  return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed& other) const {
  return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed& other) const {
  return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed& other) const {
  if (other.toFloat() == VALUE_DEFAULT)
    return Fixed();
  return Fixed(this->toFloat() / other.toFloat());
}

Fixed& Fixed::operator++() {
  this->m_value++;
  return *this;
}

Fixed Fixed::operator++(int) {
	return Fixed(static_cast<float>(this->m_value++) / (BIT_SHIFT << this->m_fractionalBits));
}

Fixed& Fixed::operator--() {
  this->m_value--;
  return *this;
}

Fixed Fixed::operator--(int) {
	return Fixed(static_cast<float>(this->m_value--) / (BIT_SHIFT << this->m_fractionalBits));
}
