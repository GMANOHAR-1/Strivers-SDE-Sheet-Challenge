/*
	Time Complexity : O(N)
	Space Complexity : O(N)

	Where N is the length of the string.
*/

bool isValidParenthesis(string expression) 
{   
    // Make an inbuilt stack.
    stack<char> s; 
    char x; 
  
    // Traversing the Expression.
    for (int i = 0; i < expression.length(); i++)  
    { 
        if (expression[i] == '(' || expression[i] == '[' || expression[i] == '{')  
        { 
            // Push the element in the stack .
            s.push(expression[i]); 
            continue; 
        } 
  
        /* 
            If current current character is not opening 
            bracket, then it must be closing. So stack 
            cannot be empty at this point. 
        */

        if (s.empty()) 
        {
            return false; 
        }
  		
        // Store the top element.
        x = s.top(); 
        s.pop(); 
        
        // Check for opening braces in stack of corresponding closing braces.
        switch (expression[i]) { 
        case ')': 
            
            if (x == '{' || x == '[') 
            {
                return false; 
            }
            break; 
  
        case '}': 
  
            if (x == '(' || x == '[') 
            {
                return false; 
            }
            break; 
  
        case ']': 
            
            if (x == '(' || x == '{')
            {
                return false;
            }
            break; 
        } 
    } 
  
    // Check Empty Stack.
    return (s.empty()); 
} 

