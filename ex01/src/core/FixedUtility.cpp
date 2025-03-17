/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FixedUtility.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 02:28:59 by dande-je          #+#    #+#             */
/*   Updated: 2025/03/17 02:38:25 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/Fixed.hpp"
#include <iostream>

int Fixed::getRawBits() const {
  log("getRawBits member function called");
  return this->m_value;
}

int Fixed::toInt() const {
  return this->m_value >> this->m_fractionalBits;
}

float Fixed::toFloat() const {
  return static_cast<float>(this->m_value) / (BIT_SHIFT << this->m_fractionalBits);
}

void Fixed::setRawBits(int const raw) {
  log("setRawBits member function called");
  this->m_value = raw;
}

void Fixed::log(const std::string& str) const {
  std::cout << this->m_color.setColor(this->m_bgColor, this->m_strColor, str) << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
  os << fixed.toFloat();
  return os;
}
