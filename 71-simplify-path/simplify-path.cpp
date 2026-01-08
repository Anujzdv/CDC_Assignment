class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        string curr = "";

        for(int i = 0; i <= path.size(); i++){
            if(i == path.size() || path[i] == '/'){
                if(curr == "" || curr == ".") {
                    // do nothing
                }
                else if(curr == ".."){
                    if(!st.empty()) st.pop();
                }
                else{
                    st.push(curr);
                }
                curr = "";
            }
            else{
                curr += path[i];
            }
        }

        string ans = "";
        while(!st.empty()){
            ans = "/" + st.top() + ans;
            st.pop();
        }

        if(ans == "") return "/";
        return ans;
    }
};