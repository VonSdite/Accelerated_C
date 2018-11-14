#include "Student_info.h"

//定义知识增量
double Knowledge_Inc(double study_time)
{
	typedef exprtk::symbol_table<double> symbol_table_t;
	typedef exprtk::expression<double>     expression_t;
	typedef exprtk::parser<double>             parser_t;

	std::string expression_string = Configure::configure["KNOWLEDGE_INC"];
	double study_knowledge = dou(Configure::configure["STUDY_KNOWLEDGE"]);

	symbol_table_t symbol_table;
	symbol_table.add_variable("STUDY_TIME", study_time);
	symbol_table.add_variable("STUDY_KNOWLEDGE", study_knowledge);
	symbol_table.add_constants();

	expression_t expression;
	expression.register_symbol_table(symbol_table);

	parser_t parser;
	parser.compile(expression_string, expression);

	return expression.value();
}

//定义男生金钱增量
double Male_Money_Inc(double work_time, double food_taken)
{
	typedef exprtk::symbol_table<double> symbol_table_t;
	typedef exprtk::expression<double>     expression_t;
	typedef exprtk::parser<double>             parser_t;

	std::string expression_string = Configure::configure["MALE_MONEY_INC"];

	double work_money = dou(Configure::configure["WORK_MONEY"]);
	double food_cost = dou(Configure::configure["FOOD_COST"]);

	symbol_table_t symbol_table;
	symbol_table.add_variable("WORK_TIME", work_time);
	symbol_table.add_variable("WORK_MONEY", work_money);
	symbol_table.add_variable("FOOD_TAKEN", food_taken);
	symbol_table.add_variable("FOOD_COST", food_cost);
	symbol_table.add_constants();

	expression_t expression;
	expression.register_symbol_table(symbol_table);

	parser_t parser;
	parser.compile(expression_string, expression);

	return expression.value();
}

//定义男生体重增量
double Male_Weight_Inc(double food_taken, double study_time, double work_time, double exercise_time)
{
	typedef exprtk::symbol_table<double> symbol_table_t;
	typedef exprtk::expression<double>     expression_t;
	typedef exprtk::parser<double>             parser_t;

	std::string expression_string = Configure::configure["MALE_WEIGHT_INC"];

	double food_weight = dou(Configure::configure["FOOD_WEIGHT"]);
	double study_weight = dou(Configure::configure["STUDY_WEIGHT"]);
	double work_weight = dou(Configure::configure["WORK_WEIGHT"]);
	double exercise_weight = dou(Configure::configure["EXERCISE_WEIGHT"]);

	symbol_table_t symbol_table;
	symbol_table.add_variable("FOOD_TAKEN", food_taken);
	symbol_table.add_variable("FOOD_WEIGHT", food_weight);
	symbol_table.add_variable("STUDY_TIME", study_time);
	symbol_table.add_variable("STUDY_WEIGHT", study_weight);
	symbol_table.add_variable("WORK_TIME", work_time);
	symbol_table.add_variable("WORK_WEIGHT", work_weight);
	symbol_table.add_variable("EXERCISE_TIME", exercise_time);
	symbol_table.add_variable("EXERCISE_WEIGHT", exercise_weight);
	symbol_table.add_constants();

	expression_t expression;
	expression.register_symbol_table(symbol_table);

	parser_t parser;
	parser.compile(expression_string, expression);

	return expression.value();
}

//定义男生健康增量
double Male_Health_Inc(double exercise_time)
{
	typedef exprtk::symbol_table<double> symbol_table_t;
	typedef exprtk::expression<double>     expression_t;
	typedef exprtk::parser<double>             parser_t;

	std::string expression_string = Configure::configure["HEALTH_INC"];

	double exercise_health = dou(Configure::configure["EXERCISE_HEALTH"]);

	symbol_table_t symbol_table;
	symbol_table.add_variable("EXERCISE_TIME", exercise_time);
	symbol_table.add_variable("EXERCISE_HEALTH", exercise_health);
	symbol_table.add_constants();

	expression_t expression;
	expression.register_symbol_table(symbol_table);

	parser_t parser;
	parser.compile(expression_string, expression);

	return expression.value();
}

//定义男生魅力值增量
double MaleStudent::Male_Charm_Inc()
{
	typedef exprtk::symbol_table<double> symbol_table_t;
	typedef exprtk::expression<double>     expression_t;
	typedef exprtk::parser<double>             parser_t;

	std::string expression_string = Configure::configure["MALE_CHARM_INC"];

	double knowledge_inc = stu_knowledge - dou(Configure::configure["KNOWLEDGE"]);
	double weight_inc = stu_weight - dou(Configure::configure["WEIGHT"]);
	double health_inc = health - dou(Configure::configure["HEALTH"]);

	symbol_table_t symbol_table;
	symbol_table.add_variable("KNOWLEDGE_INC", knowledge_inc);
	symbol_table.add_variable("WEIGHT_INC", weight_inc);
	symbol_table.add_variable("HEALTH_INC", health_inc);
	symbol_table.add_constants();

	expression_t expression;
	expression.register_symbol_table(symbol_table);

	parser_t parser;
	parser.compile(expression_string, expression);

	return expression.value();
}

