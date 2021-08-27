#include <iostream>
using namespace std;

struct node{
    int expo;
    float coeff;
    struct node* link;
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
    cout<<"Enter total number of terms : ";
    cin >>n;

    for(i = 0; i< n; i++){
        cout<<"Enter the coeff term "<<i+1<<": ";
        cin>>coeff;
        cout<<"Enter the expo term "<<i+1<<": ";
        cin>> expo;
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
            cout<<ptr -> coeff<<"x^ "<<ptr -> expo;
            ptr = ptr -> link;
            if(ptr != NULL)
                cout<<" + ";
            else
                cout<<endl;
        }
        cout<<endl;
    }
}

void polyMulti(struct node* head1, struct node* head2){
    struct node* ptr1 = head1;
    struct node* ptr2 = head2;
    struct node* head3 = NULL;

    while(ptr1 != NULL){
        while(ptr2 != NULL){
            int res1 = ptr1 -> coeff * ptr2 -> coeff;
            int res2 = ptr1 -> expo + ptr2 -> expo;
            head3 = insert(head3, res1, res2);
            ptr2 = ptr2 -> link;
        }
        ptr1 = ptr1 -> link;
        ptr2 = head2;
    }
    cout<<"Before simplification: ";
    print(head3);

    struct node* ptr3 = head3;
    struct node* temp = NULL;
    while(ptr3 -> link != NULL){
        if(ptr3 -> expo == ptr3 -> link -> expo){
            ptr3 -> coeff = ptr3 -> coeff + ptr3 -> link -> coeff;
            temp = ptr3 -> link;
            ptr3 -> link = ptr3 -> link -> link;
            free(temp);
            temp = NULL;
        }else{
            ptr3 = ptr3 -> link;
        }
    }
    cout<<"After simplification: ";
    print(head3);

}

int main(){
    struct node* head1 = NULL;
    struct node* head2 = NULL ;
    cout<<"Enter first polynomial\n";
    head1 = create(head1);
    cout<<"Enter second polynomial\n";
    head2 = create(head2);

    cout<<"First polynomial is : ";
    print(head1);
    cout<<"Second polynomial is : ";
    print(head2);
    polyMulti(head1,head2);
    return 0;
}
