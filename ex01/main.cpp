/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-tuto <lle-tuto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 14:47:46 by lle-tuto          #+#    #+#             */
/*   Updated: 2025/12/11 12:00:52 by lle-tuto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

bool	isValidLine(char *line)
{
	int	i;

	i = 0;
	
	while (line[i])
	{
		if (!isdigit(line[i]) && line[i] != '+' && line[i] != '/'
			&& line[i] != '*' && line[i] != '-' && line[i] != ' ')
		{
			std::cerr << "Wrong format" << std::endl;
			return (false);
		}
		i++;
	}
	return (true);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "This program takes a Political mathematical expression as an argument" << std::endl;
		return -1;
	}
	if (!isValidLine(argv[1]))
		return -1;
	RPN rpn(argv[1]);
	try
	{
		rpn.calculate();
	}
	catch (std::exception &e)
	{
		std::cout << "Error : " << e.what() <<  std::endl;
	}

}