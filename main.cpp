//
//  main.cpp
//  NewProj
//
//  Created by Mohammed Abdullah Omer on 07/12/21.
//

#include <iostream>
using namespace std;

//Variable declarations
string inl1="",inl2="",inl1e="",inl2e="";
char l1[14]={' '},l2[14]={' '},l1e[14]={' '},l2e[14]={' '},arm1=')',arm2='(';
int l1n=0,l2n=0,l1en=0,l2en=0,foundFlag=0,arm1Flag=0,arm2Flag=0,k;

void pickUp(int arm, int loc)//PickUp Function
{
    if(arm==1)
    {
        if(loc==1)
        {
            arm1=l1[l1n-1];
            l1[l1n-1]='\0';
            l1n--;
        }
        else
        {
            arm1=l2[l2n-1];
            l2[l2n-1]='\0';
            l2n--;
        }
        arm1Flag=1;
    }
    else
    {
        if(loc==1)
        {
            arm2=l1[l1n-1];
            l1[l1n-1]='\0';
            l1n--;
        }
        else
        {
            arm2=l2[l2n-1];
            l2[l2n-1]='\0';
            l2n--;
        }
        arm2Flag=1;
    }
}

void putDown(int arm, int loc)//PutDown Function
{
    if(arm==1)
    {
        if(arm1==')')
            return;
        if(loc==1)
        {
            l1[l1n]=arm1;
            l1n++;
            arm1=')';
        }
        else
        {
            l2[l2n]=arm1;
            l2n++;
            arm1=')';
        }
        arm1Flag=0;
    }
    else
    {
        if(arm2=='(')
            return;
        if(loc==1)
        {
            l1[l1n]=arm2;
            l1n++;
            arm2='(';
        }
        else
        {
            l2[l2n]=arm2;
            l2n++;
            arm2='(';
        }
        arm2Flag=0;
    }
}

void inputFun()//Input Function for Initial and Final states
{
    int i;
    cout<<"Enter blocks in L1 - initial state"<<endl;
    cin>>inl1;
    if(inl1[0]=='.')
    {
        inl1[0]='\0';
    }
    cout<<"Enter blocks in L2 - initial state"<<endl;
    cin>>inl2;
    if(inl2[0]=='.')
    {
        inl2[0]='\0';
    }
    cout<<"Enter blocks in L1 - final state"<<endl;
    cin>>inl1e;
    if(inl1e[0]=='.')
    {
        inl1e[0]='\0';
    }
    cout<<"Enter blocks in L2 - final state"<<endl;
    cin>>inl2e;
    if(inl2e[0]=='.')
    {
        inl2e[0]='\0';
    }
    for(i=0;inl1[i]!='\0';i++)
    {
        l1[i]=inl1[i];
    }
    l1n=i;
    for(i=0;inl2[i]!='\0';i++)
    {
        l2[i]=inl2[i];
    }
    l2n=i;
    for(i=0;inl1e[i]!='\0';i++)
    {
        l1e[i]=inl1e[i];
    }
    l1en=i;
    for(i=0;inl2e[i]!='\0';i++)
    {
        l2e[i]=inl2e[i];
    }
    l2en=i;
}

void printFun()
{
    int i;
    cout<<"L1-";
    for(i=0;i<l1n;i++)
    {
        cout<<l1[i]<<",";
    }
    cout<<endl<<"L2-";
    for(i=0;i<l2n;i++)
    {
        cout<<l2[i]<<",";
    }
    cout<<endl;
}

void arrangeBlocks()
{
    int x=0;
    for(int i=0;i<l1n;i++)
    {
        if(l1[i]=='a')
            x=1;
    }
    if(x!=1)
        foundFlag=-1;
    k=0;
    while(k!=l1en)//Arranging blocks in Location 1
    {
        while(foundFlag==0)
        {
            if(!arm1Flag)
            {
                pickUp(1,1);
                if(arm1==l1e[k])
                {
                    k++;
                    foundFlag=1;
                    continue;
                }
            }
            if(!arm2Flag)
            {
                pickUp(2,1);
                if(arm2==l1e[k])
                {
                    k++;
                    foundFlag=2;
                    continue;
                }
            }
            putDown(1,2);
            putDown(2,2);
        }
        while(foundFlag==-1)
        {
            if(!arm1Flag)
            {
                pickUp(1,2);
                if(arm1==l1e[k])
                {
                    k++;
                    foundFlag=1;
                    continue;
                }
            }
            if(!arm2Flag)
            {
                pickUp(2,2);
                if(arm2==l1e[k])
                {
                    k++;
                    foundFlag=2;
                    continue;
                }
            }
            putDown(1,1);
            putDown(2,1);
        }
        if(foundFlag==1)
        {
            putDown(2,2);
            while(l1n!=k-1)
            {
                pickUp(2,1);
                putDown(2,2);
            }
            putDown(1,1);
            foundFlag=-1;
        }
        else if(foundFlag==2)
        {
            putDown(1,2);
            while(l1n!=k-1)
            {
                pickUp(1,1);
                putDown(1,2);
            }
            putDown(2,1);
            foundFlag=-1;
        }
        printFun();//Printing the iteration
    }
    k=0;
    foundFlag=0;
    while(k!=l2en)//Arranging blocks in Location 2
    {
        while(foundFlag==0)
        {
            if(!arm1Flag)
            {
                pickUp(1,2);
                if(arm1==l2e[k])
                {
                    k++;
                    foundFlag=1;
                    continue;
                }
            }
            if(!arm2Flag)
            {
                pickUp(2,2);
                if(arm2==l2e[k])
                {
                    k++;
                    foundFlag=2;
                    continue;
                }
            }
            putDown(1,1);
            putDown(2,1);
        }
        while(foundFlag==-1)
        {
            if(!arm1Flag)
            {
                pickUp(1,1);
                if(arm1==l2e[k])
                {
                    k++;
                    foundFlag=1;
                    continue;
                }
            }
            if(!arm2Flag)
            {
                pickUp(2,1);
                if(arm2==l2e[k])
                {
                    k++;
                    foundFlag=2;
                    continue;
                }
            }
            putDown(1,2);
            putDown(2,2);
        }
        if(foundFlag==1)
        {
            putDown(2,1);
            while(l2n!=k-1)
            {
                pickUp(2,2);
                putDown(2,1);
            }
            putDown(1,2);
            foundFlag=-1;
        }
        else if(foundFlag==2)
        {
            putDown(1,1);
            while(l2n!=k-1)
            {
                pickUp(1,2);
                putDown(1,1);
            }
            putDown(2,2);
            foundFlag=-1;
        }
        printFun();//Printing the iteration
    }
    
}

int main(int argc, const char * argv[]) {
    inputFun();//Taking Input
    printFun();//Printing Initial state of the blocks
    arrangeBlocks();//Applying the logic
}
