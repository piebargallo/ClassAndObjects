struct S
{
	S() = default;

	S(const S&) = default; // copy constructor
	S(S&&) = default; // move constuctor
	S& operator=(const S&) = default; // copy assigment
	S& operator=(S&&) = default; // move assigment

	~S() = default; // destructor
};

int main() {}
