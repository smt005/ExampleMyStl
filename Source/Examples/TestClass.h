#pragma once

class TestClass final {
public:
	TestClass() = default;
	TestClass(int value)
		: _value(value)
	{}

	operator int() {
		return _value * _factor;
	}

private:
	int _value = 0;
	int _factor = 2;
};
