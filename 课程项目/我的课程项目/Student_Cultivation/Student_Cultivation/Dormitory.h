//����������ṹ
#ifndef GUARD_DORMITORY_H
#define GUARD_DORMITORY_H

#include <map>
#include <set>
#include <string>
#include <fstream>
#include "Read_Config.h"

//��������ǡ��ǌӡ����g�Ĕ����Y��
typedef std::set<std::string> Room;					//���᷿�䣬ʹ��set���ڶ�ѧ����������
typedef std::map<int, Room> Floor;					//����¥�㣬ʹ��map���ڿ����ҵ���Ӧ����ŵķ���
typedef std::map<int, Floor> Dormitory;				//����¥��ʹ��map���ڿ����ҵ���Ӧ¥��ŵ�¥��

class Dorm
{
public:
	Dorm();

	//��ȡĳ�����ѧ������
	Room get_stu(size_t, size_t) const;

	//�����������ѧ���������ӳɹ��򷵻�true�����򷵻�false
	void add_stu(size_t, size_t, std::string);

	//ɾ��������ĳ��ѧ������ѧ����ѧ������----��ѧ
	void delete_stu(size_t, size_t, std::string);

	//ͨ��¥���������ڲ�¥��
	Floor& operator[](size_t);

	//��������ѧ���Ա�
	void set_gender(size_t, size_t, std::string);

	//��ȡ����ѧ���Ա�
	std::string get_room_gender(size_t, size_t);

	//����Ƿ񳬳�����
	bool extract_limit(size_t, size_t);

	//��ⷿ����Ƿ����
	bool extract_exist(size_t, size_t) const;

	//����¥����
	void add_floor(size_t);

	//���ӷ�����
	void add_room(size_t, size_t);

	//���ӷ�������
	void add_capacity(size_t, size_t, size_t);

	std::ifstream& set_init(std::ifstream&);

	size_t get_floor_limit() const { return floor_limit; }
	std::map<size_t, size_t> get_room_limit() const { return room_limit; }
	std::map<size_t, std::map<size_t, size_t> > get_capacity_limit() const { return capacity_limit; }
private:
	Dormitory dorm;

	//¥��������
	size_t floor_limit;

	//��ֵΪ¥��������ӦԪ�ص�ֵΪÿ��¥�ķ���������
	std::map<size_t, size_t> room_limit;

	//�ֱ���¥������������Ϊ��ֵ����ӦԪ�ص�ֵΪ������������
	std::map<size_t, std::map<size_t, size_t> > capacity_limit;

	//��������ѧ���Ա�
	std::map<size_t, std::map<size_t, std::string> > room_gender;
};

#endif