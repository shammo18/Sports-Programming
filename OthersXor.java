// BEGIN CUT HERE
// PROBLEM STATEMENT
// N wolves are going to challenge bear Limak.
Each wolf chooses an integer between 0 and 2^30-1, inclusive, and shows it to all other wolves.
No wolf is going to reveal their own number to Limak.
Some wolves may remain completely silent, some may give Limak some information.
The only information a wolf will tell Limak is the bitwise xor of the numbers of all N-1 other wolves (i.e., all wolves except for the wolf who gives this particular information).

Limak's goal is to find the sum of the numbers chosen by the wolves.
If there are multiple sums that are consistent with the information Limak was given, he wants to find the smallest of them.

You are given a int[] x with N elements.
Each element of x represents one of the wolves.
If x[i] equals -1, wolf i remained silent.
Otherwise, wolf i announced that the bitwise xor of the other wolves' numbers is x[i].

If there is at least one sequence of integers between 0 and 2^30-1, inclusive, that is consistent with the information given by the wolves, return the smallest possible sum of such a sequence of numbers. Otherwise, return -1.

DEFINITION
Class:OthersXor
Method:minSum
Parameters:int[]
Returns:long
Method signature:long minSum(int[] x)


CONSTRAINTS
-N will be between 2 and 40, inclusive.
-x will contain exactly N elements.
-Each element in x will be between -1 and 1073741823 (i.e. 2^30-1), inclusive.


EXAMPLES

0)
{1,-1,3}

Returns: 3

There are many scenarios that are consistent with this information.
For example, it is possible that the wolves chose the numbers {15, 12, 13}.
Wolf 0 announces (12 xor 13) = 1, and wolf 2 announces (15 xor 12) = 3.
In this case, the sum of the wolves' numbers would be 15+12+13 = 40.

However, the sum 40 is not the smallest sum possible.
The optimal solution looks as follows:
The wolves chose the numbers {2, 1, 0}.
Wolf 0 announces (1 xor 0) = 1, and wolf 2 announces (2 xor 1) = 3.
The sum in this case is only 2+1+0 = 3, and it can be shown that this is the smallest sum that can be obtained.

1)
{0,0,1}

Returns: -1



2)
{70,100}

Returns: 170

In the only possible scenario wolves choose numbers 100 and 70, resulting in xors 70 and 100.

3)
{-1,0,-1,100,36}

Returns: 164



4)
{0,536870912,0,536870912,0,536870912,0,536870912,0,536870912,
0,536870912,0,536870912,0,536870912,0,536870912,0,536870912,
1073741823,1073741823,1073741823,123456789,987654321,804289383}

Returns: 11992352010



5)
{1287325,424244444,92759185,812358213,1000000000,825833522,749092703}

Returns: -1



6)
{-1,-1}

Returns: 0



// END CUT HERE
import java.util.*;
public class OthersXor {
	public long minSum(int[] x) {
		
	}
	public static void main(String[] args) {
		OthersXor temp = new OthersXor();
		System.out.println(temp.minSum(int[] x));
	}
}
