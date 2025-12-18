/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-tuto <lle-tuto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 14:29:06 by lle-tuto          #+#    #+#             */
/*   Updated: 2025/12/09 16:19:29 by lle-tuto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <cstdlib> 

class BitcoinExchange
{
  private:
	std::map<std::string, float> _data;

  public:
	BitcoinExchange(void);
	BitcoinExchange(BitcoinExchange const &src);
	~BitcoinExchange(void);

	BitcoinExchange &operator=(BitcoinExchange const &rhs);
	void SetData(std::map<std::string, float> data);
	std::map<std::string, float>& GetData(void);
	void storingDataFile();
	
	void DoingTheWork(std::string date, std::string rate);

};


bool	isNumeric(const std::string &s);
