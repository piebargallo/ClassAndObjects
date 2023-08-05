import spreadsheet_cell;
#include <iostream>
#include <string>
#include <memory>

using namespace std;

int main()
{
	unique_ptr<SpreadsheetCell> myCellp{ new SpreadsheetCell{ } };

	myCellp->setValue(3.7);
	cout << "cell 1: " << myCellp->getValue() <<
		" " << myCellp->getString() << endl;
}