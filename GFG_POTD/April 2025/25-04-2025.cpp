int majorityElement(int arr[], int n) {
    // code here
    int c=0,num;
    for(int i=0;i<n;i++)  
        if(c==0 || num==arr[i])
        {
            c++;
            num=arr[i];
        }
        else    c--;
    c=0;
    for(int i=0;i<n;i++)
        if(arr[i]==num) c++;
    if(c>(n/2)) return num;
    return -1;
}
