#pragma once
#define USE_EXTENDED  

/***************************************************************************
* 定义浮点数转换字符串结构         
*
*得自己写一个sprintf函数
***************************************************************************/
#if 0
typedef struct
{
	SHORT   exponent;   /* 指数（整数位数） */
	BYTE    negative;   /* 负数（0正，1负）*/
	CHAR    digits[21]; /* 十进制整数字串 */
}FloatRec;

#define F_DEFDECIMALS   6  
#define F_MAXDECIMALS   100  

#ifdef  USE_EXTENDED  

#define F_MAXPRECISION  19  
#define F_CONEXPONENT   0x3fff  

typedef long double         EXTENDED, *PExtended, *PEXTENDED;

#include <pshpack2.h>  

typedef struct
{
	UINT64 mantissa;
	USHORT exponent;
}_Extended;

#include <poppack.h>  

static CONST _Extended _tab0[] =
{
	{ 0x8000000000000000, 0x3FFF },   /* 10**0 */
	{ 0xA000000000000000, 0x4002 },   /* 10**1 */
	{ 0xC800000000000000, 0x4005 },   /* 10**2 */
	{ 0xFA00000000000000, 0x4008 },   /* 10**3 */
	{ 0x9C40000000000000, 0x400C },   /* 10**4 */
	{ 0xC350000000000000, 0x400F },   /* 10**5 */
	{ 0xF424000000000000, 0x4012 },   /* 10**6 */
	{ 0x9896800000000000, 0x4016 },   /* 10**7 */
	{ 0xBEBC200000000000, 0x4019 },   /* 10**8 */
	{ 0xEE6B280000000000, 0x401C },   /* 10**9 */
	{ 0x9502F90000000000, 0x4020 },   /* 10**10 */
	{ 0xBA43B74000000000, 0x4023 },   /* 10**11 */
	{ 0xE8D4A51000000000, 0x4026 },   /* 10**12 */
	{ 0x9184E72A00000000, 0x402A },   /* 10**13 */
	{ 0xB5E620F480000000, 0x402D },   /* 10**14 */
	{ 0xE35FA931A0000000, 0x4030 },   /* 10**15 */
	{ 0x8E1BC9BF04000000, 0x4034 },   /* 10**16 */
	{ 0xB1A2BC2EC5000000, 0x4037 },   /* 10**17 */
	{ 0xDE0B6B3A76400000, 0x403A },   /* 10**18 */
	{ 0x8AC7230489E80000, 0x403E },   /* 10**19 */
	{ 0xAD78EBC5AC620000, 0x4041 },   /* 10**20 */
	{ 0xD8D726B7177A8000, 0x4044 },   /* 10**21 */
	{ 0x878678326EAC9000, 0x4048 },   /* 10**22 */
	{ 0xA968163F0A57B400, 0x404B },   /* 10**23 */
	{ 0xD3C21BCECCEDA100, 0x404E },   /* 10**24 */
	{ 0x84595161401484A0, 0x4052 },   /* 10**25 */
	{ 0xA56FA5B99019A5C8, 0x4055 },   /* 10**26 */
	{ 0xCECB8F27F4200F3A, 0x4058 },   /* 10**27 */
	{ 0x813F3978F8940984, 0x405C },   /* 10**28 */
	{ 0xA18F07D736B90BE5, 0x405F },   /* 10**29 */
	{ 0xC9F2C9CD04674EDF, 0x4062 },   /* 10**30 */
	{ 0xFC6F7C4045812296, 0x4065 }    /* 10**31 */
};

