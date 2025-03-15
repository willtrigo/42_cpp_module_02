/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 16:44:16 by dande-je          #+#    #+#             */
/*   Updated: 2025/03/14 22:07:44 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "core/fixed/Fixed.hpp"

class Point {
 public:
  Point();
  Point(const float x, const float y);
  Point(const Point& other);
  ~Point();

  Point& operator=(const Point& other);

  const Fixed& getX() const;
  const Fixed& getY() const;

 private:
  const Fixed m_x;
  const Fixed m_y;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif // POINT_HPP
