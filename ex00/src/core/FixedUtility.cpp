/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FixedUtility.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 02:00:18 by dande-je          #+#    #+#             */
/*   Updated: 2025/03/17 02:04:54 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/Fixed.hpp"
#include <iostream>

int Fixed::getRawBits() const {
  log("getRawBits member function called");
  return this->m_value;
}

void Fixed::setRawBits(int const raw) {
  log("setRawBits member function called");
  this->m_value = raw;
}

void Fixed::log(const std::string& str) const {
  std::cout << this->m_color.setColor(this->m_bgColor, this->m_strColor, str) << std::endl;
}
