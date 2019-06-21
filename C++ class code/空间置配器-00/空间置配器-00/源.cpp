#include <iostream>
using namespace std;

template <int inst>
class _malloc_alloc_template
{
	static void *oom_malloc(size_t);
	static void *oom_realloc(void*, size_t);
public:
	//将malloc封装
	static void* allocate(size_t n)
	{
		void * result = malloc(n);
		if (result == 0)
		{
			result == oom _malloc(n);
		}
		return result;
	}

	//对free封装

	static void deallocate(void* p, size_t)
	{
		free(p);
	}

	//对realloc封装
	static void* reallocate(void* p, size_t, size_t new_sz)
	{
		void* result = realloc(p, new_sz);
		if (result == 0)
			result = oom_realloc(p, new_sz);
		return result;
	}

	//该函数的参数为函数指针，返回值同为函数指针
	static void(*set_malloc_handler(void(*f)()))()
	{
		void(*old)() = _malloc_alloc_oom_handler;
		_malloc_alloc_oom_handler = f;

		return(old);
	}
};


//malloc申请内存空间失败，调用该函数
template <int inst>

void* _malloc_alloc_template<inst> ::oom_malloc(size_t n)
{
	void(*set_malloc_handler)();
	void * result;

	while (1)
	{
		//检测用户是否设置空间不足的应对措施，若没有，抛异常，模式new的方式
		set_malloc_handler = _malloc_alloc_oom_handler;
		if (my _alloc_handler == 0)
		{
			__THROW_BAD_ALLOC;
		}

		(*my_malloc_handler)();

		result = malloc(n);

		if (result)
			return(result);
	}
}


//realloc
template <int inst>

void* _malloc_alloc_template<inst> ::oom_realloc(void* p, size_t n)
{
	void(*set_malloc_handler)();
	void * result;

	while (1)
	{
		//检测用户是否设置空间不足的应对措施，若没有，抛异常，模式new的方式
		set_malloc_handler = _malloc_alloc_oom_handler;
		if (my _alloc_handler == 0)
		{
			__THROW_BAD_ALLOC;
		}

		(*my_malloc_handler)();

		result = realloc(p, n);

		if (result)
			return(result);
	}
}
typedef _malloc_alloc_template<0> malloc_alloc;