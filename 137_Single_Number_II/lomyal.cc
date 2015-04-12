
// T=O(n) S=O(1)
class Solution {
public:
    int singleNumber(int A[], int n)
    {
        int ones = 0, twos = 0;  // 含义是状态机的某位，这里是第一位（靠左）和第二位

        // A中每一位的计算都是独立的，以下分析仅考虑int变量中单独的某一位：
        // 特点：若输入是0，而状态机状态不改变，若输入是1，则状态机向下走一个状态
        // 状态：0->1->2(->3(0)) / 00->01->10(->00)
        // 每个循环向状态机输入一个数，输入为1的相应位的状态变化一次
        // 循环体中的语句是按照状态变化规则特别设计出的

        for(int i = 0; i < n; i++){
            ones = (ones ^ A[i]) & ~twos;  // 状态机的第一位 0->1->0(->0)
            twos = (twos ^ A[i]) & ~ones;  // 状态机的第二位 0->0->1(->0)

            // 例子：若某位为1，出现0-3次时的状态依次是：00->01->10->00
            // 例子：若某位为0，出现0-3次时的状态依次是：00->00->00->00
        }

        return ones;  // 只出现一次的位“1”在状态机的第一位恰好是1，因此ones就是只出现一次的那个数
    }
};

// 状态变化规则语句如何快速写出？
//      使用数字电路中状态机的设计方法


// 若状态不编码，用一位表示一个状态是否更好写规则？(000->001->010->100->000)
//      貌似不好使……