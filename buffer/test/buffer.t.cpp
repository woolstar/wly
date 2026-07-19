#include <buffer.h>
#include <gtest/gtest.h>

using namespace ::testing ;

namespace wly
{

namespace
{

}

TEST( buffer, usage )
{
    char  tmp[8] ;
    buffer  test( tmp ) ;

    EXPECT_NE( test.begin_, nullptr ) ;
    EXPECT_NE( test.end_, nullptr ) ;
    EXPECT_EQ( test.begin_, test.curr_ ) ;
}

TEST( buffer, default_construct )
{
    buffer  test ;

    SUCCEED() ;
}

TEST( buffer, copy )
{
    char  tmp[8] = "abcd" ;
    buffer  test( tmp ) ;

    test.curr_ ++ ;
    test.curr_ ++ ;
    EXPECT_EQ( * test.curr_, 'c' ) ;

    buffer  testcopy( test ) ;
    EXPECT_EQ( * testcopy.curr_, 'c' ) ;
}

TEST( buffer, size )
{
    char tmp[8] ;
    uint8_t tmpu[8] ;

    {
      buffer test( tmp ) ;
      EXPECT_EQ( test.end_ - test.begin_, sizeof( tmp )) ;
    }
    {
      buffer test( tmpu ) ;
      EXPECT_EQ( test.end_ - test.begin_, sizeof( tmpu )) ;
    }
}

} 
