#pragma once
#include <string>
#include <fstream>

// Class used to write employees to file
class WriteEmployee
{
public:
	// Constructors
	WriteEmployee(void);
	~WriteEmployee(void);

	// Start method
	void run(void);
private:
	std::string filePath; // The output file path
	void writeLoop(std::ofstream&); // Loop for writing employees to file
};

