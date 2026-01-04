class Solution {
public:
    int sumFourDivisors(vector<int>& numbers) {
        int finalSum = 0;

        for (int currentNumber : numbers) {
            vector<int> divisorList;

            for (int possibleDivisor = 1;
                 possibleDivisor * possibleDivisor <= currentNumber;
                 possibleDivisor++) {

                if (currentNumber % possibleDivisor == 0) {
                    divisorList.push_back(possibleDivisor);

                    int pairedDivisor = currentNumber / possibleDivisor;
                    if (pairedDivisor != possibleDivisor)
                        divisorList.push_back(pairedDivisor);
                }

                if (divisorList.size() > 4)
                    break;
            }

            if (divisorList.size() == 4) {
                for (int value : divisorList)
                    finalSum += value;
            }
        }

        return finalSum;   
    }
};