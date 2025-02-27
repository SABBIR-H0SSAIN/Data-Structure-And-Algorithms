  #include <bits/stdc++.h>
  using namespace std;

    bool is_operator(char c) {
        return (c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == '^' || c == ')');
    }

    int priority(char c) {

        if (c == '^') return 3;
        else if (c == '*' || c == '/') return 2;
        else if (c == '+' || c == '-') return 1;
        else return 0;
    }

    string infixToPostfixMod(string& s) {

        string postfix = "";
        stack<char> st;

        for (int i = 0; i < s.size(); i++) {

            if (!is_operator(s[i])) {
                postfix.push_back(s[i]);
            } else {

                if (s[i] == ')') {

                    while (!st.empty() && st.top() != '(') {
                        postfix.push_back(st.top());
                        st.pop();
                    }

                    if (!st.empty() && st.top() == '(') st.pop();

                } else if (s[i] == '(') {
                    st.push(s[i]);
                } else {

                    while (!st.empty() && st.top() != '(' && priority(st.top()) > priority(s[i])) {
                        postfix.push_back(st.top());
                        st.pop();
                    }

                    st.push(s[i]);
                }
            }
        }

        while (!st.empty()) {
            postfix.push_back(st.top());
            st.pop();
        }

        return postfix;
    }

string infixToPrefix(string s){
    reverse(s.begin(),s.end());
    for(char &c:s){
        if(c=='(') c=')';
        else if(c==')')c='(';
    }
    s=infixToPostfixMod(s);
    reverse(s.begin(),s.end());
    return s;
}

int main(){
    string infinix="a+b*(c^d-e)^(f+g*h)-i";
    //output should: -+a*b^-^cde+f*ghi
    cout<<infixToPrefix(infinix)<<endl;
    return 0;
}
