void *ft_memset(void *s, int c, size_t n)
{
	if (n)
	{
		char *d = s;
		while(n--)
		{
			*d++ = c;
		}
	}
	return s;
}
