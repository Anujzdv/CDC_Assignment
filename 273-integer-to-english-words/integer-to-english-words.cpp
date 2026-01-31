class Solution {
public:
    string below20[20] = {"","One","Two","Three","Four","Five","Six","Seven","Eight","Nine",
                          "Ten","Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen",
                          "Seventeen","Eighteen","Nineteen"};

    string tens[10] = {"","Ten","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"};

    string helper(int num) {
        if (num == 0) return "";
        if (num < 20) return below20[num] + " ";
        if (num < 100) return tens[num / 10] + " " + helper(num % 10);
        return below20[num / 100] + " Hundred " + helper(num % 100);
    }

    string numberToWords(int num) {
        if (num == 0) return "Zero";

        string res;
        if (num >= 1000000000) {
            res += helper(num / 1000000000) + "Billion ";
            num %= 1000000000;
        }
        if (num >= 1000000) {
            res += helper(num / 1000000) + "Million ";
            num %= 1000000;
        }
        if (num >= 1000) {
            res += helper(num / 1000) + "Thousand ";
            num %= 1000;
        }
        res += helper(num);

        while (!res.empty() && res.back() == ' ')
            res.pop_back();

        return res;
    }
};
