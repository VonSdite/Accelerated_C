#ifndef GUARD_STRING_LIST_H
#define GUARD_STRING_LIST_H

#include <string>

//定义list结点的结构体
struct Node_t
{
	std::string data;										//保存字符串
	Node_t *next;											//指向下一个结点的指针
	Node_t *pre;											//指向上一个结点的指针
};


class String_list
{
public:
	typedef Node_t* iterator;								//将结点结构体指针命名为迭代器
	typedef const Node_t* const_iterator;					//常量迭代器

	String_list(): head(NULL), final(NULL) {}				//默认构造函数，指向空

	iterator begin() { return head; }						//返回list的头结点
	const_iterator begin() const { return head; }

	iterator end() { if (final == NULL) return final; return final - 1; }	//返回list的end()
	const_iterator end() const { if (final == NULL) return final; return final - 1; }

	iterator rend() { if (head == NULL) return head; return head->pre; }
	const_iterator rend() const { if (head == NULL) return head; return head->pre; }

	iterator rbegin() { return last(); }							

	void push_back(std::string &str) { list_insert(str); }	//插入字符串

	void clear();											//清空String_list类

private:
	iterator head;											//定义迭代器begin
	iterator final;											//定义迭代器end

	void list_insert(const std::string&);					//声明插入函数
	iterator last();
};


std::ostream& operator<<(std::ostream&, Node_t&);			//重载操作符<<，使之能读取list迭代器的内容


String_list::iterator String_list::last()
{
	iterator tmp = head;
	if (tmp == NULL) return tmp;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	return tmp;
}

void String_list::list_insert(const std::string &str)
{
	iterator tmp;
	iterator current;

	tmp = (iterator)new(Node_t);
	tmp->data = str;
	tmp->next = NULL;

	final = tmp->next + 1;										//让end指向插入信息的后一块空间，不可使用

	if (head == NULL)
	{
		head = tmp;
		head->pre = NULL;
	}
	else
	{
		current = head;
		while (current->next != NULL) current = current->next;
		current->next = tmp;
		tmp->pre = current;
	}
}

std::ostream& operator<<(std::ostream& out, Node_t& it)
{
	out << it.data;
	return out;
}


void String_list::clear()
{
	if (final == NULL) return;
	iterator current = final - 1;
	while (current != NULL)
	{
		current = current->pre;
		delete current->next;
	}
	head = NULL;
	final = NULL;
}

#endif // !GUARD_STRING_LIST_H
