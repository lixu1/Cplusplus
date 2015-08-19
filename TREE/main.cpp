#include <iostream>
#include<iomanip>
#include "Tree.h"

using namespace std;

int main()
{
    Tree<int>intTree;
    int intValue;
    cout<<"Enter 10 interger values: \n";
    for(int i=0;i<10;i++)
    {
       cin>>intValue;
       intTree.insertNode(intValue);
    }
    cout<<"\nPreorder traversal\n";
    intTree.preOrderTraversal();
    cout<<"\nInorder traversal\n";
    intTree.inOrderTraversal();
    cout<<"\nPostorder traversal\n";
    intTree.postOrderTraversal();

    Tree<double>doubleTree;
    double doubleValue;
    cout<<fixed<<setprecision(1)<<"\n\nEnter 10 double values:\n";
    for(int j=0;j<10;j++)
    {
       cin>>doubleValue;
       doubleTree.insertNode(doubleValue);
    }
    cout<<"\nPreorder traversal\n";
    doubleTree.preOrderTraversal();
    cout<<"\nInorder traversal\n";
    doubleTree.inOrderTraversal();
    cout<<"\nPostorder traversal\n";
    doubleTree.postOrderTraversal();
    cout<<endl;
    return 0;
}
