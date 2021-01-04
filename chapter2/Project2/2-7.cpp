/*王志业 1553449 3班*/
#include <iostream>
using namespace std;
int main()
{
	int i, j, m, n;
	i = 8;
	j = 10;
	m = ++i+j++;
	n = (++i) + (++j) + m;
	cout << i << '\t' << j << '\t' << m << '\t' << n << endl;
	return 0;
}
/*输出ijmn的值，i和j都分别经过两次自加，所以最后i=10,j=12，m等于i先加一再加j,后面n等于i,j再分别先自加再加上m等于n，所以最后结果为10，12，19，41*/