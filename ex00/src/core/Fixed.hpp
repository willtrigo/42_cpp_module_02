/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 17:50:54 by dande-je          #+#    #+#             */
/*   Updated: 2025/03/09 19:27:06 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include "utils/TerminalColor.hpp"

class Fixed {
 public:
  Fixed();
  Fixed(const Fixed& other);
  ~Fixed();

  Fixed& operator=(const Fixed& other);

  int getRawBits() const;
  void setRawBits(int const raw);

 private:
  enum defaultEnum {
    VALUE_DEFAULT
  };

  static const int m_fractionalBits = 8;

  int m_value;
  const TerminalColor& m_color;
  ColorCode m_bgColor;
  ColorCode m_strColor;
};

#endif // FIXED_HPP
