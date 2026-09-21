#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <string>
# include <stdint.h> // for uintptr_t

// Non empty data structure
struct Data {
	std::string	name;
	int			value;
};

class Serializer {
private:
	// OCF
	Serializer();
	Serializer(const Serializer& src);
	Serializer& operator=(const Serializer& src);
	~Serializer();

public:
	static uintptr_t	serialize(Data* ptr);
	static Data*		deserialize(uintptr_t raw);
};

#endif