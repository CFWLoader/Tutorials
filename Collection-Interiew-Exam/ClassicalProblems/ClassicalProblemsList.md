1.	Judge a number is the 2-power number without a loop.
	-	Analysis: 2 = 0x10, 4 = 0x100, 8 = 0x1000, 16 = 0x10000.
	-	Solution: !(X&(X-1))
2.	```
	int f(int x, int y)
	{
		return (x & y) + ((x ^ y) >> 1);
	}

	f(729, 271) = ?
	```
	-	Analysis: This function is getting the average number of this two number.
	-	Solution: 500
3.	Add two number via bit calculation.
	```
	int Add(int a, int b)
	{
		if (b == 0)return a;	//Finish the calculation when no carry.
		int sum, carry;
		sum = a ^ b;			//Finish no-carry add operation in first step.
		carry = (a & b) << 1;	//Finish carry and left shift operation in second step.
		return Add(sum, carry);	//Recursive add.
	}
	```