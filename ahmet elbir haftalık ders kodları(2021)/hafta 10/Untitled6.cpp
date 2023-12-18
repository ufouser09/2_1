void recurse ()  {
	static count = 1;
	printf("%d\n", count);
	count++;
	recurse();
}
main()  {
	recurse();
}
