struct book
{
	ll t, a, b;
};

bool comp(book x, book y)
{
	if(x.t != y.t) return x.t > y.t;
	if(x.a != y.a) return x.a > y.a;
	return x.b > y.b;
}

sort(A, A+n, comp)