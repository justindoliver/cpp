#pragma once
#include <string>

struct Employee
{
  int         id;
  std::string name;

  Employee(int id,const std::string& name):id(id),name(name){}

  bool operator<(const Employee& e)const { return id < e.id; }
};

std::ostream& operator <<(std::ostream& os, const Employee& e)
{
	os << "Name [" << e.name << "]" << std::endl;
	os << "ID [" << e.id << "]" << std::endl;
	return os;
}