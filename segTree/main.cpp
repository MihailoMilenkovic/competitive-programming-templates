#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+5;
int a[N],minn[4*N],lazy[4*N],n;
int a2[N];
void mrg(int i){
    minn[i]=min(minn[2*i]+lazy[2*i],minn[2*i+1]+lazy[2*i+1]);
}
void prop(int i){
    lazy[2*i]+=lazy[i];
    lazy[2*i+1]+=lazy[i];
    lazy[i]=0;
}
void init(int l=1,int r=n,int i=1)
{
    if(l==r){
        minn[i]=a[l];
        return;
    }
    int mid=(l+r)/2;
    init(l,mid,2*i);
    init(mid+1,r,2*i+1);
    mrg(i);
}
void upd(int ql,int qr,int val,int l=1,int r=n,int i=1){
    if(ql>r||qr<l){
        return;
    }
    if(ql<=l&&r<=qr){
        lazy[i]+=val;
        return;
    }
    prop(i);
    int mid=(l+r)/2;
    upd(ql,qr,val,l,mid,2*i);
    upd(ql,qr,val,mid+1,r,2*i+1);
    mrg(i);
}
int query(int ql,int qr,int l=1,int r=n,int i=1){
    if(ql>r||qr<l){
        return INT_MAX;
    }
    if(ql<=l&&r<=qr){
        return minn[i]+lazy[i];
    }
    prop(i);
    int mid=(l+r)/2;
    int q1=query(ql,qr,l,mid,2*i);
    int q2=query(ql,qr,mid+1,r,2*i+1);
    mrg(i);
    return min(q1,q2);
}
void bruteUpd(int l,int r,int val){
    for(int i=l;i<=r;i++){
        a2[i]+=val;
    }
}
int bruteQuery(int l,int r){
    int ans=INT_MAX;
    for(int i=l;i<=r;i++){
        ans=min(ans,a2[i]);
    }
    return ans;
}
int rnd(int st,int en){
    return st+rand()%(en-st);
}
int main(){
    n=1+rand()%100;
    for(int i=1;i<=n;i++){
        int x=rand()%10;
        a[i]=x;
        a2[i]=x;
    }
    init();
    for(int q=1;q<=1000;q++){
        int type=rand()%2;
        if(type==0){
            int ql=rnd(1,n),qr=rnd(1,n),val=rnd(1,10);
            if(ql>qr)swap(ql,qr);
            bruteUpd(ql,qr,val);
            upd(ql,qr,val);
        }
        else{
            int ql=rnd(1,n),qr=rnd(1,n);
            if(ql>qr)swap(ql,qr);
            int ans1=bruteQuery(ql,qr),ans2=query(ql,qr);
            if(ans1!=ans2){
                printf("%d\n",n);
                for(int i=1;i<=n;i++){
                    printf("%d ",a2[i]);

                }
                printf("\n");
                printf("ql:%d qr:%d\n",ql,qr);
                printf("ansBrute:%d\n",ans1);
                printf("ans:%d\n",ans2);
                return 0;
            }
        }
    }
    printf("ok\n");
    return 0;
}
