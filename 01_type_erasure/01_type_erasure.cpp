// What is type erasure?
#include <functional>

class Base {
public:
	Base() = default;
	virtual ~Base() = default;

protected:
	Base(const Base&) = default;
	Base(Base&&) = default;
	Base& operator=(const Base&) = default;
	Base& operator=(Base&&) = default;
};

class Derived : public Base {};
class Derived2 : public Base {};

void use_base(const Base& base) {
	auto* d1 = dynamic_cast<const Derived*>(&base);

	if (d1 != nullptr) {
		// base is of type Derived
	}
}

void break_your_assumptions()
{
	struct MyDerived : Base {};

	use_base(MyDerived{});
}

// "normal" runtime polymorphism form of type erasure

int use_function(const std::function<int(int, int)>& f) {
	return f(2, 3);
}

int add(int lhs, int rhs) {
	return lhs + rhs;
}

int use_use_function() {
	struct S {
		int operator()(int lhs, int rhs) const { return lhs + rhs + constant; }
		int constant = 0;
	};

	S s{ 42 };
	return use_function(add) + use_function([](int x, int y) { return x * y; }) +
		use_function(std::bind_front(&S::operator(), &s));
}

int main()
{
	return use_use_function();
}