//定义女生魅力值增量
double FemaleStudent::Female_Charm_Inc()
{
	typedef exprtk::symbol_table<double> symbol_table_t;
	typedef exprtk::expression<double>     expression_t;
	typedef exprtk::parser<double>             parser_t;

	std::string expression_string = Configure::configure["FEMALE_CHARM_INC"];

	double knowledge_inc = stu_knowledge - dou(Configure::configure["KNOWLEDGE"]);
	double weight_inc = stu_weight - dou(Configure::configure["WEIGHT"]);
	double looks_inc = looks - dou(Configure::configure["LOOKS"]);

	symbol_table_t symbol_table;
	symbol_table.add_variable("KNOWLEDGE_INC", knowledge_inc);
	symbol_table.add_variable("WEIGHT_INC", weight_inc);
	symbol_table.add_variable("LOOKS_INC", looks_inc);
	symbol_table.add_constants();

	expression_t expression;
	expression.register_symbol_table(symbol_table);

	parser_t parser;
	parser.compile(expression_string, expression);

	return expression.value();
}

//定义女生金钱增量
double Female_Money_Inc(double work_time, double food_taken, double makeup_time)
{
	typedef exprtk::symbol_table<double> symbol_table_t;
	typedef exprtk::expression<double>     expression_t;
	typedef exprtk::parser<double>             parser_t;

	std::string expression_string = Configure::configure["FEMALE_MONEY_INC"];

	double work_money = dou(Configure::configure["WORK_MONEY"]);
	double food_cost = dou(Configure::configure["FOOD_COST"]);
	double makeup_money = dou(Configure::configure["MAKEUP_MONEY"]);

	symbol_table_t symbol_table;
	symbol_table.add_variable("WORK_TIME", work_time);
	symbol_table.add_variable("WORK_MONEY", work_money);
	symbol_table.add_variable("FOOD_TAKEN", food_taken);
	symbol_table.add_variable("FOOD_COST", food_cost);
	symbol_table.add_variable("MAKEUP_TIME", makeup_time);
	symbol_table.add_variable("MAKEUP_MONEY", makeup_money);
	symbol_table.add_constants();

	expression_t expression;
	expression.register_symbol_table(symbol_table);

	parser_t parser;
	parser.compile(expression_string, expression);

	return expression.value();
}

//定义女生体重增量
double Female_Weight_Inc(double food_taken, double study_time, double work_time)
{
	typedef exprtk::symbol_table<double> symbol_table_t;
	typedef exprtk::expression<double>     expression_t;
	typedef exprtk::parser<double>             parser_t;

	std::string expression_string = Configure::configure["FEMALE_WEIGHT_INC"];

	double food_weight = dou(Configure::configure["FOOD_WEIGHT"]);
	double study_weight = dou(Configure::configure["STUDY_WEIGHT"]);
	double work_weight = dou(Configure::configure["WORK_WEIGHT"]);

	symbol_table_t symbol_table;
	symbol_table.add_variable("FOOD_TAKEN", food_taken);
	symbol_table.add_variable("FOOD_WEIGHT", food_weight);
	symbol_table.add_variable("STUDY_TIME", study_time);
	symbol_table.add_variable("STUDY_WEIGHT", study_weight);
	symbol_table.add_variable("WORK_TIME", work_time);
	symbol_table.add_variable("WORK_WEIGHT", work_weight);
	symbol_table.add_constants();

	expression_t expression;
	expression.register_symbol_table(symbol_table);

	parser_t parser;
	parser.compile(expression_string, expression);

	return expression.value();
}

//定义女生容貌增量
double Female_Looks_Inc(double makeup_time)
{
	typedef exprtk::symbol_table<double> symbol_table_t;
	typedef exprtk::expression<double>     expression_t;
	typedef exprtk::parser<double>             parser_t;

	std::string expression_string = Configure::configure["LOOKS_INC"];

	double makeup_looks = dou(Configure::configure["MAKEUP_LOOKS"]);

	symbol_table_t symbol_table;
	symbol_table.add_variable("MAKEUP_TIME", makeup_time);
	symbol_table.add_variable("MAKEUP_LOOKS", makeup_looks);
	symbol_table.add_constants();

	expression_t expression;
	expression.register_symbol_table(symbol_table);

	parser_t parser;
	parser.compile(expression_string, expression);

	return expression.value();
}

