#pragma once
#include "WriteEmployee.h"
#include "Reports.h"

// This class is the Main Menu for the program.
class MainMenu
{
public:
	// Constructors
	MainMenu(void);
	~MainMenu(void);

	// Main methods
	void run(void); // Initializes the menu
	void about(void); // Displays About information
private:
	// Instance classes
	Reports reporting;
	WriteEmployee writer;
};

