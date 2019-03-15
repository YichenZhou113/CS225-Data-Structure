#include <iostream>
/**
 * @file list.cpp
 * Doubly Linked List (MP 3).
 */
//using namespace std;
/**
 * Destroys the current List. This function should ensure that
 * memory does not leak on destruction of a list.
 */
template <class T>
List<T>::~List() {
  delete head_;
  delete tail_;
  head_ = NULL;
  tail_ = NULL;
  /// @todo Graded in MP3.1
}

/**
 * Destroys all dynamically allocated memory associated with the current
 * List class.
 */
template <class T>
void List<T>::clear() {
  while(head_ != NULL){
    head_->next = tail_;
    tail_->prev = head_;
  }
  delete head_;
  delete tail_;
  length_ = 0;
  /// @todo Graded in MP3.1
}

/**
 * Inserts a new node at the front of the List.
 * This function **SHOULD** create a new ListNode.
 *
 * @param ndata The data to be inserted.
 */
template <class T>
void List<T>::insertFront(T const& ndata) {

  ListNode *frontn = new ListNode(ndata);
  if(head_==NULL){
    head_ = frontn;
    length_++;
    //cout<<"lol"<<endl;
  }else{
  frontn->next = head_;
  frontn->prev = NULL;
  head_->prev = frontn;
  head_ = frontn;
  length_++;
  //std::cout<<ndata<<std::endl;
}
  //std::cout<<this.head_->data<<std::endl;
  /// @todo Graded in MP3.1
}

/**
 * Inserts a new node at the back of the List.
 * This function **SHOULD** create a new ListNode.
 *
 * @param ndata The data to be inserted.
 */
template <class T>
void List<T>::insertBack(const T& ndata) {
  //std::cout<<ndata<<std::endl;
  ListNode *backn = new ListNode(ndata);
  if(head_==NULL){
    head_ = backn;
    tail_ = backn;
    //head_->next = NULL;
    length_++;
  }else{
    tail_->next = backn;
    backn->prev = tail_;
    backn->next = NULL;
    tail_ = backn;
    length_++;
    }

  /// @todo Graded in MP3.1
}

/**
 * Reverses the current List.
 */
template <class T>
void List<T>::reverse() {
  reverse(head_, tail_);
}

/**
 * Helper function to reverse a sequence of linked memory inside a List,
 * starting at startPoint and ending at endPoint. You are responsible for
 * updating startPoint and endPoint to point to the new starting and ending
 * points of the rearranged sequence of linked memory in question.
 *
 * @param startPoint A pointer reference to the first node in the sequence
 *  to be reversed.
 * @param endPoint A pointer reference to the last node in the sequence to
 *  be reversed.
 */
template <class T>
void List<T>::reverse(ListNode*& startPoint, ListNode*& endPoint) {
  if(startPoint == endPoint||length_ == 0){
    return;
  }
  ListNode *st = startPoint;
  ListNode *ed = endPoint;
  ListNode *stp = startPoint->prev;
  ListNode *edn = endPoint->next;
  while(startPoint!=endPoint){
    ListNode *tp = startPoint->prev;
    startPoint->prev = startPoint->next;
    startPoint->next = tp;
    //std::cout<<'lol'<<std::endl;
    startPoint = startPoint->prev;
    }
    ListNode * tp = startPoint->prev;
	  startPoint->prev = stp;
	  startPoint->next = tp;
	  endPoint = st;
	  endPoint->next = edn;
	  if(stp == NULL){
		head_ = startPoint;
    //std::cout<<'ll'<<std::endl;
  }else{
		stp->next = startPoint;
  }
	  if(edn == NULL){
		tail_ = endPoint;
  }else{
		edn->prev = endPoint;
  }


}

/**
 * Reverses blocks of size n in the current List. You should use your
 * reverse( ListNode * &, ListNode * & ) helper function in this method!
 *
 * @param n The size of the blocks in the List to be reversed.
 */
template <class T>
void List<T>::reverseNth(int n) {
  if (head_ == NULL){
	return;
}
	ListNode * st = head_;
  ListNode * ed = head_;
  while(ed->next!= NULL&&st->next!=NULL){
    ed = st;
	for(int i =1; i<n; i++){
    if(ed->next!=NULL){
    ed = ed->next;
  }else{
    break;
  }
  }
  reverse(st,ed);
  st = ed->next;
}


  /// @todo Graded in MP3.1
}

/**
 * Modifies the List using the waterfall algorithm.
 * Every other node (starting from the second one) is removed from the
 * List, but appended at the back, becoming the new tail. This continues
 * until the next thing to be removed is either the tail (**not necessarily
 * the original tail!**) or NULL.  You may **NOT** allocate new ListNodes.
 * Note that since the tail should be continuously updated, some nodes will
 * be moved more than once.
 */
