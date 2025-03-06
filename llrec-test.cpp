#include <iostream>
#include <fstream>
#include <functional>
#include "llrec.h"
#include <set>
// this is included for testing 
using namespace std;

// FUNCTOR SHOULD BE DEFINED IN THIS FILE (operator())

/**
 * Reads integers (separated by whitespace) from a file
 * into a linked list.
 *
 * @param[in] filename
 *  The name of the file containing the data to read
 * @return
 *  Pointer to the linked list (or NULL if empty or the
 *  file is invalid)
 */
Node* readList(const char* filename);

/**
 * Prints the integers in a linked list pointed to
 * by head.
 */
void print(Node* head);

/**
 * Deallocates the linked list nodes
 */
void dealloc(Node* head);


Node* readList(const char* filename)
{
    Node* h = NULL;
    ifstream ifile(filename);
    int v;
    if( ! (ifile >> v) ) return h;
    h = new Node(v, NULL);
    Node *t = h;
    while ( ifile >> v ) {
        t->next = new Node(v, NULL);
        t = t->next;
    }
    return h;
}

void print(Node* head)
{
    while(head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

void dealloc(Node* head)
{
    Node* temp;
    while(head) {
        temp = head->next;
        delete head;
        head = temp;
    }
}

// -----------------------------------------------
//   Add any helper functions or
//   function object struct declarations
// -----------------------------------------------

// fuctors for testing: 
struct OddTesting{
    bool operator()(int val){
        return val % 2 != 0; 
        // this will return true if it is odd (this means it will be removed)
    }
};

    // OTHER FUNCTOR IDEAS: 
    // duplicates, less than, negative, in a certain range 
struct dupTesting{
    static set<int> allvals; 

    bool operator()(int val){
        if (allvals.count(val)){
            return true; 
        }
        allvals.insert(val);
        return false; 
    }
};
set<int> dupTesting::allvals;

struct lessthanTesting{
  bool operator()(int val){
    // want to check if less than 4 
    return val <= 0; 
  }  
};

struct negTesting{
    bool operator() (int val){
        return val <= 0;
    }
};

struct inRangeTest{
    bool operator() (int val){
        if (val >= 4 && val <= 10){
            return true; 
        }
        return false; 
        // removes if it is in range 4 to 10, inclusive 
    }
};


int main(int argc, char* argv[])
{
    if(argc < 2) {
        cout << "Please provide an input file" << endl;
        return 1;
    }

    // -----------------------------------------------
    // Feel free to update any code below this point
    // -----------------------------------------------
    Node* head = readList(argv[1]);
    Node* smaller = nullptr; 
    Node* larger = nullptr; 
    cout << "Original list: ";
    print(head);
    llpivot(head, smaller, larger, 3);

    cout << "Remaining: ";
    print(head);
    cout << "smaller list: ";
    print(smaller);
    cout << "larger list: "; 
    print(larger);

    // // code to test llpivot on current input list 

    // // initially llrec-test2.in was empty so code was tested for all null list

    // // test code for only one length list which is equal to pivot - correct 

    // // test code for a pivot that is not in the list - llrec-test3.in - this file is also in incr order AND has duplicate values
    // // worked 

    // // this concludes testing for part 1 
    // // Test out your linked list code

    // // testing for part 2 
    // OddTesting pred; 
    // Node* oddfiltered = llfilter(larger, pred);
    // cout << "odd filtered list: ";
    // print(oddfiltered);
    // // tested this for the head, smaller, and larger 
    // // this covered null, only one w odd, and list with both 


    // lessthanTesting pred2; 
    // Node* testlist = readList(argv[1]);
    // cout << "List before filter: ";
    // print(testlist); 
    // // using llrec-test4.in for this 
    // Node* lessfilter = llfilter(testlist, pred2); 
    // cout << "List after filter: ";
    // print(lessfilter);
    // // this works 

    // // for neg testing, using llrec-test5.in 
    // negTesting pred3; 
    // Node* testlist2 = readList(argv[1]);
    // cout << "List before filter: ";
    // print(testlist2);
    // Node* negfilter = llfilter(testlist2, pred3);
    // cout << "List after filter: ";
    // print(negfilter);
    // // this works 

    // // use llrec-test6.in for in range testing 
    // inRangeTest pred4; 
    // Node* testlist3 = readList(argv[1]);
    // cout << "List before filter: ";
    // print(testlist3);
    // Node* rangefilter = llfilter(testlist3, pred4);
    // cout << "List after filter: ";
    // print(rangefilter);
    // // this works 
    
    // dupTesting pred5; 
    // Node* testlist4 = readList(argv[1]);
    // cout << "List before filter: ";
    // print(testlist4); 
    // // using llrec-test4.in for this 
    // Node* dupfilter = llfilter(testlist4, pred5); 
    // cout << "List after filter: ";
    // print(dupfilter);
    // // YAY this works 

    return 0;

}
