#include<bits/stdc++.h>
using namespace std;
void Qsort(int a[], int low, int high)
{
    int length = sizeof(a) / sizeof(a[0]);
    if(low >= high)
    {
        return;
    }
    int first = low;
    int last = high;
    int key = a[first];/*���ֱ�ĵ�һ����¼��Ϊ����*/

    while(first < last)
    {
        while(first < last && a[last] >= key)
        {
            last--;
        }
        a[first] = a[last];/*���ȵ�һ��С���Ƶ��Ͷ�*/
        while(first < last && a[first] <= key)
        {
            first++;
        }
        a[last] = a[first];
/*���ȵ�һ������Ƶ��߶�*/
    }
    a[first] = key;/*�����¼��λ*/
    if( (first-1)>(length/2)){
        Qsort(a, low, first-1);
    }
    else{
        Qsort(a, first+1, high);
    }
}
int main()
{
    int a[] = {1,2,3,2,2,2,5,4,2};
    int length =  sizeof(a) / sizeof(a[0]);
    Qsort(a, 0, length - 1);
    int times = 0;
    for(int i = 0;i<length;i++){
        if(a[i] == a[length/2]){
            times++;
        }
    }
    if(times>(length/2)){
        cout << a[length/2] << " ";
    }
    else{
        cout<<"û��������Ԫ��";
    }
    return 0;
}

