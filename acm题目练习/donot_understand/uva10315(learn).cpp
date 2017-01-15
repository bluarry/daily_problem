#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int value( char ch )
{
    if ( ch == 'T' ) return 8;
    if ( ch == 'J' ) return 9;
    if ( ch == 'Q' ) return 10;
    if ( ch == 'K' ) return 11;
    if ( ch == 'A' ) return 12;
    return ch - '2';
}

int color( char ch )
{
    if ( ch == 'S' ) return 0;
    if ( ch == 'H' ) return 1;
    if ( ch == 'D' ) return 2;
    if ( ch == 'C' ) return 3;
}

int tests(char cards[][3])
{
    //冒泡终于有用武之地了╮(╯▽╰)╭
    for (int i = 5; i > 1; -- i)
        for (int j = 1; j < i; ++ j)
            if (value(cards[j-1][0]) > value(cards[j][0])) {
                swap(cards[j-1][0], cards[j][0]);
                swap(cards[j-1][1], cards[j][1]);
            }

    int maps[5][13];
    memset(maps, 0, sizeof(maps));                              //统计花色及个数
    for (int i = 0; i < 5; ++ i) {
        maps[color(cards[i][1])][value(cards[i][0])] ++;
        maps[4][value(cards[i][0])] ++;
    }
    //同花顺，牌面连续，花色相同，按最大的值比较；同花顺，区间[13^5+40，13^5+53]；
    for (int i = 0; i < 4; ++ i)
        for (int j = 0; j < 9; ++ j)
            if (maps[i][j]&maps[i][j+1]&maps[i][j+2]&maps[i][j+3]&maps[i][j+4])
                return 13*13*13*13*13+40+j;
    //四条，牌面有四个相同的值，按四个的牌面比较；四条，区间[13^5+20，13^5+33]；
    for (int i = 0; i < 13; ++ i)
        if (maps[4][i] >= 4) return 13*13*13*13*13+20+i;
    //船牌，牌面有三个相同值，剩下两个也相同值，按三个的牌面比较；船牌，区间[13^5+1，13^5+14]；
    int three = 0,two = 0;
    for (int i = 12; i >= 0; -- i) {
        if (maps[4][i] == 2)
            two = two*15+i+1;
        if (maps[4][i] == 3)
            three = i+1;
    }
    if (two && three) return 13*13*13*13*13+three+1;
    //同花，五张牌的花色相同，不是顺子，按牌面最大的开始比，相同比较下一个；同花，区间[13^4，13^5]；
    for (int i = 0; i < 4; ++ i) {
        int count = 0, number = 0;
        for (int j = 12; j >= 0; -- j)
            for (int k = 0; k < maps[i][j]; ++ k) {
                ++ count;
                number = number*13+j;
            }
        if (count == 5) return number;
    }
    //顺子，五张牌的值连续，按最大的值比较；顺子，区间[-20，-5]；
    for (int i = 0; i < 9; ++ i)
        if (maps[4][i]&maps[4][i+1]&maps[4][i+2]&maps[4][i+3]&maps[4][i+4])
            return i-20;
    //三条，牌面有三个相同的值，按三个的牌面比较；三条，区间[-40，-25]；
    if (three) return three-40;

    int ans = 0;
    for (int i = 12; i >= 0; -- i)
        if (maps[4][i] == 1)
            ans = ans*13+i;
    //两对，牌面有两个对子，比较最大的对子，相同比较第二对，相同比较剩下的；两对，区间[-8000，-2000]
    if (two >= 15) two*15+ans-8000;
    //一对，牌面有一个对子，即两个同值，比对子，相同则按同花比较；一对，区间[-13^5*2，-13^4]；
    if (two) return two*13*13*13+ans-13*13*13*13*30;
    //大牌，没有以上牌型，和同花比较方式相同。大牌，区间[-13^5*4，13^5*3]；
    return ans-13*13*13*13*50;
}

int main()
{
    char white[5][3],black[5][3];
    while ( ~scanf("%s",black[0]) ) {
        for (int i = 1; i < 5; ++ i)
            scanf("%s",black[i]);
        for (int i = 0; i < 5; ++ i)
            scanf("%s",white[i]);

        int value = tests(black)-tests(white);
        if (value < 0)
            printf("White wins.\n");
        else if (value > 0)
            printf("Black wins.\n");
        else printf("Tie.\n");
    }
    return 0;
}
