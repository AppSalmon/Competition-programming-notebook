
// Binary search
ll l = 0, r = n;
ll find = 0;
while(r - l > 1)
{
	ll mid = (l + r) / 2;
	if(check(a[mid]))
	{
		find = 1;
		break;
	}
	else if(a[mid] > q)
	{
		r = mid;
	}
	else l = mid;
}
if(check(a[l]) || check(a[r] == q)) find = 1;


int lower_bound(int arr[], int N, int X)
{
	ll mid;
	ll l = 0;
	ll r = N;
	while (l < r) {
		mid = l + (r - l) / 2;
		if (X <= arr[mid]) {
			r = mid;
		}
		else {
			l = mid + 1;
		}
	}
	if(l < N && arr[l] < X) {
	   l++;
	}
	return l;
}
 
int upper_bound(int arr[], int N, int X)
{
	int mid;
	int l = 0;
	int r = N;
	while (l < r) {
		mid = l + (r - l) / 2;
		if (X >= arr[mid]) {
			l = mid + 1;
		}
		else {
			r = mid;
		}
	}
	if(low < N && arr[low] <= X) {
	   low++;
	}
	return low;
}

int binary_search() // Low
{
	int l = 1, r = n;
	while (l < r){
		int mid = (l + r + 1) >> 1;
		if (a[mid] > x){
			r = mid - 1;
		}
		else{
			l = mid;
		}
	}
	if (a[l] == x) cout << "YES";
	else cout << "NO";
}

int binarySearch(int arr[], int l, int r, int x) // de qui
{
	if (r >= l) {
		int mid = l + (r - l) / 2;
		if (arr[mid] == x)
			return mid;
		if (arr[mid] > x)
			return binarySearch(arr, l, mid - 1, x);
		return binarySearch(arr, mid + 1, r, x);
	}
	return -1;
}

while(l <= r)
{
	int mid = (l + r)/2;
	if(a[mid] == find)
	{
		ans = mid;
		break;
	}
	else if(a[mid] < find)
	{
		l = mid + 1;
	}
	else r = mid - 1;
	cout << l << " " << r << endl;
}