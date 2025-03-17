/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 21:49:26 by dande-je          #+#    #+#             */
/*   Updated: 2025/03/17 02:41:01 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/Fixed.hpp"
#include "utils/TerminalColor.hpp"
#include <cmath>

Fixed::Fixed()
    : m_value(VALUE_DEFAULT),
      m_color(TerminalColor::getInstance()),
      m_strColor(WHITE),
      m_bgColor(BG_RESET) {
  log("Default constructor called");
}

Fixed::Fixed(const int value)
    : m_value(value << m_fractionalBits),
      m_color(TerminalColor::getInstance()), 
      m_strColor(YELLOW),
      m_bgColor(BG_RESET) {
  log("Int constructor called");
}

Fixed::Fixed(const float value)
    : m_value(static_cast<int>(roundf(value * (BIT_SHIFT << m_fractionalBits)))),
      m_color(TerminalColor::getInstance()),
      m_strColor(RED),
      m_bgColor(BG_RESET) {
  log("Float constructor called");
}

Fixed::Fixed(Fixed const& other) : m_color(TerminalColor::getInstance()) {
  this->m_strColor = BLUE;
  this->m_bgColor = BG_RESET;
  log("Copy constructor called");
  *this = other;
  this->m_strColor = BLUE;
  this->m_bgColor = BG_RESET;
}

Fixed::~Fixed() {
  log("Destructor called");
}

Fixed& Fixed::operator=(const Fixed& other) {
  if (this != &other) {
    this->m_strColor = ORANGE;
    this->m_bgColor = BG_RESET;
    log("Copy assignment operator called");
    this->m_value = other.m_value;
  }
  return *this;
}
