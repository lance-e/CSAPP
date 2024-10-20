/* 
 * CS:APP Data Lab 
 * 
 * <lance>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.


EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
//1
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
  return ~(~( ~x & y ) & ~( x & ~y ));
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
    return 0x1 << 31;
}
//2
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmax(int x) {
    int tmin = x + 1;
    x += tmin;
    x = ~x ;
    x += !tmin;
    return !x;
}
/* 
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x) {
  int mask = 0xAA + (0xAA <<8 );
  mask += mask << 16;
  return !( (x & mask)  ^ mask);
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
  return ~x + 1;
}
//3
/* 
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) {
    int sign = 0x1 << 31;
    int upper = ~(sign | 0x39);
    int lower = ~0x30;
    return !((sign & (upper + x ) >> 31) | (sign & (lower + 1 + x) >> 31 ) );
}
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
  x = !!x;
  x = (~x + 1) >>31 ;
  return ( y & x) | (z & (~x)) ;
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(3,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
    int minusx = ~x + 1;        //得到-x
    int result = y + minusx ;   //得到y-x
    int sign = (result >> 31 ) & 1;     //判断y-x的符号
    int xsign = (x >>31) & 1;   //x的符号
    int ysign = (y >>31) & 1;   //y的符号
    int bitXor = xsign ^ ysign ; //判断x，y符号
    return ((!bitXor ) & (!sign)) | (bitXor & xsign);
}
//4
/* 
 * logicalNeg - implement the ! operator, using all of 
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int logicalNeg(int x) {
    return ( ( x | (~x + 1 )) >> 31 ) + 1;
}
/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x) {
    int temp = x ^ (x >>31);    //转换成x对应正数
    int isZero = !temp;         //判断是否为0
    int notZeroMask = (!(!temp) << 31) >> 31;  //temp非零时，notZeroMask为0xFFFFFFFF
    int bit_16 , bit_8 ,bit_4 , bit_2 ,bit_1;  //逐步查找各个二分段
    bit_16 = !(!(temp >> 16)) << 4;            //高16位：高16位非零的话，bit_16为16，否则为0
    temp = temp >> bit_16;      //继续检查
    bit_8 = !(!(temp >> 8 )) << 3 ;             //高8位：高8位非零的话，bit_8为8，否则为0
    temp = temp >> bit_8;       //继续检查
    bit_4 = !(!(temp >> 4 )) << 2 ;             //高4位：高4位非零的话，bit_4为4，否则为0
    temp = temp >> bit_4;       //继续检查
    bit_2 = !(!(temp >> 2 )) << 1 ;             //高2位：高2位非零的话，bit_2为2，否则为0
    temp = temp >> bit_2;       //继续检查
    bit_1 = !(!(temp >> 1 ))  ;                 //高1位：高1位非零的话，bit_1为1，否则为0
    
    temp = bit_16 + bit_8 + bit_4 + bit_2 + bit_1 + 2 ;//加上所有需要的位,还要包括2个：1个至少的数据位，1个符号位
    return isZero | (temp & notZeroMask);       //为0直接返回1 ，不为0就是计算的temp(notZeroMask用来确保结果正确)
}
//float
/* 
 * floatScale2 - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatScale2(unsigned uf) {
    int exp = (uf & 0x7F800000) >> 23;  //阶码
    int sign = uf & ( 1 << 31) ;        //符号位
    if (exp == 0 ) return uf << 1 | sign;   //非规格数，直接乘2加上符号数
    if (exp == 255) return uf;      //无穷大或NaN，直接返回参数
    exp = exp + 1;          //乘2就是阶码+1
    if (exp == 255) return (0x7F800000 | sign) ;
    return (exp <<23 ) | ( uf & 0x807FFFFF ) ;  //返回阶码+1 后的原符号数
}
/* 
 * floatFloat2Int - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int floatFloat2Int(unsigned uf) {
    int exp = ((uf & 0x7F800000 ) >> 23 ) - 127;        //计算指数
    int sign = uf >> 31;                //符号数
    int frac = (( uf & 0x007FFFFF ) |  0x00800000 );    //尾数
    if (!(uf & 0x7FFFFFFF ) ) return 0 ;        //原浮点数为0，返回0
    if (exp > 31 ) return 0x80000000;           //原浮点数指数大于31 ，返回溢出值
    if (exp < 0 ) return 0 ;                    //浮点数小于0，返回0
    if (exp > 23 ) frac = frac << (exp - 23);   //小数转换为整数
    else frac = frac >> ( 23 - exp) ;
    if ( !(( frac >> 31) ^ sign )) return frac ; 
    else if (frac >> 31 ) return 0x80000000;
    else return ~frac  + 1;
}
/* 
 * floatPower2 - Return bit-level equivalent of the expression 2.0^x
 *   (2.0 raised to the power x) for any 32-bit integer x.
 *
 *   The unsigned value that is returned should have the identical bit
 *   representation as the single-precision floating-point number 2.0^x.
 *   If the result is too small to be represented as a denorm, return
 *   0. If too large, return +INF.
 * 
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. Also if, while 
 *   Max ops: 30 
 *   Rating: 4
 */
unsigned floatPower2(int x) {
    int inf = 0xFF << 23 ;
    int exp = x + 127;
    if (exp <= 0 ) return 0 ;
    if (exp >= 255) return inf;
    return exp << 23;
}
