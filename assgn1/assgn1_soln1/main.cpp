/*
 * To test the other files
 */

#include <iostream>
#include "list.hpp"
using namespace std;

int main()
{
    Node* head = new Node(3);
    head = insert(head,4,0);
    head = insert(head,1,0);
    head = insert(head,4,0);
    head = insert(head,3,0);
    head = insert(head,8,0);
    head = insert(head,9,3);
    print(head);
    head = remove(head,3);
    print(head);
    head=reverse(head);
    print(head);
    return 0;
}
