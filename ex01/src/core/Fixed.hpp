/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 21:49:22 by dande-je          #+#    #+#             */
/*   Updated: 2025/03/09 14:55:19 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include "utils/TerminalColor.hpp"
#include <iostream>
#include <cmath>

class Fixed {
 public:
  Fixed();
  Fixed(const int value);
  Fixed(const float value);
  Fixed(const Fixed& other);
  Fixed& operator=(const Fixed& other);
  friend std::ostream &operator<<(std::ostream& os, const Fixed& fixed);
  ~Fixed();

  int getRawBits() const;
  void setRawBits(int const raw);
  float toFloat() const;
  int toInt() const;

 private:
  enum defaultEnum {
    RAW_DEFAULT,
    BIT_SHIFT
  };
  int m_raw;
  static const int m_fractionalBits = 8;
  const TerminalColor& m_color;
  ColorCode m_strColor;
  ColorCode m_bgColor;
};

#endif // FIXED_HPP
