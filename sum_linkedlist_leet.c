/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    //if the user enters two null nodes, end the function before we screw anything up
    if(l1==NULL||l2==NULL){
        return NULL;
    }
    //this will be the node you return, either recursively or at the end of the recursions
    struct ListNode* node;
    node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->next = NULL;
    //get the sum and declare a variable to hold what needs to be carried out
    int sum = l1->val + l2->val;
    int overflow = 0;
    //while we still have a sum greater than one digit,
    //make overflow the number of 10s that appear
    //make sum the remainder of its division by 10
    while(sum >= 10){
        overflow = sum/10;
        sum %= 10;
    }
    //if we DO have overflow
    if(overflow>0){
        //the order of checking l1 and l2 is arbitrary, it shouldnt really matter which is first. importantly, you do have to check both, or else the order would matter
        //if l1 has no next node, make the overflow its next node
        if(l1->next==NULL){
            struct ListNode* flow_node;
            flow_node = (struct ListNode*)malloc(sizeof(struct ListNode));
            flow_node->next = NULL;
            flow_node->val = overflow;
            l1->next = flow_node;
        }
        //if l1 has a next node but l2 doesnt, make the overflow l2's next node
        else if(l2->next==NULL){
            struct ListNode* flow_node;
            flow_node = (struct ListNode*)malloc(sizeof(struct ListNode));
            flow_node->next = NULL;
            flow_node->val = overflow;
            l2->next = flow_node;
        }
        //if l1 and l2 have a next, add the overflow to l1's next value
        else if(l1->next!=NULL){
            l1->next->val += overflow;
        }
        //shouldnt be necessary since by now we KNOW l1 has a next, but why not
        else{
            l2->next->val += overflow;
        }
    }
    //node's value is the single-digit one's column from the sum
    node->val = sum;
    //if l1 and l2 have next nodes, make return node's next the next sum node
    if(l1->next!=NULL&&l2->next!=NULL){
        //l1->next->val += overflow;
        node->next = addTwoNumbers(l1->next, l2->next);
    }
    //if only l2 has a next node, make l1's next node a zero node
    //then make the return node's next the next sum node between l2 next and zero node
    else if(l1->next==NULL&&l2->next!=NULL){
        struct ListNode* zero_node;
        zero_node = (struct ListNode*)malloc(sizeof(struct ListNode));
        zero_node->next = NULL;
        zero_node->val = 0;
        node->next = addTwoNumbers(zero_node, l2->next);
    }
    //repeat above for the opposite scenario
    else if(l1->next!=NULL&&l2->next==NULL){
        struct ListNode* zero_node;
        zero_node = (struct ListNode*)malloc(sizeof(struct ListNode));
        zero_node->next = NULL;
        zero_node->val = 0;
        node->next = addTwoNumbers(l1->next, zero_node);
    }
    //if neither l1 nor l2 has a next node, just return our node
    else{
        return node;
    }
    //return our final sum node
    return node;
}