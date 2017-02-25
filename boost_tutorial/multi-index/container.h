#pragma once

// STL
#include <iostream>
#include <functional>
#include <string>

// Boost
#include <boost/multi_index_container.hpp>
#include <boost/multi_index/ordered_index.hpp>
#include <boost/multi_index/identity.hpp>
#include <boost/multi_index/member.hpp>

//
// STD
// #include <memory> for shared-ptr

// Tutorial
#include <employee.h>
#include <dependency.h>


using namespace boost;    
using namespace boost::multi_index;

struct by_name {};
struct by_id {};

class EmployeeContainer
{
public:

  EmployeeContainer(  Dependency* d ) : d_dependency_p(d) {}

  // define a multiply indexed set with indices by id and name
  typedef multi_index_container<
    Employee,
    indexed_by<
      // sort by Employee::operator<
      ordered_unique< tag<by_id>, identity<Employee> >,
      
      // sort by less<string> on name
      ordered_non_unique< tag<by_name>, member<Employee,std::string,&Employee::name>, std::less<std::string> >
    > 
  > Employee_container_t;

  void printByname();
  void printById();

  bool findByName( const std::string& name, Employee& e );

  bool add( const Employee& e);
  bool clear();
  int count();

private:

  Employee_container_t d_EmployeeContainer;

  Dependency* d_dependency_p;

};

bool EmployeeContainer::add( const Employee& e )
{
  std::pair<Employee_container_t::iterator,bool> result = d_EmployeeContainer.insert(e);

  d_dependency_p->doTheThing( 0 );

  return result.second;
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

  for( int x = 0; x < 2; x++ ) {
    d_dependency_p->doTheOtherThing( x, x + 1 );
  }
  
}

void EmployeeContainer::printById()
{
  const Employee_container_t::nth_index<0>::type & id_index = d_EmployeeContainer.get<0>();

  std::copy(
    id_index.begin(),id_index.end(),
    std::ostream_iterator<Employee>(std::cout));
}

bool EmployeeContainer::findByName( const std::string& name, Employee& e )
{

  std::string theArgument("theArgument");
  int returnCode = d_dependency_p->doTheSuperThing( theArgument );

  bool result = false;

  typedef Employee_container_t::index<by_name>::type employee_set_by_name;
  employee_set_by_name::iterator it = d_EmployeeContainer.get<by_name>().find(name);

  if( it != d_EmployeeContainer.get<by_name>().end() ) {
    e = *it;
    result = true;
  }

  return result;
}

int EmployeeContainer::count()
{
  return d_EmployeeContainer.size();
}