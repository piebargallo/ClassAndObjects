import spreadsheet_cell;
#include <iostream>
#include <memory>

using namespace std;

int main()
{
	SpreadsheetCell myCell;
	myCell.setValue(6);
	cout << "cell 1: " << myCell.getValue() << endl;

	auto smartCellp{ make_unique<SpreadsheetCell>() };
	
	SpreadsheetCell* myCellp{ new SpreadsheetCell };
	delete myCellp;    myCellp = nullptr;
}