void Student::add_lover(std::string lover_name)
{
	m_lover_history.push_back(lover_name);
	have_lover = true;
}

void Student::set_single()
{
	have_lover = false;
}


bool MaleStudent::study(double time)
{
	double tmp = Male_Weight_Inc(0, time, 0, 0);
	if (stu_weight > -tmp)
	{
		stu_weight += tmp;
		stu_knowledge += Knowledge_Inc(time);
		return true;
	}
	return false;
}

bool MaleStudent::work(double time)
{
	double tmp = Male_Weight_Inc(0, 0, time, 0);
	if (stu_weight > -tmp)
	{
		stu_weight += tmp;
		stu_money += Male_Money_Inc(time, 0);
		return true;
	}
	return false;
}

bool MaleStudent::eat(double taken)
{
	double tmp = Male_Money_Inc(0, taken);
	if (stu_money >= -tmp)
	{
		stu_money += tmp;
		stu_weight += Male_Weight_Inc(taken, 0, 0, 0);
		return true;
	}
	return false;
}

bool MaleStudent::special_activity(double time)
{
	double tmp = Male_Weight_Inc(0, 0, 0, time);
	if (stu_weight > -tmp)
	{
		stu_weight += tmp;
		health += Male_Health_Inc(time);
		if (health > 100) health = 100;
		return true;
	}
	return false;
}

void MaleStudent::cal_charm()
{
	stu_charm += Male_Charm_Inc();
	if (stu_charm > 100) stu_charm = 100;
}

void FemaleStudent::cal_charm()
{
	stu_charm += Female_Charm_Inc();
	if (stu_charm > 100) stu_charm = 100;
}

bool FemaleStudent::study(double time)
{
	double tmp = Female_Weight_Inc(0, time, 0);
	if (stu_weight > -tmp)
	{
		stu_weight += tmp;
		stu_knowledge += Knowledge_Inc(time);
		return true;
	}
	return false;
}

bool FemaleStudent::eat(double taken)
{
	double tmp = Female_Money_Inc(0, taken, 0);
	if (stu_money >= -tmp)
	{
		stu_money += tmp;
		stu_weight += Female_Weight_Inc(taken, 0, 0);
		return true;
	}
	return false;
}

bool FemaleStudent::work(double time)
{
	double tmp = Female_Weight_Inc(0, 0, time);
	if (stu_weight > -tmp)
	{
		stu_weight += tmp;
		stu_money += Female_Money_Inc(time, 0, 0);
		return true;
	}
	return false;
}

bool FemaleStudent::special_activity(double time)
{
	double tmp = Female_Money_Inc(0, 0, time);
	if (stu_money > -tmp)
	{
		stu_money += tmp;
		looks += Female_Looks_Inc(time);
		if (looks > 100) looks = 100;
		return true;
	}
	return false;
}

MaleStudent::MaleStudent(std::string name) : Student()
{
	health = dou(Configure::configure["HEALTH"]);
	stu_name = name;
	stu_sex = "男";
}

FemaleStudent::FemaleStudent(std::string name) : Student()
{
	looks = dou(Configure::configure["LOOKS"]);
	stu_name = name;
	stu_sex = "女";
}

void Student::set_dorm(int floor_num, int room_num)
{
	stu_dorm.floor = floor_num;
	stu_dorm.room = room_num;
}

std::istream& Student_info::read(std::istream& is)
{
	std::string temp_name;
	std::string temp_gender;
	is >> temp_name >> temp_gender;
	sp = ("男" == temp_gender) ? std::shared_ptr<Student>(new MaleStudent(temp_name))
		: std::shared_ptr<Student>(new FemaleStudent(temp_name));
	return is;
}

Student_info::Student_info(std::string name, std::string gender) :sp(NULL)
{
	sp = ("男" == gender) ? std::shared_ptr<Student>(new MaleStudent(name))
		: std::shared_ptr<Student>(new FemaleStudent(name));
}

void Student::quit_school()
{
	is_quit_school = true;
}

std::ifstream& MaleStudent::set_init(std::ifstream& is)
{
	is >> stu_weight >> stu_money >> stu_knowledge >> stu_charm >> health >> have_lover >> is_quit_school;
	is >> love_cnt;
	std::string tmp;
	for (size_t i = 0; i < love_cnt; i++)
	{
		is >> tmp;
		m_lover_history.push_back(tmp);
	}
	return is;
}

std::ifstream& FemaleStudent::set_init(std::ifstream& is)
{
	is >> stu_weight >> stu_money >> stu_knowledge >> stu_charm >> looks >> have_lover >> is_quit_school;
	is >> love_cnt;
	std::string tmp;
	for (size_t i = 0; i < love_cnt; i++)
	{
		is >> tmp;
		m_lover_history.push_back(tmp);
	}
	return is;
}