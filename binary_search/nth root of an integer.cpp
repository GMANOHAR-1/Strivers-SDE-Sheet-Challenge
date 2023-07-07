 
int NthRoot(int n, int m) {
  
    double error = 1e-2;

  
    double diff = 1e18;
 
    double xk = 2;

     
    while (diff > error) {

       
        double xk_1 = (pow(xk, n) * (n - 1) + m) / (n * pow(xk, n - 1));
       diff = abs(xk - xk_1);

   
        xk = xk_1;
    }

    // Extracting integer value from 'xk'
    int integerAns = (int) xk;

    // Checking whether nth Root exists or not
    int res = 1;
    for(int i = 0; i < n; ++i) {
      res *= integerAns;
    }
    
    if(res != m) {
      // Updating value of 'integerAns'
      integerAns = -1;
    }

    // Returning the nthRootOfM
    return integerAns;
}
