#ifndef IOHANDLER_HPP
#define IOHANDLER_HPP

#include "main.hpp"

class IOhandler {
public:
	virtual const string input() const;
	virtual void output(const string message);
};

#endif