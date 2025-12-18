/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-tuto <lle-tuto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 14:29:09 by lle-tuto          #+#    #+#             */
/*   Updated: 2025/12/10 14:42:49 by lle-tuto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

bool	isNumeric(const std::string &s)
{
	if (s.empty())
		return (false);
	for (size_t i = 0; i < s.size(); ++i)
	{
		if (!std::isdigit(static_cast<unsigned char>(s[i])) && s[i] != ' '
			&& s[i] != '\n')
			return (false);
	}
	return (true);
}
BitcoinExchange::BitcoinExchange(void)
{
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &src)
{
	_data = src._data;
}

BitcoinExchange::~BitcoinExchange(void)
{
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &rhs)
{
	if (this != &rhs)
	{
		_data = rhs._data;
	}
	return (*this);
}

void BitcoinExchange::SetData(std::map<std::string, float> data)
{
	_data = data;
}

std::map<std::string, float> &BitcoinExchange::GetData(void)
{
	return (_data);
}

void BitcoinExchange::storingDataFile()
{
	std::ifstream file("data.csv");
	if (!file.is_open())
	{
		std::cerr << "Error: could not open file!" << std::endl;
		return ;
	}
	std::map<std::string, float> data;
	std::string line;
	std::string date;
	std::string rate;
	std::getline(file, line);
	while (std::getline(file, line))
	{
		std::istringstream ss(line);
		std::getline(ss, date, ',');
		std::getline(ss, rate);
		data[date] = std::atof(rate.c_str());
	}
	SetData(data);
	file.close();
}

bool	isLeapYear(int year)
{
	if (year % 4 == 0)
	{
		if (year % 100 == 0)
		{
			if (year % 400 == 0)
				return (true);
			return (false);
		}
		return (true);
	}
	return (false);
}

bool	validDate(std::string date)
{
	int	year;
	int	month;
	int	day;
	int	daysNb[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	year = 0;
	month = 0;
	day = 0;
	std::string y;
	std::string m;
	std::string d;
	std::istringstream ss(date);
	std::string token;
	if (date.size() != 10)
		return (false);
	if (date[4] != '-' || date[7] != '-')
		return (false);
	y = date.substr(0, 4);
	m = date.substr(5, 2);
	d = date.substr(8, 2);
	if (!isNumeric(y) || !isNumeric(m) || !isNumeric(d))
		return (false);
	year = std::atoi(y.c_str());
	month = std::atoi(m.c_str());
	day = std::atoi(d.c_str());
	if (month == 2 && !isLeapYear(year))
		daysNb[1] = 28;
	if (day < 1 || day > daysNb[month - 1])
		return (false);
	if (month < 1 || month > 12)
		return (false);
	return (true);
}

bool	validRate(std::string rate)
{
	float	fRate;

	fRate = std::atof(rate.c_str());
	if (fRate < 0)
	{
		std::cerr << "Error: not a positive number." << std::endl;
		return (false);
	}
	if (fRate >= 2147483646.0f)
	{
		std::cerr << "Error: too large a number." << std::endl;
		return (false);
	}
	return (true);
}

void BitcoinExchange::DoingTheWork(std::string date, std::string amount)
{
	std::string Beginning = "0000-00-00";
	if (date.empty() || amount.empty())
	{
		std::cerr << "Error: bad input = > " << date << std::endl;
		return ;
	}
	if (!validDate(date))
	{
		std::cerr << "Error: invalid date = > " << date << std::endl;
		return ;
	}
	if (!validRate(amount))
		return ;
	float fAmount;
	float result;
	fAmount = std::atof(amount.c_str());
	if (_data.find(date) != _data.end())
		result = fAmount * _data[date];
	else
	{
		std::map<std::string, float>::iterator it;
		for (it = _data.begin(); it != _data.end(); it++)
		{
			if (Beginning > date)
				break ;
			Beginning = it->first;
		}
		result = _data[Beginning];
		date = Beginning;
	}

	std::cout << date << " => " << fAmount << " = " << fAmount
		* _data[date] << std::endl;
}