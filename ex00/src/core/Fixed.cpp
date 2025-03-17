/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 17:50:57 by dande-je          #+#    #+#             */
/*   Updated: 2025/03/17 02:16:01 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/Fixed.hpp"

Fixed::Fixed()
  : m_value(VALUE_DEFAULT),
    m_color(TerminalColor::getInstance()),
    m_bgColor(BG_RESET),
    m_strColor(WHITE)  {
  log("Default constructor called");
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
    this->m_value = other.getRawBits();
  }
  return *this;
}
