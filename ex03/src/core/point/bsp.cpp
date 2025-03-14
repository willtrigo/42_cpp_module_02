/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 17:20:17 by dande-je          #+#    #+#             */
/*   Updated: 2025/03/14 18:14:12 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/point/Point.hpp"

static Fixed crossProduct(Point const point, Point const vertexA, Point const vertexB);

bool bsp(Point const a, Point const b, Point const c, Point const point) {
  Fixed vertex1 = crossProduct(point, a, b);
  Fixed vertex2 = crossProduct(point, b, c);
  Fixed vertex3 = crossProduct(point, c, a);

  if (vertex1 == 0 || vertex2 == 0 || vertex3 == 0) {
    return false;
  }

  bool all_positive = (vertex1 > 0) && (vertex2 > 0) && (vertex3 > 0);
  bool all_negative = (vertex1 < 0) && (vertex2 < 0) && (vertex3 < 0);
  return all_positive || all_negative;
}

static Fixed crossProduct(Point const point, Point const vertexA, Point const vertexB) {
  return (vertexA.getX() - point.getX()) * (vertexB.getY() - point.getY()) -
         (vertexA.getY() - point.getY()) * (vertexB.getX() - point.getX());
}
