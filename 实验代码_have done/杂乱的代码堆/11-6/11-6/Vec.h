#ifndef GUARD_VEC_H
#define GUARD_VEC_H

#include <algorithm>
#include <cstddef>
#include <memory>

using std::max;

template <class T>
class Vec {
public:
	typedef T* iterator;
	typedef const T* const_iterator;
	typedef size_t size_type;
	typedef T value_type;
	typedef T& reference;
	typedef const T& const_reference;

	Vec() { create(); }												//构造函数
	explicit Vec(size_type n, const T& t = T()) { create(n, t); }

	Vec(const Vec& v) { create(v.begin(), v.end()); }				//复制构造函数
	Vec& operator=(const Vec&);										//赋值运算符函数
	~Vec() { uncreate(); }											//析构函数

	T& operator[](size_type i) { return data[i]; }
	const T& operator[](size_type i) const { return data[i]; }

	//插入某个元素
	void push_back(const T& t) 
	{
		if (avail == limit) grow();
		unchecked_append(t);
	}

	size_type size() const { return avail - data; }  

	iterator begin() { return data; }
	const_iterator begin() const { return data; }

	iterator end() { return avail; }                 
	const_iterator end() const { return avail; }   

	void clear() { uncreate(); }					//清空Vec类
	bool empty() const { return data == avail; }	//判断是否为空

	//清除某个位置上的元素  
	iterator erase(iterator position) 
	{
		for (iterator i = position; i != avail; ++i) 
		{
			alloc.destroy(i);
			if ((i + 1) != avail) alloc.construct(i, *(i + 1));
		}

		--avail;									//调整末元素后面一个元素
		return position;
	}

private:
	iterator data;									// Vec中的首元素
	iterator avail;									// Vec中末元素后面一个元素
	iterator limit;									// 新分配内存中末元素后面一个元素

	//内存分配工具				
	std::allocator<T> alloc;						// 控制内存分配的对象

	// 为底层的数组分配空间并对它进行初始化
	void create();
	void create(size_type, const T&);
	void create(const_iterator, const_iterator);

	// 删除数组中的元素并释放其占用的内存
	void uncreate();

	//支持push_back的函数
	void grow();
	void unchecked_append(const T&);
};

template <class T> void 
Vec<T>::create() 
{
	data = avail = limit = 0;
}

template <class T> 
void Vec<T>::create(size_type n, const T& val) 
{
	data = alloc.allocate(n);
	limit = avail = data + n;
	std::uninitialized_fill(data, limit, val);
}

template <class T>
void Vec<T>::create(const_iterator i, const_iterator j) 
{
	data = alloc.allocate(j - i);
	limit = avail = std::uninitialized_copy(i, j, data);
}

template <class T> 
void Vec<T>::uncreate() 
{
	if (data) {
		// （以相反的顺序）删除构造函数生成的元素
		iterator it = avail;
		while (it != data)
			alloc.destroy(--it);

		// 返回占用的所有内存空间
		alloc.deallocate(data, limit - data);
	}

	// 重置指针以表明Vec类型对象为空
	data = limit = avail = 0;
}

template <class T> 
void Vec<T>::grow() 
{
	// 在扩展对象大小时，为对象分配实际使用的两倍大小的内存空间
	size_type new_size = max(2 * (limit - data), ptrdiff_t(1));

	//分配新的内存空间并将已存在的对象元素内容复制到新内存中
	iterator new_data = alloc.allocate(new_size);
	iterator new_avail = std::uninitialized_copy(data, avail, new_data);

	// 返回原来的内存空间
	uncreate();

	// 重置指针，使其指向新分配的内存空间
	data = new_data;
	avail = new_avail;
	limit = data + new_size;
}

// 假设avail指向一片新分配但尚未被初始化的内存空间
template <class T> 
void Vec<T>::unchecked_append(const T& val) 
{
	alloc.construct(avail++, val);
}

template <class T>
Vec<T>& Vec<T>::operator=(const Vec& rhs) 
{
	// 判断是否进行自我赋值
	if (&rhs != this) {
		// 删除运算符左侧的数组
		uncreate();

		// 从右侧复制元素到左侧
		create(rhs.begin(), rhs.end());
	}

	return *this;
}
#endif // GUARD_VEC_H