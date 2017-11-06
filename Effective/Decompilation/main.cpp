int func0(int para1)
{
	int para2 = para1 + 1;

	return para2;
}

int func0wrapper(int para1)
{
	int para2 = func0(para1);

	return para2;
}

int main(int argc, char* argv[])
{
	int a = 1234;

	func0wrapper(a);

	return 0;
}