#pragma once

template <typename PtrT, typename T>
void LOG(PtrT* ptr, T&& text)
{
	std::cout << ptr << " " << text << std::endl;
	//std::cout <<  << std::endl;
}

class TestClass final {
public:
	TestClass()
	{
		std::cout << "[" << this << "] TestClass( int " << std::to_string(_value) << " )" << std::endl;
	}

	TestClass(int value)
		: _value(value)
	{
		std::cout << "[" << this << "] TestClass( int " << std::to_string(_value) << " )" << std::endl;
	}

	TestClass(const TestClass& obj)
		: _value(obj._value)
		, _countToThrow(obj._countToThrow)
	{
		std::cout << "[" << this << "] TestClass( const & " << std::to_string(_value) << " [" << &obj << "])" << std::endl;

		if (_value == 2) {
			if (_countToThrow-- <= 0) {
				std::cout << "\nthrow error;\n" << std::endl;
				throw "error";
			}
		}
	}

	/*TestClass(TestClass&& obj) // noexcept
		: _value(obj._value)
	{
		std::cout << "[" << this << "] TestClass( && " << std::to_string(_value) << " [" << &obj << "])" << std::endl;
	}*/

	TestClass operator = (const TestClass& obj)
	{
		_value = obj._value;
		_countToThrow = obj._countToThrow;
		std::cout << "[" << this << "] TestClass = ( " << std::to_string(_value) << " [" << &obj << "])" << std::endl;
		return *this;
	}

	/*TestClass operator = (TestClass&& obj) noexcept
	{
		_value = obj._value;
		_countToThrow = obj._countToThrow;
		std::cout << "[" << this << "] TestClass = ( && " + std::to_string(_value) + " )" << std::endl;
		return *this;
	}*/

	~TestClass()
	{
		std::cout << "[" << this << "] ~TestClass( " + std::to_string(_value) + " )" << std::endl;
		_value = -1;
		_factor = -1;
		_countToThrow = 1;
	}
	operator int() const {
		return _value * _factor;
	}

private:
	int _value = 0;
	int _factor = 2;
	int _countToThrow = 1;
};
