#ifndef TEST_H_INCLUDED
#define TEST_H_INCLUDED

#include <cmath>
#include <algorithm>
#include "complex.h"

//#ifndef TEST_ASSERT
#define TEST(x)                         \
   if (!(x)) cout << "check "           \
                  << #x << " "          \
                  << " failed in file " \
                  << __FILE__           \
                  << " at line "        \

/*                  << __LINE__ << endl;
#else
#define TEST(x) assert(x);
#endif
*/

#define EXCEPT_EQ(x,y) TEST((x) == (y));
#define EXCEPT_NQ(x,y) TEST((x) != (y));
#define EXCEPT_NAN(x)  TEST((x) != (x));
#define EXCEPT_INF(x)  TEST((x) == 1.0/0.0 || (x) == -1.0/0.0);
#define EXCEPT_PINF(x) TEST((x) == 1.0/0.0);
#define EXCEPT_NINF(x) TEST((x) == -1.0/0.0);
#define EXCEPT_APPR(x,y,eps) \
     TEST(std::abs(((x)-(y))/std::max((x),(y))) < eps);

void test_cm();
#endif // TEST_H_INCLUDED
