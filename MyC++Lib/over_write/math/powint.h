#pragma once

float PowInt(float basicNum, int exponent)
{
	int tempBasicNum = basicNum;
	if (0 == exponent)
		return 1;
	else
	{
		for (int i = 0; i < exponent - 1; i++)
			basicNum *= tempBasicNum;
		return basicNum;
	}
		
}