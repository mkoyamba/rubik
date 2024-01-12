/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cube.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyamba <mkoyamba@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:27:12 by mkoyamba          #+#    #+#             */
/*   Updated: 2024/01/12 11:03:20 by mkoyamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Cube.hpp"
#include "../../includes/rubik.hpp"

Cube::Cube(int size, const std::string &shuffle) {
	char				colors[7] = "WRBGYO";
	std::istringstream	stream(shuffle);
	std::string			str;

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
	this->cube[FACE_UP][0][0] = 'B';
	while (std::getline(stream, str, ' ')) {
		if (str.c_str()[0] != '\0')
			this->shuffle.push_back(str);
	}
}

void	Cube::moveUprime() {
	std::vector<char>	temp = this->cube[FACE_RIGHT][0];

	this->cube[FACE_RIGHT][0] = this->cube[FACE_FRONT][0];
	this->cube[FACE_FRONT][0] = this->cube[FACE_LEFT][0];
	for (int i = 0; i < this->size; i++) {
		this->cube[FACE_LEFT][0][i] = this->cube[FACE_BACK][this->size - 1][this->size - 1 - i];
	}
	for (int i = 0; i < this->size; i++) {
		this->cube[FACE_BACK][this->size - 1][this->size - 1 - i] = temp[i];
	}
	for (int n = 0; n < this->size/2; n++) {
		temp = this->cube[FACE_UP][n];
		for (int i = n; i < this->size - n; i++) {
			this->cube[FACE_UP][n][i] = this->cube[FACE_UP][i][this->size - 1 - n];
		}
		for (int i = n; i < this->size - n; i++) {
			this->cube[FACE_UP][i][this->size - 1 - n] = this->cube[FACE_UP][this->size - 1 - n][this->size - 1 - i];
		}
		for (int i = n; i < this->size - n; i++) {
			this->cube[FACE_UP][this->size - 1 - n][this->size - 1 - i] = this->cube[FACE_UP][this->size - 1 - i][n];
		}
		for (int i = n; i < this->size - n; i++) {
			this->cube[FACE_UP][i][n] = temp[this->size - 1 - i];
		}
	}
}

void	Cube::moveU() {
	for (int i = 0; i < 3; i++)
		this->moveUprime();
}

void	Cube::moveD() {

}