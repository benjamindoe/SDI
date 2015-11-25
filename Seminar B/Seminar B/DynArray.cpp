#ifndef SDI_DYN_ARRAY_CPP
#define SDI_DYN_ARRAY_CPP

#include "DynArray.h"


namespace SDI
{
	template <class ComponentType>
	DynArray<ComponentType>::DynArray(int cap = 10)
		{
			buffer_ = new ComponentType[cap];
			cap_ = cap;
			sz_ = 0;
		}

		template <class ComponentType>
		DynArray<ComponentType>::DynArray(DynArray<ComponentType> & tbc)
		{
			buffer_ = new ComponentType[tbc.cap_];
			cap_ = tbc.cap_;
			sz_ = tbc.sz_;
			for (int i = 0; i < cap_; i++)
			{
				buffer_[i] = tbc.buffer_[i];
			}
		}
		template <class ComponentType>
		DynArray<ComponentType>::~DynArray()
		{
			delete[] buffer_;
		}

		template <class ComponentType>
		int DynArray<ComponentType>::size() const
		{
			return (sz_);
		}
		
		template <class ComponentType>
		int DynArray<ComponentType>::capacity() const
		{
			return (cap_);
		}

		template <class ComponentType>
		bool DynArray<ComponentType>::empty() const
		{
			return (sz_ != 0);
		}

		template <class ComponentType>
		void DynArray<ComponentType>::push_back(ComponentType data)
		{

			if (sz_ == cap_)
			{
				int newCap = cap_ * 1.5;
				ComponentType * tmp = new ComponentType[newCap];
				
				for (int i = 0; i < cap_; i++)
				{
					tmp[i] = buffer_[i];
				}

				delete[] buffer_;
				buffer_ = tmp;
				cap_ = newCap;
			}
			buffer_[sz_] = data;
			sz_++;
		}

		template <class ComponentType>
		void DynArray<ComponentType>::pop_back()
		{
			sz_--;
		}

		template <class ComponentType>
		ComponentType DynArray<ComponentType>::front() const
		{
			return (buffer_[0]);
		}

		template <class ComponentType>
		ComponentType DynArray<ComponentType>::back() const
		{
			return (buffer_[sz_ - 1]);
		}

		template <class ComponentType>
		ComponentType DynArray<ComponentType>::get(int index) const
		{
			if (index < sz_)
			{
				return (buffer_[index]);
			}
		}

		template <class ComponentType>
		void DynArray<ComponentType>::set(ComponentType data, int index)
		{
			if (index < sz_)
			{
				buffer_[index] = data;
			}
		}

		template <class ComponentType>
		void DynArray<ComponentType>::zap()
		{
			delete[] buffer_;
			buffer_ = new ComponentType[cap_];
		}

		template <class ComponentType>
		void DynArray<ComponentType>::shrink()
		{
			if (cap_ > sz_)
			{
				ComponentType * tmp = new ComponentType[sz_];
				for (int i = 0; i < sz_; i++)
				{
					tmp[i] = buffer_[i];
				}
				delete[] buffer_;
				buffer_ = tmp;
				cap_ = sz_;
			}
		}

		template <class ComponentType>
		DynArray<ComponentType> & DynArray<ComponentType>::operator=(const DynArray<ComponentType> & rhs)
		{
			if (buffer_ != rhs.buffer_)
			{
				delete[] buffer_;
				buffer_ = new ComponentType[rhs.cap_];
				cap_ = rhs.cap_;
				sz_ = rhs.sz_;
				for (unsigned int i = 0; i < cap_; ++i)
				{
					buffer_[i] = rhs.buffer_[i];
				}
			}
			return (*this);
		}

		template <class ComponentType>
		bool operator==(const DynArray<ComponentType> & lhs, const DynArray<ComponentType> & rhs)
		{
			bool equal = false;
			if (lhs.size() == rhs.size())
			{
				for (int i = 0; i < lhs.size(); i++)
				{
					equal = (lhs.get(i) == rhs.get(i)) ? true : false;
				}
			}
			return equal;
		}
}

#endif