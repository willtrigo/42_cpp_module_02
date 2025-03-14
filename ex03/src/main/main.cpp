/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 16:23:57 by dande-je          #+#    #+#             */
/*   Updated: 2025/03/14 18:57:11 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/point/Point.hpp"
#include <cstdlib>
#include <iostream>

int main() {
  Point a(0, 0);
  Point b(-10, 0);
  Point c(0, -10);

  Point point1(-1, -1);
  Point point2(-4, -4);
  Point point3(10, 10);
  Point point4(0, 0);
  Point point5(5, 0);

  std::cout << "Point1 is inside the triangle: " 
            << (bsp(a, b, c, point1) ? "inside" : "outside or in an edge or a vertex") << std::endl;
  std::cout << "Point2 is inside the triangle: " 
            << (bsp(a, b, c, point2) ? "inside" : "outside or in an edge or a vertex") << std::endl;
  std::cout << "Point3 is inside the triangle: " 
            << (bsp(a, b, c, point3) ? "inside" : "outside or in an edge or a vertex") << std::endl;
  std::cout << "Point4 is inside the triangle: " 
            << (bsp(a, b, c, point4) ? "inside" : "outside or in an edge or a vertex") << std::endl;
  std::cout << "Point5 is inside the triangle: " 
            << (bsp(a, b, c, point5) ? "inside" : "outside or in an edge or a vertex") << std::endl;
  return EXIT_SUCCESS;
}