static CONST _Extended _tab1[] =
{
	{ 0x9DC5ADA82B70B59E, 0x4069 },   /* 10**32 */
	{ 0xC2781F49FFCFA6D5, 0x40D3 },   /* 10**64 */
	{ 0xEFB3AB16C59B14A3, 0x413D },   /* 10**96 */
	{ 0x93BA47C980E98CE0, 0x41A8 },   /* 10**128 */
	{ 0xB616A12B7FE617AA, 0x4212 },   /* 10**160 */
	{ 0xE070F78D3927556B, 0x427C },   /* 10**192 */
	{ 0x8A5296FFE33CC930, 0x42E7 },   /* 10**224 */
	{ 0xAA7EEBFB9DF9DE8E, 0x4351 },   /* 10**256 */
	{ 0xD226FC195C6A2F8C, 0x43BB },   /* 10**288 */
	{ 0x81842F29F2CCE376, 0x4426 },   /* 10**320 */
	{ 0x9FA42700DB900AD2, 0x4490 },   /* 10**352 */
	{ 0xC4C5E310AEF8AA17, 0x44FA },   /* 10**384 */
	{ 0xF28A9C07E9B09C59, 0x4564 },   /* 10**416 */
	{ 0x957A4AE1EBF7F3D4, 0x45CF },   /* 10**448 */
	{ 0xB83ED8DC0795A262, 0x4639 }    /* 10**480 */
};

static CONST _Extended _tab2[] =
{
	{ 0xE319A0AEA60E91C7, 0x46A3 },   /* 10**512 */
	{ 0xC976758681750C17, 0x4D48 },   /* 10**1024 */
	{ 0xB2B8353B3993A7E4, 0x53ED },   /* 10**1536 */
	{ 0x9E8B3B5DC53D5DE5, 0x5A92 },   /* 10**2048 */
	{ 0x8CA554C020A1F0A6, 0x6137 },   /* 10**2560 */
	{ 0xF9895D25D88B5A8B, 0x67DB },   /* 10**3072 */
	{ 0xDD5DC8A2BF27F3F8, 0x6E80 },   /* 10**3584 */
	{ 0xC46052028A20979B, 0x7525 },   /* 10**4096 */
	{ 0xAE3511626ED559F0, 0x7BCA }    /* 10**4608 */
};

static CONST EXTENDED _conPrec = 1E19;

#else   // USE_EXTENDED  

#define F_MAXPRECISION  17  
#define F_CONEXPONENT   0x03ff  

typedef double      EXTENDED, *PExtended, *PEXTENDED;

static CONST UINT64 _tab0[] =
{
	{ 0x3FF0000000000000 },   /* 10**0 */
	{ 0x4024000000000000 },   /* 10**1 */
	{ 0x4059000000000000 },   /* 10**2 */
	{ 0x408F400000000000 },   /* 10**3 */
	{ 0x40C3880000000000 },   /* 10**4 */
	{ 0x40F86A0000000000 },   /* 10**5 */
	{ 0x412E848000000000 },   /* 10**6 */
	{ 0x416312D000000000 },   /* 10**7 */
	{ 0x4197D78400000000 },   /* 10**8 */
	{ 0x41CDCD6500000000 },   /* 10**9 */
	{ 0x4202A05F20000000 },   /* 10**10 */
	{ 0x42374876E8000000 },   /* 10**11 */
	{ 0x426D1A94A2000000 },   /* 10**12 */
	{ 0x42A2309CE5400000 },   /* 10**13 */
	{ 0x42D6BCC41E900000 },   /* 10**14 */
	{ 0x430C6BF526340000 },   /* 10**15 */
	{ 0x4341C37937E08000 },   /* 10**16 */
	{ 0x4376345785D8A000 },   /* 10**17 */
	{ 0x43ABC16D674EC800 },   /* 10**18 */
	{ 0x43E158E460913D00 },   /* 10**19 */
	{ 0x4415AF1D78B58C40 },   /* 10**20 */
	{ 0x444B1AE4D6E2EF50 },   /* 10**21 */
	{ 0x4480F0CF064DD592 },   /* 10**22 */
	{ 0x44B52D02C7E14AF7 },   /* 10**23 */
	{ 0x44EA784379D99DB4 },   /* 10**24 */
	{ 0x45208B2A2C280291 },   /* 10**25 */
	{ 0x4554ADF4B7320335 },   /* 10**26 */
	{ 0x4589D971E4FE8402 },   /* 10**27 */
	{ 0x45C027E72F1F1281 },   /* 10**28 */
	{ 0x45F431E0FAE6D722 },   /* 10**29 */
	{ 0x46293E5939A08CEA },   /* 10**30 */
	{ 0x465F8DEF8808B024 }    /* 10**31 */
};

