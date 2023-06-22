
/**
 * _isdigit - function that checks wether
 * the given digits is an const char *
 *
 * @s: string to be checked
 * Return: (1) means is digit, (0) means is not digit
 */
int _isdigit(const char *s)
{
	int sign;

	sign = 0;
	if (!s || !*s)
		return (0);
	while (*s)
	{
		if (*s == '+' || *s == '-')
		{
			if (sign)
				return (0);
			sign = 1;
		}
		else if (*s < '0' || *s > '9')
			return (0);
		s++;
	}
	return (1);
}
