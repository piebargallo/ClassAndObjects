import spreadsheet_cell;
#include <iostream>

int main()
{
	SpreadsheetCell myCell{ 4 };
	myCell = 5;
	std::cout << "Cell 1: " << myCell.getValue() << std::endl;
	return 0;
}
