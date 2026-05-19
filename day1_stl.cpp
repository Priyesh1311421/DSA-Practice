#include<bits/stdc++.h>
using namespace std;
// pairs

void explainPair(){

    pair<int, int> p = {1, 3};

    cout<< p.first << " "<< p.second;

    pair<int, pair<int, int>>p1 = {1, {3, 4}};

    cout<< p1.first << " "<< p1.second.second << " "<< p1.second.first;

    pair<int, int> arr[] = {{1, 2}, {2, 5}, {5, 1}};

    cout<< arr[1].second;

}

void explianVector() {

    vector<int> v;

    v.push_back(1);
    v.emplace_back(2);

    vector<pair<int, int>> vec;

    vec.push_back({1, 2});
    vec.emplace_back(1, 2);

    vector<int> v(5, 100);

    vector<int> v(5);

    vector<int> v1(5, 20);
    vector<int> v2(v1);

    vector<int>::iterator it = v.begin();
    it++;
    cout<< *(it) << " ";
    vector<int> :: iterator it = v.end();
    vector<int> :: reverse_iterator it = v.rend();
    vector<int> :: iterator it = v.begin();

    cout<< v[0] << " "<< v.at(0);

    cout<< v.back()<< " ";

    for(auto it = v.begin(); it != v.end(); it++){
        cout<< *(it) << " ";
    }


    for(vector<int> ::iterator it = v.begin(); it != v.end(); it++){
        cout<< *(it) << " ";
    }
    
    for(auto it : v){
        cout<< it << " ";
    }

    v.erase(v.begin() + 1);
    v.erase(v.begin()+2, v.begin() + 4);

    // Insert function

    vector<int> v(2, 100);
    v.insert(v.begin(), 300);
    v.insert(v.begin()+ 1, 2, 10);

    vector<int> copy(2, 50);
    v.insert(v.begin(), copy.begin(), copy.end());

    cout << v.size();

    v.pop_back();

    v1.swap(v2);

    v.clear();

    cout<< v.empty();

}

void explainList(){
    list< int> ls;
    ls.push_back(2); //{2}
    ls.emplace_back(4);  //{2,4}

    ls.push_front(5);  //{5, 2, 4}

    ls.emplace_front(); // {2, 4}

    //rest functions are same as vector
    //begin, end, rbegin, rend, clear insert, size, swap etc.
}



void explainDeque() {
    deque< int> dq;
    dq.push_back(1);
    dq.emplace_back(2);
    dq.push_front(4);
    dq.emplace_front(3);

    dq.pop_back();
    dq.pop_front();

    dq.back();
    dq.front();

    // rest functions same as vector
    // begin, end, rbegin, rend, clear, insert, size, swap
}


void explainStack() {
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(3);
    st.emplace(5);

    cout<< st.top();
    st.pop();

    cout<< st.top(); 
    cout<< st.size();

    cout<< st.empty();

    stack<int> st1, st2;

    st1.swap(st2);
}

void explainQueue() {
    queue<int> q; 
    q.push(1);
    q.push(2);
    q.emplace(4);

    q.back() += 5;

    cout<< q.back();

    cout<< q.front();

    q.pop();

    cout<< q.front();
}


void explainPQ() {
    priority_queue<int> pq;
    pq.push(5);
    pq.push(2);
    pq.push(8);
    pq.emplace(10);

    cout<< pq.top();

    pq.pop();

    cout<< pq.top();


    priority_queue<int, vector<int> , greater<int>> pq;

    pq.push(5);
    pq.push(2);
    pq.push(8);
    pq.emplace(10);

    cout<< pq.top();
}


void explainSet() {
    set<int>st;
    st.insert(1);
    st.emplace(2);
    st.insert(2);
    st.insert(4);
    st.insert(3);

    auto it = st.find(3);

    auto it = st.find(6);

    st.erase(5);

    int cnt = st.count(1);
    auto it = st.find(3);

    st.erase(it);

    auto it1 = st.find(2);
    auto it2 = st.find(4);

    st.erase(it1, it2);  //erases (first,last)

    auto it = st.lower_bound(2);
    auto it = st.upper_bound(3);
}


void explainMulitSet() {
    // everything is same as set 
    // only store duplicate elements also

    multiset<int> ms;
    ms.insert(1);
    ms.insert(1);
    ms.insert(1);

    ms.erase(1); // all 1's are deleted

    int cnt = ms.count(1);

    ms.erase(ms.find(1));

    ms.erase(ms.find(1), ms.find(1));

    // rest all functions are same.
}


void explainUSet() {
    unordered_set<int> st;
    // lower_bound and upper_bound function does not work , rest all functions are same 
    // as above , it does not stores in particular order  it has a better complexity than set in most cases , except some when collision happens
}

void explainMap(){

    map<int,int> mpp;

    map<int, pair<int,int>> mpp1;

    map<pair<int,int>, int> mpp2;

    mpp[1] = 2;
    mpp.emplace(3, 1);
    mpp.insert({3, 1});

    mpp2[{2,3}] = 10;

    for(auto it: mpp){
        cout<< it.first <<" "<< it.second << endl;
    }

    cout << mpp[1];
    cout << mpp[5];


    auto it = mpp.find(3);
    //cout << *(it).second;

    auto it = mpp.find(5);

    auto it = mpp.lower_bound(2);

    auto it = mpp.upper_bound(3);
}


void explainMultiMap() {
    // everything same as map but it can store multiple keys
    // only mpp[key] can not be used here

}

void explainUnorderedMap() {
    // same as set and unordered_set difference
}


bool comp(pair<int,int> p1, pair<int,int> p2) {
    if(p1.second < p2.second) {
        return true;
    }else if(p1.second == p2.second){
        if(p1.first > p2.second) return true;
    }else {
        return false;
    }
}



void explainExtra(){
    int a[] = {1, 2, 3,4, 5};
    vector<int> v;
    int n = 5;

    sort(a, a+n);
    sort(v.begin(), v.end());
    sort(a+2, a+4);

    sort(a, a+n, greater<int>());

    pair<int,int>a[] = {{1,2},{2,1},{4,1}};
    
    //sort it according to second element
    // if second element is same then sort
    // it according to first element but in descending order 


    sort(a, a + n, comp);

    int num = 7;
    int cnt = __builtin_popcount(num);
    long long num = 165786578687;
    int cnt = __builtin_popcountll(num);

    string s = "123";
    do{
        cout<<s<<endl;
    }while(next_permutation(s.begin(), s.end()));

    int maxi = *max_element(a, a+n);


}


int main(){
    explainPair();
    cout<< "hellow";
    return 0;
}