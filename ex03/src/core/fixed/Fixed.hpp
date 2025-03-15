/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 16:24:29 by dande-je          #+#    #+#             */
/*   Updated: 2025/03/14 22:08:00 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
 public:
  Fixed();
  Fixed(const int value);
  Fixed(const float value);
  Fixed(const Fixed& other);
  ~Fixed();

  Fixed& operator=(const Fixed& other);

  bool operator>(const Fixed& other) const;
  bool operator<(const Fixed& other) const;
  bool operator>=(const Fixed& other) const;
  bool operator<=(const Fixed& other) const;
  bool operator==(const Fixed& other) const;
  bool operator!=(const Fixed& other) const;

  Fixed operator+(const Fixed& other) const;
  Fixed operator-(const Fixed& other) const;
  Fixed operator*(const Fixed& other) const;
  Fixed operator/(const Fixed& other) const;

  Fixed& operator++();
  Fixed operator++(int);
  Fixed& operator--();
  Fixed operator--(int);

  static Fixed& min(Fixed& a, Fixed& b);
  static const Fixed& min(const Fixed& a, const Fixed& b);
  static Fixed& max(Fixed& a, Fixed& b);
  static const Fixed& max(const Fixed& a, const Fixed& b);

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
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif // FIXED_HPP
