#ifndef GUARD_STUDENT_INFO_H
#define GUARD_STUDENT_INFO_H

#include <vector>
#include <string>
#include <iostream>
#include <memory>
#include <cstdlib>

#include "exprtk.h"
#include "Read_Config.h"


//声明知识增量
double Knowledge_Inc(double);
//声明男生金钱增量
double Male_Money_Inc(double, double);
//声明男生体重增量
double Male_Weight_Inc(double, double, double, double);
//声明男生健康增量
double Male_Health_Inc(double);
//声明女生金钱增量
double Female_Money_Inc(double, double, double);
//声明女生体重增量
double Female_Weight_Inc(double, double, double);
//声明女生容貌增量
double Female_Looks_Inc(double);

//声明宿舍房号的结构体
//包含 楼层， 房号
typedef struct DORMITORY
{
	int floor;
	int room;

	DORMITORY() : floor(0), room(0) { }

}Dorm_t;


//声明学生基类
class Student
{
public:
	//当前恋人信息
	typedef Student *Pre_Lover;

	//恋人历史
	typedef std::vector<Student *> Old_lover;

	Student() : is_quit_school(false),									//默认构造函数
		have_lover(false),										//进行学生信息的初始化
		stu_money(dou(Configure::configure["MONEY"])),
		stu_weight(dou(Configure::configure["WEIGHT"])),
		stu_knowledge(dou(Configure::configure["KNOWLEDGE"])),
		stu_charm(dou(Configure::configure["CHARM"])),
		love_cnt(0)
		{ }

	//用于获取各数据成员变量值的成员函数
	std::string get_name() const { return stu_name; }
	std::string get_sex() const { return stu_sex; }

	double get_money() const { return stu_money; }
	double get_weight() const { return stu_weight; }
	double get_konwledge() const { return stu_knowledge; }
	double get_charm() const { return stu_charm; }

	int get_floor() const { return stu_dorm.floor; }
	int get_room() const { return stu_dorm.room; }
	Dorm_t get_dorm() const { return stu_dorm; }

	const std::vector<std::string>& get_lover_history()const { return m_lover_history; }
	std::string get_lover_name()const { return m_lover_history[m_lover_history.size() - 1]; }
	size_t get_lover_num()const { return love_cnt; }
	bool get_love_status()const { return have_lover; }

	bool get_is_quit_school() const { return is_quit_school; }
	void quit_school();

	virtual double get_special() const = 0;		

	void set_dorm(int, int);
	void add_lover(std::string);							//添加恋人名字
	void set_single();										//设置恋爱状态为单身
	void set_love_cnt() { love_cnt = m_lover_history.size(); }

	//学生类具有的活动函数
	virtual bool study(double) = 0;
	virtual bool eat(double) = 0;
	virtual bool work(double) = 0;
	virtual bool special_activity(double) = 0;

	//计算魅力值函数
	virtual void cal_charm() = 0;

	//设置学生信息
	virtual std::ifstream& set_init(std::ifstream&) = 0;

protected:
	//学生 姓名， 性别
	std::string stu_name;
	std::string stu_sex;

	//学生 体重， 金钱， 知识， 魅力值
	double stu_weight;
	double stu_money;
	double stu_knowledge;
	double stu_charm;

	//学生住的 楼层， 房间号
	Dorm_t stu_dorm;

	bool have_lover;	//是否恋爱中
	size_t love_cnt;	//恋爱次数

	std::vector<std::string> m_lover_history;

	//是否退过学
	bool is_quit_school;
};

//声明男生子类
class MaleStudent : public Student
{
public:
	MaleStudent() {};									//默认构造函数
	MaleStudent(std::string);

	bool study(double);
	bool eat(double);
	bool work(double);

	double get_special() const { return health; }		//获取男生健康值

	bool special_activity(double);						//男生特有的活动 运动

	double Male_Charm_Inc();							//声明男生魅力值增量
	void cal_charm();									//男生类计算魅力值函数

	//设置男学生信息
	std::ifstream& set_init(std::ifstream&);
private:
	double health;
};

//声明女生子类
class FemaleStudent : public Student
{
public:
	FemaleStudent() {};									//默认构造函数
	FemaleStudent(std::string);

	bool study(double);
	bool eat(double);
	bool work(double);

	double get_special() const { return looks; }		//获取女生容貌值

	bool special_activity(double);							//女生特有的活动 化妆

	double Female_Charm_Inc();							//声明女生魅力值增量
	void cal_charm();									//女生类计算魅力值函数

