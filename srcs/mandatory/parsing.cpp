/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyamba <mkoyamba@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:20:04 by mkoyamba          #+#    #+#             */
/*   Updated: 2024/01/11 15:41:06 by mkoyamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rubik.hpp"

void	print_color(char c) {
	if (c == 'W')
		std::cout << NONE << " ■ ";
	else if (c == 'R')
		std::cout << RED << " ■ ";
	else if (c == 'B')
		std::cout << BLUE << " ■ ";
	else if (c == 'G')
		std::cout << GREEN << " ■ ";
	else if (c == 'Y')
		std::cout << YELLOW << " ■ ";
	else if (c == 'O')
		std::cout << PURPLE << " ■ ";
	
}

void	print_rubik(Cube &cube) {
	std::vector<std::vector<char> >	face = cube.getFace(FACE_UP);

	for (int n = 0; n < cube.getSize(); n++) {
		for (int i = 0; i < cube.getSize(); i++)
			std::cout << "   ";
		std::cout << "   ";
		for (int i = 0; i < cube.getSize(); i++) {
			print_color(face[n][i]);
		}
		std::cout << std::endl;
	}
	std::cout << "\n" << std::endl;

	for (int n = 0; n < cube.getSize(); n++) {
		face = cube.getFace(FACE_LEFT);
		for (int i = 0; i < cube.getSize(); i++) {
			print_color(face[n][i]);
		}
		std::cout << "   ";
		face = cube.getFace(FACE_FRONT);
		for (int i = 0; i < cube.getSize(); i++) {
			print_color(face[n][i]);
		}
		std::cout << "   ";
		face = cube.getFace(FACE_RIGHT);
		for (int i = 0; i < cube.getSize(); i++) {
			print_color(face[n][i]);
		}
		std::cout << std::endl;
	}
	std::cout << "\n" << std::endl;

	face = cube.getFace(FACE_DOWN);
	for (int n = 0; n < cube.getSize(); n++) {
		for (int i = 0; i < cube.getSize(); i++)
			std::cout << "   ";
		std::cout << "   ";
		for (int i = 0; i < cube.getSize(); i++) {
			print_color(face[n][i]);
		}
		std::cout << std::endl;
	}
	std::cout << "\n" << std::endl;

	face = cube.getFace(FACE_BACK);
	for (int n = 0; n < cube.getSize(); n++) {
		for (int i = 0; i < cube.getSize(); i++)
			std::cout << "   ";
		std::cout << "   ";
		for (int i = 0; i < cube.getSize(); i++) {
			print_color(face[n][i]);
		}
		std::cout << std::endl;
	}
}

void	parsing() {
	int size = 3;

	Cube cube(size);
	print_rubik(cube);
}