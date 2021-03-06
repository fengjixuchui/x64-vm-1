// STD
#include <iostream>

// VM
#include "vm_test.hpp"


int main()
{
	global::console.log("Testing x86-64 virtual machine");

	constexpr std::uint8_t buffer[] = {
		
		0x49, 0x81, 0x81, 0x20, 0x04, 0x00, 0x00, 0x37, 0x13, 0x00, 0x00,	// ADD [R9+0x420], 1337

		
		0x66, 0x48, 0x81, 0xC3, 0x00, 0x00, 0x05, 0x00,						// ADD RBX, 50000
	};

	auto test_engine = vm_tester(buffer);

	test_engine.prepare_test();
	test_engine.run();


	return 0;
}