static CONST UINT64 _tab1[] =
{
	{ 0x4693B8B5B5056E17 },   /* 10**32 */
	{ 0x4D384F03E93FF9F5 },   /* 10**64 */
	{ 0x53DDF67562D8B363 },   /* 10**96 */
	{ 0x5A827748F9301D32 },   /* 10**128 */
	{ 0x6126C2D4256FFCC3 },   /* 10**160 */
	{ 0x67CC0E1EF1A724EB },   /* 10**192 */
	{ 0x6E714A52DFFC679A },   /* 10**224 */
	{ 0x75154FDD7F73BF3C },   /* 10**256 */
	{ 0x7BBA44DF832B8D46 },   /* 10**288 */
};

static CONST EXTENDED _conPrec = 1E17;

#endif      // !USE_EXTENDED  

static CONST UINT64 _cvttab[F_MAXPRECISION] =
{
#ifdef  USE_EXTENDED  
	0xDE0B6B3A7640000, 0x16345785D8A0000,
#endif  
	0x02386F26FC10000, 0x0038D7EA4C68000, 0x0005AF3107A4000, 0x00009184E72A000,
	0x00000E8D4A51000, 0x00000174876E800, 0x0000002540BE400, 0x00000003B9ACA00,
	0x000000005F5E100, 0x000000000989680, 0x0000000000F4240, 0x0000000000186A0,
	0x000000000002710, 0x0000000000003E8, 0x000000000000064, 0x00000000000000A,
	0x000000000000001
};

#define DECIMAL_EXP(exponent)   ((((exponent - F_CONEXPONENT) * 0x4d10) >> 16) + 1)  

static VOID AdjFloatDigits(UINT64 value, INT precision, INT decimals, FloatRec *rec)
{
	INT i;
	// value是F_MAXPRECISION位十进制整数，故从最高位开始转换为数字串  
	for (i = 0; value; i++)
	{
		rec->digits[i] = (CHAR)((value / _cvttab[i]) | 0x30);
		value %= _cvttab[i];
	}
	memset(rec->digits + i, 0, F_MAXPRECISION - i);
	// 下面对数字串作精度处理  
	// 如果总的精度小于0，数字串为空串，该数字转换为'0'  
	if ((i = (rec->exponent + decimals)) < 0)
	{
		rec->exponent = rec->negative = rec->digits[0] = 0;
		return;
	}
	if (i > precision) i = precision;
	// 如果精度位数小于18，同时该位大于等于'5'，四舍五入  
	if (i < F_MAXPRECISION && rec->digits[i] >= '5')
	{
		do
		{
			rec->digits[i--] = 0;
			rec->digits[i] ++;
		} while (i >= 0 && rec->digits[i] > '9');
		if (i < 0)
		{
			rec->digits[0] = '1';
			rec->exponent++;
		}
	}
	// 否则，去掉数字串尾部多余的'0'  
	else
	{
		if (i > F_MAXPRECISION) i = F_MAXPRECISION;
		do rec->digits[i--] = 0;
		while (i >= 0 && rec->digits[i] == '0');
		if (i < 0) rec->negative = 0;
	}
}

#ifdef  USE_EXTENDED  

