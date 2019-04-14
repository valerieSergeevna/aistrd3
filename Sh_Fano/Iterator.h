#pragma once


template <class T>
class Iterator
{
public:
	virtual size_t operator*() const = 0;
	virtual void operator++(int) = 0;
	virtual bool operator==(const nullptr_t) const = 0;
	virtual bool operator!=(const nullptr_t) const = 0;
	virtual T current_key() = 0;
	virtual bool current_color() = 0;
//	virtual  current_node() = 0;

};