#pragma once
#include <iostream>

template <class  T>
class Vector
{
private:

	unsigned int m_size;// array size
	T* m_data = nullptr;

public:
	
	Vector(unsigned int Size = 0, T init = T());
	void Resize(unsigned int newSize,T init=T() );
	void PushBack(T a);
	void Insert(unsigned int index, T value = T() ) ;
	void Remove(unsigned int index);
	void Clear();
	unsigned int GetSize(); 

	T& operator[](int index);

	~Vector()
	{
		delete[] m_data;
	}



};

template <class  T>
Vector<T>::Vector(unsigned int Size , T init )
{

	m_size = Size;
	m_data = new T[m_size];
	for (size_t i = 0; i < m_size; i++)
	{
		m_data[i] = init;
	}
};

template <class  T>
unsigned int Vector<T>::GetSize()
{
	return m_size;
};



template<class T>
 void Vector<T>::Resize(unsigned int newSize,T init)
{
	if (newSize == m_size) return;

	T* temp = m_data;
	m_data = new T[newSize];
	
	for (size_t i = 0; i < newSize; i++)
	{
		if (i < m_size) m_data[i] = temp[i];
		else m_data[i] = init;
	}
	m_size = newSize;
	delete[] temp;

}

template<class T>
void Vector<T>::PushBack(T a)
{
	Resize(m_size + 1);
	m_data[m_size-1] = a;

}

 template<class T>
 T& Vector<T>::operator[](int index)
 {
	 if (index >= m_size) {
		 std::cout << "Array index out of bound, exiting";
		 exit(0);
	 }
	 return m_data[index];
 }

 template<class T>
 void Vector<T>::Insert(unsigned int index, T value )
 {
	 if (index <= m_size)
	 {
		 int newSize = m_size + 1;
		 T* temp = m_data;
		 m_data = new T[newSize];
		 int shifter = 0;
		 for (size_t i = 0; i < newSize; i++)
		 {
			 if (i == index)
			 {
				 shifter=1;
				 m_data[i] = value;

			 }
			 else
			 {
				 m_data[i] = temp[i-shifter];
			 }
		 }

		 m_size = newSize;
		 delete[] temp;

	 }
	 else 
	 {
		 Resize(index );
		 m_data[index-1] = value;
	 }
 }

 template<class T>
 void Vector<T>::Remove(unsigned int index)
 {
	 if (index < m_size)
	 {
		 int newSize = m_size - 1;
		 T* temp = m_data;
		 m_data = new T[newSize];
		 int shifter = 0;
		 for (size_t i = 0; i < newSize; i++)
		 {
			 if (i == index)
			 {
				 shifter = 1;

			 }

			 m_data[i] = temp[i + shifter];
			 
		 }

		 m_size = newSize;
		 delete[] temp;

	 }
	 return;

 }
 template<class T>
 void Vector<T>::Clear()
 {
	 delete[] m_data;
	 m_size = 0;
	 m_data = nullptr;
 }
 template<class T>
 std::ostream& operator<< (std::ostream& out, Vector<T>& a) 
{
	 
	unsigned int len = a.GetSize();
	 
	for (size_t i = 0; i < len; i++)
	{
		out << a[i] ;
		if (i < len - 1) out << ',';
	}

	out << " size= " << a.GetSize();
	 return out;
 }
 

 