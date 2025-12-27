/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-tuto <lle-tuto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 11:54:25 by lle-tuto          #+#    #+#             */
/*   Updated: 2025/12/12 11:54:25 by lle-tuto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void checkingSequence(std::string &sequence)
{
    while (i < sequence.size())
    {
        if (!isdigit(sequence[i]) && !isspace(sequence[i]))
            throw std::runtime_error("wrong sequence bro");
        //checker que seulement positif, checker que pas int max
        //checker que max 3000 integers
        i++;
    }

}


int main( int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "This program takes one integer sequence" << std::endl;
        return -1
    }
    try 
    {
        std::string sequence  = argv[1];
        checkingSequence(sequence);
        // sorting_pairs(argv[1]);
    }
    catch(std::exception &e)
    {
        std::cout << "Error : " << e.what() <<  std::endl;
    }
}