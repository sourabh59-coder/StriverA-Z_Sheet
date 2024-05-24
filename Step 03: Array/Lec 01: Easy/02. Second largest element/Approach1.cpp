int print2largest(int arr[], int n) {
	    int sec=-1, fir = arr[0];
	    for(int i=1;i<n;i++)
	    {
	        if(arr[i]>fir)
	        {
	            sec = fir;
	            fir = arr[i];
	        }
	        
	        if(arr[i]<fir && arr[i] > sec) sec = arr[i];
	    }
	    return sec;
	}