	//设置女学生信息
	std::ifstream& set_init(std::ifstream&);
private:
	double looks;
};


//当前恋人信息
typedef Student *Pre_Lover;

//恋人历史
typedef std::vector<Student *> Old_lover;

//实现用户接口
class Student_info
{
public:
	Student_info() :sp(NULL) {}
	Student_info(std::istream& is) :sp(NULL) { read(is); }
	Student_info(std::string, std::string);

	std::istream& read(std::istream&);

	std::string name() const 
	{
		if (sp)
			return sp->get_name();
		else
			throw std::runtime_error("uninitialized Student");
	}
	std::string sex() const 
	{
		if (sp)
			return sp->get_sex();
		else
			throw std::runtime_error("uninitialized Student");
	}
	double money() const 
	{
		if (sp)
			return sp->get_money();
		else
			throw std::runtime_error("uninitialized Student");
	}
	double weight() const 
	{
		if (sp)
			return sp->get_weight();
		else
			throw std::runtime_error("uninitialized Student");
	}
	double knowledge() const 
	{
		if (sp)
			return sp->get_konwledge();
		else
			throw std::runtime_error("uninitialized Student");
	}
	double charm() const 
	{
		if (sp)
			return sp->get_charm();
		else
			throw std::runtime_error("uninitialized Student");
	}
	void count_charm() 
	{
		if (sp)
			sp->cal_charm();
		else
			throw std::runtime_error("uninitialized Student");
	}
	double special() const 
	{
		if (sp)
			return sp->get_special();
		else
			throw std::runtime_error("uninitialized Student");
	}
	int get_floor() const 
	{
		if (sp)
			return sp->get_floor();
		else
			throw std::runtime_error("uninitialized Student");
	}
	int get_room() const 
	{
		if (sp)
			return sp->get_room();
		else
			throw std::runtime_error("uninitialized Student");
	}
	Dorm_t get_dorm() const
	{
		if (sp)
			return sp->get_dorm();
		else
			throw std::runtime_error("uninitialized Student");
	}
	void set_quit_school()
	{
		if (sp)
			sp->quit_school();
		else
			throw std::runtime_error("uninitialized Student");
	}
	void set_single()
	{
		if (sp)
			sp->set_single();
		else
			throw std::runtime_error("uninitialized Student");
	}
	void add_lover(std::string name)
	{
		if (sp)
			sp->add_lover(name);
		else
			throw std::runtime_error("uninitialized Student");
	}
	bool get_love_status() const
	{
		if (sp)
			return sp->get_love_status();
		else
			throw std::runtime_error("uninitialized Student");
	}
	std::string get_lover_name()const 
	{
		if (sp)
			return sp->get_lover_name();
		else
			throw std::runtime_error("uninitialized Student");
	}
	size_t get_lover_num() const 
	{
		if (sp)
			return sp->get_lover_num();
		else
			throw std::runtime_error("uninitialized Student");
	}
	const std::vector<std::string>& get_lover_history()const 
	{
		if (sp)
			return sp->get_lover_history();
		else
			throw std::runtime_error("uninitialized Student");
	}
	bool love_status()const 
	{
		if (sp)
			return sp->get_love_status();
		else
			throw std::runtime_error("uninitialized Student");
	}
	bool get_is_quit_school() const
	{
		if (sp)
			return sp->get_is_quit_school();
		else
			throw std::runtime_error("uninitialized Student");
	}
	void set_dorm(int floor_num, int room_num) 
	{
		if (sp)
			sp->set_dorm(floor_num, room_num);
		else
			throw std::runtime_error("uninitialized Student");
	}
	void eat(double time) const 
	{
		if (sp)
			sp->eat(time);
		else
			throw std::runtime_error("uninitialized Student");
	}
	void study(double time)const 
	{
		if (sp)
			sp->study(time);
		else
			throw std::runtime_error("uninitialized Student");
	}
	void work(double time)const 
	{
		if (sp)
			sp->work(time);
		else
			throw std::runtime_error("uninitialized Student");
	}
	void special_activity(double time) const 
	{
		if (sp)
			sp->special_activity(time);
		else
			throw std::runtime_error("uninitialized Student");
	}
	std::ifstream& set_init(std::ifstream& is)
	{
		if (sp)
			return sp->set_init(is);
		else
			throw std::runtime_error("uninitialized Student");
	}
	void set_love_cnt() 
	{ 
		if (sp)
			sp->set_love_cnt();
		else
			throw std::runtime_error("uninitialized Student");
	}
private:
	std::shared_ptr<Student> sp;
};



#endif 
