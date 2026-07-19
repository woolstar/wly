#include <buffer.h>
#include <gtest/gtest.h>

using namespace ::testing ;

namespace wly
{

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

} 
