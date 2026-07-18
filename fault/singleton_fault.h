
#include <fault.h>

namespace wly
{

class singleton_fault : public fault
{
    public:
      static bool   has_fault() ;
      static void   reset() ;

      static fault &  get() ;

      void  operator()() override ;
} ;

}