// 解析扩展精度浮点数为十进制字符串，并存入浮点数记录中  
// 参数：浮点数指针，精度，小数位，浮点数记录  
VOID FloatResolve(PEXTENDED pvalue, INT precision, INT decimals, FloatRec *rec)
{
	INT power;
	EXTENDED val;

	// 79位：扩展精度浮点数符号位  
	rec->negative = ((_Extended*)pvalue)->exponent >> 15;
	// 64-78位：扩展精度浮点数阶码(阶码 - 0x3fff = 二进制指数)  
	rec->exponent = ((_Extended*)pvalue)->exponent & 0x7fff;
	if (!rec->exponent)          // *pvalue = 0  
	{
		rec->negative = rec->digits[0] = 0;
		return;
	}
	if (rec->exponent == 0x7fff)// *pvalue = nan or inf  
	{
		if (!((*(LPBYTE)pvalue + 7) & 0x80) || !(*(PUINT64)pvalue & 0x7fffffffffffffff))
		{
			lstrcpyA(rec->digits, "INF");
		}
		else
		{
			rec->exponent++;
			rec->negative = 0;
			lstrcpyA(rec->digits, "NAN");
		}
		return;
	}
	// 阶码转换为十进制指数  
	rec->exponent = DECIMAL_EXP(rec->exponent);
	// 0-63位：扩展精度浮点数尾数转换成F_MAXPRECISION位十进制浮点整数格式  
	val = *pvalue;
	*((LPBYTE)&val + 9) &= 0x7f;// val = fabs(*pvalue)  
	power = F_MAXPRECISION - rec->exponent;
	if (power > 0)               // if (power > 0) val *= (10**power)  
	{
		val *= *(PEXTENDED)&_tab0[power & 31];
		power >>= 5;          // power /= 32;  
		if (power)
		{
			if (power & 15)
				val *= *(PEXTENDED)&_tab1[(power & 15) - 1];
			power >>= 4;      // power /= 16;  
			if (power)
				val *= *(PEXTENDED)&_tab2[power - 1];
		}
	}
	else if (power < 0)          // if (power < 0) val /= (10**power)  
	{
		power = -power;
		val /= *(PEXTENDED)&_tab0[power & 31];
		power >>= 5;          // power /= 32;  
		if (power)
		{
			if (power & 15)
				val /= *(PEXTENDED)&_tab1[(power & 15) - 1];
			power >>= 4;      // power /= 16;  
			if (power)
				val /= *(PEXTENDED)&_tab2[power - 1];
		}
	}
	val += 0.5;                 // 四舍五入  
	if (val >= _conPrec)
	{
		val /= 10;
		rec->exponent++;
	}
	// 调整并转换扩展精度浮点数尾数的整数部分rec->digits  
	AdjFloatDigits(*(PUINT64)&val >> ((((_Extended*)&val)->exponent - 0x3fff) ^ 0x3f),
		precision, decimals, rec);
}

#else   // USE_EXTENDED  

