/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cube.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyamba <mkoyamba@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:27:12 by mkoyamba          #+#    #+#             */
/*   Updated: 2024/01/11 15:11:00 by mkoyamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Cube.hpp"

Cube::Cube(int size) {
	char	colors[7] = "WRBGYO";

	this->size = size;
	for (int face = 0; face < 6; face++) {
		for (int n = 0; n < size; n++) {
			std::vector<char> row;
			for (int i = 0; i < size; i++) {
				row.push_back(colors[face]);
			}
			this->cube[face].push_back(row);
		}
	}
}

int	Cube::getSize() {
	return this->size;
}

std::vector<std::vector<char> >	Cube::getFace(int face) {
	return this->cube[face];
}