#pragma once
template<class T>
class MySharedPtr
{
	T* ptr;
	static int count;
public:
	MySharedPtr() = default;
	MySharedPtr(T* ptr);
	MySharedPtr(const MySharedPtr& ptr_);
	MySharedPtr& operator=(MySharedPtr& ptr_);
	~MySharedPtr();
	T* get() {return ptr;}
	int getcount() {return count;}
};

template<class T>
int MySharedPtr<T>::count = 0;

template<class T>
inline MySharedPtr<T>::MySharedPtr(T* ptr)
{
	this->ptr = ptr;
	count++;
}

template<class T>
inline MySharedPtr<T>::MySharedPtr(const MySharedPtr& ptr_)
{
	ptr = ptr_.ptr;
	count++;

}

template<class T>
inline MySharedPtr<T>& MySharedPtr<T>::operator=(MySharedPtr& ptr_)
{
	count++;
	return ptr_;
}

template<class T>
inline MySharedPtr<T>::~MySharedPtr()
{
	if (count == 1)
	{
		delete ptr;
		count = 0;
		return;
	}
	ptr = nullptr;
	count--;
}
