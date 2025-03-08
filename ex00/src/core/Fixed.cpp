/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 17:50:57 by dande-je          #+#    #+#             */
/*   Updated: 2025/03/08 19:41:46 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/Fixed.hpp"
#include <iostream>

Fixed::Fixed() : m_raw(0) {
  std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const& other) {
  *this = other;
  std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other) {
  if (this != &other) {
    this->m_raw = other.m_raw;
    std::cout << "Copy assignment operator called" << std::endl;
  }
  return *this;
}

Fixed::~Fixed() {
  std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const {
  std::cout << "getRawBits member function called" << std::endl;
  return m_raw;
}

void Fixed::setRawBits(int const raw) {
  std::cout << "setRawBits member function called" << std::endl;
  m_raw = raw;
}
