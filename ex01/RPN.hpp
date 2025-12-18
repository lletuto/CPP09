/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-tuto <lle-tuto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 14:48:02 by lle-tuto          #+#    #+#             */
/*   Updated: 2025/12/11 12:02:14 by lle-tuto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <queue>
#include <sstream>
#include <stack>
#include <string>

class RPN
{
  private:
	std::stack<int> _numbers;
	std::string _line;

  public:
	RPN(std::string line);
	RPN(RPN const &src);
	~RPN(void);

	RPN &operator=(RPN const &rhs);
	void calculate();
	void Checks();

};
