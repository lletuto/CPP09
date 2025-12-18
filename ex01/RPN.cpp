/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-tuto <lle-tuto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 14:48:08 by lle-tuto          #+#    #+#             */
/*   Updated: 2025/12/11 12:02:45 by lle-tuto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(std::string line)
{
	_line = line;
}

RPN::RPN(RPN const &src)
{
	*this = src;
}

RPN::~RPN(void)
{
}

RPN &RPN::operator=(RPN const &rhs)
{
	if (this != &rhs)
	{
		_numbers = rhs._numbers;
		_line = rhs._line;
	}
	return (*this);
}

bool	isSymbol(char letter)
{
	if (letter == '+' || letter == '-' || letter == '*' || letter == '/')
		return (true);
	return (false);
}
int	Do_the_math(int n1, int n2, char symbol)
{
	if (symbol == '+')
	{
		// std::cout << n1 << " + " << n2 << std::endl;
		return (n1 + n2);
	}
	else if (symbol == '-')
	{
		// std::cout << n1 << " - " << n2 << std::endl;
		return (n1 - n2);
	}
	else if (symbol == '*')
	{
		// std::cout << n1 << " * " << n2 << std::endl;
		return (n1 * n2);
	}
	else if (symbol == '/')
	{
		if (n2 == 0)
			throw std::runtime_error("Division by 0");
		// std::cout << n1 << " / " << n2 << std::endl;
		return (n1 / n2);
	}
	throw std::runtime_error("Weird things going on");
}

void RPN::calculate()
{
	int	n1;
	int	n2;
	int	result;

	if (_line.empty())
		throw std::runtime_error("You're not fooling me with parenthesis,this is empty");
	Checks();
	std::string token;
	std::istringstream iss(_line);
	while (iss >> token)
	{
		if (token.size() > 1)
			throw std::runtime_error("Two characters are touching inapproprietly");
		if (isdigit(token[0]))
		{
			_numbers.push(std::atoi(token.c_str()));
		}
		else if (isSymbol(token[0]))
		{
			n2 = _numbers.top();
			_numbers.pop();
			n1 = _numbers.top();
			_numbers.pop();
			result = Do_the_math(n1, n2, token[0]);
			_numbers.push(result);
		}
	}
	std::cout << result << std::endl;
}

void RPN::Checks()
{
	int i;
	int numbers;
	int signs;

	i = 0;
	signs = 0;
	numbers = 0;
	while (_line[i])
	{
		if (isSymbol(_line[i]) && numbers < 2)
			throw std::runtime_error("You got it all messed up here buddy");
		if (isSymbol(_line[i]))
			signs++;
		else if (isdigit(_line[i]))
			numbers++;
		i++;
	}
	if (signs == 0 || numbers == 0)
		throw std::runtime_error("You're missing like half the stuff dude");
	if (numbers < 2)
		throw std::runtime_error("Gonna be a tough one to calculate");
	if (signs != numbers - 1)
		throw std::runtime_error("You got it all messed up here buddy");
}