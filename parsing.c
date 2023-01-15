static int    is_space(char c);
static int    handle_sign(char **str);
double        ft_atof(char *str);
int            is_double(char *str);

int    is_double(char *str)
{
    while (str && is_space(*str))
        str++;
    while (str && (*str == '-' || *str == '+'))
        str++;
    while (str && ft_isdigit(*str))
        str++;
    if (str && *str == '.')
        str++;
    else
        return (0);
    while (str && ft_isdigit(*str))
        str++;
    if (str && *str != 0)
        return (0);
    return (1);
}

double    ft_atof(char *str)
{
    double    res;
    int        dec;
    int        sign;

    res = 0;
    dec = 1;
    while (str && is_space(*str))
        str++;
    sign = handle_sign(&str);
    while (str && *str >= '0' && *str <= '9')
    {
        res = res * 10 + (*str - '0');
        str++;
    }
    if (str && *str == '.')
        str++;
    while (str && *str >= '0' && *str <= '9')
    {
        res = res * 10 + (*str++ - '0');
        dec *= 10;
    }
    return ((res * sign) / dec);
}

static int    is_space(char c)
{
    return (c == ' ' || (c >= '\t' && c <= '\r'));
}

static int    handle_sign(char **str)
{
    int    sign;

    sign = 1;
    while (str && (**str == '-' || **str == '+' || is_space(**str)))
    {
        if (**str == '-')
            sign *= -1;
        (*str)++;
    }
    return (sign);
}