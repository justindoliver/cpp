#include <boost/multi_index_container.hpp>
#include <boost/multi_index/ordered_index.hpp>
#include <boost/multi_index/identity.hpp>
#include <boost/multi_index/member.hpp>

// define a multiply indexed set with indices by id and name
typedef multi_index_container<
  employee,
  indexed_by<
    // sort by employee::operator<
    ordered_unique<identity<employee> >,
    
    // sort by less<string> on name
    ordered_non_unique<member<employee,std::string,&employee::name> >
  > 
> employee_set;

void print_out_by_name(const employee_set& es)
{
  // get a view to index #1 (name)
  const employee_set::nth_index<1>::type& name_index=es.get<1>();
  // use name_index as a regular std::set
  std::copy(
    name_index.begin(),name_index.end(),
    std::ostream_iterator<employee>(std::cout));
}