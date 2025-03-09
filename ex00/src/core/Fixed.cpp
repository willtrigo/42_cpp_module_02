/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 17:50:57 by dande-je          #+#    #+#             */
/*   Updated: 2025/03/09 19:22:29 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/Fixed.hpp"
#include "utils/TerminalColor.hpp"
#include <iostream>

Fixed::Fixed() : m_value(VALUE_DEFAULT), m_color(TerminalColor::getInstance()),  m_bgColor(BG_RESET), m_strColor(WHITE)  {
  std::cout << this->m_color.setColor(this->m_bgColor, this->m_strColor, "Default constructor called") << std::endl;
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
    this->m_value = other.getRawBits();
  }
  return *this;
}

Fixed::~Fixed() {
  std::cout << this->m_color.setColor(this->m_bgColor, this->m_strColor, "Destructor called") << std::endl;
}

int Fixed::getRawBits() const {
  std::cout << this->m_color.setColor(this->m_bgColor, this->m_strColor, "getRawBits member function called") << std::endl;
  return this->m_value;
}

void Fixed::setRawBits(int const raw) {
  std::cout << this->m_color.setColor(this->m_bgColor, this->m_strColor, "setRawBits member function called") << std::endl;
  this->m_value = raw;
}
