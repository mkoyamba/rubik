/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyamba <mkoyamba@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:20:04 by mkoyamba          #+#    #+#             */
/*   Updated: 2024/01/12 10:17:41 by mkoyamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rubik.hpp"

static bool	isValidMove(const std::string &move) {
	std::string	instructions[] = {
		"U", "U'", "D", "D'", "R", "R'", "L", "L'", "F", "F'", "B", "B'",
		"u", "r", "f", "d", "l", "b", "M", "m", "E", "e", "S", "s", "x", "y", "z"
	};

	for (int i = 0; i < 27; i++) {
		if (move == instructions[i])
			return true;
	}
	return false;
}

static bool	isValidShuffle(const std::string &shuffle) {
	std::vector<std::string>	splitted;
	std::istringstream			stream(shuffle);
	std::string					str;

	while (std::getline(stream, str, ' ')) {
		if (str.c_str()[0] != '\0')
			splitted.push_back(str);
	}
	for (size_t i = 0; i < splitted.size(); i++) {
		if (!isValidMove(splitted[i]))
			return false;
	}
	return true;
}

void	parsing(const std::string &shuffle, int size) {
	if (!isValidShuffle(shuffle)) {
		std::cerr << "Instructions has to be like \"U D\' r b d...\"" << std::endl;
		exit(1);
	}
	Cube cube(size, shuffle);
	print_rubik(cube);
	std::cout << "\n\n\n===========\n\n\n" << std::endl;
	print_rubik(cube);
}