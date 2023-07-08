/*

    Time Complexity : O(N)
    Space Complexity : O(N)

    where 'N' is the size of array/list ‘PRICE’.
    
*/

#include <stack>

vector<int> findSpans(vector<int> &price) {
    //  Size of array/list ‘price’.
    int n = price.size();

    vector<int> result(n);
    stack<int> stk;

    for(int i = 0; i < n; i++) {
        //  Stack will have only those days before ‘i’ in which price is higher than price at day ‘i’.
        while(stk.empty() == false && price[stk.top()] <= price[i]) {
            stk.pop();
        }

        //  Span on day 'i'.
        if(stk.empty() == true) {
            result[i] = i + 1;
        } else {
            result[i] = i - stk.top();
        }

        stk.push(i);
    }

    return result;
}
