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

#include <string> // std::string

class Contact
{
	private:
		std::string firstName;
		std::string lastName;
		std::string nickname;

	public:
		void setFirstName(std::string value);
		void setLastName(std::string value);
		void setNickname(std::string value);
		
		std::string getFirstName();
		std::string getLastName();
		std::string getNickname();
};

#endif /* CONTACT_HPP */
