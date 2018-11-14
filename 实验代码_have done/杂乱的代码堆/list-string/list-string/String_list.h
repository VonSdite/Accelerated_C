#ifndef GUARD_STRING_LIST_H
#define GUARD_STRING_LIST_H

#include <string>

//����list���Ľṹ��
struct Node_t
{
	std::string data;										//�����ַ���
	Node_t *next;											//ָ����һ������ָ��
	Node_t *pre;											//ָ����һ������ָ��
};


class String_list
{
public:
	typedef Node_t* iterator;								//�����ṹ��ָ������Ϊ������
	typedef const Node_t* const_iterator;					//����������

	String_list(): head(NULL), final(NULL) {}				//Ĭ�Ϲ��캯����ָ���

	iterator begin() { return head; }						//����list��ͷ���
	const_iterator begin() const { return head; }

	iterator end() { if (final == NULL) return final; return final - 1; }	//����list��end()
	const_iterator end() const { if (final == NULL) return final; return final - 1; }

	iterator rend() { if (head == NULL) return head; return head->pre; }
	const_iterator rend() const { if (head == NULL) return head; return head->pre; }

	iterator rbegin() { return last(); }							

	void push_back(std::string &str) { list_insert(str); }	//�����ַ���

	void clear();											//���String_list��

private:
	iterator head;											//���������begin
	iterator final;											//���������end

	void list_insert(const std::string&);					//�������뺯��
	iterator last();
};


std::ostream& operator<<(std::ostream&, Node_t&);			//���ز�����<<��ʹ֮�ܶ�ȡlist������������


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

	final = tmp->next + 1;										//��endָ�������Ϣ�ĺ�һ��ռ䣬����ʹ��

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
