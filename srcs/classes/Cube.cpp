/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cube.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyamba <mkoyamba@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:27:12 by mkoyamba          #+#    #+#             */
/*   Updated: 2024/01/13 11:47:40 by mkoyamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Cube.hpp"
#include "../../includes/rubik.hpp"

Cube::Cube(int size, const std::string &shuffle) {
	char				colors[7] = "YBRGWO";
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
	while (std::getline(stream, str, ' ')) {
		if (str.c_str()[0] != '\0')
			this->shuffle.push_back(str);
	}
}

void	Cube::rotateFacePrime(int face) {
	std::vector<char>	temp;

	for (int n = 0; n < this->size/2; n++) {
		temp = this->cube[face][n];
		for (int i = n; i < this->size - n; i++) {
			this->cube[face][n][i] = this->cube[face][i][this->size - 1 - n];
		}
		for (int i = n; i < this->size - n; i++) {
			this->cube[face][i][this->size - 1 - n] = this->cube[face][this->size - 1 - n][this->size - 1 - i];
		}
		for (int i = n; i < this->size - n; i++) {
			this->cube[face][this->size - 1 - n][this->size - 1 - i] = this->cube[face][this->size - 1 - i][n];
		}
		for (int i = n; i < this->size - n; i++) {
			this->cube[face][i][n] = temp[this->size - 1 - i];
		}
	}
}

void	Cube::rotateFace(int face) {
	for (int i = 0; i < 3; i++)
		this->rotateFacePrime(face);
}

void	Cube::moveUprime(bool mode) {
	std::vector<char>	temp = this->cube[FACE_RIGHT][0];

	this->cube[FACE_RIGHT][0] = this->cube[FACE_FRONT][0];
	this->cube[FACE_FRONT][0] = this->cube[FACE_LEFT][0];
	for (int i = 0; i < this->size; i++) {
		this->cube[FACE_LEFT][0][i] = this->cube[FACE_BACK][this->size - 1][this->size - 1 - i];
	}
	for (int i = 0; i < this->size; i++) {
		this->cube[FACE_BACK][this->size - 1][this->size - 1 - i] = temp[i];
	}
	rotateFacePrime(FACE_UP);
	if(mode == SOLUTION) 
		this->solution.push_back("U'");
}

void	Cube::moveU(bool mode) {
	for (int i = 0; i < 3; i++)
		this->moveUprime(SHUFFLE);
	if(mode == SOLUTION) 
		this->solution.push_back("U");
}

void	Cube::moveDprime(bool mode) {
	std::vector<char>	temp = this->cube[FACE_LEFT][this->size - 1];

	this->cube[FACE_LEFT][this->size - 1] = this->cube[FACE_FRONT][this->size - 1];
	this->cube[FACE_FRONT][this->size - 1] = this->cube[FACE_RIGHT][this->size - 1];
	for (int i = 0; i < this->size; i++) {
		this->cube[FACE_RIGHT][this->size - 1][i] = this->cube[FACE_BACK][0][this->size - 1 - i];
	}
	for (int i = 0; i < this->size; i++) {
		this->cube[FACE_BACK][0][this->size - 1 - i] = temp[i];
	}
	rotateFacePrime(FACE_DOWN);
	if(mode == SOLUTION) 
		this->solution.push_back("D'");
}

void	Cube::moveD(bool mode) {
	for (int i = 0; i < 3; i++)
		this->moveDprime(SHUFFLE);
	if(mode == SOLUTION) 
		this->solution.push_back("D");
}

void	Cube::moveR(bool mode) {
	std::vector<char>	temp = this->cube[FACE_UP][this->size - 1];

	for (int i = 0; i < this->size ; i++) {
		this->cube[FACE_UP][this->size - 1][i] = this->cube[FACE_LEFT][this->size - 1 - i][this->size -1];
	}
	for (int i = 0; i < this->size ; i++) {
		this->cube[FACE_LEFT][i][this->size - 1] = this->cube[FACE_DOWN][0][i];
	}
	for (int i = 0; i < this->size ; i++) {
		this->cube[FACE_DOWN][0][i] = this->cube[FACE_RIGHT][this->size - 1 - i][0];
	}
	for (int i = 0; i < this->size ; i++) {
		this->cube[FACE_RIGHT][i][0] = temp[i];
	}
	rotateFace(FACE_FRONT);
	if(mode == SOLUTION) 
		this->solution.push_back("R");
}

void	Cube::moveRprime(bool mode) {
	for (int i = 0; i < 3; i++)
		this->moveR(SHUFFLE);
	rotateFacePrime(FACE_FRONT);
	if(mode == SOLUTION) 
		this->solution.push_back("R'");
}

void	Cube::moveL(bool mode) {
	std::vector<char>	temp;

	if(mode == SOLUTION) 
		this->solution.push_back("L");
}

void	Cube::moveLprime(bool mode) {
	for (int i = 0; i < 3; i++)
		this->moveL(SHUFFLE);
	
	if(mode == SOLUTION) 
		this->solution.push_back("L'");
}

void	Cube::moveF(bool mode) {
	std::vector<char>	temp;

	if(mode == SOLUTION) 
		this->solution.push_back("F");
}

void	Cube::moveFprime(bool mode) {
	for (int i = 0; i < 3; i++)
		this->moveF(SHUFFLE);
	
	if(mode == SOLUTION) 
		this->solution.push_back("F'");
}

void	Cube::moveB(bool mode) {
	std::vector<char>	temp;

	if(mode == SOLUTION) 
		this->solution.push_back("B");
}

void	Cube::moveBprime(bool mode) {
	for (int i = 0; i < 3; i++)
		this->moveB(SHUFFLE);
	
	if(mode == SOLUTION) 
		this->solution.push_back("B'");
}