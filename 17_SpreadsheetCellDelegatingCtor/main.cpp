import spreadsheet_cell;
#include <iostream>

int main()
{
	SpreadsheetCell myCell{ "6.2" };
	std::cout << "cell 1: " << myCell.getValue() << std::endl;
	return 0;
}