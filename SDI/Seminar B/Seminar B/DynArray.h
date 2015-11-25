

#ifndef SDI_DYN_ARRAY_H
#define SDI_DYN_ARRAY_H
#include <string>

namespace SDI
{
	//class ComponentType;	//forward declaration –
							//probably replaced a typedef

template <class ComponentType>
class DynArray 
{
private:
	//your choice (data & helper functions)
	ComponentType * buffer_;
	int cap_;
	int sz_;
public:
	DynArray();
	DynArray(DynArray<ComponentType>&);
	DynArray(int);
	~DynArray();
	int size() const;
	int capacity() const;
	bool empty() const;
	void push_back(ComponentType);
	void pop_back();
	ComponentType back() const;
	ComponentType front() const;
	ComponentType get(int) const;
	void set(ComponentType, int);
	void zap();
	void shrink();
	DynArray & operator=(const DynArray<ComponentType> & rhs);
};

template <class ComponentType>
bool operator==(const DynArray<ComponentType> &, const DynArray<ComponentType> &);
}

#include "DynArray.cpp"
#endif