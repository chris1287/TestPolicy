#include <deque>
#include <iostream>
#include <algorithm>

using namespace std;

namespace TestPolicy
{
	template <typename T>
	class ExtractPolicy
	{
		public:
			virtual ~ExtractPolicy(){};
			virtual T& GetElement() = 0;
			virtual T& PopElement() = 0;
			virtual void RemoveElement() = 0;

			virtual void PutElement(T& t)
			{
				q_.push_front(t);
			}

			virtual bool IsEmpty()
			{
				return q_.empty();
			}

		protected:
			deque<T> q_;
	};

	template <typename T>
	class FIFOPolicy : public ExtractPolicy<T>
	{
		public:
			T& GetElement()
			{
				return this->q_.back();
			}

			void RemoveElement()
			{
				this->q_.pop_back();
			}

			T& PopElement()
			{
				T& t = GetElement();
				RemoveElement();
				return t;
			}
	};

	template <typename T>
	class LIFOPolicy : public ExtractPolicy<T>
	{
		public:
			T& GetElement()
			{
				return this->q_.front();
			}

			void RemoveElement()
			{
				this->q_.pop_front();
			}

			T& PopElement()
			{
				T& t = GetElement();
				RemoveElement();
				return t;
			}
	};

	template<typename T, template<typename> class EP>
	class DataStructure : public EP<T>
	{
		public:
			void Traverse()
			{
				for_each(this->q_.begin(), this->q_.end(), [](T i){ cout << i << endl; });
			}
	};
}

int main()
{
	using namespace TestPolicy;

	DataStructure<int, FIFOPolicy> dsf;
	DataStructure<int, LIFOPolicy> dsl;

	int i;

	for(i = 0; i < 10; i++)
	{
		dsf.PutElement(i);
		dsl.PutElement(i);
	}

	while(! dsf.IsEmpty() )
	{
		cout << "First element of dsf:" << endl;
		cout << dsf.GetElement() << endl;
		dsf.RemoveElement();
	}

	while(! dsl.IsEmpty() )
	{
		cout << "First element of dsl:" << endl;
		cout << dsl.GetElement() << endl;
		dsl.RemoveElement();
	}

	cout << "Traversing dsf:" << endl;
	dsf.Traverse();
	cout << "Traversing dsl:" << endl;
	dsl.Traverse();

	return 0;
}

