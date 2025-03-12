/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FixedUtility.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 12:30:41 by dande-je          #+#    #+#             */
/*   Updated: 2025/03/12 03:44:39 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/Fixed.hpp"
#include <iostream>

int Fixed::getRawBits() const {
  return this->m_value;
}

int Fixed::toInt() const {
  return this->m_value >> this->m_fractionalBits;
}

float Fixed::toFloat() const {
  return static_cast<float>(this->m_value) / (BIT_SHIFT << this->m_fractionalBits);
}

void Fixed::setRawBits(int const raw) {
  this->m_value = raw;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
  os << fixed.toFloat();
  return os;
}
