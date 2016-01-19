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
	void expandBuffer();
	DynArray();
public:
	DynArray(DynArray<ComponentType>&);
	DynArray(int = 10);
	~DynArray();
	int size() const;
	int capacity() const;
	bool empty() const;
	ComponentType back() const;
	ComponentType front() const;
	ComponentType get(int) const;
	void push_back(ComponentType);
	void push_front(ComponentType);
	void set(ComponentType, int);
	void insert(ComponentType, int);
	void append(DynArray<ComponentType>&);
	void pop_back();
	void pop_front();
	void remove(int);
	void shrink();
	void zap();
	DynArray & operator=(const DynArray<ComponentType>&);
	ComponentType& operator[](int);
	template <class T>
	friend std::ostream &operator<< (std::ostream& out, DynArray<T>& arrayOut);

};

template <class ComponentType>
bool operator==(const DynArray<ComponentType> &, const DynArray<ComponentType> &);
}

#include "DynArray.cpp"
#endif