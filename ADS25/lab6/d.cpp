#include <iostream> 
#include <algorithm>
#include <vector>
#include <cmath>
#include <map> 
#include <set> 
#include <queue>
#include <deque>
#include <stack>
#include <climits> 
#define pb push_back
#define pf push_front 
#define p_b pop_back
#define p_f pop_front 
#define vec vector
#define ll long long
using namespace std;

struct date{ 
    int year; 
    int month;
    int day;
};

bool cmp(const date& a, const date& b){
    if(a.year != b.year) return a.year < b.year;
    if(a.month != b.month) return a.month < b.month;
    return a.day < b.day;    
}

void merge(vec<date>& arr, int l, int m, int r, bool (*comp)(const date&, const date&)){
    int n1 = m-l+1; 
    int n2 = r-m; 
    vec<date> arrleft(n1), arrright(n2); 
    for(int i=0; i<n1; i++) arrleft[i] = arr[l+i]; 
    for(int i=0; i<n2; i++) arrright[i] = arr[m + 1 + i];
    int i =0, j=0, k=l; 
    while(i<n1 && j<n2){ 
        if(comp(arrleft[i],arrright[j])){ 
            arr[k] = arrleft[i]; 
            i++;
        }
        else{ 
            arr[k] = arrright[j]; 
            j++;
        }
        k++;
    }
    while (i < n1) { 
        arr[k] = arrleft[i]; 
        i++;
        k++;
    }
    while (j < n2) { 
        arr[k] = arrright[j]; 
        j++;
        k++; 
    }


}

void mergeSort(vec<date>& arr, int l, int r, bool (*comp)(const date&, const date&)){ 
    if(l<r){ 
        int m=(l+r)/2; 
        mergeSort(arr, l, m, comp);
        mergeSort(arr, m+1, r, comp);
        merge(arr, l, m, r, comp); 
    }
}

int main(){
    int n;
    cin>>n; 
    vector<date> calendar;  
    for(int i=0; i<n; i++){ 
        string s; 
        cin >> s;
        int dday = (s[0] - '0') * 10 + (s[1] - '0');
        int dmonth = (s[3] - '0') * 10 + (s[4] - '0');
        int dyear = (s[6] - '0') * 1000 + (s[7] - '0') * 100 + (s[8] - '0') * 10 + (s[9] - '0');
        calendar.pb(date{dyear, dmonth, dday});
    }
    mergeSort(calendar, 0, calendar.size()-1, cmp); 
    for(auto it : calendar){ 
       if(it.day<10)cout<<"0"<<it.day<<"-"; 
       else cout<<it.day<<"-";
       if(it.month<10)cout<<"0"<<it.month<<"-"; 
       else cout<<it.month<<"-";
       cout<<it.year<<endl; 
    }



}