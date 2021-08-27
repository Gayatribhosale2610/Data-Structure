#include <iostream>

using namespace std;

struct node{
    int data;
    struct node* link;
};

/*struct node*push(struct node* head, int val){
    struct node* newP = (struct node*)malloc(sizeof(struct node));
    newP -> data = val;
    newP -> link = head;
    head = newP;
    return head;
};
*/
struct node* addNode(struct node* head, int val){
    struct node* newP = (struct node*)malloc(sizeof(struct node));
    newP -> data = val;
    newP -> link = NULL;

    newP -> link = head;
    head = newP;
    return head;
};

struct node* add(struct node* head1, struct node* head2){
    if(head1 -> data == 0)
        return head2;
    if(head2 -> data == 0)
        return head1;
    struct node* ptr1 = head1;
    struct node* ptr2 = head2;
    struct node* head3 = NULL;
    int carry = 0, sum;

    while(ptr1 || ptr2){
        sum = 0;
        if(ptr1)
            sum += ptr1 -> data;
        if(ptr2)
            sum += ptr2 -> data;
        sum += carry;

        carry = sum / 10;
        sum = sum % 10;

        head3 = addNode(head3, sum);

        if(ptr1)
            ptr1 = ptr1 -> link;
        if(ptr2)
            ptr2 = ptr2 -> link;
    }
    if(carry)
        head3 = addNode(head3, carry);
    return head3;
}

struct node* reverseList(struct node* head){
    if(head == NULL)
        return head;
    struct node* current = NULL;
    struct node* next = head -> link;
    head -> link = NULL;
    while(next != NULL){
        current = next;
        next = next -> link;
        current -> link = head;
        head = current;
    }
    return head;
};

struct node* create(struct node* head, int n){
    while(n > 0){
        head = addNode(head, n % 10);
        n = n /10;
    }
    return head;
};

void print(struct node* head){
    if(head == NULL)
        cout<<"no polynomial";
    else{
        struct node* ptr = head;
        while(ptr -> link != NULL){
            cout<<ptr -> data<<" -> ";
            ptr = ptr -> link;
        }
        cout <<ptr -> data;
    }
    cout<<endl;
}

void back2num(struct node* head){
    struct node* temp = head;
    cout<<"Result : ";
    while(temp){
        cout<<temp -> data;
        temp = temp -> link;
    }
    //return;
}

int main(){
    int n1, n2;
    cout<<"Enter two numbers: ";
    cin>>n1>>n2;

    cout<<"Linked list representation of first number is: ";
    struct node* head1 = NULL;
    head1 = create(head1, n1);
    print(head1);

    cout<<"Linked list representation of second number is: ";
    struct node* head2 = NULL;
    head2 = create(head2, n2);
    print(head2);

    head1 = reverseList(head1);
    head2 = reverseList(head2);

    cout<<endl;
    cout<<"First Reversed list is : ";
    print(head1);
    cout<<"First Reversed list is : ";
    print(head2);

    struct node* head3 = NULL;
    head3 = add(head1, head2);
    cout<<"\nResultant linked list after addition is : ";
    print(head3);
    back2num(head3);
    return 0;
}
