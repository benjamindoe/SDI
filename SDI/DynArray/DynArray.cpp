#ifndef SDI_DYN_ARRAY_CPP
#define SDI_DYN_ARRAY_CPP

#include <cassert>
#include "DynArray.h"


namespace SDI
{
	template <class ComponentType>
	DynArray<ComponentType>::DynArray(int cap)
		{
			buffer_ = new ComponentType[cap];
			cap_ = cap;
			sz_ = 0;
		}

	template<class ComponentType>
	DynArray<ComponentType>::DynArray()
	{
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
		void DynArray<ComponentType>::expandBuffer()
		{
			if (sz_ == cap_)
			{
				int newCap = (int)(cap_ * 1.5);
				ComponentType * tmp = new ComponentType[newCap];

				for (int i = 0; i < cap_; i++)
				{
					tmp[i] = buffer_[i];
				}

				delete[] buffer_;
				buffer_ = tmp;
				cap_ = newCap;
			}
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
				expandBuffer();
			}
			buffer_[sz_] = data;
			sz_++;
		}

		template <class ComponentType>
		void DynArray<ComponentType>::pop_back()
		{
			assert(sz_ > 0);
			buffer_[sz_ - 1].~ComponentType();
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
			assert(index < sz_);
			return (buffer_[index]);
		}

		template <class ComponentType>
		void DynArray<ComponentType>::set(ComponentType data, int index)
		{
			assert(index < sz_);
			buffer_[index] = data;
		}

		template <class ComponentType>
		void DynArray<ComponentType>::zap()
		{
			delete[] buffer_;
			buffer_ = new ComponentType[cap_];
			sz_ = 0;
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
		void DynArray<ComponentType>::insert(ComponentType data, int index)
		{
			assert(index < cap_);
			ComponentType tmp;

			if (sz_ == cap_) 
				expandBuffer();

			for (int i = sz_; i >= 0; i--)
			{
				buffer_[i + 1] = buffer_[i];
			}
			buffer_[index] = data;
		}

		template <class ComponentType> 
		void DynArray<ComponentType>::remove(int index)
		{
			assert(index < sz_);
			for (int i = index; i <= sz_; i++)
			{
				buffer_[i] = buffer_[i + 1];
			}
			sz_--;
		}

		template <class ComponentType>
		void DynArray<ComponentType>::push_front(ComponentType data)
		{
			insert(data, 0);
		}

		template <class ComponentType>
		void DynArray<ComponentType>::pop_front()
		{
			remove(0);
		}

		template <class ComponentType>
		void DynArray<ComponentType>::append(DynArray<ComponentType>& tba)
		{
			int newSz = sz_ + tba.sz_;
			if (newSz > cap_)
			{
				int newCap = (int)(newSz * 1.5);
				ComponentType * tmp = new ComponentType[newCap];
				int j = 0;
				for (int i = 0; i < newSz; i++)
				{
					if (i < sz_)
					{
						tmp[i] = buffer_[i];
					}
					else
					{
						tmp[i] = tba[j];
					}
					j++;
				}
				delete[] buffer_;
				buffer_ = tmp;
				cap_ = newCap;
				sz_ = newSz;
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
				for (unsigned int i = 0; i < cap_; i++)
				{
					buffer_[i] = rhs.buffer_[i];
				}
			}
			return (*this);
		}

		template <class ComponentType>
		ComponentType& DynArray<ComponentType>::operator[](int i)
		{
			assert(i < sz_);
			return buffer_[i];
		}

		template <class ComponentType>
		std::ostream &	operator<< (std::ostream& out, DynArray<ComponentType>& arrayOut)
		{
			out << "<";
			if (!arrayOut.empty())
			{
				out << arrayOut.front();
			}
			int i = 1;
			while (i < arrayOut.size())
			{
				out << ", " << arrayOut[i];
				i++;
			}
			out << ">";
			return out;
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