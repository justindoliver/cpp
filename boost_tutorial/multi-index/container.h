#pragma once

// STL
#include <iostream>

// Boost
#include <boost/multi_index_container.hpp>
#include <boost/multi_index/ordered_index.hpp>
#include <boost/multi_index/identity.hpp>
#include <boost/multi_index/member.hpp>

// Tutorial
#include <employee.h>


using namespace boost;    
using namespace boost::multi_index;

class EmployeeContainer
{
public:

  // define a multiply indexed set with indices by id and name
  typedef multi_index_container<
    Employee,
    indexed_by<
      // sort by Employee::operator<
      ordered_unique<identity<Employee> >,
      
      // sort by less<string> on name
      ordered_non_unique<member<Employee,std::string,&Employee::name> >
    > 
  > Employee_container_t;

  void printByname();

  bool add( const Employee& e);
  bool clear();

private:

  Employee_container_t d_EmployeeContainer;

};

bool EmployeeContainer::add( const Employee& e )
{
  d_EmployeeContainer.insert(e);
}

bool EmployeeContainer::clear()
{
  d_EmployeeContainer.clear();
  return true;
}

void EmployeeContainer::printByname()
{
  // get a view to index #1 (name)
  const Employee_container_t::nth_index<1>::type& name_index = d_EmployeeContainer.get<1>();

  // use name_index as a regular std::set
  std::copy(
    name_index.begin(),name_index.end(),
    std::ostream_iterator<Employee>(std::cout));
}