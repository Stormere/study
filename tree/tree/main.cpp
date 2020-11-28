//
//  main.cpp
//  tree
//
//  Created by steveluccy on 11/28/20.
//

#include <iostream>

#include <stack>

typedef struct BTree {
    char data;
    struct BTree  *LChild;
    struct BTree  *RChild;
} myTree;


myTree *CreateTree()
{
    myTree * pA = (myTree *)malloc(sizeof(myTree));
    myTree * pB = (myTree *)malloc(sizeof(myTree));
    myTree * pD = (myTree *)malloc(sizeof(myTree));
    myTree * pE = (myTree *)malloc(sizeof(myTree));
    myTree * pC = (myTree *)malloc(sizeof(myTree));
    myTree * pF = (myTree *)malloc(sizeof(myTree));
    myTree * pG = (myTree *)malloc(sizeof(myTree));
    pA->data = 'A';
    pB->data = 'B';
    pD->data = 'D';
    pE->data = 'E';
    pC->data = 'C';
    pF->data = 'F';
    pG->data = 'Q';
    pA->LChild = pB;
    pA->RChild = pC;
    pB->LChild = pD;
    pB->RChild = pE;
    pD->LChild = pD->RChild = NULL;
    pE->LChild = pE->RChild = NULL;
    pC->LChild = pF;
    pC->RChild = NULL;
    pF->LChild = NULL;
    pF->RChild = pG;
    pG->LChild = pG->RChild = NULL;
    return pA;
}
// 递归前序遍历
void preVisitTree(myTree *T) {
    if(T==NULL) {
        return;
    } else {
        std::cout<< "节点 : "<<T->data<< std::endl;
        // if(T->LChild)
        preVisitTree(T->LChild);
        // if(T->LChild)
        preVisitTree(T->RChild);
    }
}

// 递归中序遍历
void midVisitTree(myTree *T) {
    if(T==NULL) {
        return;
    } else {
        midVisitTree(T->LChild);
        std::cout<< "节点 : "<<T->data<< std::endl;
        midVisitTree(T->RChild);
    }
}
// 递归后序遍历
void afterVisitTree(myTree *T) {
    if(T==NULL) {
        return;
    } else {
        midVisitTree(T->LChild);
        midVisitTree(T->RChild);
        std::cout<< "节点 : "<<T->data<< std::endl;
    }
}
// 深度
int Depth(myTree *T) {
    int left,right;
    if(T==NULL){
        return 0;
    } else {
        left=Depth(T->LChild);
        right=Depth(T->RChild);
        return left>right?left+1:right+1;
    }
}
// 某个节点的深度
int FindDepthInTree(myTree *T,char ch) {
    int left,right;
    if(T==NULL ){
        return -1;
    }
    if(T->data == ch) {
        return 1;
    }
    left = T->LChild == NULL?-1:FindDepthInTree(T->LChild,ch);
    right = T->RChild == NULL?-1:FindDepthInTree(T->RChild,ch);
    if (left < 0 && right < 0) {
        return -1;
    }
    return left>right?left+1:right+1;
}
// 返回某个节点的指针
myTree *ReturnChildrenPoint(myTree *T,char ch) {
    myTree *left;
    myTree *right;
    if(T==NULL) {
        return NULL;
    }
    if(T->data == ch) {
        return T;
    }
    left = ReturnChildrenPoint(T->LChild,ch);
    right =    ReturnChildrenPoint(T->RChild,ch);
    if(left==NULL && right != NULL) {
        return right;
    }
    if (right==NULL && left != NULL) {
        return left;
    }
    return NULL;
}
// 子树的深度
int ChildrenDepth(myTree *T,char ch) {
    myTree *childT = ReturnChildrenPoint(T,ch);
    return Depth(childT);
}


// 前序非递归遍历
void preVisitTree2(myTree *T) {
    std::stack<myTree *> s;
    myTree *p = T;
    while (p!=NULL || !s.empty()) {
        while (p!=NULL) {
            std::cout << p->data << std::endl;
            s.push(p);
            p=p->LChild;
        }
        if (!s.empty()) {
            p=s.top();
            s.pop();
            p=p->RChild;
        }
    }
    
}
// 中序非递归遍历
void midVisitTree2(myTree *T) {
    std::stack<myTree *> s;
    myTree *p = T;
    while (p!=NULL || !s.empty()) {
        while (p!=NULL) {
            s.push(p);
            p=p->LChild;
        }
        if (!s.empty()) {
            p=s.top();
            std::cout << p->data << std::endl;
            s.pop();
            p=p->RChild;
        }
    }
}
// 后序非递归遍历
void afterVisitTree2(myTree *T) {
    std::stack<myTree*> s;
    myTree *cur;                      //当前结点
    myTree *pre=NULL;                 //前一次访问的结点
    s.push(T);
    while(!s.empty())
    {
        cur=s.top();
        if((cur->LChild==NULL&&cur->RChild==NULL)||
           (pre!=NULL&&(pre==cur->LChild||pre==cur->RChild)))
        {
            std::cout<<cur->data<<std::endl;  //如果当前结点没有孩子结点或者孩子节点都已被访问过
            s.pop();
            pre=cur;
        }
        else
        {
            if(cur->RChild!=NULL)
                s.push(cur->RChild);
            if(cur->LChild!=NULL)
                s.push(cur->LChild);
        }
    }
    
}


int main(int argc, const char * argv[]) {
    //     构建二叉树
    myTree *tree =  CreateTree();
//    preVisitTree(tree);
//    preVisitTree2(tree);
//    midVisitTree2(tree);
//    midVisitTree(tree);
    afterVisitTree(tree);
    afterVisitTree2(tree);
    std::cout<< FindDepthInTree(tree,'Q') << std::endl;
    
    return 0;
}

