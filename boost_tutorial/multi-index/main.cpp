#include <iostream>
#include <iterator>
#include <algorithm>
#include <container.h>
#include <employee.h>

void print_out_by_name(const employee_set& es)
{
  // get a view to index #1 (name)
  const employee_set::nth_index<1>::type& name_index = es.get<1>();
  // use name_index as a regular std::set
  std::copy(
    name_index.begin(),name_index.end(),
    std::ostream_iterator<employee>(std::cout));
}

int main()
{
    using namespace boost;    
    using namespace boost::multi_index;

    return 0;  
}
