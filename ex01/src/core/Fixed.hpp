/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 21:49:22 by dande-je          #+#    #+#             */
/*   Updated: 2025/03/14 20:33:35 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include "utils/TerminalColor.hpp"
#include <iostream>

class Fixed {
 public:
  Fixed();
  Fixed(const int value);
  Fixed(const float value);
  Fixed(const Fixed& other);
  ~Fixed();

  Fixed& operator=(const Fixed& other);

  int getRawBits() const;
  int toInt() const;
  float toFloat() const;
  void setRawBits(int const raw);

 private:
  enum defaultEnum {
    VALUE_DEFAULT,
    BIT_SHIFT
  };

  static const int m_fractionalBits = 8;

  int m_value;
  const TerminalColor& m_color;
  ColorCode m_strColor;
  ColorCode m_bgColor;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif // FIXED_HPP
