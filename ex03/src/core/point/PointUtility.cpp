/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PointUtility.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 16:46:04 by dande-je          #+#    #+#             */
/*   Updated: 2025/03/14 18:02:49 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/point/Point.hpp"

const Fixed& Point::getX() const {
  return this->m_x;
}

const Fixed& Point::getY() const {
  return this->m_y;
}
