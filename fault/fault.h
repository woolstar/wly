#ifndef FAULT_H
#define FAULT_H 1

namespace wly
{

class fault
{
    public:
      virtual ~ fault() {}

      virtual void  operator()() = 0 ;
} ;

}  // namespace wly

#endif
