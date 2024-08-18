struct S
{
	[[nodiscard]] S();
};

S get_S() {}

int main()
{
	get_S();
}

S::S() {}
