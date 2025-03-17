/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 17:20:17 by dande-je          #+#    #+#             */
/*   Updated: 2025/03/17 02:57:24 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/point/Point.hpp"

static Fixed crossProduct(Point const point,
                          Point const vertexA,
                          Point const vertexB);

bool bsp(Point const a, Point const b, Point const c, Point const point) {
  Fixed product1 = crossProduct(point, a, b);
  Fixed product2 = crossProduct(point, b, c);
  Fixed product3 = crossProduct(point, c, a);

  if (product1 == 0 || product2 == 0 || product3 == 0) {
    return false;
  }

  bool all_positive = (product1 > 0) && (product2 > 0) && (product3 > 0);
  bool all_negative = (product1 < 0) && (product2 < 0) && (product3 < 0);
  return all_positive || all_negative;
}

static Fixed crossProduct(Point const point,
                          Point const vertexA,
                          Point const vertexB) {
  return (vertexA.getX() - point.getX()) * (vertexB.getY() - point.getY()) -
         (vertexA.getY() - point.getY()) * (vertexB.getX() - point.getX());
}
