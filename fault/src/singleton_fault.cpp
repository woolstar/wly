
#include <singleton_fault.h>

namespace wly
{

namespace
{

bool &  get_fault()
{
    static bool fault_ = false ;
    return fault_ ;
}

}

fault &
singleton_fault::get()
{
    static singleton_fault  s_fault ;

    return s_fault ;
}

bool  singleton_fault::has_fault()
{
    return get_fault() ;
}

void  singleton_fault::reset()
{
    get_fault()= false ;
}

void
singleton_fault::operator()()
{
    get_fault()= true ;
}

}

