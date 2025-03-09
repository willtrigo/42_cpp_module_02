/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 17:50:57 by dande-je          #+#    #+#             */
/*   Updated: 2025/03/09 14:35:19 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/Fixed.hpp"
#include "utils/TerminalColor.hpp"
#include <iostream>

Fixed::Fixed() : m_raw(RAW_DEFAULT), m_color(TerminalColor::getInstance()), m_str_color(WHITE), m_bg_color(BG_RESET)  {
  std::cout << this->m_color.setColor(this->m_bg_color, this->m_str_color, "Default constructor called") << std::endl;
}

Fixed::Fixed(Fixed const& other) : m_color(TerminalColor::getInstance()) {
  std::cout << this->m_color.setColor(BG_RESET, BLUE, "Copy constructor called") << std::endl;
  *this = other;
  this->m_str_color = BLUE;
  this->m_bg_color = BG_RESET;
}

Fixed& Fixed::operator=(const Fixed& other) {
  if (this != &other) {
    std::cout << this->m_color.setColor(BG_RESET, ORANGE, "Copy assignment operator called") << std::endl;
    this->m_str_color = ORANGE;
    this->m_bg_color = BG_RESET;
    this->m_raw = other.getRawBits();
  }
  return *this;
}

Fixed::~Fixed() {
  std::cout << this->m_color.setColor(this->m_bg_color, this->m_str_color, "Destructor called") << std::endl;
}

int Fixed::getRawBits() const {
  std::cout << this->m_color.setColor(this->m_bg_color, this->m_str_color, "getRawBits member function called") << std::endl;
  return this->m_raw;
}

void Fixed::setRawBits(int const raw) {
  std::cout << this->m_color.setColor(this->m_bg_color, this->m_str_color, "setRawBits member function called") << std::endl;
  this->m_raw = raw;
}
