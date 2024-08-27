#pragma once

template <typename T>
class TemplateClass final {
public:
	TemplateClass() = default;

	template <typename U>
	TemplateClass(U&& value)
		: _value(static_cast<T>(value))
	{}

	operator T() const {
		return _value * _factor;
	}

private:
	T _value = 0;
	T _factor = 2;
};
