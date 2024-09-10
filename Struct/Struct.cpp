#include <cstdio>

struct Lifetime {
	Lifetime() noexcept { puts("Lfetime() [default constructor]"); }
	Lifetime(const Lifetime&) noexcept {
		puts("Lifetime(const Lifetime &) [copy constructor]");
	}
	Lifetime(Lifetime&&) noexcept {
		puts("Lifetime(Lifetime &&) [move constructor]");
	}
	~Lifetime() noexcept { puts("~Lifetime() [destructor]"); }
	Lifetime& operator=(const Lifetime&) noexcept {
		puts("operator=(const Lifetime &) [copy assigment]");
		return *this;
	}
	Lifetime& operator=(Lifetime&&) noexcept {
		puts("operator=(Lifetime &&) [move assigment]");
		return *this;
	}
};