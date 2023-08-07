import spreadsheet_cell;

int main()
{
	// This line compiles without a default constructor
	SpreadsheetCell cells[3]{ SpreadsheetCell{ 0 }, SpreadsheetCell{ 23 },
					SpreadsheetCell{ 41 } };
	return 0;
}