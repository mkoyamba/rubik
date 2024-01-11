/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rubik.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyamba <mkoyamba@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 17:10:06 by mkoyamba          #+#    #+#             */
/*   Updated: 2024/01/11 15:42:02 by mkoyamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEBSERV_HPP
# define WEBSERV_HPP

# include <iostream>
# include <vector>
# include <map>
# include "Cube.hpp"

# define NONE	"\033[m"
# define PURPLE	"\033[0;35m"
# define BLUE	"\033[0;34m"
# define BLUE_B	"\033[1;34m"
# define YELLOW	"\033[0;33m"
# define GREEN	"\033[0;32m"
# define RED		"\033[0;31m"
# define GREY	"\033[0;30m"
# define PURPLE_B	"\033[1;35m"

# define FACE_UP 0
# define FACE_LEFT 1
# define FACE_FRONT 2
# define FACE_RIGHT 3
# define FACE_DOWN 4
# define FACE_BACK 5

void	parsing();
void	print_rubik(Cube &cube);

#endif