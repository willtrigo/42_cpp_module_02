/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 21:49:26 by dande-je          #+#    #+#             */
/*   Updated: 2025/03/09 15:08:13 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/Fixed.hpp"
#include "utils/TerminalColor.hpp"
#include <iostream>

Fixed::Fixed() : m_raw(RAW_DEFAULT), m_color(TerminalColor::getInstance()), m_strColor(WHITE), m_bgColor(BG_RESET)  {
  std::cout << this->m_color.setColor(this->m_bgColor, this->m_strColor, "Default constructor called") << std::endl;
}

Fixed::Fixed(const int value) : m_color(TerminalColor::getInstance()), m_strColor(YELLOW), m_bgColor(BG_RESET) {
  this->m_raw = value << this->m_fractionalBits;
  std::cout << this->m_color.setColor(this->m_bgColor, this->m_strColor, "Int constructor called") << std::endl;
}

Fixed::Fixed(const float value) : m_color(TerminalColor::getInstance()), m_strColor(RED), m_bgColor(BG_RESET) {
  this->m_raw = roundf(value * (BIT_SHIFT << this->m_fractionalBits));
  std::cout << this->m_color.setColor(this->m_bgColor, this->m_strColor, "Float constructor called") << std::endl;
}

Fixed::Fixed(Fixed const& other) : m_color(TerminalColor::getInstance()) {
  std::cout << this->m_color.setColor(BG_RESET, BLUE, "Copy constructor called") << std::endl;
  *this = other;
  this->m_strColor = BLUE;
  this->m_bgColor = BG_RESET;
}

Fixed& Fixed::operator=(const Fixed& other) {
  if (this != &other) {
    std::cout << this->m_color.setColor(BG_RESET, ORANGE, "Copy assignment operator called") << std::endl;
    this->m_strColor = ORANGE;
    this->m_bgColor = BG_RESET;
    this->m_raw = other.m_raw;
  }
  return *this;
}

std::ostream &operator<<(std::ostream& os, const Fixed& fixed) {
  os << fixed.toFloat();
  return os;
}

Fixed::~Fixed() {
  std::cout << this->m_color.setColor(this->m_bgColor, this->m_strColor, "Destructor called") << std::endl;
}

int Fixed::getRawBits() const {
  std::cout << this->m_color.setColor(this->m_bgColor, this->m_strColor, "getRawBits member function called") << std::endl;
  return this->m_raw;
}

void Fixed::setRawBits(int const raw) {
  std::cout << this->m_color.setColor(this->m_bgColor, this->m_strColor, "setRawBits member function called") << std::endl;
  this->m_raw = raw;
}

float Fixed::toFloat() const {
  return (float)this->m_raw / (BIT_SHIFT << this->m_fractionalBits);
}

int Fixed::toInt() const {
  return this->m_raw >> this->m_fractionalBits;
}
