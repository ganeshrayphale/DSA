 while(start<end){
        if(target>vec[mid]){
            start=mid;
            mid=(start+end)/2;
        }
        else if(target<vec[mid]){
            end=mid;
            mid=(start+end)/2;
        }
        else{
            cout<<"the numebr is present";
        }
    }
    