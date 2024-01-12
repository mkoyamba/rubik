/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyamba <mkoyamba@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 17:09:10 by mkoyamba          #+#    #+#             */
/*   Updated: 2024/01/12 08:11:14 by mkoyamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rubik.hpp"

bool is_number(const std::string& s) {
	std::string::const_iterator it = s.begin();
	while (it != s.end() && std::isdigit(*it)) ++it;
	return !s.empty() && it == s.end();
}

int	main(int argc, char **argv) {
	if (argc != 2 && argc != 3) {
		std::cerr << "Usage : ./rubik [instructions] {size of cube}" << std::endl;
		return 1;
	}
	else if (argc == 2)
		parsing(std::string(argv[1]), 3);
	else if (argc == 3) {
		if (!is_number(std::string(argv[2]))) {
			std::cerr << "Size has to be an integer." << std::endl;
			return 1;
		}
		parsing(std::string(argv[1]), std::stoi(std::string(argv[2])));
	}
	return 0;
}