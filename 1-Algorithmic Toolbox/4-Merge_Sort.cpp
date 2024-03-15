void merge( vector<int>& arr , int l , int m , int r){
    int i , j , k = l , nL = m+1-l , nR = r-m;
    vector<int> L(nL) , R(nR);
    for(i=0 ; i < nL ; i++){
        L[i] = arr[l+i] ;
    }
    for(j=0 ; j < nR ; j++){
        R[j] = arr[m+1+j];
    }
    i = 0 ;  j = 0 ;
    while( i < nL && j < nR ){
        if( L[i] <= R[j] ){
            arr[k] = L[i];
            i++;
        }else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while( i < nL ){
        arr[k] = L[i];
        i++ ; k++ ;
    }
    while( j < nR ){
        arr[k] = R[j];
        j++ ; k++ ;
    }
}

void merge_sort(vector<int>& arr , int l ,int r){
    if( l < r ){
        int m = l + (r - l)/2 ;
        merge_sort( arr , l , m);
        merge_sort( arr , m + 1 , r);
        merge( arr , l , m , r);
    }
    else    return;
}
void mergeSort(vector<int>& arr){
    if(arr.size() < 2)  return;
    int n = arr.size()-1;
    merge_sort(arr , 0 , n);
}