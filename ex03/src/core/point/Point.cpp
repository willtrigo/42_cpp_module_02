/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PointConstructor.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 16:59:05 by dande-je          #+#    #+#             */
/*   Updated: 2025/03/14 17:13:49 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/fixed/Fixed.hpp"
#include "core/point/Point.hpp"

Point::Point() : m_x(Fixed()), m_y(Fixed()) {}

Point::Point(const float x, const float y) : m_x(Fixed(x)), m_y(Fixed(y)) {}

Point::Point(Point const& other) : m_x(other.m_x), m_y(other.m_y) {}

Point::~Point() {}

Point& Point::operator=(const Point& other) {
  if (this != &other) {
    const_cast<Fixed&>(m_x) = other.m_x;
    const_cast<Fixed&>(m_y) = other.m_y;
  }
  return *this;
}
