int missingNumber(int arr[], int n) {
    // code here
    int i=0,t;
    while(i<n){
        if(arr[i]<1 || arr[i]>n)    i++;
        else if(arr[i]!=(i+1) && arr[i]!=arr[arr[i]-1])   
        {
            t=arr[i];
            arr[i]=arr[arr[i]-1];
            arr[t-1]=t;
        }
        else    i++;
    }
    for(int i=0;i<n;i++)
        if(arr[i]!=(i+1))   return i+1;
    
    return n+1;
}
