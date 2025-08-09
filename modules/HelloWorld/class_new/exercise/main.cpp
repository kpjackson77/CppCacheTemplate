#include <iostream>

class SomeData {
  int _a,_b;
  public:
    SomeData(int a, int b) :_a(a), _b(b) {}
    void* operator new(size_t size)
    {
    	std::cout << "Allocating for SomeData..." << std::endl;
      	return ::operator new(size);
    }
    void operator delete(void* ptr)
    {
      	std::cout << "De-allocating for SomeData..." << std::endl;
      	::operator delete(ptr);
    }
    int get_a()const { return _a;}
};
int main()
{
	
	{
		SomeData *psd = new SomeData{ 5,6 }, *psd2 = new SomeData{23,5};

    	delete psd;
    	delete psd2;
	}

	std::cout << "Hello World!\n";
	return 0;
}
