export module spreadsheet_cell;

import <charconv>;
import <iostream>;
import <string>;
import <string_view>;

export class SpreadsheetCell
{
public:
	void setValue(double value);
	double getValue() const;

	void setString(std::string_view value);
	std::string getString() const;

private:
	std::string doubleToString(double value) const;
	double stringToDouble(std::string_view value) const;

	double value{ 0 };
};
