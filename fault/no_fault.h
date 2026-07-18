
#include <fault.h>

namespace wly
{

class no_fault : public fault
{
    public:
      void  operator()() override { }
} ;

} ;

