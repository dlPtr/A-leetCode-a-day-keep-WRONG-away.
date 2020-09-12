int myAtoi(char *str)
{
	int strLen = strlen(str);
	if (0 == strLen) {
		return 0;
	}

	/* Pass blank char */
	int index = 0;
	while ((str[index] == ' ') && (index++ < strLen));

	/* Get sign */
	int sign = 1;
	if(str[index] == '-' || str[index] == '+') {
		sign = (str[index++] == '-') ? -1 : 1;
	}

	/* Get correct char until wrong */
#define IS_CHARNUMBER(CHAR) ('0' <= (CHAR) && (CHAR) <= '9')
	int retNum = 0;
	while (IS_CHARNUMBER(str[index]) && (index < strLen)) {
		/* Make sure retNum will not overflow */
		if ((retNum > (INT_MAX / 10)) || (retNum == (INT_MAX / 10) && (str[index] - '0') > 7)) {
			retNum = (sign == 1) ? INT_MAX : INT_MIN;
            sign = 1; /* In case of retNum == INT_MIN */
			break;
		}
		else {
			/* Not using "()" may cause overflow in critical condition */
			retNum = retNum * 10 + (str[index++] - '0');
		}
	}
#undef IS_CHARNUMBER
	return retNum * sign;
}