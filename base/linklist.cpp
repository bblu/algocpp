#include <iostream>

using namespace std;

static const bool debug = true;
/*  Project 1

    定义一个单向链表node, 每个节点值为int.
    定义函数void create_linklist(…, int n)来生成链表，链表长度由参数n传入,生成的链表要作为参数返回，而不是当初函数返回值返回，链表节点值为1,2,3...n。
    定义函数reverse_linklist(...),　对参数传入的链表进行逆转。
    定义函数insert_node(node *pHead, int Index, int Value ), 在指定链表位置Index插入指定Value
    定义函数delete_node(node *pHead,  int Index),删除链表位置Index所在的节点
    定义函数delete_linklist(),　删除整个链表


    main()函数：
    １．调用create_linklist()生成链表
    ２．调用insert_node()插入节点
    ３．调用delete_node()删除节点
    ４．调用reverse_linklist()逆转
    ５．打印链表所有值
    ６．结束程序工作
*/

struct node
{
    node(int v=-1):value(v),next(nullptr){}
    int value;
    node* next;
};

/* assistant function printing node struct for debug 
 * wblu @ 4-19-2019
*/
void print(node **pHead){
    node *it = *pHead;
    while(it){
        cout << it->value << " ";
        it=it->next;
    }
    cout << endl;
}

/* 链表长度由参数n传入,生成的链表要作为参数返回，而不是当初函数返回值返回，
   链表节点值为1,2,3...n
*/
void create_linklist(node **pHead, int n)
{
    if(n<1){
        *pHead = nullptr;
        return;
    }
    node * last = new node(1);
    *pHead = last;
    for(int i = 2; i <= n; i++){
        node *n = new node(i);
        last->next = n;
        last = n;
    }
}


//对参数传入的链表进行逆转
/*
    i -|-> j -> k
    i      j -> k
    

*/
void reverse_linklist(node **pHead)
{
    node 
}

//在指定链表位置Index插入指定Value
// Index 为 1 ~ n 代表 1 ~ n 个节点
// Index = 0 即为头添加
void insert_node(node **pHead,  int Index, int Value)
{

}

//删除链表位置Index所在的节点
void delete_node(node **pHead,  int Index)
{

}

//删除整个链表
void delete_linklist(node **pHead)
{

}

/* Project 2
  编写一个函数int Calculate(node *pHead, int k);在链表数字之间插入+ 、- 或者什么都不插入,使得计算结果等于
  给定的整数 K,返回所有可能性的个数。例如链表有数字 1, 2, 3, ..., 9 并且给
  定的整数为 100,那么其中的一种可能性是: 1 + 2 + 34 – 5 + 67 – 8 + 9 = 100。
  (不允许开辟额外的字符串空间,假设链表所有数字都大于 0 并且小于 10)
*/
int Calculate(node *pHead, int k)
{
    return -1;
}

/*  Project 3

    定义一个聚类函数 cluster(int data[], int len, int radius)；
    data中的值没有重复，长度为len,
    把按照数值的聚类进行分为n组，
    对于组G中任意一个数值a,总是能在本组G中找到一个数值b,　使　|a-b| < radius　　.
    在函数内部打印出所有n个组成员，分成n行输出

    (要求：不能使用数组排序操作)

    例如:
       输入 data[] = { 1, 20, 89, 22, 72, 2,39, 3,56,86, 5, 93,13, 15, 18, 73, 79, 81, 25, 38, 43, 83,48, 52, 59,92,84,95,87 };
       正确的屏幕输出为组及成员为(每行为一组,行之间顺序随意,组内成员顺序随意)：
       1, 2, 3, 5,
       13, 15, 18, 20, 22, 25,
       39, 38, 43, 48, 52, 56, 59,
       73, 72,
       79, 89, 92, 84, 95,87,86, 93,81, 83,

*/
void cluster(int data[], int len, int radius)
{

}


int main()
{
    // Project 1
    // 可将头尾指针及节点个数封装结构体，更方便操作
    cout << "==========Project1=================" << endl;
    node *pHead = nullptr;
    // １．调用create_linklist()生成链表
    create_linklist(&pHead,9);
    if(debug)print(&pHead);
    // ２．调用insert_node()插入节点
    insert_node(&pHead,9,10);
    if(debug)print(&pHead);
    // ３．调用delete_node()删除节点
    delete_node(&pHead,10);
    if(debug)print(&pHead);
    // ４．调用reverse_linklist()逆转
    reverse_linklist(&pHead);
    if(debug)print(&pHead);

    node *pTemp = pHead;
    while (pTemp)
    {
        std::cout << pTemp->value << " ";
        pTemp = pTemp->next;
    }
    cout << endl;
    cout << "==========Project1=================" << endl;
    cout << endl;

    // Project 2
    cout << "==========Project2=================" << endl;
    delete_linklist(&pHead);
    create_linklist(&pHead,9);
    cout << Calculate(pHead,100) << endl;
    cout << "==========Project2=================" << endl;
    cout << endl;

    // Project 3
    cout << "==========Project3=================" << endl;
    int data[] = { 1, 20, 89, 22, 72, 2,39, 3,56,86, 5, 93,13, 15, 18, 73, 79, 81, 25, 38, 43, 83,48, 52, 59,92,84,95,87 };
    cluster(data, sizeof(data)/sizeof(int), 5);
    /*
    正确的输出为组及成员为(组内成员顺序随意)：
    1, 2, 3, 5,
    13, 15, 18, 20, 22, 25,
    39, 38, 43, 48, 52, 56, 59,
    73, 72,
    79, 89, 92, 84, 95,87,86, 93,81, 83,
    */
    cout << "==========Project3=================" << endl;

    return 0;
}