// 解析双精度浮点数为十进制字符串，并存入浮点数记录中  
// 参数：浮点数指针，精度，小数位，浮点数记录  
VOID FloatResolve(PEXTENDED pvalue, INT precision, INT decimals, FloatRec *rec)
{
	INT power;
	EXTENDED val;

	// 63位：双精度浮点数符号位  
	rec->negative = *((LPBYTE)pvalue + 7) >> 7;
	// 52-62位：双精度浮点数阶码(阶码 - 0x3ff = 二进制指数)  
	rec->exponent = (*(PUINT64)pvalue >> 52) & 0x7ff;
	if (!rec->exponent)          // *pvalue = 0  
	{
		rec->negative = rec->digits[0] = 0;
		return;
	}
	if (rec->exponent == 0x7ff)// *pvalue = nan or inf  
	{
		if ((*(PUINT64)pvalue & 0xfffffffffffff) == 0)
		{
			lstrcpyA(rec->digits, "INF");
		}
		else
		{
			rec->exponent++;
			rec->negative = 0;
			lstrcpyA(rec->digits, "NAN");
		}
		return;
	}
	// 阶码转换为十进制指数  
	rec->exponent = DECIMAL_EXP(rec->exponent);
	// 0-51位：双精度浮点数尾数转换成F_MAXPRECISION位十进制浮点整数格式  
	val = *pvalue;
	*((LPBYTE)&val + 7) &= 0x7f;// val = fabs(*pvalue)  
	power = F_MAXPRECISION - rec->exponent;
	if (power > 0)               // if (power > 0) val *= (10**power)  
	{
		val *= *(PEXTENDED)&_tab0[power & 31];
		power >>= 5;          // power /= 32;  
		if (power)
			val *= *(PEXTENDED)&_tab1[power - 1];
	}
	else if (power < 0)          // if (power < 0) val /= (10**power)  
	{
		power = -power;
		val /= *(PEXTENDED)&_tab0[power & 31];
		power >>= 5;          // power /= 32;  
		if (power)
			val /= *(PEXTENDED)&_tab1[power - 1];
	}

	// 16位十进制浮点整数四舍五入  
	val += 0.5;
	if (val >= _conPrec)
	{
		val /= 10;
		rec->exponent++;
	}
	// 调整并转换扩展精度浮点数尾数的整数部分rec->digits  
	// 清除52-63位，加隐藏的高位，F_MAXPRECISION=17，高位超过52位，所以左移  
	AdjFloatDigits(((*(PUINT64)&val & 0x000fffffffffffff) | 0x0010000000000000) <<
		-(52 - ((*(PUINT64)&val >> 52) - 0x3ff)), precision, decimals, rec);
}

#endif  // !USE_EXTENDED  

// 输出指数字符串到buffer，返回指数字符串长度  
INT PutExponent(LPSTR buffer, CONST FloatRec *rec)
{
	LPSTR p = buffer;
	INT e, exp = rec->digits[0] ? rec->exponent - 1 : 0;
	*p++ = rec->negative & 0x80 ? 'E' : 'e';
	if (exp < 0)
	{
		exp = -exp;
		*p++ = '-';
	}
	else *p++ = '+';
	if ((e = (exp / 1000)) != 0)
	{
		*p++ = e + 0x30;
		exp %= 1000;
	}
	*p++ = exp / 100 + 0x30;
	exp %= 100;
	*(PUSHORT)p = (((exp % 10) << 8) | (exp / 10)) + 0x3030;
	return (INT)(p - buffer + 2);
}

// 浮点数转换为字符串。参数：字符串，浮点数  
LPSTR FloatToStr(LPSTR str, EXTENDED value)
{
	INT exp;
	FloatRec rec;
	LPSTR pd = rec.digits;
	LPSTR ps = str;

	// 解析浮点数，并将信息保存在rec  
	FloatResolve(&value, 15, 9999, &rec);
	// 打印负数符号  
	if (rec.negative) *ps++ = '-';
	// NAN or INF  
	if (*pd > '9')
	{
		memcpy(ps, pd, 4);
		return str;
	}
	exp = rec.exponent;
	// 如果十进制指数大于15或者小于-3，转换为指数形式  
	if (exp > 15 || exp < -3)
	{
		*ps++ = *pd++;
		if (*pd)
			for (*ps++ = '.'; *pd; *ps++ = *pd++);
		ps += PutExponent(ps, &rec);
		*ps = 0;
		return str;
	}
	// 否则，转换为小数形式  
	if (exp <= 0)
	{
		*ps++ = '0';
		if (*pd)
		{
			for (*ps++ = '.'; exp < 0; *ps++ = '0', exp++);
			while (*ps++ = *pd++);
		}
		else *ps = 0;
	}
	else
	{
		for (; exp > 0 && *pd; *ps++ = *pd++, exp--);
		if (*pd)
		{
			*ps++ = '.';
			while (*ps++ = *pd++);
		}
		else
		{
			memset(ps, '0', exp);
			ps[exp] = 0;
		}
	}
	return str;
}

#endif