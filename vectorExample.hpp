#include <memory>
#include <iostream>


template<typename T>
class vectorExample
{
	private:
		T *m_Data = nullptr; // will store a pointer whatever our data type is
		size_t	m_size = 0;
		size_t  m_capasity = 0;

		void ReAlloc(size_t newCapasity)
		{
			// 1. allocate a new block of memory
			// 2. copy / move old elements into new block
			// 3. delete
			T *newBlock = new T[newCapasity]; // allocate()

			if (newCapasity < m_size) // downsizing 
				m_size = newCapasity;

			for (size_t i = 0; i < m_size; i++)
				newBlock[i] = m_Data[i];
			
			delete[] m_Data;
			m_Data = newBlock;
			m_capasity = newCapasity;
		}

	public:

		vectorExample(size_t n)
		{
			ReAlloc(n);
		};

		~vectorExample()
		{
			delete[] m_Data;
		};

		void PushBack(const T &value)
		{
			if (m_size >= m_capasity)
			{
				ReAlloc((m_capasity + m_size) / 2); // growing by 50%
			}

			m_Data[m_size] = value;
			m_size += 1;
		};

		void PopBack()
		{
			if (m_size > 0)
			{
				m_size -= 1;
				m_Data[m_size];
			}
		}

		void Clear()
		{
			for (size_t i = 0; i < m_size; i++)
				m_Data[i].~T();

			m_size = 0;
		}

		const T &operator[](size_t index) const
		{
			return m_Data[index];
		};
	
		size_t Size() const { return m_size; };
		size_t Capasity() const { return m_capasity; } ;
};
