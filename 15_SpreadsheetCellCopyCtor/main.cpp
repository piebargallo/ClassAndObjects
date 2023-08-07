import spreadsheet_cell;
#include <iostream>

int main()
{
	SpreadsheetCell myCell1{ 4 };
	SpreadsheetCell myCell2{ myCell1 };
	// myCell2 has the same values as myCell1

	std::cout << "Cell 1: " << myCell1.getValue() << std::endl;
	std::cout << "Cell 2: " << myCell2.getValue() << std::endl;
	return 0;
}
