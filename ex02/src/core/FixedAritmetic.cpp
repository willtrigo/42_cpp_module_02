/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FixedAritmetic.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 21:37:41 by dande-je          #+#    #+#             */
/*   Updated: 2025/03/13 00:21:08 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/Fixed.hpp"

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
    return Fixed(this->toFloat() / other.toFloat());
}

Fixed& Fixed::operator++() {
  this->m_value += (BIT_SHIFT << this->m_fractionalBits);
  return *this;
}

Fixed Fixed::operator++(int) {
  Fixed temp(*this);
  ++(*this);
  return temp;
}

Fixed& Fixed::operator--() {
  this->m_value -= (BIT_SHIFT << this->m_fractionalBits);
  return *this;
}

Fixed Fixed::operator--(int) {
  Fixed temp(*this);
  --(*this);
  return temp;
}
