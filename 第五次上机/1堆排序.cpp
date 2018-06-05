#include<bits/stdc++.h>
using namespace std;
void adjustHeap(int data[],int heapbegin, int heaplength)//heapfirstΪ�ѵĿ�ʼλ��
{
    int tempfather=data[heapbegin];//���游�ڵ�
    for (int leftchild=heapbegin*2+1;leftchild<heaplength;leftchild=leftchild*2+1)
    {
        //����ұ�ֵ�������ֵ��ָ���ұ�
        int rightchild = leftchild+1;
        int maxchild = leftchild;
        if (rightchild<heaplength && data[leftchild]< data[rightchild])
        {
            maxchild = rightchild;//ָ���Һ���
        }
        //����ӽڵ���ڸ��ڵ㣬���ӽڵ�ֵ�������ڵ�,�����µ��ӽڵ���Ϊ���ڵ㣨���ý��н�����
        if (data[maxchild]>tempfather)
        {
            data[heapbegin]=data[maxchild];
            heapbegin=maxchild;
        }
        else
            break;
    }
        //put the value in the final position
    data[heapbegin]=tempfather;
}
void Heapsort(int data[],int length){
    //������
    for(int i = length/2-1;i>=0;i--){//�����һ����Ҷ�ӽ�㿪ʼ
        adjustHeap(data,i,length);
    }
    //����
    for(int j=length-1;j>0;j--){
        int temp = data[j];
        data[j] = data[0];
        data[0] = temp;
        adjustHeap(data,0,j);
    }
}
int main()
{
    int data[] = {4,5,1,6,2,7,3,8};
    int length = sizeof(data)/sizeof(data[0]);
    Heapsort(data,length);
    int k = 0;
    cin>>k;
    for(int i =0;i<k;i++){
        cout<<data[i]<<" ";
    }
}
