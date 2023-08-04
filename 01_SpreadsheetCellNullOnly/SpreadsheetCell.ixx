export module spreadsheet_cell;

export class SpreadsheetCell
{
public:
	void setValue(double value); 
	double getValue() const; 
private:
	double m_value{ 0 };
};
