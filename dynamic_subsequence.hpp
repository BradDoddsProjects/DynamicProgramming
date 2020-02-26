///////////////////////////////////////////////////////////////////////////////
// dynamic_subsequence.hpp
//
// Dynamic programming algorithms for the longest substring, and longest
// subsequence, problems.
//
///////////////////////////////////////////////////////////////////////////////

#pragma once

using namespace std;

std::string dynamic_longest_substring(const std::string& a,
                                      const std::string& b) {

    
    int m = a.length();
    int n = b.length();
    
    std::string s = "";
    std::string A[m + 1][n + 1];
    
    for(int i = 0; i <= m; i++){
        A[i][0] = "";
    }
    
    for(int j = 0; j <= n; j++){
        A[0][j] = "";
    }
    
    
    for(int i = 1; i <= m; i++) {
        
        for(int j = 1; j <= n; j++){
            
            if(a[i - 1] != b[j - 1]) {
                
                A[i][j] = "";
            }else {
                
                A[i][j] = A[i-1][j-1] + a[i-1];
              
                if(A[i][j].length() > s.length()){
                    s = A[i][j];
                }
            }
            
            
        }//End Inner-For loop
       
    }//End Outer-For loop

    return s;
}

std::string dynamic_longest_subsequence(const std::string& a,
                                        const std::string& b) {
   
    int m = a.length();
    int n = b.length();
    std::string A[m + 1][n + 1];
    std::string s = "";
    std::string s1 = "";
    std::string s2 = "";


    for(int i = 0; i < m; i++){
        A[i][0] = "";
    }
    
    for(int j = 0; j < n; j++){
        
        A[0][j] = "";
    }
    
    
    for(int i = 1; i <= m; i++) {
        
        for(int j = 1; j <= n; j++){
            
            if(a[i - 1] == b[j - 1]) {
                
                A[i][j] = A[i-1][j-1] + a[i-1];
                
                
            }else if(A[i-1][j].length() > A[i][j-1].length()) {
                
                A[i][j] = A[i-1][j];
                
            }else {
                
                A[i][j] = A[i][j-1];
            }
            
        }//End Inner-For loop
        
    }//End Outer-For loop
    

    for(int i = 1; i <= n; i++){
     
        for(int j = 1; j <= m; j++) {
            
            s1 = A[m][i];
            s2 = A[j][n];
   
            if(s1.length() > s2.length()){
                s = s1;
            }
            
            if(s2.length() > s1.length()){
                s = s2;
            }
            
            if(s2.length() == s1.length()) {    //Check if subsequence are equal in row & column
                if(int(s1[0]) < int(s2[0])){    //Compare ASCII values. Returns true if ASCII value of s1[0] < s2[0]
                    s = s1;
                }else {
                    s = s2;
                }
            }
            
        }//END Inner-Loop
    
    }//END Outer-loop
    
 
  return s;
}
