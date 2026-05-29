class Solution {
public:
void multiplyBigNumbers(const vector<int>& a, const vector<int>& b, vector<int>& res) {
    if ((a.size() == 1 && a[0] == 0) || (b.size() == 1 && b[0] == 0)) {
        res = {0};
        return;
    }

    vector<int> result(a.size() + b.size(), 0);

    for (int i = a.size() - 1; i >= 0; --i) {
        for (int j = b.size() - 1; j >= 0; --j) {
            int mul = a[i] * b[j];
            
            int p1 = i + j;      
            int p2 = i + j + 1;  

            int sum = mul + result[p2];

            result[p2] = sum % 10;   
            result[p1] += sum / 10;  
        }
    }

    size_t startPos = 0;
    while (startPos < result.size() && result[startPos] == 0) {
        startPos++;
    }

    res.assign(result.begin() + startPos, result.end());
}
    string multiply(string num1, string num2) {
     vector<int> n1;
     vector<int> n2;
     for(char c : num1){
        n1.push_back(c - '0');
     }
      for(char c : num2){
        n2.push_back(c - '0');
     }
     vector<int> res;
     multiplyBigNumbers(n1,n2,res);
     string s = "";
     for(int x : res){
        char c = x + '0';
        s+=c;
     }
    return s;
    }
};