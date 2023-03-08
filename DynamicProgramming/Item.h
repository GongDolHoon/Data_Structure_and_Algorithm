#pragma once

#include <cstdint>

class Item final
{
public:
	Item(const int value, const int space)
		: mValue(value), mSpace(space)
	{
	}
	Item(const Item& other) = default;
	Item& operator=(const Item& other) = default;

	~Item() = default;

	int32_t GetValue() const
	{
		return mValue;
	}

	int32_t GetSpace() const
	{
		return mSpace;
	}

private:
	int32_t mValue;
	int32_t mSpace;
};