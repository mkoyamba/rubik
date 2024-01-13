/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cube.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyamba <mkoyamba@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:27:35 by mkoyamba          #+#    #+#             */
/*   Updated: 2024/01/13 11:42:10 by mkoyamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_HPP
# define CUBE_HPP

# include <iostream>
# include <vector>

class Cube {
	public:
		Cube(int size, const std::string &shuffle);
		~Cube() {};

		std::vector<std::vector<char> >	&getFace(int face) { return this->cube[face]; };
		int								&getSize() { return this->size; };
		std::vector<std::string>		&getShuffle() { return this->shuffle; };
		std::vector<std::string>		&getSolution() { return this->solution; };

		void							moveU(bool mode);
		void							moveUprime(bool mode);
		void							moveD(bool mode);
		void							moveDprime(bool mode);
		void							moveR(bool mode);
		void							moveRprime(bool mode);
		void							moveL(bool mode);
		void							moveLprime(bool mode);
		void							moveF(bool mode);
		void							moveFprime(bool mode);
		void							moveB(bool mode);
		void							moveBprime(bool mode);

	private:
		std::vector<std::vector<char> > cube[6];
		int								size;
		std::vector<std::string>		shuffle;
		std::vector<std::string>		solution;

		void	rotateFace(int face);
		void	rotateFacePrime(int face);
};

#endif