template <class T>
void List<T>::waterfall() {
  if (head_==NULL){
		return;
	}
	ListNode* curr = head_->next;
	ListNode* tp;
	while(curr!=NULL&&curr->next!=NULL){
		curr->next->prev=curr->prev;
		curr->prev->next=curr->next;
		curr->prev=tail_;
		tp = curr->next->next;
		curr->next=NULL;
		tail_->next=curr;
		tail_ = curr;
		curr = tp;
	}
}

// @todo Graded in MP3.1

/**
 * Splits the given list into two parts by dividing it at the splitPoint.
 *
 * @param splitPoint Point at which the list should be split into two.
 * @return The second list created from the split.
 */
template <class T>
List<T> List<T>::split(int splitPoint) {
    if (splitPoint > length_)
        return List<T>();

    if (splitPoint < 0)
        splitPoint = 0;

    ListNode* secondHead = split(head_, splitPoint);

    int oldLength = length_;
    if (secondHead == head_) {
        // current list is going to be empty
        head_ = NULL;
        tail_ = NULL;
        length_ = 0;
    } else {
        // set up current list
        tail_ = head_;
        while (tail_->next != NULL)
            tail_ = tail_->next;
        length_ = splitPoint;
    }

    // set up the returned list
    List<T> ret;
    ret.head_ = secondHead;
    ret.tail_ = secondHead;
    if (ret.tail_ != NULL) {
        while (ret.tail_->next != NULL)
            ret.tail_ = ret.tail_->next;
    }
    ret.length_ = oldLength - splitPoint;
    return ret;
}

/**
 * Helper function to split a sequence of linked memory at the node
 * splitPoint steps **after** start. In other words, it should disconnect
 * the sequence of linked memory after the given number of nodes, and
 * return a pointer to the starting node of the new sequence of linked
 * memory.
 *
 * This function **SHOULD NOT** create **ANY** new List objects!
 *
 * @param start The node to start from.
 * @param splitPoint The number of steps to walk before splitting.
 * @return The starting node of the sequence that was split off.
 */
template <class T>
typename List<T>::ListNode* List<T>::split(ListNode* start, int splitPoint) {
  for(int i=0;i<splitPoint;i++){
    if(start!=NULL){
      start = start->next;
    }else{
      return NULL;
    }
  }
  start->prev->next = NULL;
  start->prev = NULL;
  return start;
    /// @todo Graded in MP3.2
}

/**
 * Merges the given sorted list into the current sorted list.
 *
 * @param otherList List to be merged into the current list.
 */
template <class T>
void List<T>::mergeWith(List<T>& otherList) {
    // set up the current list
    head_ = merge(head_, otherList.head_);
    tail_ = head_;

    // make sure there is a node in the new list
    if (tail_ != NULL) {
        while (tail_->next != NULL)
            tail_ = tail_->next;
    }
    length_ = length_ + otherList.length_;

    // empty out the parameter list
    otherList.head_ = NULL;
    otherList.tail_ = NULL;
    otherList.length_ = 0;
}

/**
 * Helper function to merge two **sorted** and **independent** sequences of
 * linked memory. The result should be a single sequence that is itself
 * sorted.
 *
 * This function **SHOULD NOT** create **ANY** new List objects.
 *
 * @param first The starting node of the first sequence.
 * @param second The starting node of the second sequence.
 * @return The starting node of the resulting, sorted sequence.
 */
template <class T>
typename List<T>::ListNode* List<T>::merge(ListNode* first, ListNode* second) {

  ListNode* c1;
  ListNode* c2;
  ListNode* nl;

  if(first->data<second->data){
  		nl = first;
  		c1 = first;
  		c2 = second;
    }else{
  		nl = second;
  		c1 = second;
  		c2 = first;
  	}

    while(c1!=NULL&&c2!=NULL){
  		while(c1->next!=NULL&&c1->next->data<c2->data){
  			c1=c1->next;
  		}
  		if(c1->next==NULL){
  			c1->next=c2;
  			c2->prev=c1;
  			break;
  		}
      ListNode *tp = c1->next;
  		c1->next->prev=NULL;
  		c1->next = c2;
  		c2->prev = c1;
  		c1=c2;
  		c2=tp;
  	}
    return nl;
}

/**
 * Sorts the current list by applying the Mergesort algorithm.
 */
template <class T>
void List<T>::sort() {
    if (empty())
        return;
    head_ = mergesort(head_, length_);
    tail_ = head_;
    while (tail_->next != NULL)
        tail_ = tail_->next;
}

/**
 * Sorts a chain of linked memory given a start node and a size.
 * This is the recursive helper for the Mergesort algorithm (i.e., this is
 * the divide-and-conquer step).
 *
 * @param start Starting point of the chain.
 * @param chainLength Size of the chain to be sorted.
 * @return A pointer to the beginning of the now sorted chain.
 */
template <class T>
typename List<T>::ListNode* List<T>::mergesort(ListNode* start, int chainLength) {
  if(chainLength==1){return start;}
	ListNode* tp = split(start,chainLength/2);
	start = mergesort(start, chainLength/2);
	tp = mergesort(tp, chainLength-chainLength/2);
  return merge(start,tp);
}
