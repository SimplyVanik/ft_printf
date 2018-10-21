/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdzhanaz <vdzhanaz@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 17:33:21 by vdzhanaz          #+#    #+#             */
/*   Updated: 2018/10/18 20:04:05 by vdzhanaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <locale.h>
#include <stdarg.h>

#define BLURB "Authentic imitation!"

void	ft_next1(va_list ap)
{
	int tmp;

	tmp = va_arg(ap, int);	
}

void	ft_next(va_list *ap)
{
	int tmp;

	tmp = va_arg(*ap, int);
}

void	ft_vaar_test(char *format, ...)
{
	va_list ap;
	va_list	dup;
	int		tmp;

	va_start(ap, format);
	va_copy(dup, ap);
	ft_next(&ap);
	ft_next1(ap);
	tmp = va_arg(ap, int);
	printf("%d\n", tmp);
	tmp = va_arg(dup, int);
	printf("%d\n", tmp);
	va_copy(dup, ap);
	ft_next1(ap);
	tmp = va_arg(ap, int);
	printf("%d\n", tmp);
	va_arg(dup, char*);
	//printf("%d\n", tmp);
	tmp = va_arg(dup, int);
	printf("%d\n", tmp);
	va_end(ap);
}

int main(void)
{
	setlocale(LC_ALL, "");
	float pi;
	const double RENT = 3852.99;
	char k;
	char *l;
	long long int num;
	short bb;
	unsigned short cc;
	unsigned int dd;
	int	ll[5] = {940, 945, 946, 947, 948};
	int		uuu;
	int *lk;

	pi = 3.9915947450;

	//ll = NULL;
	printf("*%8f*\n", RENT);
	printf("*%e*\n", RENT);
	printf("*%4.2f*\n", RENT);
	printf("*%3.1f*\n", RENT);
	printf("*%10.3f*\n", RENT);
	printf("*%10.3E*\n", RENT);
	printf("*%+4.2f*\n", RENT);

	printf("%x %X %#x\n", 31, 31, 31);
	printf("**%d**% d% d **\n", 42, 42, -42);
	printf("**%5d**%5.3d**%05d**%05.3d**\n", 6, 6, 6, 6);
	printf("\n");

	printf("[%2s]\n", BLURB);
	printf("[%24s]\n", BLURB);
	printf("[%24.5s]\n", BLURB);
	printf("[%-24.5s]\n", BLURB);
	pi = 3.1415947450;
	printf("%.5s = %*.*f\n", "value trash", 10, 5, pi);
	printf("%.5s = %f\n", "value trash", pi);
	k = 'h';
	l = &k;
	printf("razmer - %lu\n", sizeof(l));
	printf("%0.5f\n", 12.123);
	printf("%*d\n", 5, 12);
	printf("aaa%%d\n");
	printf("%o\n", -1);
	//printf("%llu\n", 10446744073709551615);
	printf("%lu\n", 1121124234235345);
	num = -1345679089;
	bb = num;
	cc = bb;
	printf("%d\n", (short)num);
	printf("%d\n", cc);
	dd = (unsigned int)num;
	cc = dd;
	printf("%d\n", dd);
	printf("%u\n", dd);
	dd = (unsigned)num;
	printf("%d\n", dd);
	printf("%u\n", dd);
	printf("%d\n", cc);
	printf("%000d\n", (unsigned short)num);
	printf("%lld\n", num);
	printf("%X\n", 255);
	printf("% .4f\n", 0.7777777);
	//printf("%-7p\n", ll);
	(num == -1345679089) ? printf("%s\n", "daaaaaa") : (num);
	printf("%f\n", pi);
	printf("%e\n", pi);
	printf("%x\n", 141595);
	printf("%a\n", 32.5678);
	printf("dgmd\0 %s%d%c%d\n", "sldkf; \0lskdf;lsf", 45, '\0', 457);
	printf("kajsdh%50.50s%C%d%nwer%d\n", "sldkf;lskdf;lsf", 123, 333, &uuu, 55);
	printf("%d\n", uuu);
	printf("%u\n", (unsigned)(-1));//(-2147483648));
	printf("%05C\n", 945);
	printf("%C\n", 200000);
	printf("%07.5C\n", 945);
	printf("%d %.2s %.2a\n", 1234, NULL, -1234.456);
	printf("%.2S\n", NULL);
	printf("%.4S%n\n", L"φφαα", lk);
	printf("%d\n\n", *lk);
	printf("%.5c\n", 'I');
	printf("%05c\n", 'I');
	printf("%05.3c\n", 'I');
	printf("%-05.3c\n", 'I');
	printf("%-5c\n", 'I');
	printf("%015s\n", "Idfg");
	printf("%-015s\n", "Idfg");
	printf("%015.3s\n", "Idfg");
	l = "sldkf;lskdf;lsf";
	printf("%20p\n", &l);
	printf("%#o\n", 34857);
	printf("% 10.5d\n", 123);
	printf("%- 10.5d\n", 123);
	printf("% 10.5d\n", -123);
	printf("% 5.6d\n", 123);
	printf("% 5.6d\n", -123);
	printf("% 05d\n", 123);
	printf("%0#10.7o\n", 34857);
	printf("%0#10.8o\n", 34857);
	printf("%#10.10o\n", 34857);
	printf("%#10.5o\n", 348);
	printf("%#10.3o\n", 348);
	printf("%#010o\n", 0);
	printf("%0#10.7x\n", 34857);
	printf("%0#10.8X\n", 34857);
	printf("%#10.9X\n", 34857);
	printf("%06x\n", 20);
	printf("%#06x\n", 20);
	printf("%06o\n", 20);
	printf("%0#6o\n", 20);
	printf("%#6o\n", 20);
	printf("%#06x\n", 20);
	printf("%#06x\n", 20);
	printf("%025.20p\n", &l);
	printf("%20.15d\n", 123847);
	printf("%20.15d\n", -123847);
	printf("\n%-+#10.8x\n", 555);
	printf("%8-.4,+d\n", 12);
	//*ll = 345;
	//printf("%Lf\n", 01923480128340928401283409128340982134098209348120934809128409840928340921834092843.2093429987987987989879879879898798987987);
				   //1923480128340928202992552233237309358523344034348950565915977463688021778991415296
	
	printf("%d\n", (int)(-3.945));
	pi = 4 / 3;
	printf("%d\n", (int)123.956);
	printf("%.5a\n", 260.36356);
	//printf("%.5LF\n", -922337203685477580812341234120980980900998888900988834.12341234);
	printf("%.2g\n", 0.000334534);
	//printf("%s%.-21f\n", "skfjghskdfgh ", -1.23);
	printf("%#o\n", 1230948);
	printf("% #.555hhd\n", 123234134132412);
	printf("%.c\n", NULL);
	printf("%c\n", 'lsdkfjewrwer');
	printf("%.*-+ll.15d\n", 20, 123123123);
	printf("%.15-+ll.*d\n", 20, 123123123);
	printf("TUUUUUTTTT\n");
	printf("%d%d%2$d%d\n", 12, 18, 22, 45 );
	printf("%02$20d\n", 20, 123123123);
	printf("%0$*d\n", 20, 12, 45, 13);
	printf("%$d\n", 20, 12, 45, 13);
	printf("%$*-ld%d\n", 20, 12, 45, 13);
	printf("%01$*d\n", 20, 12, 45, 13);
	printf("%02$*d\n", 20, 12, 45, 13);
	printf("%03$*d\n", 20, 12, 45, 13);
	printf("yyyyyyyyyyyyy\n");
	printf("%01$*d\n", 20, 12, 45, 13);
	printf("%03$*d\n", 20, 12, 45, 13);
	printf("%02$*01$d\n\n\n", 20, 12, 45, 13);
	printf("%d\n%d\n%*1$d\n a teper posmotrim \n%*d\n%d\n%*03$2$d\n%d\n%*d\n%4$d\n%d\n\n\n", 15, 20, 25, 30, 35, 40, 45, 50, 55, 60, 65, 70);
	printf("%d\n%03$*d\n", 20, 12, 45, 13);
	printf("aaaaaaaaaa\n");
	printf("%02$**d\n", 20, 12, 45, 13);
	printf("%03$**d\n", 20, 12, 45, 13);
	printf("%0*$7d\n", 20, 12, 45, 13);
	printf("%d\n%d\n%d\n%*01$d\n", 20, 12, 45, 13);
	printf("%d\n%d\n%d\n%*-01$d\n", 20, 12, 45, 13);
	printf("%d\n%*02$d\n", 20, 12, 45, 13);
	printf("%d\n%0*1$d\n", 20, 12, 45, 13);
	printf("%0*2$d\n", 20, 12, 45, 13);
	printf("%0*3$d\n", 20, 12, 45, 13);
	printf("%*000$d\n", 5, 15, 40);
	printf("%*000$5d\n", 5, 15, 40);
	printf("OOOOOOOOO\n");
	printf("%02$*7d\n", 20, 12, 45, 13);
	printf("%03$*7d\n", 20, 12, 45, 13);
	printf("%0*$d\n", 20, 12, 45, 13);
	printf("%05*$5d\n", 20, 12, 45, 13);
	printf("%0*2$7*d\n", 20, 12, 45, 13);
	printf("%0*3$7d\n", 20, 12, 45, 13);
	printf("%0.*3$f\n", 20.23, 12, 45, 13);
	printf("%02$d\n", 20, 12, 45, 13);
	printf("%.00*s\n", 5, "wer");
	printf("%..7d\n", 5);
	printf("%-7h.$0+lld\n", 5, 7, 9);
	printf("%7h.$0+lld\n", 5, 7, 9);
	printf("%4.5$d\n", 5, 7, 9);
	printf("%.+2$d\n", 5, 7, 9);
	printf("%5.*$s\n", 5, "ewrwerwer");
	printf("%.*$s\n", 5, "ewrwerwer");
	printf("%.*.*$s\n", 5, "ewr");
	printf("%5.*.*0$s\n", 5, "ewr");
	printf("TUUUUUTTTT\n");
	printf("%10.2s\n", "qwerqer");
	printf("%10.002s\n", "qwerqer");
	printf("%10.-2s\n", "qwerqer");
	printf("%10.*s\n", -2, "qwerqer");
	printf("%*.5s\n", -22, "qwerqer");
	printf("%.10*d\n", 20, 123123123);
	printf("%.000*s\n", 20, "dlkgjds" );
	printf("%d\n", uuu);
	
	if (61 == uuu++)
		printf("%d\n", uuu);
	printf("%d\n", uuu);

	uuu = 3;
	if (ll[uuu++] == 946)
		printf("%d\n", ll[uuu]);
	printf("%d\n", uuu);

	printf("%.**.3s\n", 5, 8, "kdsfjlsdjfsdlfkj");
	printf("%*.*s\n", 5, 4, "werwerwer");
	printf("%.**s\n", 5, 4, "werwerwer");
	ft_vaar_test("eee", 12, 34, 56, 78, 13);
	return (0);
}