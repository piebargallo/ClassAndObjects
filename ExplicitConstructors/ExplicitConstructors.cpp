#include <optional>
#include <string>

struct S
{
	S() = default;
	S(int) {}
	S(int, int);
};

void f(const S&);

S get_s()
{
	return { 1,2 };
}

void use_string(const std::string&);

int main()
{
	std::string data;
	use_string(data.c_str());
}