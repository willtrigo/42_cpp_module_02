/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 17:50:54 by dande-je          #+#    #+#             */
/*   Updated: 2025/03/08 19:48:09 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include "utils/TerminalColor.hpp"

class Fixed {
 public:
  Fixed();
  Fixed(const Fixed& other);
  Fixed& operator=(const Fixed& other);
  ~Fixed();

  int getRawBits() const;
  void setRawBits(int const raw);

 private:
  int m_raw;
  static const int m_fractionalBits = 8;
  const TerminalColor& m_color;
  ColorCode m_str_color;
  ColorCode m_bg_color;
};

#endif // FIXED_HPP
