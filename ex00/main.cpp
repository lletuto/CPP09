/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-tuto <lle-tuto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 14:31:10 by lle-tuto          #+#    #+#             */
/*   Updated: 2025/12/10 14:13:30 by lle-tuto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	main(int argc, char **argv)
{
	BitcoinExchange	BE;

	if (argc != 2)
	{
		std::cout << "Error: This program takes a filename" << std::endl;
		return (-1);
	}
	std::string fileName = argv[1];
	if (fileName.empty())
	{
		std::cout << "Error: This program takes a filename" << std::endl;
		return (-1);
	}
	BE.storingDataFile();
	std::ifstream file(argv[1]);
	if (!file.is_open())
	{
		std::cerr << "Error: could not open file!" << std::endl;
		return (1);
	}
	std::string line;
	std::string date;
	std::string amount;
	std::getline(file, line);
	while (std::getline(file, line))
	{
		if (line.empty())
			continue ;
		std::istringstream ss(line);
		if (line.find('|') == std::string::npos)
		{
			std::getline(ss, date);
			amount = "";			
			BE.DoingTheWork(date, amount);
			continue ;
		}
		std::getline(ss, date, '|');
		std::getline(ss, amount);
		std::size_t found = date.find_last_not_of(' ');
		date.erase(found + 1);
		BE.DoingTheWork(date, amount);
		date.clear();
		amount.clear();
	}
	file.close();
	return (0);
}
