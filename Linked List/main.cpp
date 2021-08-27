#include <iostream>

using namespace std;

struct node{
    struct node* link;
    float coeff;
    int expo;
};

struct node* insert(struct node* head, float co, int ex){
    struct node* newP = (struct node*)malloc(sizeof(struct node));
    newP -> coeff = co;
    newP -> expo = ex;
    newP -> link = NULL;

    if(head == NULL || ex > head -> expo){
        newP -> link = head;
        head = newP;
    }
    else{
        struct node* temp = head;
        while(temp -> link != NULL && temp -> link -> expo >= ex){
            temp = temp -> link;
        }
        newP -> link = temp -> link;
        temp -> link = newP;
    }
    return head;
};

struct node* create(struct node* head){
    int i,n,expo;
    float coeff;
    cout<<"Enter the total number of terms: ";
    cin>>n;

    for(i = 0; i < n; i++){
        cout<<"Enter the coefficient for term "<<i+1<<": ";
        cin>>coeff;
        cout<<"Enter the exponent for term "<<i+1<<": ";
        cin>>expo;
        head = insert(head, coeff, expo);
    }
    return head;
};

void print(struct node* head){
    if(head == NULL)
        cout<<"No polynomial";
    else{
        struct node* ptr = head;
        while(ptr != NULL){
            cout<<ptr -> coeff<<"x^"<<ptr -> expo;
            ptr = ptr -> link;
            if(ptr != NULL)
                cout<<" + ";
            else
                cout<<endl;
        }
        cout<<endl;
    }
}

void polyAdd(struct node* head1, struct node* head2){
    struct node* ptr1 = head1;
    struct node* ptr2 = head2;
    struct node* head3 = NULL;
    while(ptr1 != NULL && ptr2 != NULL){
        if(ptr1 -> expo == ptr2 -> expo){
            head3 = insert(head3, ptr1 -> coeff + ptr2 -> coeff, ptr1 -> expo);
            ptr1 = ptr1 -> link;
            ptr2 = ptr2 -> link;
        }
        else if(ptr1 -> expo > ptr2 -> expo){
            head3 = insert(head3, ptr1 -> coeff, ptr1 -> expo);
            ptr1 = ptr1 -> link;
        }
        else if(ptr1 -> expo < ptr2 ->expo){
            head3 = insert(head3, ptr2 -> coeff, ptr2 -> expo);
            ptr2 = ptr2 -> link;
        }
    }
    while(ptr1 != NULL){
        head3 = insert(head3, ptr1 -> coeff, ptr1 -> expo);
        ptr1 = ptr1 -> link;
    }
    while(ptr2 != NULL){
        head3 = insert(head3, ptr2 -> coeff, ptr2 -> expo);
        ptr2 = ptr2 -> link;
    }
    cout<<"Added Polynomial is: ";
    print(head3);
};

int main(){
    struct node* head1 = NULL;
    struct node* head2 = NULL;
    cout<<"Enter first polynomial\n";
    head1 = create(head1);
    cout<<"Enter second polynomial\n";
    head2 = create(head2);
    print(head1);
    print(head2);
    polyAdd(head1, head2);
    return 0;
}
