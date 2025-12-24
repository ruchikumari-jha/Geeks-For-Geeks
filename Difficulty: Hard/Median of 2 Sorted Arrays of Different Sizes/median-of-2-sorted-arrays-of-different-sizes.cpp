class Solution {
public:
    double medianOf2(vector<int>& a, vector<int>& b) {
         // merge both the arrays
    vector<int> c(a.begin(), a.end());
    c.insert(c.end(), b.begin(), b.end());

    // sort the concatenated array
    sort(c.begin(), c.end());
    
    int len = c.size();
  	
  	// if length of array is even
    if (len % 2 == 0) 
        return (c[len / 2] + c[len / 2 - 1]) / 2.0;
  
  	// if length of array is odd
  	else 
        return c[len / 2];
    }
};