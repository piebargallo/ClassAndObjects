// Type Erasure: hide the exact type of an object when you go to work with it
// simpler and faster to compile interfaces
// can work with any type that migth be declared in the future
// compilation firewall to prevent recompiling the entire library for adding a new type

#include <print>
using namespace std;

class animal_view {
public:
	template <typename Speakable>
	explicit animal_view(const Speakable& speakable) :
		object{ &speakable },
		speak_impl{ // create a lambda that knows how to unpack the stored object
			[](const void* obj) {
				return static_cast<const Speakable*>(obj)->speak();
			} } {}

			void speak() const { speak_impl(object); }
private:
	// void * to object of unknow type
	const void* object;

	// function pointer that knows how to use unknow type
	void (*speak_impl)(const void*);
};

void do_animal_things(animal_view animal) { animal.speak(); }

int main()
{
	struct Cow {
		void speak() const {
			fmt::print("Mooo\n");
		}
	};

	struct Sheep {
		void speak() const {
			fmt::print("Baaa\n");
		}
	};

	// no pholimorpism, no dynamic allocations, but still
	// a function indirection. From a performance perspective
	// we have not gained anything over a virtual function 
	// call.

	// we have increased risk, some. We migth end up with a dangling
	// reference.
	do_animal_things(animal_view{ Cow{} });
	do_animal_things(animal_view{ Sheep{} });
}
