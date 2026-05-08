/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross-s <cgross-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 22:10:29 by cgross-s          #+#    #+#             */
/*   Updated: 2026/05/08 23:20:33 by cgross-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

//# include <iostream>
#include <string> // std::string

class Contact {
	private:
		std::string name;

	public:
		void setName(std::string value); // Função que guarda um nome.
		std::string getName(); // Função que devolve o nome.

};

#endif /* CONTACT_HPP */
