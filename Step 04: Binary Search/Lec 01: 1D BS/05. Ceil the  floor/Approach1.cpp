int floor_val(vector<int> &arr,int l,int r,int k)
{
	int temp = -1;

	while(l<=r)
	{
		int mid = (r-l)/2 + l;

		if(arr[mid]==k)	return arr[mid];

		else if(arr[mid] < k)
		{
			temp = arr[mid];
			l = mid+1;
		}

		else	r = mid-1;

	}

	return temp;
}

int ceil_val(vector<int> &arr,int l,int r,int k)
{
	int temp = -1;

	while(l<=r)
	{
		int mid = (r-l)/2 + l;

		if(arr[mid]==k)	return arr[mid];

		else if(arr[mid]>k)
		{
			temp = arr[mid];
			r = mid-1;
		}

		else	l = mid+1;
	}

	return temp;
}

pair<int, int> getFloorAndCeil(vector<int> &v, int n, int k) {
	// Write your code here.
	int a  = floor_val(v,0,n-1,k);
	int b = ceil_val(v,0,n-1,k);

	return {a,b};
}
