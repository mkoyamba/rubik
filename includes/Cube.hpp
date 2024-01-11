/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cube.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyamba <mkoyamba@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:27:35 by mkoyamba          #+#    #+#             */
/*   Updated: 2024/01/11 15:10:17 by mkoyamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_HPP
# define CUBE_HPP

#include "rubik.hpp"

class Cube {
	public:
		Cube(int size);
		~Cube() {};

		std::vector<std::vector<char> >	getFace(int face);
		int								getSize();

	private:
		std::vector<std::vector<char> > cube[6];
		int								size;
};

#endif