/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-tuto <lle-tuto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 11:54:21 by lle-tuto          #+#    #+#             */
/*   Updated: 2025/12/12 11:54:53 by lle-tuto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <cstring>
#include <vector> 
#include <deque>


class PmergeMe
{
    private :
    vector<int> jacob;
    vector<int> main;
    vector<int> pend;

    public :
    PmergeMe();
    ~PmergeMe();
	PmergeMe &operator=(PmergeMe const &rhs);
    PmergeMe(PmergeMe const &src);

    void jacobstahl();
}

#endif